#pragma once

#include "BulletManager.h"

// �G�N���X
class Enemy
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �傫��
	static constexpr int SIZE = 64;

	// �ړ��̑���
	static constexpr int SPEED = 5;

	// �e�̔��ˊԊu
	static constexpr int SHOOT_INTERVAL = 60;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �A�N�e�B�u�Ȃ�true��ݒ�
	bool m_isActive;

	// �ʒu
	POINT m_position;

	// ���x
	POINT m_velocity;

	// �e�̔��˗p�J�E���^�[
	int m_shootCounter;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Enemy();

	// �f�X�g���N�^
	~Enemy();

	// �������֐�
	void Initialize(POINT position);

	// �X�V�֐�
	void Update(BulletManager& bulletManager);

	// �`��֐�
	void Render(int ghShootingGame);

	// �G���A�N�e�B�u�����ׂ�֐�
	bool IsActive() const { return m_isActive; }

	// ���̓G���o��������֐�
	void Spawn(POINT position);

	// ���E�{�b�N�X���擾����֐�
	RECT GetBoundingBox() const;

	// �Փ˂�����Ăяo�����֐�
	void OnHit() { m_isActive = false; }

	// �G�̒��S�̈ʒu���擾����֐�
	POINT GetCenterPosition();

};
