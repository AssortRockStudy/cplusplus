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
		cout << "지금까지" << userMap.size() << "명의 회원을 등록했습니다." << endl;
		User newUser;

		map<string, User>::iterator isValidName;
		do // 이름 입력
		{
			cout << "이름 입력(영문): ";
			cin >> newUser.m_Name;
			isValidName = userMap.find(newUser.m_Name);
			if (isValidName == userMap.end())
				cout << "중복된 이름입니다. 다시 입력해주세요." << endl;
		} while (isValidName == userMap.end());

		do // 성별 입력
		{
			cout << "성별 입력(남성-> 1, 여성-> 2): ";
			cin >> newUser.m_Sex;
			if (newUser.m_Sex == 1 || newUser.m_Sex == 2)
				cout << "잘못된 값입니다. 다시 입력해주세요." << endl;
		} while (newUser.m_Sex == 1 || newUser.m_Sex == 2);

		// 나이 입력
		cout << "나이 입력: ";
		cin >> newUser.m_Age;

		// 데이터 삽입
		userMap.insert(make_pair(newUser.m_Name, newUser));
		cout << endl << endl
			<< "회원 등록이 완료되었습니다." << endl;


		int answer = 0;
		do
		{
			cout << "회원 등록을 한 번 더 진행할까요? (yes-> 1, no-> 2): ";
			cin >> answer;

		} while (answer == 1 || answer == 2);

		if (answer == 2) break;
	}
}