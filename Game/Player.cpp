#include "Player.h"

// �R���X�g���N�^
Player::Player()
	: m_position{ 0, 0 }
{
}

// �f�X�g���N�^
Player::~Player()
{
}

// �X�V�֐�
void Player::Update(int keyCondition, int keyTrigger)
{
}

// �`��֐�
void Player::Render(int ghShootingGame)
{
	// �v���C���[�̕`��
	DrawRectExtendGraph( m_position.x, m_position.y, m_position.x + Player::SIZE, m_position.y + Player::SIZE
					   , 0, 0, 32, 32
					   , ghShootingGame, TRUE);
}
