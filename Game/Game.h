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
#include "Enemy.h"

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


// データメンバの宣言 -----------------------------------------------
private:
	// 入力関連
	int m_key;       ///< 現在のキー情報
	int m_oldKey;    ///< 前回のキー情報

	// 絵のグラフィックハンドル
	int m_ghShootingGame;

	// プレイヤー
	Player m_player;

	// 敵
	Enemy m_enemy;

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


// 取得/設定
public:


// 内部実装
private:


};
