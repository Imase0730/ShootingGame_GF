//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"

// コンストラクタ
GamePlayScene::GamePlayScene(Game* pGame)
	: m_pGame{ pGame }
	, m_ghShootingGame{ -1 }
	, m_player{}
	, m_enemyManager{}
	, m_playerBulletManager{}
	, m_enemyBulletManager{}
	, m_explosion{}
	, m_numberRenderer{ POINT{ Screen::WIDTH / 2 - (NumberRenderer::NUMBER_WIDTH * 2 * 6) / 2, 0}, 6, false }
	, m_score{ 0 }
{

}

// デストラクタ
GamePlayScene::~GamePlayScene()
{

}

// 初期化処理
void GamePlayScene::Initialize()
{
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

	// 数字のサイズの設定
	m_numberRenderer.SetSize(NumberRenderer::NUMBER_WIDTH * 2, NumberRenderer::NUMBER_HEIGHT * 2);

	// 爆発エフェクトの初期化
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		m_explosion[i].Initialize();
	}
}

// 更新処理
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{
	// プレイヤーがアクティブだったら
	if (m_player.IsActive())
	{
		// プレイヤーの更新
		m_player.Update(keyCondition, keyTrigger, m_playerBulletManager);
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

	// 得点を設定
	m_numberRenderer.SetNumber(m_score);
}

// 描画処理
void GamePlayScene::Render()
{
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

	// 数字の描画
	m_numberRenderer.Render(m_ghShootingGame);

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlayシーン");
}

// 終了処理
void GamePlayScene::Finalize()
{

}

// 矩形の衝突判定
bool GamePlayScene::IsColliding(RECT a, RECT b)
{
	if ((a.right >= b.left)
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
void GamePlayScene::CheckPlayerColliedWithEnemyBullet()
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
			// タイトルシーンへ
			m_pGame->RequestSceneChange(Game::SceneID::TITLE);
		}
	}
}

// 敵とプレイヤーの弾との衝突判定
void GamePlayScene::CheckEnemyColliedWithPlayerBullet()
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
				// 得点加算
				m_score += ENEMY_SCORE;
			}
		}
	}
}

// 爆発エフェクトを表示する関数
void GamePlayScene::SetExplosion(POINT position)
{
	for (int i = 0; i < EXPLOSION_MAX; i++)
	{
		// 使用可能な爆発エフェクトなら
		if (!m_explosion[i].IsActive())
		{
			// 爆発エフェクトを発生する
			m_explosion[i].StartExplosion(position);
			return;
		}
	}
}


