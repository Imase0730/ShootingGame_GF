#pragma once

#include "BulletManager.h"

// 敵クラス
class Enemy
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 大きさ
	static constexpr int SIZE = 64;

	// 移動の速さ
	static constexpr int SPEED = 5;

	// 弾の発射間隔
	static constexpr int SHOOT_INTERVAL = 60;

	// データメンバの宣言 -----------------------------------------------
private:

	// アクティブならtrueを設定
	bool m_isActive;

	// 位置
	POINT m_position;

	// 速度
	POINT m_velocity;

	// 弾の発射用カウンター
	int m_shootCounter;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Enemy();

	// デストラクタ
	~Enemy();

	// 初期化関数
	void Initialize(POINT position);

	// 更新関数
	void Update(BulletManager& bulletManager);

	// 描画関数
	void Render(int ghShootingGame);

	// 敵がアクティブか調べる関数
	bool IsActive() const { return m_isActive; }

	// この敵を出現させる関数
	void Spawn(POINT position);

	// 境界ボックスを取得する関数
	RECT GetBoundingBox() const;

	// 衝突したら呼び出される関数
	void OnHit() { m_isActive = false; }

	// 敵の中心の位置を取得する関数
	POINT GetCenterPosition();

};
