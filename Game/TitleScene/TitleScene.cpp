//--------------------------------------------------------------------------------------
// File: TitleScene.cpp
//
//--------------------------------------------------------------------------------------
#include "TitleScene.h"
#include "Game/Game.h"

// �R���X�g���N�^
TitleScene::TitleScene(Game* pGame)
	: m_pGame{ pGame }
{

}

// �f�X�g���N�^
TitleScene::~TitleScene()
{

}

// ����������
void TitleScene::Initialize()
{

}

// �X�V����
void TitleScene::Update(int keyCondition, int keyTrigger)
{

}

// �`�揈��
void TitleScene::Render()
{
	DrawFormatString(10, 30, GetColor(255, 255, 255), L"Title�V�[��");
}

// �I������
void TitleScene::Finalize()
{

}

