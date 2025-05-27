#include "EnemyManager.h"
#include "Game/Screen.h"

// コンストラクタ
EnemyManager::EnemyManager()
	: m_enemyCount{ 0 }
	, m_pEnemy{ nullptr }
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
}

// 描画処理
void EnemyManager::Render(int ghShootingGame)
{
}

// 終了処理
void EnemyManager::Finalize()
{
}
