#include <stdio.h>
#include <stdlib.h>

#include "tarray.h"
#include "struct.h"
#include <iostream>

void additionalInfo();

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

