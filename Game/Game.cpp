/**
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
	, m_currentSceneID{ SceneID::NONE }
	, m_requestedSceneID{ SceneID::NONE }
	, m_titleScene{ this }
	, m_gamePlayScene{ this }
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

	// 開始シーンの設定
	SetStartScene(SceneID::TITLE);
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

	// キートリガー
	int keyTrigger = ~m_oldKey & m_key;

	// シーンの変更要求がある？
	if (m_requestedSceneID != SceneID::NONE)
	{
		// シーンを変更する
		ChangeScene();
	}

	// ゲームの更新

	// 実行中のシーンの更新処理
	UpdateCurrentScene(m_key, keyTrigger);
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

	// 実行中のシーンの描画処理
	RenderCurrentScene();
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

	// 実行中のシーンの終了処理
	FinalizeCurrentScene();
}

// シーンを変更する関数
void Game::RequestSceneChange(SceneID nextSceneID)
{
	m_requestedSceneID = nextSceneID;
}


// 開始シーンの設定
void Game::SetStartScene(SceneID startSceneID)
{
	// 実行中のシーンを設定
	m_currentSceneID = startSceneID;

	// シーンの初期化処理
	InitializeCurrentScene();
}

// シーンの変更関数
void Game::ChangeScene()
{
	// 現在実行中のシーンを終了する
	FinalizeCurrentScene();

	// 新しいシーンに変更する
	m_currentSceneID = m_requestedSceneID;

	// シーンを初期化する
	InitializeCurrentScene();

	// シーン変更要求をリセットする
	m_requestedSceneID = SceneID::NONE;
}

// 現在のシーンの初期化処理
void Game::InitializeCurrentScene()
{
	switch (m_currentSceneID)
	{
	case Game::SceneID::TITLE:
		m_titleScene.Initialize();
		break;
	case Game::SceneID::GAMEPLAY:
		m_gamePlayScene.Initialize();
		break;
	default:
		break;
	}
}

// 現在のシーンの更新処理
void Game::UpdateCurrentScene(int keyCondition, int keyTrigger)
{
	switch (m_currentSceneID)
	{
	case Game::SceneID::TITLE:
		m_titleScene.Update(keyCondition, keyTrigger);
		break;
	case Game::SceneID::GAMEPLAY:
		m_gamePlayScene.Update(keyCondition, keyTrigger);
		break;
	default:
		break;
	}
}

// 現在のシーンの描画処理
void Game::RenderCurrentScene()
{
	switch (m_currentSceneID)
	{
	case Game::SceneID::TITLE:
		m_titleScene.Render();
		break;
	case Game::SceneID::GAMEPLAY:
		m_gamePlayScene.Render();
		break;
	default:
		break;
	}
}

// 現在のシーンの終了処理
void Game::FinalizeCurrentScene()
{
	switch (m_currentSceneID)
	{
	case Game::SceneID::TITLE:
		m_titleScene.Finalize();
		break;
	case Game::SceneID::GAMEPLAY:
		m_gamePlayScene.Finalize();
		break;
	default:
		break;
	}
}

