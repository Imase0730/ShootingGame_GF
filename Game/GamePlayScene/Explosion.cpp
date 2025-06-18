#include "Explosion.h"

// �R���X�g���N�^
Explosion::Explosion()
	: m_position{ 0, 0 }
	, m_animationState{ AnimationState::AnimNone }
	, m_animationCounter{ 0 }
{
}

// �f�X�g���N�^
Explosion::~Explosion()
{
}

// �������֐�
void Explosion::Initialize()
{
	m_position = POINT{ 0, 0 };
	m_animationState=AnimationState::AnimNone;
	m_animationCounter = 0;
}

// �X�V����
void Explosion::Update()
{
	// �A�j���[�V�����X�e�[�g���ݒ肪�Ȃ��ꍇ�͍X�V���Ȃ�
	if (m_animationState == AnimationState::AnimNone) return;

	// �A�j���[�V�����J�E���^�[�����Z
	m_animationCounter++;

	if (m_animationCounter > ANIMATION_INTERVAL)
	{
		// �A�j���[�V�����J�E���^�[�����Z�b�g����
		m_animationCounter = 0;

		// �����̍Ō�̊G�Ȃ�A�j���[�V�������I������
		if (m_animationState == AnimationState::Anim04)
		{
			// ���g�p�ɂ���
			m_animationState = AnimationState::AnimNone;
		}
		else
		{
			// ���̊G�ɕύX����
			m_animationState = static_cast<AnimationState>(static_cast<int>(m_animationState) + 1);
		}
	}
}

// �`�揈��
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

// �w�肵���ʒu�ɔ�����\������֐�
void Explosion::StartExplosion(POINT position)
{
	// �����̕\���ʒu��ݒ肷��
	m_position = 
		POINT{ position.x - Explosion::SIZE / 2, position.y - Explosion::SIZE / 2 };

	// �A�j���[�V�����J�E���^�[������������
	m_animationCounter = 0;

	// �A�j���[�V�����X�e�[�g�𔚔��̍ŏ��̊G�ɂ���
	m_animationState = AnimationState::Anim01;
}

// ���̔����I�u�W�F�N�g���g�p�����`�F�b�N����֐�
bool Explosion::IsActive()
{
	if (m_animationState == AnimationState::AnimNone)
	{
		return false;
	}
	return true;
}

