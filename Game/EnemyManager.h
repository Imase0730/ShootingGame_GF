#pragma once

#include "Enemy.h"
#include "BulletManager.h"

// 敵のマネージャークラス
class EnemyManager
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 敵の出現間隔
	static constexpr int SPAWN_INTERVAL = 10;

	// データメンバの宣言 -----------------------------------------------
private:

	// 管理できる敵の数
	int m_enemyCount;

	// 敵のオブジェクトへのポインタ
	Enemy* m_pEnemy;

	// 敵の出現用カウンター
	int m_spawnCounter;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	EnemyManager();

	// デストラクタ
	~EnemyManager();

	// 初期化処理
	void Initialize(int enemyCount);

	// 更新処理
	void Update(BulletManager& bulletManager);

	// 描画処理
	void Render(int ghShootingGame);

	// 終了処理
	void Finalize();

public:

	// 敵の管理している数を取得する関数
	int GetEnemyCount() const { return m_enemyCount; }

	// 管理している敵を取得する関数
	Enemy* GetEnemy(int index);

private:

	// 敵を出現させる関数
	void SpawnEnemy(POINT point);

};
