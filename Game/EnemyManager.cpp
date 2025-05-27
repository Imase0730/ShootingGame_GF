#include "EnemyManager.h"
#include "Game/Screen.h"

// �R���X�g���N�^
EnemyManager::EnemyManager()
	: m_enemyCount{ 0 }
	, m_pEnemy{ nullptr }
{
}

// �f�X�g���N�^
EnemyManager::~EnemyManager()
{
	// �m�ۂ������������������
	if (m_pEnemy) delete[] m_pEnemy;
}

// ����������
void EnemyManager::Initialize(int enemyCount)
{
	// �Ǘ�����G�̐�
	m_enemyCount = enemyCount;

	// ������x���������m�ۂ���Ă�����������
	if (m_pEnemy) delete[] m_pEnemy;

	// �G�̐������������m�ۂ���
	m_pEnemy = new Enemy[enemyCount];
}

// �X�V����
void EnemyManager::Update()
{
}

// �`�揈��
void EnemyManager::Render(int ghShootingGame)
{
}

// �I������
void EnemyManager::Finalize()
{
}
