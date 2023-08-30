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

struct UserData {
	char sex;
	char age;
};

bool duplicateCheck(string name);
void save(string name, const UserData&);
void saveUser();
void findUser();
void printData();

map<string, UserData> storage;

int main() {
	bool flag = true;
	while (flag) {
		int input;
		system("cls");
		printf("1. 회원등록\n");
		printf("2. 회원 모두 출력\n");
		printf("3. 회원 검색\n");
		printf("4. 종료\n");
		scanf_s("%d", &input);

		switch (input)
		{
		case 1:
			saveUser();
			break;
		case 2:
			printData();
			break;
		case 3:
			findUser();
			break;
		case 4:
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

void printData() {
	system("cls");
	map<string, UserData>::iterator iter;
	int cnt = 0;
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
	char continued;
	printf("메인 화면으로 이동하려면 아무 키나 입력하세요\n");
	scanf_s("%s", &continued, 1);
}

