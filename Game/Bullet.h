#pragma once

// 弾クラス
class Bullet
{
	// 列挙型の定義 -----------------------------------------------------
public:

	// 弾のタイプ
	enum class Type { None, Player, Enemy, TypeMax };

	// クラス定数の宣言 -------------------------------------------------
public:

	// 大きさ
	static constexpr int SIZE = 16;

	// 各タイプ毎の弾の速度
	static constexpr POINT VELOCITY[static_cast<int>(Type::TypeMax)] =
	{
		{ 0, 0 }, { 0, -10 }, { 0, 10 }
	};

	// データメンバの宣言 -----------------------------------------------
private:

	// アクティブならtrueを設定
	bool m_isActive;

	// 位置
	POINT m_position;

	// 速度
	POINT m_velocity;

	// タイプ
	Type m_type;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Bullet();

	// デストラクタ
	~Bullet();

	// 初期化関数
	void Initialize(POINT position);

	// 更新関数
	void Update();

	// 描画関数
	void Render(int ghShootingGame);

	// 敵がアクティブか調べる関数
	bool IsActive() const { return m_isActive; }

	// 弾を発射する関数
	void Shoot(POINT position);

	// 弾のタイプを設定する
	void SetType(Type type) { m_type = type; }

};
