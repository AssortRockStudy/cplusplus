#include "app.h"



void app::run()
{

	while (true)
	{
		system("cls");

		int inp;

		cout << "1. ȸ�� ���� ���" << endl;
		cout << "2. ȸ�� ���� ���" << endl;
		cout << "3. ȸ�� ���� �˻�" << endl;
		cout << "4. ȸ�� ���� ����" << endl;
		cout << "5. ȸ�� ���� ����" << endl;
		cout << "6. ������" << endl;

		cin >> inp;

		if (inp < 1 || inp >6)
		{
			cout << endl << "�߸��� ��ȣ�Դϴ�." << endl;
			_getch();
			continue;
		}

		if (inp == 1)
		{
			userRegister();
		}
		else if (inp == 2)
		{
			userPrint();
		}
		else if (inp == 3)
		{
			userSearch();
		}
		else if (inp == 4)
		{
			userEdit();
		}
		else if (inp == 5)
		{
			userDel();
		}
		else if (inp == 6)
		{
			break;
		}

	}

}

void app::userRegister()
{
	while (true)
	{
		system("cls");

		tUser* user = new tUser;

		cout << "ȸ�� ���" << endl;
		cout << "�̸��� �Է��ϼ���." << endl;
		cin >> user->Name;
		cout << endl;

		cout << "������ �Է����ּ���(����1, ����2) " << endl;
		cin >> user->Sex;
		cout << endl;

		cout << "���̸� �Է��ϼ���." << endl;
		cin >> user->Age;
		cout << endl;

		int inp;
		cout << "�׷��� �Է��ϼ���(1~3)." << endl;
		cin >> inp;
		user->Type = (GROUP_TYPE)inp;
		cout << endl;

		// �ߺ� üũ
		bool flag = false;
		for (int i = 0; i < m_vecUser.size(); ++i)
		{
			if (m_vecUser[i]->Name == user->Name && m_vecUser[i]->Age == user->Age && m_vecUser[i]->Sex == user->Sex && m_vecUser[i]->Type == user->Type)
				flag = true;
		}

		if (!flag)
		{
			m_vecUser.push_back(user);
		}

		cout << "1. �߰� �Է�" << endl;
		cout << "2. ���� ȭ��" << endl;
		cout << "�Է� : ";
		cin >> inp;

		if (inp == 2)
		{
			break;
		}
	}

}

bool desc(tUser* first, tUser* second)
{
	return first->Name > second->Name;
}

bool asc(tUser* first, tUser* second)
{
	return first->Name < second->Name;
}

void app::userPrint()
{
	system("cls");

	int inp;
	cout << "������ ������ ����մϴ�.(1:��������, 2:��������)" << endl << endl;
	cin >> inp;

	if (inp == 1)
	{
		sort(m_vecUser.begin(), m_vecUser.end(),asc);
	}
	else if (inp == 2)
	{
		sort(m_vecUser.begin(), m_vecUser.end(), desc);
	}
	else 
	{
		cout << "�߸� �Է��ϼ̽��ϴ�.";
		_getch();
		return;
	}

	for (int i = 0; i < m_vecUser.size(); ++i)
	{
		cout << i << " �� ° User " << endl;

		m_vecUser[i]->print();

		cout << endl;
	}

	_getch();
}

void app::userSearch()
{
	system("cls");

	string target;
	cout << "�˻��Ͻ� ������ �̸��� �Է����ּ���.\n";
	cin >> target;


	int flag = -1;
	for (int i = 0; i < m_vecUser.size(); ++i)
	{
		if (m_vecUser[i]->Name == target)
			flag = i;
	}

	if (flag == -1)
	{
		cout << "�ش� �̸��� ���� ������ ã�� �� �����ϴ�.\n";
		_getch();
	}
	else
	{
		m_vecUser[flag]->print();
		_getch();
	}
}

void app::userEdit()
{
	string target;
	cout << "�����Ͻ� ������ �̸��� �Է����ּ���.\n";
	cin >> target;

	int flag = -1;
	for (int i = 0; i < m_vecUser.size(); ++i)
	{
		if (m_vecUser[i]->Name == target)
			flag = i;
	}

	if (flag == -1)
	{
		cout << "�ش� �̸��� ���� ������ ã�� �� �����ϴ�.\n";
		_getch();
	}
	else
	{
		int inp;
		cout << "�����Ͻ� ������ �Է����ּ���(1.�̸�, 2:����, 3:����, 4:�׷�)\n";
		cin >> inp;

		switch (inp)
		{
		case 1:
			cout << "�����Ͻ� �̸��� �Է����ּ���.\n";
			cin >> m_vecUser[flag]->Name;

			break;
		case 2:
			cout << "�����Ͻ� ������ �Է����ּ���(����:1, ����:2).\n";
			cin >> m_vecUser[flag]->Sex;
			break;
		case 3:
			cout << "�����Ͻ� ������ �Է����ּ���.\n";
			cin >> m_vecUser[flag]->Age;
			break;
		case 4:
			cout << "�����Ͻ� �׷��� �Է����ּ���.\n";
			int tmp;
			cin >> tmp;
			m_vecUser[flag]->Type = (GROUP_TYPE)tmp;
			break;

		default:
			cout << "�߸� �Է��ϼ̽��ϴ�.\n";
			break;
		}


		cout << "������ �����Ǿ����ϴ�.\n";
		_getch();
	}

}

void app::userDel()
{
	system("cls");

	string target;
	cout << "�����Ͻ� ������ �̸��� �Է����ּ���.\n";
	cin >> target;


	vector<tUser*>::iterator iter = m_vecUser.begin();

	for (; iter!=m_vecUser.end(); ++iter)
	{
		if ((*iter)->Name == target)
		{
			break;
		}
	}



	if (iter == m_vecUser.end())
	{
		cout << "�ش� �̸��� ���� ������ ã�� �� �����ϴ�.\n";
	}
	else
	{
		delete *iter;
		m_vecUser.erase(iter);
	}

	cout << "�ش� ������ ������ �����Ǿ����ϴ�.\n";
	_getch();
}
