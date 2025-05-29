#include "Player.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Player::Player()
	: m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
	, m_bullet{ Bullet::Type::Player }
{
}

// �f�X�g���N�^
Player::~Player()
{
}

// �������֐�
void Player::Initialize(POINT position)
{
	// �ʒu������������
	m_position = position;
}

// �X�V�֐�
void Player::Update(int keyCondition, int keyTrigger)
{
	// ���x���O�ɂ���
	m_velocity = POINT{ 0, 0 };

	// �E�L�[�������ꂽ
	if (keyCondition & PAD_INPUT_RIGHT)
	{
		m_velocity.x = Player::SPEED;
	}
	// ���L�[�������ꂽ
	if (keyCondition & PAD_INPUT_LEFT)
	{
		m_velocity.x = -Player::SPEED;
	}

	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// �v���C���[����ʊO�֏o�Ȃ��悤�Ɉʒu�𒲐�
	if (m_position.x < 0)
	{
		m_position.x = 0;
	}
	if (m_position.x > Screen::WIDTH - Player::SIZE)
	{
		m_position.x = Screen::WIDTH - Player::SIZE;
	}

	// �X�y�[�X�L�[�������ꂽ��
	if (keyTrigger & PAD_INPUT_10)
	{
		// �e�����g�p�Ȃ�
		if (!m_bullet.IsActive())
		{
			// �e�𔭎˂���
			POINT pos = POINT{ m_position.x + (Player::SIZE - Bullet::SIZE) / 2, m_position.y };
			m_bullet.Shoot(pos);
		}
	}

	// �e���g�p����������X�V����
	if (m_bullet.IsActive()) m_bullet.Update();

}

// �`��֐�
void Player::Render(int ghShootingGame)
{
	// �v���C���[�̕`��
	DrawRectExtendGraph( m_position.x, m_position.y, m_position.x + Player::SIZE, m_position.y + Player::SIZE
					   , 0, 0, 32, 32
					   , ghShootingGame, TRUE);

	// �e���g�p����������`�悷��
	if (m_bullet.IsActive()) m_bullet.Render(ghShootingGame);
}
