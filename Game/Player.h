#pragma once

// �v���C���[�N���X
class Player
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �傫��
	static constexpr int SIZE = 64;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �ʒu
	POINT m_position;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Player();

	// �f�X�g���N�^
	~Player();

	// �X�V�֐�
	void Update(int keyCondition, int keyTrigger);

	// �`��֐�
	void Render(int ghShootingGame);

};
