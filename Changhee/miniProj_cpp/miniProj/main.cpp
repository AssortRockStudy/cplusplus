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
		cout << "이름 : " << name << endl;

		if (sex == 1)
		{
			cout << "성별 : 남" << endl;
		}
		else
		{
			cout << "성별 : 여" << endl;
		}

		cout << "나이 : " << age << endl;
	}

};

vector<tUser> vUserList;


void userRegister()
{
	while (true)
	{
		system("cls");

		tUser user = {};

		cout << "회원 등록" << endl;
		cout << "이름을 입력하세요." << endl;
		cin >> user.name;
		cout << endl;

		cout << "성별을 입력해주세요(남자1, 여자2) " << endl;
		cin >> user.sex;
		cout << endl;

		cout << "나이를 입력하세요." << endl;
		cin >> user.age;
		cout << endl;

		vUserList.push_back(user);

		int inp;
		cout << "1. 추가 입력" << endl;
		cout << "2. 메인 화면" << endl;
		cout << "입력 : ";
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

	cout << "유저의 정보를 출력합니다." << endl << endl;

	for (int i = 0; i < vUserList.size(); ++i)
	{
		cout << i << " 번 째 User " << endl;

		vUserList[i].print();

		cout << endl;
	}

	int inp;
	cout << endl << "1. 메인화면으로 나가기" << endl;
	
	cin >> inp;
}



int main()
{
	while (true)
	{
		system("cls");

		int inp;

		cout << "1. 회원 등록" << endl;
		cout << "2. 회원 출력" << endl;
		cout << "3. 끝내기" << endl;

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