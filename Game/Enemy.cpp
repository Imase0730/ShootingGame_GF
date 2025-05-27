#include "Enemy.h"
#include "Game/Screen.h"

// コンストラクタ
Enemy::Enemy()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
{
}

// デストラクタ
Enemy::~Enemy()
{
}

// 初期化関数
void Enemy::Initialize()
{
	// 敵の移動速度を設定する
	m_velocity = POINT{ 0, Enemy::SPEED };
}

// 更新関数
void Enemy::Update()
{
	// アクティブじゃなかったら
	if (!m_isActive) return;

	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;
}

// 描画関数
void Enemy::Render(int ghShootingGame)
{
	// アクティブだったら
	if (m_isActive)
	{
		// 敵の描画
		DrawRectExtendGraph(m_position.x, m_position.y, m_position.x + Enemy::SIZE, m_position.y + Enemy::SIZE
			, 96, 0, 32, 32
			, ghShootingGame, TRUE);
	}
}

// この敵を出現させる関数
void Enemy::Appear(POINT position)
{
	// アクティブにする
	m_isActive = true;

	// 出現位置を設定する
	m_position = position;
}
