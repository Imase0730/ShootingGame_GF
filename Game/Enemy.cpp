#include "Enemy.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Enemy::Enemy()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
{
}

// �f�X�g���N�^
Enemy::~Enemy()
{
}

// �������֐�
void Enemy::Initialize()
{
	// �G�̈ړ����x��ݒ肷��
	m_velocity = POINT{ 0, Enemy::SPEED };
}

// �X�V�֐�
void Enemy::Update()
{
	// �A�N�e�B�u����Ȃ�������
	if (!m_isActive) return;

	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;
}

// �`��֐�
void Enemy::Render(int ghShootingGame)
{
	// �A�N�e�B�u��������
	if (m_isActive)
	{
		// �G�̕`��
		DrawRectExtendGraph(m_position.x, m_position.y, m_position.x + Enemy::SIZE, m_position.y + Enemy::SIZE
			, 96, 0, 32, 32
			, ghShootingGame, TRUE);
	}
}

// ���̓G���o��������֐�
void Enemy::Appear(POINT position)
{
	// �A�N�e�B�u�ɂ���
	m_isActive = true;

	// �o���ʒu��ݒ肷��
	m_position = position;
}
