#include <iostream>
#include <string>
using namespace std;

// �����\���N���X�̒�`
class Weapon {
protected:
	string name;		// ���O��ێ����郁���o�ϐ�
	unsigned int maxTimes;	//�g�p�ł����
	unsigned int lastTimes; //�c��̎g�p��
	unsigned int expendTimes;	//��x�̎g�p�ŏ����g�p��
	int expend() {
		lastTimes -= expendTimes;
		return lastTimes;
	}
public:
	virtual void shoot() = 0;	// ������g�p���郁���o�֐�
	string getName() {
		return name;
	}
	Weapon(string name, unsigned int maxTimes, unsigned int expendTimes)	// �R���X�g���N�^
	{
		this->name = name;
		this->maxTimes = maxTimes;
		this->expendTimes = expendTimes;
		lastTimes = maxTimes;
	}
};

// ����\���N���X�̒�`
class Sword : public  Weapon {
public:
	void shoot() {	// ������g�p���郁���o�֐�
		cout << this->name << ":�U�艺�낷,�V���L�[�[��" << endl;
		cout << "�c��g�p�\�񐔂�" << expend() << endl;
	}
	Sword(string name, unsigned int maxTimes, unsigned int expendTimes = 1) :Weapon(name, maxTimes, expendTimes) {	// �R���X�g���N�^

	}
};
// �}�V���K����\���N���X�̒�`
class MachineGun : public  Weapon {
public:
	void shoot() {	// ������g�p���郁���o�֐�
		cout << this->name << ":" << this->expendTimes << "���A�ˁA�A���Ō��ƔM�Ŏg���Ȃ�" << endl;
		for (int i = 0; i < expendTimes; i++) {

			if (lastTimes > 0) {
				lastTimes--;
				cout << "�_�b�@";
			}
			else {
				cout << "�e�؂�";
				break;
			}

		}
		cout << "�c��g�p�\�񐔂�" << lastTimes << endl;
	}
	MachineGun(string name, unsigned int maxTimes, unsigned int expendTimes) :Weapon(name, maxTimes, expendTimes) {	// �R���X�g���N�^
	}
};
// ��C��\���N���X�̒�`
class Canon : public  Weapon {
public:
	void shoot() {	// ������g�p���郁���o�֐�
		cout << this->name << ":��C���˂�5�b����" << endl;
		cout << "�h�b�J�[�[�[�[�[�[�[�[�[��";
		cout << "�c��g�p�\�񐔂�" << expend() << endl;
	}
	Canon(string name, unsigned int maxTimes, unsigned int expendTimes = 1) :Weapon(name, maxTimes, expendTimes) {	// �R���X�g���N�^
	}
};



// sub�֐����g��main�֐�
int main() {
	Sword knife("�i�C�t", 10);
	Sword stick("�؂̖_", 5);
	MachineGun subMachineGun("�T�u�}�V���K��", 500, 60);
	Canon littleDavid("���g���E�f�[�r�b�h", 5);

	Weapon* weapon[4];
	weapon[0] = &knife;
	weapon[1] = &stick;
	weapon[2] = &subMachineGun;
	weapon[3] = &littleDavid;

	unsigned int select = 0;
	for (int loop = 0; loop < 10; loop++) {
		cout << endl;
		for (int i = 0; i < _countof(weapon); i++) {
			cout << "�����Ă镐��" << i << ":" << weapon[i]->getName() << endl;
		}
		cout << "����" << weapon[select]->getName() << "�𑕔���";
		int selectInput;
		cout << "�ǂ�𑕔����܂���";
		cin >> selectInput;
		if (selectInput < _countof(weapon)) {
			select = selectInput;
			cout << weapon[select]->getName() << "�𑕔����܂���" << endl;
		}
		cout << "�g���܂���(=0�g��Ȃ�  ��0�g��)";
		int useWeapon;
		cin >> useWeapon;
		if (useWeapon != 0) {
			weapon[select]->shoot();
		}
	}
	return 0;
}
