//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"

// �R���X�g���N�^
GamePlayScene::GamePlayScene(Game* pGame)
	: m_pGame{ pGame }
	, m_ghShootingGame{ -1 }
	, m_player{}
	, m_enemyManager{}
	, m_playerBulletManager{}
	, m_enemyBulletManager{}
	, m_explosion{}
	, m_numberRenderer{ POINT{ Screen::WIDTH / 2 - (NumberRenderer::NUMBER_WIDTH * 2 * 6) / 2, 0}, 6, false }
	, m_score{ 0 }
{

}

// �f�X�g���N�^
GamePlayScene::~GamePlayScene()
{

}

// ����������
void GamePlayScene::Initialize()
{
	// �G�̓ǂݍ���
	m_ghShootingGame = LoadGraph(L"Resources/Textures/ShootingGame.png");

	// �v���C���[�̏�����
	POINT startPosition = POINT{ PLAYER_START_POSITION_X, PLAYER_START_POSITION_Y };
	m_player.Initialize(startPosition);

	// �G�̃}�l�[�W���[�̏�����
	m_enemyManager.Initialize(10);

	// �e�̃}�l�[�W���[�̏������i�v���C���[�p�j
	m_playerBulletManager.Initialize(Bullet::Type::Player, 3);

	// �e�̃}�l�[�W���[�̏������i�G�p�j
	m_enemyBulletManager.Initialize(Bullet::Type::Enemy, 100);

	// �����̃T�C�Y�̐ݒ�
	m_numberRenderer.SetSize(NumberRenderer::NUMBER_WIDTH * 2, NumberRenderer::NUMBER_HEIGHT * 2);

	// �����G�t�F�N�g�̏�����
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		m_explosion[i].Initialize();
	}
}

// �X�V����
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{
	// �v���C���[���A�N�e�B�u��������
	if (m_player.IsActive())
	{
		// �v���C���[�̍X�V
		m_player.Update(keyCondition, keyTrigger, m_playerBulletManager);
	}

	// �G�̃}�l�[�W���[�̍X�V
	m_enemyManager.Update(m_enemyBulletManager);

	// �e�̃}�l�[�W���[�̍X�V�i�v���C���[�p�j
	m_playerBulletManager.Update();

	// �e�̃}�l�[�W���[�̍X�V�i�G�p�j
	m_enemyBulletManager.Update();

	// �v���C���[�ƓG�̒e�Ƃ̏Փ˔���
	CheckPlayerColliedWithEnemyBullet();

	// �G�ƃv���C���[�̒e�Ƃ̏Փ˔���
	CheckEnemyColliedWithPlayerBullet();

	// �����̃G�t�F�N�g�̍X�V
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		m_explosion[i].Update();
	}

	// ���_��ݒ�
	m_numberRenderer.SetNumber(m_score);
}

// �`�揈��
void GamePlayScene::Render()
{
	// �v���C���[���A�N�e�B�u��������
	if (m_player.IsActive())
	{
		// �v���C���[�̕`��
		m_player.Render(m_ghShootingGame);
	}

	// �G�̃}�l�[�W���[�̕`��
	m_enemyManager.Render(m_ghShootingGame);

	// �e�̃}�l�[�W���[�̕`��i�v���C���[�p�j
	m_playerBulletManager.Render(m_ghShootingGame);

	// �e�̃}�l�[�W���[�̕`��i�G�p�j
	m_enemyBulletManager.Render(m_ghShootingGame);

	// �����G�t�F�N�g�̕`��
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		m_explosion[i].Render(m_ghShootingGame);
	}

	// �����̕`��
	m_numberRenderer.Render(m_ghShootingGame);

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlay�V�[��");
}

// �I������
void GamePlayScene::Finalize()
{

}

// ��`�̏Փ˔���
bool GamePlayScene::IsColliding(RECT a, RECT b)
{
	if ((a.right >= b.left)
		&& (a.left <= b.right)
		&& (a.bottom >= b.top)
		&& (a.top <= b.bottom)
		)
	{
		return true;
	}
	return false;
}

// �v���C���[�ƓG�̒e�Ƃ̏Փ˔���
void GamePlayScene::CheckPlayerColliedWithEnemyBullet()
{
	// �v���C���[�����S���Ă����珈�����s��Ȃ�
	if (m_player.IsActive() == false) return;

	// �Ǘ����Ă���G�̒e�̐������[�v
	for (int i = 0; i < m_enemyBulletManager.GetBulletCount(); i++)
	{
		// �g�p���Ă��Ȃ��e�Ȃ珈�����s��Ȃ�
		Bullet* pBullet = m_enemyBulletManager.GetBullet(i);
		if (pBullet == nullptr) continue;

		// �v���C���[�ƓG�̒e�ƏՓ˔�����s��
		if (IsColliding(m_player.GetBoundingBox(), pBullet->GetBoundingBox()))
		{
			// �Փ˂���
			m_player.OnHit();
			pBullet->OnHit();
			// �v���C���[�̈ʒu�ɔ����G�t�F�N�g�𔭐�������
			SetExplosion(m_player.GetCenterPosition());
			// �^�C�g���V�[����
			m_pGame->RequestSceneChange(Game::SceneID::TITLE);
		}
	}
}

// �G�ƃv���C���[�̒e�Ƃ̏Փ˔���
void GamePlayScene::CheckEnemyColliedWithPlayerBullet()
{
	// �v���C���[�̒e�̊Ǘ��������[�v
	for (int j = 0; j < m_playerBulletManager.GetBulletCount(); j++)
	{
		// �e���g�p���łȂ��Ȃ珈�����s��Ȃ�
		Bullet* pBullet = m_playerBulletManager.GetBullet(j);
		if (!pBullet) continue;

		// �G�̊Ǘ��������[�v
		for (int i = 0; i < m_enemyManager.GetEnemyCount(); i++)
		{
			// �G���g�p���łȂ��Ȃ珈�����s��Ȃ�
			Enemy* pEnemy = m_enemyManager.GetEnemy(i);
			if (!pEnemy) continue;

			// �v���C���[�̒e�ƓG�̏Փ˔�����s��
			if (IsColliding(pBullet->GetBoundingBox(), pEnemy->GetBoundingBox()))
			{
				// �Փ˂���
				pBullet->OnHit();
				pEnemy->OnHit();
				// �G�̈ʒu�ɔ����G�t�F�N�g�𔭐�������
				SetExplosion(pEnemy->GetCenterPosition());
				// ���_���Z
				m_score += ENEMY_SCORE;
			}
		}
	}
}

// �����G�t�F�N�g��\������֐�
void GamePlayScene::SetExplosion(POINT position)
{
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		// �g�p�\�Ȕ����G�t�F�N�g�Ȃ�
		if (!m_explosion[i].IsActive())
		{
			// �����G�t�F�N�g�𔭐�����
			m_explosion[i].StartExplosion(position);
			return;
		}
	}
}


