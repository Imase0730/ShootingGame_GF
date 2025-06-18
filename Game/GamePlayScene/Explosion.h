#pragma once

// 爆発クラス
class Explosion
{
private:

	// 爆発のアニメーションステート
	enum class AnimationState
	{
		AnimNone = -1,
		Anim01, Anim02, Anim03, Anim04,
	};

private:

	// 爆発アニメーションの間隔
	static constexpr int ANIMATION_INTERVAL = 4;

	// 爆発の表示の大きさ
	static constexpr int SIZE = 64;

	// 爆発のスプライトシート上の絵の位置
	static constexpr POINT EXPLOSION_SPRITES[] =
	{
		{ 96 + 16 * 0, 32 },		// パターン１
		{ 96 + 16 * 1, 32 },		// パターン２
		{ 96 + 16 * 2, 32 },		// パターン３
		{ 96 + 16 * 3, 32 },		// パターン４
	};

private:

	// 表示位置
	POINT m_position;

	// アニメーションステート
	AnimationState m_animationState;

	// 爆発のアニメーションカウンター
	int m_animationCounter;

public:

	// コンストラクタ
	Explosion();

	// デストラクタ
	~Explosion();

	// 初期化関数
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Render(int ghShootingGame);

	// 指定した位置に爆発を表示する関数
	void StartExplosion(POINT position);

	// この爆発オブジェクトが使用中かチェックする関数
	bool IsActive();

};


