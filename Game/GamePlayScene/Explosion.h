#pragma once

// �����N���X
class Explosion
{
private:

	// �����̃A�j���[�V�����X�e�[�g
	enum class AnimationState
	{
		AnimNone = -1,
		Anim01, Anim02, Anim03, Anim04,
	};

private:

	// �����A�j���[�V�����̊Ԋu
	static constexpr int ANIMATION_INTERVAL = 4;

	// �����̕\���̑傫��
	static constexpr int SIZE = 64;

	// �����̃X�v���C�g�V�[�g��̊G�̈ʒu
	static constexpr POINT EXPLOSION_SPRITES[] =
	{
		{ 96 + 16 * 0, 32 },		// �p�^�[���P
		{ 96 + 16 * 1, 32 },		// �p�^�[���Q
		{ 96 + 16 * 2, 32 },		// �p�^�[���R
		{ 96 + 16 * 3, 32 },		// �p�^�[���S
	};

private:

	// �\���ʒu
	POINT m_position;

	// �A�j���[�V�����X�e�[�g
	AnimationState m_animationState;

	// �����̃A�j���[�V�����J�E���^�[
	int m_animationCounter;

public:

	// �R���X�g���N�^
	Explosion();

	// �f�X�g���N�^
	~Explosion();

	// �������֐�
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Render(int ghShootingGame);

	// �w�肵���ʒu�ɔ�����\������֐�
	void StartExplosion(POINT position);

	// ���̔����I�u�W�F�N�g���g�p�����`�F�b�N����֐�
	bool IsActive();

};


