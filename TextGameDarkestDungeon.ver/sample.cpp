#include <iostream>
#include <string>
#include "unitstatus.h"
using namespace std;



// unitstat �Է� ���� (ü��, ���ݷ�, ����, ���߷�, ȸ����, ũ��Ƽ����)
// resistanceStatusSetter �Է� ���� (���� �̸�, ����, ���, ����, �����, �����̵�, ������ ����)


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
	// a : ����
	// s : ������ ���
	// d : ����

	while (witch.HP != 0 && warrior.HP != 0)
	{
		cin >> action;

		switch (action)
		{
		case 'a':cout << "������ �����ϼ̽��ϴ�" << endl;
			Attack(witch, warrior);
			break;
		case's': cout << "�����ۻ���� �����ϼ̽��ϴ�" << endl;
			break;
		case 'd': cout << "������ �����ϼ̽��ϴ�" << endl;
			runningpoint++;
			break;
		default: cout << "����ε� �Է��� ��Ź�帳�ϴ�" << endl;
		}

		if (runningpoint >= rand() % 3 + 1)
		{
			break;
		}
		else
		{
			cout << "����ġ�⿡ �����ϼ̽��ϴ�" << endl;
		}







	}





}


// ���ǵ�(����) ����
// 8������