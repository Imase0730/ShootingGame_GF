#pragma once

#include "Enemy.h"

// �G�̃}�l�[�W���[�N���X
class EnemyManager
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �G�̏o���Ԋu
	static constexpr int SPAWN_INTERVAL = 10;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �Ǘ��ł���G�̐�
	int m_enemyCount;

	// �G�̃I�u�W�F�N�g�ւ̃|�C���^
	Enemy* m_pEnemy;

	// �G�̏o���p�J�E���^�[
	int m_spawnCounter;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	EnemyManager();

	// �f�X�g���N�^
	~EnemyManager();

	// ����������
	void Initialize(int enemyCount);

	// �X�V����
	void Update();

	// �`�揈��
	void Render(int ghShootingGame);

	// �I������
	void Finalize();

private:

	// �G���o��������֐�
	void AppearEnemy(POINT point);

};
