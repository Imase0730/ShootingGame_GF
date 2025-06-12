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
	, m_ghShootingGame{ -1 }
	, m_player{}
	, m_enemyManager{}
	, m_playerBulletManager{}
	, m_enemyBulletManager{}
	, m_explosion{}
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

	// 敵のマネージャーの初期化
	m_enemyManager.Initialize(10);

	// 弾のマネージャーの初期化（プレイヤー用）
	m_playerBulletManager.Initialize(Bullet::Type::Player, 3);

	// 弾のマネージャーの初期化（敵用）
	m_enemyBulletManager.Initialize(Bullet::Type::Enemy, 100);

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

	// プレイヤーがアクティブだったら
	if (m_player.IsActive())
	{
		// プレイヤーの更新
		m_player.Update(m_key, ~m_oldKey & m_key, m_playerBulletManager);
	}

	// 敵のマネージャーの更新
	m_enemyManager.Update(m_enemyBulletManager);

	// 弾のマネージャーの更新（プレイヤー用）
	m_playerBulletManager.Update();

	// 弾のマネージャーの更新（敵用）
	m_enemyBulletManager.Update();

	// プレイヤーと敵の弾との衝突判定
	CheckPlayerColliedWithEnemyBullet();

	// 敵とプレイヤーの弾との衝突判定
	CheckEnemyColliedWithPlayerBullet();

	// 爆発のエフェクトの更新
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		m_explosion[i].Update();
	}

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

	// プレイヤーがアクティブだったら
	if (m_player.IsActive())
	{
		// プレイヤーの描画
		m_player.Render(m_ghShootingGame);
	}

	// 敵のマネージャーの描画
	m_enemyManager.Render(m_ghShootingGame);

	// 弾のマネージャーの描画（プレイヤー用）
	m_playerBulletManager.Render(m_ghShootingGame);

	// 弾のマネージャーの描画（敵用）
	m_enemyBulletManager.Render(m_ghShootingGame);

	// 爆発エフェクトの描画
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		m_explosion[i].Render(m_ghShootingGame);
	}

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

// 矩形の衝突判定
bool Game::IsColliding(RECT a, RECT b)
{
	if ( (a.right >= b.left)
	  && (a.left <= b.right)
	  && (a.bottom >= b.top)
	  && (a.top <= b.bottom)
	   )
	{
		return true;
	}
	return false;
}

// プレイヤーと敵の弾との衝突判定
void Game::CheckPlayerColliedWithEnemyBullet()
{
	// プレイヤーが死亡していたら処理を行わない
	if (m_player.IsActive() == false) return;

	// 管理している敵の弾の数分ループ
	for (int i = 0; i < m_enemyBulletManager.GetBulletCount(); i++)
	{
		// 使用していない弾なら処理を行わない
		Bullet* pBullet = m_enemyBulletManager.GetBullet(i);
		if (pBullet == nullptr) continue;

		// プレイヤーと敵の弾と衝突判定を行う
		if (IsColliding(m_player.GetBoundingBox(), pBullet->GetBoundingBox()))
		{
			// 衝突した
			m_player.OnHit();
			pBullet->OnHit();
			// プレイヤーの位置に爆発エフェクトを発生させる
			SetExplosion(m_player.GetCenterPosition());
		}
	}
}

// 敵とプレイヤーの弾との衝突判定
void Game::CheckEnemyColliedWithPlayerBullet()
{
	// プレイヤーの弾の管理数分ループ
	for (int j = 0; j < m_playerBulletManager.GetBulletCount(); j++)
	{
		// 弾が使用中でないなら処理を行わない
		Bullet* pBullet = m_playerBulletManager.GetBullet(j);
		if (!pBullet) continue;

		// 敵の管理数分ループ
		for (int i = 0; i < m_enemyManager.GetEnemyCount(); i++)
		{
			// 敵が使用中でないなら処理を行わない
			Enemy* pEnemy = m_enemyManager.GetEnemy(i);
			if (!pEnemy) continue;

			// プレイヤーの弾と敵の衝突判定を行う
			if (IsColliding(pBullet->GetBoundingBox(), pEnemy->GetBoundingBox()))
			{
				// 衝突した
				pBullet->OnHit();
				pEnemy->OnHit();
				// 敵の位置に爆発エフェクトを発生させる
				SetExplosion(pEnemy->GetCenterPosition());
			}
		}
	}
}

// 爆発エフェクトを表示する関数
void Game::SetExplosion(POINT position)
{
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		// 使用可能な爆発エフェクトなら
		if (!m_explosion[i].IsActive())
		{
			// 爆発エフェクトを発生する
			m_explosion[i].Initialize(position);
			return;
		}
	}
}


