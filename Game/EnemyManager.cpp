#include "EnemyManager.h"
#include "Game/Screen.h"

// コンストラクタ
EnemyManager::EnemyManager()
	: m_enemyCount{ 0 }
	, m_pEnemy{ nullptr }
	, m_spawnCounter{ 0 }
{
}

// デストラクタ
EnemyManager::~EnemyManager()
{
	// 確保したメモリを解放する
	if (m_pEnemy) delete[] m_pEnemy;
}

// 初期化処理
void EnemyManager::Initialize(int enemyCount)
{
	// 管理する敵の数
	m_enemyCount = enemyCount;

	// もし一度メモリが確保されていたら解放する
	if (m_pEnemy) delete[] m_pEnemy;

	// 敵の数分メモリを確保する
	m_pEnemy = new Enemy[enemyCount];
}

// 更新処理
void EnemyManager::Update()
{
	// 全ての敵の更新処理を行う
	for (int i = 0; i < m_enemyCount; i++)
	{
		// 敵がアクティブだったら更新する
		if (m_pEnemy[i].IsActive()) m_pEnemy[i].Update();
	}

	// 敵の出現用のカウンターの加算
	m_spawnCounter++;

	// 一定の間隔で敵を出現させる
	if (m_spawnCounter >= SPAWN_INTERVAL)
	{
		m_spawnCounter = 0;

		// 敵を出現させる
		POINT position = POINT{ GetRand(Screen::WIDTH - Enemy::SIZE), -Enemy::SIZE };
		SpawnEnemy(position);
	}

}

// 描画処理
void EnemyManager::Render(int ghShootingGame)
{
	// 全ての敵の描画処理を行う
	for (int i = 0; i < m_enemyCount; i++)
	{
		// 敵がアクティブだったら描画する
		if (m_pEnemy[i].IsActive()) m_pEnemy[i].Render(ghShootingGame);
	}
}

// 終了処理
void EnemyManager::Finalize()
{
}

// 敵を出現させる関数
void EnemyManager::SpawnEnemy(POINT position)
{
	for (int i = 0; i < m_enemyCount; i++)
	{
		// 敵が未使用だったら
		if (!m_pEnemy[i].IsActive())
		{
			// 敵を出現させる
			m_pEnemy[i].Spawn(position);
			return;
		}
	}
}

