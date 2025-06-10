#include "Player.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Player::Player()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
{
}

// �f�X�g���N�^
Player::~Player()
{
}

// �������֐�
void Player::Initialize(POINT position)
{
	// �A�N�e�B�u�ɂ���
	m_isActive = true;

	// �ʒu������������
	m_position = position;
}

// �X�V�֐�
void Player::Update(int keyCondition, int keyTrigger, BulletManager& bulletManager)
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
		// �e�𔭎˂���
		POINT position = POINT{
			m_position.x + (Player::SIZE - Bullet::SIZE) / 2, m_position.y };
		bulletManager.ShootBullet(position);
	}

}

// �`��֐�
void Player::Render(int ghShootingGame)
{
	// �v���C���[�̕`��
	DrawRectExtendGraph( m_position.x, m_position.y, m_position.x + Player::SIZE, m_position.y + Player::SIZE
					   , 0, 0, 32, 32
					   , ghShootingGame, TRUE);
}

// ���E�{�b�N�X���擾����֐�
RECT Player::GetBoundingBox() const
{
	RECT rect{};

	rect.left = m_position.x;
	rect.right = m_position.x + Player::SIZE;
	rect.top = m_position.y;
	rect.bottom = m_position.y + Player::SIZE;

	return rect;
}

// �v���C���[�̒��S�̈ʒu���擾����֐�
POINT Player::GetCenterPosition()
{
	return POINT{ m_position.x + Player::SIZE / 2, m_position.y + Player::SIZE / 2 };
}
