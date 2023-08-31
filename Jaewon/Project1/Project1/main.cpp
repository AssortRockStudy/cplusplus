#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>
#include <string>

using std::string;
using std::map;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

// 이름 순으로 정렬해서 출력(역순도 선택 가능하도록)
// 성별에 따라, 나이대(10대, 20대 등)에 따라 필터링해서 출력
// 회원 정보 삭제
// 회원 그룹 정보 추가

struct UserData {
	char sex;
	char age;
};

bool duplicateCheck(string name);
void save(string name, const UserData&);
void saveUser();
void findUser();
void printAllData();
void printFilteredData();

map<string, UserData> storage;

int main() {
	bool flag = true;
	while (flag) {
		int input;
		system("cls");
		printf("1. 회원등록\n");
		printf("2. 회원 모두 출력\n");
		printf("3. 회원 검색\n");
		printf("4. 회원 필터링 출력\n");
		printf("5. 종료\n");
		scanf_s("%d", &input);

		switch (input)
		{
		case 1:
			saveUser();
			break;
		case 2:
			printAllData();
			break;
		case 3:
			findUser();
			break;
		case 4:
			printFilteredData();
			break;
		case 5:
			flag = false;
			break;
		default:
			break;
		}
	}
	return 0;
}

bool duplicateCheck(string name) {
	return storage.find(name) != storage.end();
}

void save(string name, const UserData& data) { 
	storage.insert({name, data}); 
}


void saveUser() {
	while (true) {
		system("cls");
		UserData user = {};
		string name = "";
		bool duplicated = true;
		while (duplicated) {
			printf("이름 입력\n");
			cin >> name;
			duplicated = duplicateCheck(name);
			if (duplicated)
				printf("중복된 이름입니다.\n");
		}
		printf("성별 입력(남자는 1, 여자는 2)\n");
		scanf_s("%hhd", &user.sex);
		printf("나이 입력\n");
		scanf_s("%hhd", &user.age);
		save(name, user);
		int flag = 0;
		printf("추가로 저장하시겠습니까?(y = 1 / n = 0)\n");
		scanf_s("%d", &flag);
		if (flag == 0)
			break;
	}
}

void findUser()
{
	string name;
	system("cls");
	printf("이름 입력\n");
	cin >> name;
	if (duplicateCheck(name)) {
		map<string, UserData>::iterator iter = storage.find(name);
		cout << "이름 : " << iter->first << endl;
		if (iter->second.sex == 1)
			printf("성별 : 남자\n");
		else
			printf("성별 : 여자\n");
		printf("나이 : %d\n", iter->second.age);
	}
	char continued;
	printf("메인 화면으로 이동하려면 아무 키나 입력하세요\n");
	scanf_s("%s", &continued, 1);
}

// 이름 순으로 정렬해서 출력(역순도 선택 가능하도록)
// map에는 reverse iterator가 구현되어 있어 역순 출력이 가능
// 변수 reverse를 두어 true면 정순 false면 역순으로 출력하도록

void printAllData() {
	system("cls");
	bool reverse = false;
	printf("이름의 역순으로 출력하시려면 0번을 아니면 1번을 눌러주세요.\n");
	cin >> reverse;
	int cnt = 0;
	if (reverse) {
		map<string, UserData>::iterator iter;
		for (iter = storage.begin(); iter != storage.end(); ++iter) {
			printf("회원 %d\n", cnt);
			cout << "이름 : " << iter->first << endl;
			if (iter->second.sex == 1)
				printf("성별 : 남자\n");
			else
				printf("성별 : 여자\n");
			printf("나이 : %d\n", iter->second.age);
			++cnt;
		}
	}
	else {
		map<string, UserData>::reverse_iterator iter;
		for (iter = storage.rbegin(); iter != storage.rend(); ++iter) {
			printf("회원 %d\n", cnt);
			cout << "이름 : " << iter->first << endl;
			if (iter->second.sex == 1)
				printf("성별 : 남자\n");
			else
				printf("성별 : 여자\n");
			printf("나이 : %d\n", iter->second.age);
			++cnt;
		}
	}
	char continued;
	printf("메인 화면으로 이동하려면 아무 키나 입력하세요\n");
	scanf_s("%s", &continued, 1);
}

// 성별에 따라, 나이대(10대, 20대 등)에 따라 필터링해서 출력

void printFilteredData() {
	system("cls");
	printf("출력하고 싶은 옵션에 따른 번호를 입력하세요.\n");
	printf("1. 성별\n");
	printf("2. 나이대\n");
	int sel;
	cin >> sel;
	if (1 == sel) {
		system("cls");
		printf("출력하고 싶은 성별에 따른 번호를 입력하세요.\n");
		printf("1. 남자\n");
		printf("2. 여자\n");
		cin >> sel;
		int selectedSex;
		if (1 == sel) 
			selectedSex = 1;
		else 
			selectedSex = 2;
		map<string, UserData>::iterator iter;
		for (iter = storage.begin(); iter != storage.end(); ++iter) {
			if (selectedSex == iter->second.sex) {
				cout << "이름 : " << iter->first << endl;
				if (iter->second.sex == 1)
					printf("성별 : 남자\n");
				else
					printf("성별 : 여자\n");
				printf("나이 : %d\n", iter->second.age);
			}
		}
	}
	else if(2 == sel){
		system("cls");
		printf("출력하고 싶은 나이대에 따른 번호를 입력하세요.\n");
		printf("0. 10대 미만\n");
		printf("1. 10대\n");
		printf("2. 20대\n");
		printf("3. 30대\n");
		printf("4. 40대 이상\n");
		cin >> sel;
		int selectedAge;
		switch (sel)
		{
		case 0:
			selectedAge = 0;
			break;
		case 1:
			selectedAge = 10;
			break;
		case 2:
			selectedAge = 20;
			break;
		case 3:
			selectedAge = 30;
			break;
		case 4:
			selectedAge = 40;
			break;
		default:
			break;
		} 
		map<string, UserData>::iterator iter;
		for (iter = storage.begin(); iter != storage.end(); ++iter) {
			if (selectedAge != 40) {
				if (selectedAge <= iter->second.age && selectedAge + 10 > iter->second.age) {
					cout << "이름 : " << iter->first << endl;
					if (iter->second.sex == 1)
						printf("성별 : 남자\n");
					else
						printf("성별 : 여자\n");
					printf("나이 : %d\n", iter->second.age);
				}
			}
			else {
				if (selectedAge <= iter->second.age) {
					cout << "이름 : " << iter->first << endl;
					if (iter->second.sex == 1)
						printf("성별 : 남자\n");
					else
						printf("성별 : 여자\n");
					printf("나이 : %d\n", iter->second.age);
				}
			}
		}
	}
	else {
		printf("옵션을 잘 못 입력하셨습니다. 메인 메뉴로 돌아갑니다.");
	}
	char continued;
	printf("메인 화면으로 이동하려면 아무 키나 입력하세요\n");
	scanf_s("%s", &continued, 1);
}