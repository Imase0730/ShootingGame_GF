#pragma once

#include "Bullet.h"

// プレイヤークラス
class Player
{
	// クラス定数の宣言 -------------------------------------------------
public:

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

	// 弾
	Bullet m_bullet;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Player();

	// デストラクタ
	~Player();

	// 初期化関数
	void Initialize(POINT position);

	// 更新関数
	void Update(int keyCondition, int keyTrigger);

	// 描画関数
	void Render(int ghShootingGame);

};
