#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <map>
#include <string>

#include "UserFunc.h"
#include "User.h"

using namespace std;

map<string, User> userMap;

void registrationUser()
{
	while (true)
	{
		system("cls");
		cout << "+++++ 회원 등록" << endl;	
		cout << "지금까지" << userMap.size() << "명의 회원을 등록했습니다." << endl;

		User newUser;

		map<string, User>::iterator isValidName;
		do // 이름 입력
		{
			cout << "이름 입력(영문): ";
			cin >> newUser.m_Name;
			isValidName = userMap.find(newUser.m_Name);
			if (isValidName != userMap.end())
				cout << "중복된 이름입니다. 다시 입력해주세요." << endl;
		} while (isValidName != userMap.end());

		do // 성별 입력
		{
			cout << "성별 입력(남성-> 1, 여성-> 2): ";
			cin >> newUser.m_Sex;
			if (newUser.m_Sex != MALE && newUser.m_Sex != FEMALE)
				cout << "잘못된 값입니다. 다시 입력해주세요." << endl;
		} while (newUser.m_Sex != MALE && newUser.m_Sex != FEMALE);

		// 나이 입력
		cout << "나이 입력: ";
		cin >> newUser.m_Age;

		// 데이터 삽입
		userMap.insert(make_pair(newUser.m_Name, newUser));
		cout << endl << endl
			<< "회원 등록이 완료되었습니다." << endl;


		int answer = 0;
		do // 재실행 체크
		{
			cout << "회원 등록을 한 번 더 진행할까요? (yes-> 1, no-> 2): ";
			cin >> answer;

		} while (answer != 1 && answer != 2);

		if (answer == 2) break;
	}
}

void outputUser(const User& data)
{
	cout << "----- " << data.m_Name << "님" << endl;
	cout << "나이: " << data.m_Age << endl;
	cout << "성별: ";
	if (data.m_Sex == MALE)
		cout << "남성" << endl;
	else
		cout << "여성" << endl;
	cout << "그룹: " << data.m_Group << endl;
}

void outputSort_Name()
{
	for (auto iter = userMap.begin(); iter != userMap.end(); ++iter)
	{
		User data = iter->second;
		outputUser(data);
	}

}

void outputSort_NameReverse()
{
	for (auto riter = userMap.rbegin(); riter != userMap.rend(); ++riter)
	{
		User data = riter->second;
		outputUser(data);
	}
}

void outputSort_MALE()
{
	for (auto iter = userMap.begin(); iter != userMap.end(); ++iter)
	{
		User data = iter->second;
		if (SEX::MALE != data.m_Sex) continue;
		outputUser(data);
	}
}
void outputSort_FEMALE()
{
	for (auto iter = userMap.begin(); iter != userMap.end(); ++iter)
	{
		User data = iter->second;
		if (SEX::FEMALE != data.m_Sex) continue;
		outputUser(data);
	}
}

void outputSort_Age()
{
	cout << "출력 할 나이대(10, 20, 30 등)를 입력하세요." << endl;
	cout << "(참고: 30 31 39 모두 30대 검색으로 간주하며 1의 자리는 절삭되어 판단합니다.): ";
	int ageGroup = 0;
	cin >> ageGroup;
	ageGroup %= 10;
	for (auto iter = userMap.begin(); iter != userMap.end(); ++iter)
	{
		User data = iter->second;
		if (ageGroup != (data.m_Age % 10)) continue;
		outputUser(data);
	}
}

void outputSort_Group()
{
	cout << "출력 할 그룹 명을 입력하세요: ";
	string Group = "";
	cin >> Group;
	for (auto iter = userMap.begin(); iter != userMap.end(); ++iter)
	{
		User data = iter->second;
		if (Group != data.m_Group) continue;
		outputUser(data);
	}
}

void outputSort() // 정렬 후 출력
{
	system("cls");
	cout << "1. 이름 순 출력" << endl;
	cout << "2. 이름 역순 출력" << endl;
	cout << "3. 모든 남성 출력" << endl;
	cout << "4. 모든 여성 출력" << endl;
	cout << "5. 나이대 별 출력" << endl;
	cout << "6. 그룹 별 출력" << endl;
	cout << "원하는 기능을 입력하세요: ";
	
	int answer = 0;
	cin >> answer;
	switch (answer)
	{
	case 1:
		outputSort_Name();
		break;
	case 2:
		outputSort_NameReverse();
		break;
	case 3:
		outputSort_MALE();
		break;
	case 4:
		outputSort_FEMALE();
		break;
	case 5:
		outputSort_Age();
		break;
	case 6:
		outputSort_Group();
		break;
	}
	return;
}

int searchUser(map<string, User>::iterator& dataIter)
{
	// 유저 탐색
	string nameBuffer = "";
	cout << "찾고자 하는 유저의 이름을 입력하세요: ";
	cin >> nameBuffer;
	dataIter = userMap.find(nameBuffer);
	if (dataIter == userMap.end())
	{
		cout << "해당 이름의 회원은 저장되어있지 않습니다." << endl;
		return 0;
	}
	return 1;
}

void outputSearch() // 탐색 후 유저 출력
{
	map<string, User>::iterator dataIter;
	if (!searchUser(dataIter)) { return; }
	User data = dataIter->second;
	outputUser(data);
	return;
}

void printUser()
{
	system("cls");
	cout << "+++++ 회원 출력" << endl;
	cout << "현재 " << userMap.size() << "명의 회원이 저장되어 있습니다." << endl;
	cout << "1. 유저 검색 후 출력" << endl;
	cout << "2. 유저 전체 출력" << endl; 
	cout << "3. 돌아가기" << endl << endl << endl;
	cout << "원하는 기능을 입력하세요: ";

	int answer = 0;
	cin >> answer;
	
	switch (answer) // 연속된 구조의 case면 jump table을 사용
	{
	case OUTPUT::SEARCH:
		outputSearch();
		break;
	case OUTPUT::SORT:
		outputSort();
		break;
	case OUTPUT::BREAK:
	default:
		break;	
	}
	
	cout << "회원을 출력했습니다. 아무 키를 누르면 메인 화면으로 복귀합니다..." << endl;
	_getwch();
	return;
}

void editUser()
{
	// 유저 검색 후 출력
	map<string, User>::iterator dataIter;
	if (!searchUser(dataIter)) { return; } // 예외 처리
	User data = dataIter->second;
	outputUser(data);

	// 원하는 옵션 선택 후 변경하기
	cout << "1. 나이 변경" << endl;
	cout << "2. 성별 변경" << endl;
	cout << "3. 그룹 변경" << endl << endl;
	cout << "4. 유 저  데 이 터  삭 제" << endl;
	cout << "5. 끝내기" << endl << endl << endl;
	cout << "원하는 기능을 입력하세요: ";

	int answer = 0;
	cin >> answer;
	system("cls");
	switch (answer) // 연속된 구조의 case면 jump table을 사용
	{
	case 1:
		cout << "변경할 나이 입력:";
		cin >> data.m_Age;
		break;
	case 2:
		do // 성별 입력
		{
			cout << "변경할 성별 입력(남성-> 1, 여성-> 2): ";
			cin >> data.m_Sex;
			if (data.m_Sex != MALE && data.m_Sex != FEMALE)
				cout << "잘못된 값입니다. 다시 입력해주세요." << endl;
		} while (data.m_Sex != MALE && data.m_Sex != FEMALE);
		break;
	case 3:
		cout << "그룹 입력:";
		cin >> data.m_Group;
		break;
	case 4:
		userMap.erase(dataIter);
	default:
		return;
	}

	cout << "변경이 완료되었습니다. 아무 키를 누르면 메인 화면으로 복귀합니다..." << endl;
	_getwch();
}

void eraseUser()
{
	cout << "정말로 모든 데이터를 초 기 화 시키려면 \"yes\"를 입력하세요: ";
	string answer = "";
	cin >> answer;
	if (answer == "yes")
	{
		userMap.clear();
		cout << "모든 데이터가 초기화 되었습니다. 아무 키를 누르면 메인 화면으로 복귀합니다..." << endl;
		_getwch();
	}
	return;
}

int RunUserInfoSystem()
{
	system("cls");
	int answer = 0;
	cout << "+++++회원정보 입출력 프로그램+++++" << endl;
	cout << "---현재 입력된 유저의 수: " << userMap.size() << endl;
	cout << "1. 회원 등록" << endl;
	cout << "2. 회원 출력" << endl;
	cout << "3. 회원 정보 수정" << endl;
	cout << "4. 끝내기" << endl << endl << endl;
	cout << "원하는 기능을 입력하세요: ";

	cin >> answer;
	switch (answer) // 연속된 구조의 case면 jump table을 사용
	{
	case REGISTRATION:
		registrationUser();
		break;
	case PRINT:
		printUser();
		break;
	case EDIT:
		editUser();
		break;
	case CLEAR:
		eraseUser();
	case RETURN:
		cout << "프로그램을 종료합니다." << endl;
		return 0;
		break;
	default:
		break;
	}

	return 1;
}

void UserInfoSystem()
{
	int ROOP = 1;
	while (ROOP) { ROOP = RunUserInfoSystem(); }
}
