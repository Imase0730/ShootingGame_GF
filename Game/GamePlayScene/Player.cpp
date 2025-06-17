#include "Player.h"
#include "Game/Screen.h"

// コンストラクタ
Player::Player()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
{
}

// デストラクタ
Player::~Player()
{
}

// 初期化関数
void Player::Initialize(POINT position)
{
	// アクティブにする
	m_isActive = true;

	// 位置を初期化する
	m_position = position;
}

// 更新関数
void Player::Update(int keyCondition, int keyTrigger, BulletManager& bulletManager)
{
	// 速度を０にする
	m_velocity = POINT{ 0, 0 };

	// 右キーが押された
	if (keyCondition & PAD_INPUT_RIGHT)
	{
		m_velocity.x = Player::SPEED;
	}
	// 左キーが押された
	if (keyCondition & PAD_INPUT_LEFT)
	{
		m_velocity.x = -Player::SPEED;
	}

	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// プレイヤーが画面外へ出ないように位置を調整
	if (m_position.x < 0)
	{
		m_position.x = 0;
	}
	if (m_position.x > Screen::WIDTH - Player::SIZE)
	{
		m_position.x = Screen::WIDTH - Player::SIZE;
	}

	// スペースキーが押されたら
	if (keyTrigger & PAD_INPUT_10)
	{
		// 弾を発射する
		POINT position = POINT{
			m_position.x + (Player::SIZE - Bullet::SIZE) / 2, m_position.y };
		bulletManager.ShootBullet(position);
	}

}

// 描画関数
void Player::Render(int ghShootingGame)
{
	// プレイヤーの描画
	DrawRectExtendGraph( m_position.x, m_position.y, m_position.x + Player::SIZE, m_position.y + Player::SIZE
					   , 0, 0, 32, 32
					   , ghShootingGame, TRUE);
}

// 境界ボックスを取得する関数
RECT Player::GetBoundingBox() const
{
	RECT rect{};

	rect.left = m_position.x;
	rect.right = m_position.x + Player::SIZE;
	rect.top = m_position.y;
	rect.bottom = m_position.y + Player::SIZE;

	return rect;
}

// プレイヤーの中心の位置を取得する関数
POINT Player::GetCenterPosition()
{
	return POINT{ m_position.x + Player::SIZE / 2, m_position.y + Player::SIZE / 2 };
}
