#pragma once

#include "BulletManager.h"

// �v���C���[�N���X
class Player
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �A�N�e�B�u�Ȃ�true��ݒ�
	bool m_isActive;

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
	Player();

	// �f�X�g���N�^
	~Player();

	// �������֐�
	void Initialize(POINT position);

	// �X�V�֐�
	void Update(int keyCondition, int keyTrigger, BulletManager& bulletManager);

	// �`��֐�
	void Render(int ghShootingGame);

	// ���E�{�b�N�X���擾����֐�
	RECT GetBoundingBox() const;

	// �A�N�e�B�u�����ׂ�֐�
	bool IsActive() const { return m_isActive; }

	// �Փ˂�����Ăяo�����֐�
	void OnHit() { m_isActive = false; }

	// �v���C���[�̒��S�̈ʒu���擾����֐�
	POINT GetCenterPosition();

};
