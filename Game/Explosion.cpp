#include "Explosion.h"

Explosion::Explosion()
	: m_position{ 0, 0 }
	, m_animationState{ AnimationState::AnimNone }
{
}

Explosion::~Explosion()
{
}

void Explosion::Update()
{
}

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

