#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <map>
#include <string>

#include "UserFunc.h"
#include "User.h"

void initUser()
{
	while (true)
	{
		system("cls");
		cout << "���ݱ���" << userMap.size() << "���� ȸ���� ����߽��ϴ�." << endl;
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