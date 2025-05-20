#pragma once

// プレイヤークラス
class Player
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 大きさ
	static constexpr int SIZE = 64;

	// データメンバの宣言 -----------------------------------------------
private:

	// 位置
	POINT m_position;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Player();

	// デストラクタ
	~Player();

	// 更新関数
	void Update(int keyCondition, int keyTrigger);

	// 描画関数
	void Render(int ghShootingGame);

};
