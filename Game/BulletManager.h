#pragma once

#include "Bullet.h"

// 弾のマネージャークラス
class BulletManager
{
	// クラス定数の宣言 -------------------------------------------------
public:

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

	// 管理している弾を取得する関数
	Bullet* GetBullet(int index);

	// 管理している弾の数を取得する関数
	int GetBulletCount() const { return m_bulletCount; }

};
