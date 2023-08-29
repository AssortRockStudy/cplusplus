#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <map>
#include <string>
#include "User.h"

using namespace std;

map<string, User> userMap;

void initUser()
{
	while (true)
	{
		system("cls");
		User newUser;

		map<string, User>::iterator isValidName;
		do // �̸� �Է�
		{
			cout << "�̸� �Է�(����): ";
			cin >> newUser.m_Name;
			isValidName = userMap.find(newUser.m_Name);
			if (isValidName == userMap.end())
				cout << "�ߺ��� �̸��Դϴ�. �ٽ� �Է����ּ���." << endl;
		} while (isValidName == userMap.end());

		do // ���� �Է�
		{
			cout << "���� �Է�(����-> 1, ����-> 2): ";
			cin >> newUser.m_Sex;
			if (newUser.m_Sex == 1 || newUser.m_Sex == 2)
				cout << "�߸��� ���Դϴ�. �ٽ� �Է����ּ���." << endl;
		} while (newUser.m_Sex == 1 || newUser.m_Sex == 2);

		// ���� �Է�
		cout << "���� �Է�: ";
		cin >> newUser.m_Age;

		// ������ ����
		userMap.insert(make_pair(newUser.m_Name, newUser));
		cout << endl << endl
			 << "ȸ�� ����� �Ϸ�Ǿ����ϴ�." << endl;


		int answer = 0;
		do
		{
			cout << "ȸ�� ����� �� �� �� �����ұ��? (yes-> 1, no-> 2): ";
			cin >> answer;

		} while (answer == 1 || answer == 2);
		
		if (answer == 2) break;
	}
}

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
		printf("+++++ȸ������ ����� ���α׷�+++++\n");
		printf("1. ȸ�� ���\n");
		printf("2. ȸ�� ���� ���\n");
		printf("3. ������\n\n\n");
		printf("���ϴ� ����� �Է��ϼ���: ");

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