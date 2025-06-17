//--------------------------------------------------------------------------------------
// File: GamePlayScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Player.h"
#include "EnemyManager.h"
#include "BulletManager.h"
#include "Explosion.h"
#include "NumberRenderer.h"

// �N���X�̑O���錾
class Game;

// �^�C�g���V�[��
class GamePlayScene
{

	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �v���C���[�����ʒu
	static constexpr int PLAYER_START_POSITION_X = (Screen::WIDTH - Player::SIZE) / 2;
	static constexpr int PLAYER_START_POSITION_Y = 600;

	// �����G�t�F�N�g�̍ő吔
	static constexpr int EXPLOSION_MAX = 10;

	// �G�̓��_
	static constexpr int ENEMY_SCORE = 10;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// ���̃V�[�����܂ރQ�[���I�u�W�F�N�g�ւ̃|�C���^
	Game* m_pGame;

	// �G�̃O���t�B�b�N�n���h��
	int m_ghShootingGame;

	// �v���C���[
	Player m_player;

	// �G�̃}�l�[�W���[
	EnemyManager m_enemyManager;

	// �e�̃}�l�[�W���[�i�v���C���[�p�j
	BulletManager m_playerBulletManager;

	// �e�̃}�l�[�W���[�i�G�p�j
	BulletManager m_enemyBulletManager;

	// �����G�t�F�N�g�I�u�W�F�N�g
	Explosion m_explosion[EXPLOSION_MAX];

	// ������`�悷��I�u�W�F�N�g
	NumberRenderer m_numberRenderer;

	// ���_
	int m_score;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	GamePlayScene(Game* pGame);

	// �f�X�g���N�^
	~GamePlayScene();

	// ����������
	void Initialize();

	// �X�V����
	void Update(int keyCondition, int keyTrigger);

	// �`�揈��
	void Render();

	// �I������
	void Finalize();

private:

	// ��`�̏Փ˔���
	bool IsColliding(RECT a, RECT b);

	// �v���C���[�ƓG�̒e�Ƃ̏Փ˔���
	void CheckPlayerColliedWithEnemyBullet();

	// �G�ƃv���C���[�̒e�Ƃ̏Փ˔���
	void CheckEnemyColliedWithPlayerBullet();

	// �����G�t�F�N�g��\������֐�
	void SetExplosion(POINT position);
};
