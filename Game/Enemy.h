#pragma once

// �G�N���X
class Enemy
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �傫��
	static constexpr int SIZE = 64;

	// �ړ��̑���
	static constexpr int SPEED = 5;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �ʒu
	POINT m_position;

	// ���x
	POINT m_velocity;


	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Enemy();

	// �f�X�g���N�^
	~Enemy();

	// �������֐�
	void Initialize(POINT position);

	// �X�V�֐�
	void Update();

	// �`��֐�
	void Render(int ghShootingGame);

};
