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
	// �A�j���[�V�����X�e�[�g���ݒ肪�Ȃ��ꍇ�͕`�悵�Ȃ�
	if (m_animationState == AnimationState::AnimNone) return;

	// �X�v���C�g�V�[�g��̊G�̈ʒu���擾
	int x = EXPLOSION_SPRITES[static_cast<int>(m_animationState)].x;
	int y = EXPLOSION_SPRITES[static_cast<int>(m_animationState)].y;

	// �����̕`��
	DrawRectExtendGraph( m_position.x, m_position.y
		, m_position.x + Explosion::SIZE, m_position.y + Explosion::SIZE
		, x, y, 16, 16
		, ghShootingGame, TRUE);
}

