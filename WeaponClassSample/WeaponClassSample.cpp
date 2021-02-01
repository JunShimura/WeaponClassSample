#include <iostream>
#include <string>
using namespace std;

// 武器を表すクラスの定義
class Weapon {
protected:
	string name;		// 名前を保持するメンバ変数
	unsigned int maxTimes;	//使用できる回数
	unsigned int lastTimes; //残りの使用回数
	unsigned int expendTimes;	//一度の使用で消費する使用回数
	int expend() {
		lastTimes -= expendTimes;
		return lastTimes;
	}
public:
	virtual void shoot() = 0;	// 武器を使用するメンバ関数
	string getName() {
		return name;
	}
	Weapon(string name, unsigned int maxTimes, unsigned int expendTimes)	// コンストラクタ
	{
		this->name = name;
		this->maxTimes = maxTimes;
		this->expendTimes = expendTimes;
		lastTimes = maxTimes;
	}
};

// 刀を表すクラスの定義
class Sword : public  Weapon {
public:
	void shoot() {	// 武器を使用するメンバ関数
		cout << this->name << ":振り下ろす,シャキーーン" << endl;
		cout << "残り使用可能回数は" << expend() << endl;
	}
	Sword(string name, unsigned int maxTimes, unsigned int expendTimes = 1) :Weapon(name, maxTimes, expendTimes) {	// コンストラクタ

	}
};
// マシンガンを表すクラスの定義
class MachineGun : public  Weapon {
public:
	void shoot() {	// 武器を使用するメンバ関数
		cout << this->name << ":" << this->expendTimes << "発連射、連続で撃つと熱で使えない" << endl;
		for (int i = 0; i < expendTimes; i++) {

			if (lastTimes > 0) {
				lastTimes--;
				cout << "ダッ　";
			}
			else {
				cout << "弾切れ";
				break;
			}

		}
		cout << "残り使用可能回数は" << lastTimes << endl;
	}
	MachineGun(string name, unsigned int maxTimes, unsigned int expendTimes) :Weapon(name, maxTimes, expendTimes) {	// コンストラクタ
	}
};
// 大砲を表すクラスの定義
class Canon : public  Weapon {
public:
	void shoot() {	// 武器を使用するメンバ関数
		cout << this->name << ":大砲発射し5秒沈黙" << endl;
		cout << "ドッカーーーーーーーーーん";
		cout << "残り使用可能回数は" << expend() << endl;
	}
	Canon(string name, unsigned int maxTimes, unsigned int expendTimes = 1) :Weapon(name, maxTimes, expendTimes) {	// コンストラクタ
	}
};



// sub関数を使うmain関数
int main() {
	Sword knife("ナイフ", 10);
	Sword stick("木の棒", 5);
	MachineGun subMachineGun("サブマシンガン", 500, 60);
	Canon littleDavid("リトル・デービッド", 5);

	Weapon* weapon[4];
	weapon[0] = &knife;
	weapon[1] = &stick;
	weapon[2] = &subMachineGun;
	weapon[3] = &littleDavid;

	unsigned int select = 0;
	for (int loop = 0; loop < 10; loop++) {
		cout << endl;
		for (int i = 0; i < _countof(weapon); i++) {
			cout << "持ってる武器" << i << ":" << weapon[i]->getName() << endl;
		}
		cout << "現在" << weapon[select]->getName() << "を装備中";
		int selectInput;
		cout << "どれを装備しますか";
		cin >> selectInput;
		if (selectInput < _countof(weapon)) {
			select = selectInput;
			cout << weapon[select]->getName() << "を装備しました" << endl;
		}
		cout << "使いますか(=0使わない  ≠0使う)";
		int useWeapon;
		cin >> useWeapon;
		if (useWeapon != 0) {
			weapon[select]->shoot();
		}
	}
	return 0;
}
