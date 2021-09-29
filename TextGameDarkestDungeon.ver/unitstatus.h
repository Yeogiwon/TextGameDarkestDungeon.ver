#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>;


using namespace std;


namespace unit
{
	class unitstat
	{
	public:


		// ���ط� ����(������������ ���� ����, ������ ǥ��, ũ��Ƽ�õ� ����?, )
		int ATK;
		int DMG;
		float CRIT;
		int DEF;
		int CRITDMG = 2;
		// �⺻ ������ ����?(������X(ũ�� ������ ũ��������)- ��� ) 0�����϶��� ���� ǥ��, ũ��Ƽ�ö� ũ��Ƽ�� ����ǥ��



		// ü�°��� ü���� 0�̵Ǹ� DeathBlowȮ�� ���� ��Ʈ���� �޴� ���� ��ȭ
		int HP;
		int MAXHP;


		// ��Ʈ���� ����(100 ä���� ���º�ȭ 200�� ��� �ٷ� ���)
		int STRESS = 0;
		int MAXSTRESS = 200;

		// ���߷� ���� (���� ȣ��� %100 ���� �� �� ���� �̻��� ��� ������)
		int ACC; // ���߷�
		int DODGE; // ȸ����

		// ���׷� ���� ������ Ȯ���� ������ ǥ��
		int Stun;
		int Blight;
		int Bleed;
		int Debuff;
		int Move;
		int DeathBlow;

		//���ǵ� ����;
		int SPD; // spd ������ �����ϴ� �˰��� �ʿ�


		void DungeonStart(unitstat& unitname) // ���� ���۽� ����Ʈ �ʱ�ȭ(�ΰ��ӿ����� �ٸ��� �ؾ���)
		{
			unitname.HP = unitname.MAXHP;
			unitname.STRESS = 0;

		}

		void Display(unitstat& unitname)
		{
			cout << "��ü�� : " << unitname.MAXHP << endl;
			cout << "���� ü�� : " << unitname.HP << endl;
			cout << "���ݷ� : " << unitname.ATK << endl;
			cout << "���� : " << unitname.DEF << endl;
			cout << "���߷� : " << unitname.ACC << endl;
			cout << "ȸ���� : " << unitname.DODGE << endl;
			cout << "ũ��Ƽ�� Ȯ�� : " << unitname.CRIT << endl;
		}

		void battleResult(unitstat& unitname)
		{
			cout << "=====================================================" << endl;

			cout << "== ���� ü�� : " << unitname.HP << "/" << unitname.MAXHP << " ==" << endl;
			cout << "=====================================================" << endl;
		}


		unitstat(int UNITMAXHP, int UNITATK, int UNITDEF, int UNITACC, int UNITDODGE, float UNITCRIT)
		{
			MAXHP = UNITMAXHP;
			ATK = UNITATK;
			DEF = UNITDEF;
			ACC = UNITACC;
			DODGE = UNITDODGE;
			CRIT = UNITCRIT;

		}


	};
}
using namespace unit;

void resistanceStatusSetter(unitstat& unitname, int unitStun, int unitBlight, int unitBleed, int unitDebuff, int unitMove, int unitDeatahBlow)
{
	unitname.Stun = unitStun;
	unitname.Blight = unitBlight;
	unitname.Bleed = unitBleed;
	unitname.Debuff = unitDebuff;
	unitname.Move = unitMove;
	unitname.DeathBlow = unitDeatahBlow;
}

// �������� ���� ��Ȳ�� ǥ���� �Լ�
void Attack(unitstat& attacker, unitstat& defender)
{
	cout << "����" << endl << endl;

	int Damage = attacker.ATK;
	int totalDamage;
	srand(time(NULL));

	// ũ��Ƽ�� ����
	if (rand() % 100 < attacker.CRIT)
	{
		Damage *= attacker.CRITDMG;
	}

	// ���ݷ°� ���� ����
	if (Damage - defender.DEF > 0)
	{
		totalDamage = Damage - defender.DEF;
	}
	else
	{
		totalDamage = 0;
	}



	// ���߷��� ȸ���� ���� �� ������ ���� ����

	if (rand() % 100 < attacker.ACC - defender.DODGE)
	{
		defender.HP = defender.HP - totalDamage;
	}

	if (defender.HP <= 0)
	{
		defender.HP = 0;
	}


	cout << "���� ������" << endl;

	attacker.battleResult(attacker);
	defender.battleResult(defender);
	cout << "���� ��" << endl;


}