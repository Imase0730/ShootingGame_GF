﻿/**
 * @file   Game.cpp
 *
 * @brief  ゲーム全体に関するソースファイル
 *
 * @author 制作者名
 *
 * @date   日付
 */

// ヘッダファイルの読み込み ===================================================
#include "Game.h"

#include "Game/Screen.h"




// メンバ関数の定義 ===========================================================
/**
 * @brief デフォルトコンストラクタ
 *
 * @param なし
 */
Game::Game()
	: m_key{ 0 }
	, m_oldKey{ 0 }
	, m_ghShootingGame{ -1 }
	, m_player{}
	, m_enemy{}
{
	// 乱数の初期値を設定
	SRand(static_cast<int>(time(nullptr)));
}



/**
 * @brief デストラクタ
 */
Game::~Game()
{

}



/**
 * @brief 初期化処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Initialize()
{
	// ゲームの初期化

	// 絵の読み込み
	m_ghShootingGame = LoadGraph(L"Resources/Textures/ShootingGame.png");

	// プレイヤーの初期化
	POINT startPosition = POINT{ PLAYER_START_POSITION_X, PLAYER_START_POSITION_Y };
	m_player.Initialize(startPosition);

	// 敵の初期化
	m_enemy.Initialize(POINT{ 100, 100 });

}



/**
 * @brief 更新処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Update(float elapsedTime)
{
	// キー入力の取得
	m_oldKey = m_key;
	m_key    = GetJoypadInputState(DX_INPUT_KEY_PAD1);


	// ゲームの更新

	// プレイヤーの更新
	m_player.Update(m_key, ~m_oldKey & m_key);

	// 敵の更新
	m_enemy.Update();

}



/**
 * @brief 描画処理
 *
 * @param[in] なし
 *
 * @return なし
 */
void Game::Render()
{
	// ゲームの描画

	// プレイヤーの描画
	m_player.Render(m_ghShootingGame);

	// 敵の描画
	m_enemy.Render(m_ghShootingGame);

}



/**
 * @brief 終了処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Finalize()
{
	// ゲームの終了処理

}
