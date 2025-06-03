#include "EnemyManager.h"
#include "Game/Screen.h"

// �R���X�g���N�^
EnemyManager::EnemyManager()
	: m_enemyCount{ 0 }
	, m_pEnemy{ nullptr }
	, m_spawnCounter{ 0 }
{
}

// �f�X�g���N�^
EnemyManager::~EnemyManager()
{
	// �m�ۂ������������������
	if (m_pEnemy) delete[] m_pEnemy;
}

// ����������
void EnemyManager::Initialize(int enemyCount)
{
	// �Ǘ�����G�̐�
	m_enemyCount = enemyCount;

	// ������x���������m�ۂ���Ă�����������
	if (m_pEnemy) delete[] m_pEnemy;

	// �G�̐������������m�ۂ���
	m_pEnemy = new Enemy[enemyCount];
}

// �X�V����
void EnemyManager::Update()
{
	// �S�Ă̓G�̍X�V�������s��
	for (int i = 0; i < m_enemyCount; i++)
	{
		// �G���A�N�e�B�u��������X�V����
		if (m_pEnemy[i].IsActive()) m_pEnemy[i].Update();
	}

	// �G�̏o���p�̃J�E���^�[�̉��Z
	m_spawnCounter++;

	// ���̊Ԋu�œG���o��������
	if (m_spawnCounter >= SPAWN_INTERVAL)
	{
		m_spawnCounter = 0;

		// �G���o��������
		POINT position = POINT{ GetRand(Screen::WIDTH - Enemy::SIZE), -Enemy::SIZE };
		SpawnEnemy(position);
	}

}

// �`�揈��
void EnemyManager::Render(int ghShootingGame)
{
	// �S�Ă̓G�̕`�揈�����s��
	for (int i = 0; i < m_enemyCount; i++)
	{
		// �G���A�N�e�B�u��������`�悷��
		if (m_pEnemy[i].IsActive()) m_pEnemy[i].Render(ghShootingGame);
	}
}

// �I������
void EnemyManager::Finalize()
{
}

// �G���o��������֐�
void EnemyManager::SpawnEnemy(POINT position)
{
	for (int i = 0; i < m_enemyCount; i++)
	{
		// �G�����g�p��������
		if (!m_pEnemy[i].IsActive())
		{
			// �G���o��������
			m_pEnemy[i].Spawn(position);
			return;
		}
	}
}

