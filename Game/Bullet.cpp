#include "Bullet.h"
#include "Game/Screen.h"

// コンストラクタ
Bullet::Bullet()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
	, m_type{ Type::None }
{
}

// デストラクタ
Bullet::~Bullet()
{
}

// 初期化関数
void Bullet::Initialize(POINT position)
{
	// 敵の移動速度を設定する
	m_velocity = POINT{ 0, Bullet::SPEED };

	// 出現位置を設定する
	m_position = position;
}

// 更新関数
void Bullet::Update()
{
	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// 画面外出たら
	if (m_position.y > Screen::HEIGHT)
	{
		// 敵を未使用にする
		m_isActive = false;
	}
}

// 描画関数
void Bullet::Render(int ghShootingGame)
{
	// 敵の描画
	DrawRectExtendGraph(m_position.x, m_position.y, m_position.x + Bullet::SIZE, m_position.y + Bullet::SIZE
		, 96, 0, 32, 32
		, ghShootingGame, TRUE);
}

// この敵を出現させる関数
void Bullet::Spawn(POINT position)
{
	// アクティブにする
	m_isActive = true;

	// 敵を初期化する
	Initialize(position);
}
