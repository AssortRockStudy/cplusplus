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

struct UserData {
	bool sex;
	char age;
	string group;
};

bool duplicateCheck(string name);
void save(string name, const UserData&);
void saveUser();
void findUser();
void printAllData();
void printFilteredData();
void printData(map<string, UserData>::iterator);
void printData(map<string, UserData>::reverse_iterator);
void modifyUser();
void eraseUser();

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
		printf("5. 회원 정보 수정\n");
		printf("6. 회원 삭제\n");
		printf("7. 종료\n");
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
			modifyUser();
			break;
		case 6:
			eraseUser();
			break;
		case 7:
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
		printf("성별 입력(남자는 0, 여자는 1)\n");
		scanf_s("%hhd", &user.sex);
		printf("나이 입력\n");
		scanf_s("%hhd", &user.age);
		printf("그룹 입력\n");
		cin >> user.group;
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
		printData(iter);
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
	int cnt = 1;
	if (reverse) {
		map<string, UserData>::iterator iter;
		for (iter = storage.begin(); iter != storage.end(); ++iter) {
			printf("회원 %d\n", cnt);
			printData(iter);
			++cnt;
			cout << endl;
		}
	}
	else {
		map<string, UserData>::reverse_iterator iter;
		for (iter = storage.rbegin(); iter != storage.rend(); ++iter) {
			printf("회원 %d\n", cnt);
			printData(iter);
			++cnt;
			cout << endl;
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
		bool selectedSex;
		if (1 == sel) 
			selectedSex = false;
		else 
			selectedSex = true;
		map<string, UserData>::iterator iter;
		for (iter = storage.begin(); iter != storage.end(); ++iter) {
			if (selectedSex == iter->second.sex) {
				printData(iter);
				cout << endl;
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
		int selectedAge;
		while (true) {
			cin >> selectedAge;
			if (0 <= selectedAge <= 4)
				break;
			else {
				cout << "잘못된 숫자를 입력하셨습니다. 다시 입력해 주세요.";
			}
		}
		map<string, UserData>::iterator iter;
		for (iter = storage.begin(); iter != storage.end(); ++iter) {
			if (selectedAge < 4) {
				if (selectedAge*10 <= iter->second.age && selectedAge*10 + 10 > iter->second.age) {
					printData(iter);
					cout << endl;
				}
			}
			else {
				if (selectedAge * 10 <= iter->second.age) {
					printData(iter);
					cout << endl;
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

void printData(map<string, UserData>::iterator iter) {
	cout << "이름 : " << iter->first << endl;
	if (iter->second.sex == false)
		printf("성별 : 남자\n");
	else
		printf("성별 : 여자\n");
	printf("나이 : %d\n", iter->second.age);
	cout << "그룹 : " << iter->second.group << endl;
}

void printData(map<string, UserData>::reverse_iterator iter) {
	cout << "이름 : " << iter->first << endl;
	if (iter->second.sex == false)
		printf("성별 : 남자\n");
	else
		printf("성별 : 여자\n");
	printf("나이 : %d\n", iter->second.age);
	cout << "그룹 : " << iter->second.group << endl;
}

void eraseUser() {
	string name;
	system("cls");
	printf("삭제하고 싶은 정보의 이름을 입력해주세요.\n");
	cin >> name;
	if (duplicateCheck(name)) {
		map<string, UserData>::iterator iter = storage.find(name);
		storage.erase(iter);
		cout << "삭제되었습니다.\n" << endl;
	}
	else
		cout << "해당되는 이름의 회원이 없습니다.\n" << endl;
	char continued;
	printf("메인 화면으로 이동하려면 아무 키나 입력하세요\n");
	scanf_s("%s", &continued, 1);
}

void modifyUser()
{
	string name;
	system("cls");
	printf("수정하고 싶은 정보의 이름을 입력해주세요.\n");
	cin >> name;
	if (duplicateCheck(name)) {
		map<string, UserData>::iterator iter = storage.find(name);
		printData(iter);
		int sel = -1;
		cout << "이름을 변경하시려면 1 아니면 아무 키를 입력해주세요.\n";
		cin >> sel;
		if (sel == 1) {
			cout << "기존 정보 삭제 후 새로 저장됩니다.\n" << endl;
			storage.erase(iter);
			cout << "회원 등록 탭으로 이동합니다. 아무 키나 입력하세요\n" << endl;
			char continued;
			scanf_s("%s", &continued, 1);
			saveUser();
		}
		else {
			cout << "나이 변경" << endl;
			cin >> iter->second.age;
			cout << "성별 변경을 하시려면 1 아니면 아무 키를 입력해주세요." << endl;
			int change = 0;
			cin >> change;
			if (change == 1)
				iter->second.sex = !(iter->second.sex);
			cout << "그룹 변경" << endl;
			cin >> iter->second.group;
		}
	}
	else
		cout << "해당되는 이름의 회원이 없습니다.\n" << endl;
	char continued;
	printf("메인 화면으로 이동하려면 아무 키나 입력하세요\n");
	scanf_s("%s", &continued, 1);
}
