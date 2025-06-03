#include "Bullet.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Bullet::Bullet()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
	, m_type{ Type::None }
{
}

// �f�X�g���N�^
Bullet::~Bullet()
{
}

// �������֐�
void Bullet::Initialize(POINT position)
{
	// �e�̈ړ����x��ݒ肷��
	m_velocity = VELOCITY[static_cast<int>(m_type)];

	// �o���ʒu��ݒ肷��
	m_position = position;
}

// �X�V�֐�
void Bullet::Update()
{
	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// ��ʊO�ɒe���o�����H
	if ( (m_position.y < -Bullet::SIZE)		// ��ʊO�ɏo����i�㕔�j
	  || (m_position.y > Screen::HEIGHT)	// ��ʊO�ɏo����i�����j
	   )
	{
		// �e�𖢎g�p�ɂ���
		m_isActive = false;
	}
}

// �`��֐�
void Bullet::Render(int ghShootingGame)
{
	// �e�̃^�C�v���ɕ`�悷��e��ς���
	switch (m_type)
	{
	case Type::Player:
		// �v���C���[�̒e�̕`��
		DrawRectExtendGraph(m_position.x, m_position.y, m_position.x + Bullet::SIZE, m_position.y + Bullet::SIZE
			, 64, 32, 16, 16
			, ghShootingGame, TRUE);
		break;
	case Type::Enemy:
		// �G�̒e�̕`��
		DrawRectExtendGraph(m_position.x, m_position.y, m_position.x + Bullet::SIZE, m_position.y + Bullet::SIZE
			, 64 + 16, 32, 16, 16
			, ghShootingGame, TRUE);
		break;
	default:
		break;
	}
}

// �e�𔭎˂���֐�
void Bullet::Shoot(POINT position)
{
	// �A�N�e�B�u�ɂ���
	m_isActive = true;

	// �e������������
	Initialize(position);
}
