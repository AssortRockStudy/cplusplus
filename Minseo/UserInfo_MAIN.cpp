#include <iostream>
#include <map>

#include "User.h"
#include "UserFunc.h"

using namespace std;

map<string, User> userMap;



void printUser()
{
	system("cls");
	int i = 0;
	//for (; i < u_Count; ++i)
	//{
	//	printf("+++++���� %d\n", i + 1);
	//	printf("- ���� �̸�: %s\n", u_Name[i]);
	//	printf("- ���� ����: %s\n", u_Sex[i] == 1 ? "����" : "����");
	//	printf("- ���� ����: %d\n", u_Age[i]);
	//}
	printf("��� ȸ���� ����߽��ϴ�. �ƹ� ���ڸ� �Է��ϸ� ���� ȭ������ �����մϴ�...");
	_getwch();
}

int main()
{
	while (true)
	{
		system("cls");
		int answer = 0;
		cout << "+++++ȸ������ ����� ���α׷�+++++" << endl;
		cout << "---���� �Էµ� ������ ��: " << userMap.size() << endl;
		cout << "1. ȸ�� ���" << endl;
		cout << "2. ȸ�� ���� ���" << endl;
		cout << "3. ������" << endl << endl << endl;
		cout << "���ϴ� ����� �Է��ϼ���: " << endl;

		scanf_s("%d", &answer);
		switch (answer) // ���ӵ� ������ case�� jump table�� ���
		{
		case 1:
			initUser();
			break;
		case 2:
			printUser();
			break;
		case 3:
			printf("���α׷��� �����մϴ�.\n");
			return 0;
			break;
		default:
			break;
		}
	}
}