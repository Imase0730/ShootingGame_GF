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
	// �G�̈ړ����x��ݒ肷��
	m_velocity = POINT{ 0, Bullet::SPEED };

	// �o���ʒu��ݒ肷��
	m_position = position;
}

// �X�V�֐�
void Bullet::Update()
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
}

// �`��֐�
void Bullet::Render(int ghShootingGame)
{
	// �G�̕`��
	DrawRectExtendGraph(m_position.x, m_position.y, m_position.x + Bullet::SIZE, m_position.y + Bullet::SIZE
		, 96, 0, 32, 32
		, ghShootingGame, TRUE);
}

// ���̓G���o��������֐�
void Bullet::Spawn(POINT position)
{
	// �A�N�e�B�u�ɂ���
	m_isActive = true;

	// �G������������
	Initialize(position);
}
