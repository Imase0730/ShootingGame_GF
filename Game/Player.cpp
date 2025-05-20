#include "Player.h"

// コンストラクタ
Player::Player()
	: m_position{ 0, 0 }
{
}

// デストラクタ
Player::~Player()
{
}

// 更新関数
void Player::Update(int keyCondition, int keyTrigger)
{
}

// 描画関数
void Player::Render(int ghShootingGame)
{
	// プレイヤーの描画
	DrawRectExtendGraph( m_position.x, m_position.y, m_position.x + Player::SIZE, m_position.y + Player::SIZE
					   , 0, 0, 32, 32
					   , ghShootingGame, TRUE);
}
