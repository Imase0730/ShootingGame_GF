#include "Enemy.h"
#include "Game/Screen.h"

// コンストラクタ
Enemy::Enemy()
	: m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
{
	m_velocity.y = Enemy::SPEED;
}

// デストラクタ
Enemy::~Enemy()
{
}

// 初期化関数
void Enemy::Initialize(POINT position)
{
	// 位置を初期化する
	m_position = position;
}

// 更新関数
void Enemy::Update()
{
	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;
}

// 描画関数
void Enemy::Render(int ghShootingGame)
{
	// 敵の描画
	DrawRectExtendGraph( m_position.x, m_position.y, m_position.x + Enemy::SIZE, m_position.y + Enemy::SIZE
					   , 96, 0, 32, 32
					   , ghShootingGame, TRUE);
}
