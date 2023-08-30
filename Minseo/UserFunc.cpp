#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <map>
#include <string>

#include "UserFunc.h"
#include "User.h"

using namespace std;

map<string, User> userMap;

enum USER_FUNC
{
	INIT = 1,
	PRINT,
	EDIT,
	RETURN
}; 

enum OUTPUT
{
	SEARCH = 1,
	SORT,
	BREAK,
};

enum SEX
{
	MALE = 1,
	FEMALE
};


void initUser()
{
	while (true)
	{
		system("cls");
		cout << "+++++ ȸ�� ���" << endl;	
		cout << "���ݱ���" << userMap.size() << "���� ȸ���� ����߽��ϴ�." << endl;

		User newUser;

		map<string, User>::iterator isValidName;
		do // �̸� �Է�
		{
			cout << "�̸� �Է�(����): ";
			cin >> newUser.m_Name;
			isValidName = userMap.find(newUser.m_Name);
			if (isValidName != userMap.end())
				cout << "�ߺ��� �̸��Դϴ�. �ٽ� �Է����ּ���." << endl;
		} while (isValidName != userMap.end());

		do // ���� �Է�
		{
			cout << "���� �Է�(����-> 1, ����-> 2): ";
			cin >> newUser.m_Sex;
			if (newUser.m_Sex != MALE && newUser.m_Sex != FEMALE)
				cout << "�߸��� ���Դϴ�. �ٽ� �Է����ּ���." << endl;
		} while (newUser.m_Sex != MALE && newUser.m_Sex != FEMALE);

		// ���� �Է�
		cout << "���� �Է�: ";
		cin >> newUser.m_Age;

		// ������ ����
		userMap.insert(make_pair(newUser.m_Name, newUser));
		cout << endl << endl
			<< "ȸ�� ����� �Ϸ�Ǿ����ϴ�." << endl;


		int answer = 0;
		do // ����� üũ
		{
			cout << "ȸ�� ����� �� �� �� �����ұ��? (yes-> 1, no-> 2): ";
			cin >> answer;

		} while (answer != 1 && answer != 2);

		if (answer == 2) break;
	}
}

void outputSort_Name(int isReverse)
{
	if (isReverse == 1)
	{
		for (auto iter = userMap.begin(); iter != userMap.end(); ++iter)
		{
			User data = iter->second;
			cout << "----- " << data.m_Name << "��" << endl;
			cout << "����: " << data.m_Age << endl;
			cout << "����: ";
			if (data.m_Sex == MALE)
				cout << "����" << endl;
			else
				cout << "����" << endl;
			cout << "�׷�: " << data.m_Group << endl;
		}
	}
	else
	{
		for (auto riter = userMap.rbegin(); riter != userMap.rend(); ++riter)
		{
			User data = riter->second;
			cout << "----- " << data.m_Name << "��" << endl;
			cout << "����: " << data.m_Age << endl;
			cout << "����: ";
			if (data.m_Sex == MALE)
				cout << "����" << endl;
			else
				cout << "����" << endl;
			cout << "�׷�: " << data.m_Group << endl;
		}
	}
}
void outputSort_Sex(int Sex)
{
	for (auto iter = userMap.begin(); iter != userMap.end(); ++iter)
	{
		User data = iter->second;
		if (Sex != data.m_Sex) continue;
		cout << "----- " << data.m_Name << "��" << endl;
		cout << "����: " << data.m_Age << endl;
		cout << "����: ";
		if (data.m_Sex == MALE)
			cout << "����" << endl;
		else
			cout << "����" << endl;
		cout << "�׷�: " << data.m_Group << endl;
	}
}

void outputSort() // ���� �� ���
{
	system("cls");
	cout << "1. �̸� �� ���" << endl;
	cout << "2. �̸� ���� ���" << endl;
	cout << "3. ��� ���� ���" << endl;
	cout << "4. ��� ���� ���" << endl;
	cout << "5. ���̴� �� ���" << endl;
	cout << "���ϴ� ����� �Է��ϼ���: ";
	
	int answer = 0;
	cin >> answer;
	switch (answer)
	{
	case 1:
	case 2:
		outputSort_Name(answer);
		break;
	case 3:
	case 4:
		outputSort_Sex(answer - 2);
		break;
	case 5:

		break;
	}
	return;
}

void outputSearch() // Ž�� �� ���� ���
{
	system("cls");

	// ���� Ž��
	string nameBuffer = "";
	cout << "ã���� �ϴ� �̸� �Է�: ";
	cin >> nameBuffer;

	map<string, User>::iterator dataIter = userMap.find(nameBuffer);

	if (dataIter == userMap.end())
	{
		cout << "�ش� �̸��� ȸ���� ����Ǿ����� �ʽ��ϴ�." << endl;
		return;
	}

	// ���� ���
	User data = dataIter->second;
	cout << "----- " << data.m_Name << "��" << endl;
	cout << "����: " << data.m_Age << endl;
	cout << "����: ";
	if (data.m_Sex == MALE)
		cout << "����" << endl;
	else
		cout << "����" << endl;
	cout << "�׷�: " << data.m_Group << endl;

	return;
}

void printUser()
{
	system("cls");
	cout << "+++++ ȸ�� ���" << endl;
	cout << "���� " << userMap.size() << "���� ȸ���� ����Ǿ� �ֽ��ϴ�.";
	cout << "1. ���� �˻� �� ���" << endl;
	cout << "2. ���� ��ü ���" << endl; 
	cout << "3. ���ư���" << endl << endl << endl;
	cout << "���ϴ� ����� �Է��ϼ���: ";

	int answer = 0;
	cin >> answer;
	
	switch (answer) // ���ӵ� ������ case�� jump table�� ���
	{
	case OUTPUT::SEARCH:
		outputSearch();
		break;
	case OUTPUT::SORT:
		outputSort();
		break;
	case OUTPUT::BREAK:
		break;	
	default:
		break;
	}
	
	cout << "ȸ���� ����߽��ϴ�. �ƹ� Ű�� ������ ���� ȭ������ �����մϴ�..." << endl;
	_getwch();
	return;
}

int RunUserInfoSystem()
{
	system("cls");
	int answer = 0;
	cout << "+++++ȸ������ ����� ���α׷�+++++" << endl;
	cout << "---���� �Էµ� ������ ��: " << userMap.size() << endl;
	cout << "1. ȸ�� ���" << endl;
	cout << "2. ȸ�� ���" << endl;
	cout << "3. ȸ�� ���� ����" << endl;
	cout << "4. ������" << endl << endl << endl;
	cout << "���ϴ� ����� �Է��ϼ���: ";

	cin >> answer;
	switch (answer) // ���ӵ� ������ case�� jump table�� ���
	{
	case INIT:
		initUser();
		break;
	case PRINT:
		printUser();
		break;
	case EDIT:
		// ȸ���������� �Լ�
		break;
	case RETURN:
		cout << "���α׷��� �����մϴ�." << endl;
		return 0;
		break;
	default:
		break;
	}

	return 1;
}