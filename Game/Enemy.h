#pragma once

// 敵クラス
class Enemy
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 大きさ
	static constexpr int SIZE = 64;

	// 移動の速さ
	static constexpr int SPEED = 5;

	// データメンバの宣言 -----------------------------------------------
private:

	// アクティブならtrueを設定
	bool m_isActive;

	// 位置
	POINT m_position;

	// 速度
	POINT m_velocity;


	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Enemy();

	// デストラクタ
	~Enemy();

	// 初期化関数
	void Initialize();

	// 更新関数
	void Update();

	// 描画関数
	void Render(int ghShootingGame);

	// 敵がアクティブか調べる関数
	bool IsActive() const { return m_isActive; }

	// この敵を出現させる関数
	void Appear(POINT position);

};
