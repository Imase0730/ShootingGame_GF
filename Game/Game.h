/**
 * @file   Game.h
 *
 * @brief  ゲーム全体に関するヘッダファイル
 *
 * @author 制作者名
 *
 * @date   日付
 */

// 多重インクルードの防止 =====================================================
#pragma once




// ヘッダファイルの読み込み ===================================================

#include "Game/Screen.h"
#include "Player.h"
#include "EnemyManager.h"
#include "BulletManager.h"
#include "Explosion.h"
#include "NuberRenderer.h"

// クラスの宣言 ===============================================================




// クラスの定義 ===============================================================
/**
 * @brief ゲーム
 */
class Game
{
// クラス定数の宣言 -------------------------------------------------
public:
	// システム関連
	static constexpr const wchar_t* TITLE = L"Shooting Game";   ///< ゲームタイトル

	// プレイヤー初期位置
	static constexpr int PLAYER_START_POSITION_X = (Screen::WIDTH - Player::SIZE) / 2;
	static constexpr int PLAYER_START_POSITION_Y = 600;

	// 爆発エフェクトの最大数
	static constexpr int EXPLOSION_MAX = 10;


// データメンバの宣言 -----------------------------------------------
private:
	// 入力関連
	int m_key;       ///< 現在のキー情報
	int m_oldKey;    ///< 前回のキー情報

	// 絵のグラフィックハンドル
	int m_ghShootingGame;

	// プレイヤー
	Player m_player;

	// 敵のマネージャー
	EnemyManager m_enemyManager;

	// 弾のマネージャー（プレイヤー用）
	BulletManager m_playerBulletManager;

	// 弾のマネージャー（敵用）
	BulletManager m_enemyBulletManager;

	// 爆発エフェクトオブジェクト
	Explosion m_explosion[EXPLOSION_MAX];

	// 数字を描画するオブジェクト
	NumberRenderer m_numberRenderer;

// メンバ関数の宣言 -------------------------------------------------
// コンストラクタ/デストラクタ
public:
	// コンストラクタ
	Game();

	// デストラクタ
	~Game();


// 操作
public:
	// 初期化処理
	void Initialize();

	// 更新処理
	void Update(float elapsedTime);

	// 描画処理
	void Render();

	// 終了処理
	void Finalize();

private:

	// 矩形の衝突判定
	bool IsColliding(RECT a, RECT b);

	// プレイヤーと敵の弾との衝突判定
	void CheckPlayerColliedWithEnemyBullet();

	// 敵とプレイヤーの弾との衝突判定
	void CheckEnemyColliedWithPlayerBullet();

	// 爆発エフェクトを表示する関数
	void SetExplosion(POINT position);

};
