#pragma once

#include "Bullet.h"

// �e�̃}�l�[�W���[�N���X
class BulletManager
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �e�̏o���Ԋu
	static constexpr int SPAWN_INTERVAL = 10;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �Ǘ��ł���e�̐�
	int m_bulletCount;

	// �e�̃I�u�W�F�N�g�ւ̃|�C���^
	Bullet* m_pBullet;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	BulletManager();

	// �f�X�g���N�^
	~BulletManager();

	// ����������
	void Initialize(Bullet::Type type, int BulletCount);

	// �X�V����
	void Update();

	// �`�揈��
	void Render(int ghShootingGame);

	// �I������
	void Finalize();

	// �e�𔭎˂���֐�
	void ShootBullet(POINT point);

};
