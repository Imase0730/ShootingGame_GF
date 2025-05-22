#include "Enemy.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Enemy::Enemy()
	: m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
{
	m_velocity.y = Enemy::SPEED;
}

// �f�X�g���N�^
Enemy::~Enemy()
{
}

// �������֐�
void Enemy::Initialize(POINT position)
{
	// �ʒu������������
	m_position = position;
}

// �X�V�֐�
void Enemy::Update()
{
	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;
}

// �`��֐�
void Enemy::Render(int ghShootingGame)
{
	// �G�̕`��
	DrawRectExtendGraph( m_position.x, m_position.y, m_position.x + Enemy::SIZE, m_position.y + Enemy::SIZE
					   , 96, 0, 32, 32
					   , ghShootingGame, TRUE);
}
