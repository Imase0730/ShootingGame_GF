#pragma once

#include "Bullet.h"

// 弾のマネージャークラス
class BulletManager
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 弾の出現間隔
	static constexpr int SPAWN_INTERVAL = 10;

	// データメンバの宣言 -----------------------------------------------
private:

	// 管理できる弾の数
	int m_bulletCount;

	// 弾のオブジェクトへのポインタ
	Bullet* m_pBullet;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	BulletManager();

	// デストラクタ
	~BulletManager();

	// 初期化処理
	void Initialize(Bullet::Type type, int BulletCount);

	// 更新処理
	void Update();

	// 描画処理
	void Render(int ghShootingGame);

	// 終了処理
	void Finalize();

	// 弾を発射する関数
	void ShootBullet(POINT point);

};
