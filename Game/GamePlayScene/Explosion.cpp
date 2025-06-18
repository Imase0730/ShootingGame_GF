#include "Explosion.h"

// コンストラクタ
Explosion::Explosion()
	: m_position{ 0, 0 }
	, m_animationState{ AnimationState::AnimNone }
	, m_animationCounter{ 0 }
{
}

// デストラクタ
Explosion::~Explosion()
{
}

// 初期化関数
void Explosion::Initialize()
{
	m_position = POINT{ 0, 0 };
	m_animationState=AnimationState::AnimNone;
	m_animationCounter = 0;
}

// 更新処理
void Explosion::Update()
{
	// アニメーションステートが設定がない場合は更新しない
	if (m_animationState == AnimationState::AnimNone) return;

	// アニメーションカウンターを加算
	m_animationCounter++;

	if (m_animationCounter > ANIMATION_INTERVAL)
	{
		// アニメーションカウンターをリセットする
		m_animationCounter = 0;

		// 爆発の最後の絵ならアニメーションを終了する
		if (m_animationState == AnimationState::Anim04)
		{
			// 未使用にする
			m_animationState = AnimationState::AnimNone;
		}
		else
		{
			// 次の絵に変更する
			m_animationState = static_cast<AnimationState>(static_cast<int>(m_animationState) + 1);
		}
	}
}

// 描画処理
void Explosion::Render(int ghShootingGame)
{
	// アニメーションステートが設定がない場合は描画しない
	if (m_animationState == AnimationState::AnimNone) return;

	// スプライトシート上の絵の位置を取得
	int x = EXPLOSION_SPRITES[static_cast<int>(m_animationState)].x;
	int y = EXPLOSION_SPRITES[static_cast<int>(m_animationState)].y;

	// 爆発の描画
	DrawRectExtendGraph( m_position.x, m_position.y
		, m_position.x + Explosion::SIZE, m_position.y + Explosion::SIZE
		, x, y, 16, 16
		, ghShootingGame, TRUE);
}

// 指定した位置に爆発を表示する関数
void Explosion::StartExplosion(POINT position)
{
	// 爆発の表示位置を設定する
	m_position = 
		POINT{ position.x - Explosion::SIZE / 2, position.y - Explosion::SIZE / 2 };

	// アニメーションカウンターを初期化する
	m_animationCounter = 0;

	// アニメーションステートを爆発の最初の絵にする
	m_animationState = AnimationState::Anim01;
}

// この爆発オブジェクトが使用中かチェックする関数
bool Explosion::IsActive()
{
	if (m_animationState == AnimationState::AnimNone)
	{
		return false;
	}
	return true;
}

