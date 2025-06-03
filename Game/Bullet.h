#pragma once

// �e�N���X
class Bullet
{
	// �񋓌^�̒�` -----------------------------------------------------
public:

	// �e�̃^�C�v
	enum class Type { None, Player, Enemy, TypeMax };

	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �傫��
	static constexpr int SIZE = 16;

	// �e�^�C�v���̒e�̑��x
	static constexpr POINT VELOCITY[static_cast<int>(Type::TypeMax)] =
	{
		{ 0, 0 }, { 0, -10 }, { 0, 10 }
	};

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �A�N�e�B�u�Ȃ�true��ݒ�
	bool m_isActive;

	// �ʒu
	POINT m_position;

	// ���x
	POINT m_velocity;

	// �^�C�v
	Type m_type;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Bullet();

	// �f�X�g���N�^
	~Bullet();

	// �������֐�
	void Initialize(POINT position);

	// �X�V�֐�
	void Update();

	// �`��֐�
	void Render(int ghShootingGame);

	// �G���A�N�e�B�u�����ׂ�֐�
	bool IsActive() const { return m_isActive; }

	// �e�𔭎˂���֐�
	void Shoot(POINT position);

	// �e�̃^�C�v��ݒ肷��
	void SetType(Type type) { m_type = type; }

};
