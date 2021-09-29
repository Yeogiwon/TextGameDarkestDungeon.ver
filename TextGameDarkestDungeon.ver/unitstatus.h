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


		// 피해량 관련(데미지사이의 범위 지정, 난수로 표현, 크리티컬도 난수?, )
		int ATK;
		int DMG;
		float CRIT;
		int DEF;
		int CRITDMG = 2;
		// 기본 데미지 공식?(데미지X(크리 터지면 크리데미지)- 방어 ) 0이하일때는 방어로 표시, 크리티컬때 크리티컬 문자표시



		// 체력관련 체력이 0이되면 DeathBlow확률 적용 스트레스 받는 상태 변화
		int HP;
		int MAXHP;


		// 스트레스 관련(100 채울경우 상태변화 200일 경우 바로 사망)
		int STRESS = 0;
		int MAXSTRESS = 200;

		// 명중률 관련 (난수 호출로 %100 했을 때 그 숫자 이상일 경우 빗나감)
		int ACC; // 명중률
		int DODGE; // 회피율

		// 저항력 관련 각각의 확률를 난수로 표현
		int Stun;
		int Blight;
		int Bleed;
		int Debuff;
		int Move;
		int DeathBlow;

		//스피드 관련;
		int SPD; // spd 순으로 정렬하는 알고리즘 필요


		void DungeonStart(unitstat& unitname) // 원정 시작시 디폴트 초기화(인게임에서는 다르게 해야함)
		{
			unitname.HP = unitname.MAXHP;
			unitname.STRESS = 0;

		}

		void Display(unitstat& unitname)
		{
			cout << "총체력 : " << unitname.MAXHP << endl;
			cout << "현재 체력 : " << unitname.HP << endl;
			cout << "공격력 : " << unitname.ATK << endl;
			cout << "방어력 : " << unitname.DEF << endl;
			cout << "명중률 : " << unitname.ACC << endl;
			cout << "회피율 : " << unitname.DODGE << endl;
			cout << "크리티컬 확률 : " << unitname.CRIT << endl;
		}

		void battleResult(unitstat& unitname)
		{
			cout << "=====================================================" << endl;

			cout << "== 현재 체력 : " << unitname.HP << "/" << unitname.MAXHP << " ==" << endl;
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

// 공격했을 때의 상황을 표현한 함수
void Attack(unitstat& attacker, unitstat& defender)
{
	cout << "공격" << endl << endl;

	int Damage = attacker.ATK;
	int totalDamage;
	srand(time(NULL));

	// 크리티컬 판정
	if (rand() % 100 < attacker.CRIT)
	{
		Damage *= attacker.CRITDMG;
	}

	// 공격력과 방어력 연산
	if (Damage - defender.DEF > 0)
	{
		totalDamage = Damage - defender.DEF;
	}
	else
	{
		totalDamage = 0;
	}



	// 명중률과 회피율 연산 및 데미지 적용 연산

	if (rand() % 100 < attacker.ACC - defender.DODGE)
	{
		defender.HP = defender.HP - totalDamage;
	}

	if (defender.HP <= 0)
	{
		defender.HP = 0;
	}


	cout << "공격 결과출력" << endl;

	attacker.battleResult(attacker);
	defender.battleResult(defender);
	cout << "공격 끝" << endl;


}