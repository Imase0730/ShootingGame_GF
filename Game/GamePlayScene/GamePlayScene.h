//--------------------------------------------------------------------------------------
// File: GamePlayScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Player.h"
#include "EnemyManager.h"
#include "BulletManager.h"
#include "Explosion.h"
#include "NumberRenderer.h"

// クラスの前方宣言
class Game;

// タイトルシーン
class GamePlayScene
{

	// クラス定数の宣言 -------------------------------------------------
public:

	// プレイヤー初期位置
	static constexpr int PLAYER_START_POSITION_X = (Screen::WIDTH - Player::SIZE) / 2;
	static constexpr int PLAYER_START_POSITION_Y = 600;

	// 爆発エフェクトの最大数
	static constexpr int EXPLOSION_MAX = 10;

	// 敵の得点
	static constexpr int ENEMY_SCORE = 10;

	// データメンバの宣言 -----------------------------------------------
private:

	// このシーンを含むゲームオブジェクトへのポインタ
	Game* m_pGame;

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

	// 得点
	int m_score;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	GamePlayScene(Game* pGame);

	// デストラクタ
	~GamePlayScene();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update(int keyCondition, int keyTrigger);

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
