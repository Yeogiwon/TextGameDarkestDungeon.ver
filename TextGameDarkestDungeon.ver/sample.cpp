#include <iostream>
#include <string>
#include "unitstatus.h"
using namespace std;



// unitstat 입력 순서 (체력, 공격력, 방어력, 명중률, 회피율, 크리티컬율)
// resistanceStatusSetter 입력 순서 (유닛 이름, 스턴, 밝기, 출혈, 디버프, 강제이동, 죽음의 숨결)


void main()
{
	int HP;
	int ATK;
	int DEF;
	int ACC;
	int DODGE;
	int CRIT;



	unitstat witch(100, 30, 5, 90, 10, 80);
	unitstat warrior(200, 20, 10, 80, 20, 10.5);
	resistanceStatusSetter(witch, 10, 20, 30, 40, 50, 60);

	witch.DungeonStart(witch);
	warrior.DungeonStart(warrior);

	char action;
	int runningpoint = 0;
	// a : 공격
	// s : 아이템 사용
	// d : 도망

	while (witch.HP != 0 && warrior.HP != 0)
	{
		cin >> action;

		switch (action)
		{
		case 'a':cout << "공격을 선택하셨습니다" << endl;
			Attack(witch, warrior);
			break;
		case's': cout << "아이템사용을 선택하셨습니다" << endl;
			break;
		case 'd': cout << "도망을 선택하셨습니다" << endl;
			runningpoint++;
			break;
		default: cout << "제대로된 입력을 부탁드립니다" << endl;
		}

		if (runningpoint >= rand() % 3 + 1)
		{
			break;
		}
		else
		{
			cout << "도망치기에 실패하셨습니다" << endl;
		}







	}





}


// 스피드(선공) 구현
// 8개유닛