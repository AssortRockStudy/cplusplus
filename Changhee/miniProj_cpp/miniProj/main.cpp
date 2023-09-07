#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct tUser
{
	char	name[255];
	int		sex;
	int		age;


	void print()
	{
		cout << "�̸� : " << name << endl;

		if (sex == 1)
		{
			cout << "���� : ��" << endl;
		}
		else
		{
			cout << "���� : ��" << endl;
		}

		cout << "���� : " << age << endl;
	}

};

vector<tUser> vUserList;


void userRegister()
{
	while (true)
	{
		system("cls");

		tUser user = {};

		cout << "ȸ�� ���" << endl;
		cout << "�̸��� �Է��ϼ���." << endl;
		cin >> user.name;
		cout << endl;

		cout << "������ �Է����ּ���(����1, ����2) " << endl;
		cin >> user.sex;
		cout << endl;

		cout << "���̸� �Է��ϼ���." << endl;
		cin >> user.age;
		cout << endl;

		vUserList.push_back(user);

		int inp;
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

void userPrint()
{
	system("cls");

	cout << "������ ������ ����մϴ�." << endl << endl;

	for (int i = 0; i < vUserList.size(); ++i)
	{
		cout << i << " �� ° User " << endl;

		vUserList[i].print();

		cout << endl;
	}

	int inp;
	cout << endl << "1. ����ȭ������ ������" << endl;
	
	cin >> inp;
}



int main()
{
	while (true)
	{
		system("cls");

		int inp;

		cout << "1. ȸ�� ���" << endl;
		cout << "2. ȸ�� ���" << endl;
		cout << "3. ������" << endl;

		cin >> inp;

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
			break;
		}

	}

	return 0;
}