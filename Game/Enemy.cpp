#include "Enemy.h"
#include "Game/Screen.h"

// コンストラクタ
Enemy::Enemy()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 } 
	, m_shootCounter{ 0 }
{
}

// デストラクタ
Enemy::~Enemy()
{
}

// 初期化関数
void Enemy::Initialize(POINT position)
{
	// 敵の移動速度を設定する
	m_velocity = POINT{ 0, Enemy::SPEED };

	// 出現位置を設定する
	m_position = position;
}

// 更新関数
void Enemy::Update(BulletManager& bulletManager)
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

	// 弾の発射用カウンターを加算
	m_shootCounter++;
	if (m_shootCounter > SHOOT_INTERVAL)
	{
		m_shootCounter = 0;
		// 弾を発射する
		POINT position{ m_position.x + (Enemy::SIZE - Bullet::SIZE) / 2
					  , m_position.y + (Enemy::SIZE - Bullet::SIZE) };
		bulletManager.ShootBullet(position);
	}
}

// 描画関数
void Enemy::Render(int ghShootingGame)
{
	// 敵の描画
	DrawRectExtendGraph(m_position.x, m_position.y, m_position.x + Enemy::SIZE, m_position.y + Enemy::SIZE
		, 96, 0, 32, 32
		, ghShootingGame, TRUE);
}

// この敵を出現させる関数
void Enemy::Spawn(POINT position)
{
	// アクティブにする
	m_isActive = true;

	// 敵を初期化する
	Initialize(position);
}
