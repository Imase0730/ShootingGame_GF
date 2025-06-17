#include "BulletManager.h"
#include "Game/Screen.h"

// コンストラクタ
BulletManager::BulletManager()
	: m_bulletCount{ 0 }
	, m_pBullet{ nullptr }
{
}

// デストラクタ
BulletManager::~BulletManager()
{
	// 確保したメモリを解放する
	if (m_pBullet) delete[] m_pBullet;
}

// 初期化処理
void BulletManager::Initialize(Bullet::Type type, int bulletCount)
{
	// 管理する弾の数
	m_bulletCount = bulletCount;

	// もし一度メモリが確保されていたら解放する
	if (m_pBullet) delete[] m_pBullet;

	// 弾の数分メモリを確保する
	m_pBullet = new Bullet[bulletCount];

	// 弾のタイプを設定する
	for (int i = 0; i < bulletCount; i++)
	{
		m_pBullet[i].SetType(type);
	}
}

// 更新処理
void BulletManager::Update()
{
	// 全ての弾の更新処理を行う
	for (int i = 0; i < m_bulletCount; i++)
	{
		// 弾がアクティブだったら更新する
		if (m_pBullet[i].IsActive()) m_pBullet[i].Update();
	}
}

// 描画処理
void BulletManager::Render(int ghShootingGame)
{
	// 全ての弾の描画処理を行う
	for (int i = 0; i < m_bulletCount; i++)
	{
		// 弾がアクティブだったら描画する
		if (m_pBullet[i].IsActive()) m_pBullet[i].Render(ghShootingGame);
	}
}

// 終了処理
void BulletManager::Finalize()
{
}

// 弾を発射する関数
void BulletManager::ShootBullet(POINT position)
{
	for (int i = 0; i < m_bulletCount; i++)
	{
		// 弾が未使用だったら
		if (!m_pBullet[i].IsActive())
		{
			// 弾を発射する
			m_pBullet[i].Shoot(position);
			return;
		}
	}
}

// 管理している弾を取得する関数
Bullet* BulletManager::GetBullet(int index)
{
	// 弾の配列の添え字にできるインデックスかチェックする
	if ((index < 0) || (index >= m_bulletCount)) return nullptr;

	// 弾のワークが使用中なら
	if (m_pBullet[index].IsActive())
	{
		return &m_pBullet[index];
	}

	return nullptr;
}

