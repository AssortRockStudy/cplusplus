#include <stdio.h>
#include <stdlib.h>

#include "tarray.h"
#include "struct.h"
#include <iostream>
#include <algorithm> 

void additionalInfo();
bool cmpid(User& _A, User& _B);

void InputUserInfo()
{
	system("cls");

	User user;

	cout<<"유저 정보 입력" << endl;
	cout << "이름을 입력하세요" << endl;
	cin >> user.name;

	cout << "성별을 입력하세요( 남자 : 1, 여자 2)" << endl;
	cin >> user.Sex;

	cout << "나이를 입력하세요" << endl;
	cin >> user.Age;

	vector<User>::iterator iter=g_user.begin();
	for (iter; g_user.end()!=iter; ++iter)
	{
		if (user == (*iter)) { 
			break;
		}
	}

	if (g_user.end() != iter)
	{
		cout << "중복된 회원입니다." << endl;
		system("pause");
		return;
	}


	iter= max_element(g_user.begin(), g_user.end(), cmpid);
	user.ID = (iter->ID) + 1;

	g_user.push_back(user);
	additionalInfo();
}

void additionalInfo()
{

	int Input = 0;

	system("cls");

	cout << "추가로 정보를 입력 하시겠습니까?  " << endl;
	cout << "1.추가입력" << endl;
	cout << "2.메인화면" << endl;
	cin >> Input;
	if (1 == Input) { InputUserInfo(); }
	else { return; }

}

