#pragma once

#include "BulletManager.h"

// プレイヤークラス
class Player
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// アクティブならtrueを設定
	bool m_isActive;

	// 大きさ
	static constexpr int SIZE = 64;

	// 移動の速さ
	static constexpr int SPEED = 5;

	// データメンバの宣言 -----------------------------------------------
private:

	// 位置
	POINT m_position;

	// 速度
	POINT m_velocity;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Player();

	// デストラクタ
	~Player();

	// 初期化関数
	void Initialize(POINT position);

	// 更新関数
	void Update(int keyCondition, int keyTrigger, BulletManager& bulletManager);

	// 描画関数
	void Render(int ghShootingGame);

	// 境界ボックスを取得する関数
	RECT GetBoundingBox() const;

	// アクティブか調べる関数
	bool IsActive() const { return m_isActive; }

	// 衝突したら呼び出される関数
	void OnHit() { m_isActive = false; }

	// プレイヤーの中心の位置を取得する関数
	POINT GetCenterPosition();

};
