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
	// 弾の移動速度を設定する
	m_velocity = VELOCITY[static_cast<int>(m_type)];

	// 出現位置を設定する
	m_position = position;
}

// 更新関数
void Bullet::Update()
{
	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// 画面外に弾が出たか？
	if ( (m_position.y < -Bullet::SIZE)		// 画面外に出たら（上部）
	  || (m_position.y > Screen::HEIGHT)	// 画面外に出たら（下部）
	   )
	{
		// 弾を未使用にする
		m_isActive = false;
	}
}

// 描画関数
void Bullet::Render(int ghShootingGame)
{
	// 弾のタイプ毎に描画する弾を変える
	switch (m_type)
	{
	case Type::Player:
		// プレイヤーの弾の描画
		DrawRectExtendGraph(m_position.x, m_position.y, m_position.x + Bullet::SIZE, m_position.y + Bullet::SIZE
			, 64, 32, 16, 16
			, ghShootingGame, TRUE);
		break;
	case Type::Enemy:
		// 敵の弾の描画
		DrawRectExtendGraph(m_position.x, m_position.y, m_position.x + Bullet::SIZE, m_position.y + Bullet::SIZE
			, 64 + 16, 32, 16, 16
			, ghShootingGame, TRUE);
		break;
	default:
		break;
	}
}

// 弾を発射する関数
void Bullet::Shoot(POINT position)
{
	// アクティブにする
	m_isActive = true;

	// 弾を初期化する
	Initialize(position);
}
