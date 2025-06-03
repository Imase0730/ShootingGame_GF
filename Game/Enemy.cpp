#include "Enemy.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Enemy::Enemy()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 } 
	, m_shootCounter{ 0 }
{
}

// �f�X�g���N�^
Enemy::~Enemy()
{
}

// �������֐�
void Enemy::Initialize(POINT position)
{
	// �G�̈ړ����x��ݒ肷��
	m_velocity = POINT{ 0, Enemy::SPEED };

	// �o���ʒu��ݒ肷��
	m_position = position;
}

// �X�V�֐�
void Enemy::Update(BulletManager& bulletManager)
{
	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// ��ʊO�o����
	if (m_position.y > Screen::HEIGHT)
	{
		// �G�𖢎g�p�ɂ���
		m_isActive = false;
	}

	// �e�̔��˗p�J�E���^�[�����Z
	m_shootCounter++;
	if (m_shootCounter > SHOOT_INTERVAL)
	{
		m_shootCounter = 0;
		// �e�𔭎˂���
		POINT position{ m_position.x + (Enemy::SIZE - Bullet::SIZE) / 2
					  , m_position.y + (Enemy::SIZE - Bullet::SIZE) };
		bulletManager.ShootBullet(position);
	}
}

// �`��֐�
void Enemy::Render(int ghShootingGame)
{
	// �G�̕`��
	DrawRectExtendGraph(m_position.x, m_position.y, m_position.x + Enemy::SIZE, m_position.y + Enemy::SIZE
		, 96, 0, 32, 32
		, ghShootingGame, TRUE);
}

// ���̓G���o��������֐�
void Enemy::Spawn(POINT position)
{
	// �A�N�e�B�u�ɂ���
	m_isActive = true;

	// �G������������
	Initialize(position);
}
