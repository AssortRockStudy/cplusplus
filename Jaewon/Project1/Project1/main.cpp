#include <iostream>
#include <Windows.h>

struct User {
	char name[20];
	char sex;
};

struct Storage{
	User u[200];
	int uCnt;
};

void save(const User&);
void saveUser();
void printData();

Storage s;

int main() {
	bool flag = true;
	while (flag) {
		int input;
		system("cls");
		printf("1. 회원등록\n");
		printf("2. 회원 모두 출력\n");
		printf("3. 종료\n");
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
			flag = false;
			break;
		default:
			break;
		}
	}
	return 0;
}

void save(const User& q) {
	if (s.uCnt < 200) {
		s.u[s.uCnt++] = q;
	}
}


void saveUser() {
	while (true) {
		system("cls");
		printf("이름 입력\n");
		User user = {};
		scanf_s("%s", &user.name, sizeof(user.name));
		printf("성별 입력(남자는 1, 여자는 2)\n");
		scanf_s("%hhd", &user.sex);
		save(user);
		int flag = 0;
		printf("추가로 저장하시겠습니까?(y=1/n=0)\n");
		scanf_s("%d", &flag);
		if (flag == 0)
			break;
	}
}

void printData() {
	system("cls");
	for (int i = 0; i < s.uCnt; ++i) {
		printf("회원 %d\n", i + 1);
		printf("이름 : %s\n", s.u[i].name);
		if (s.u[i].sex == 1)
			printf("성별 : 남자\n");
		else
			printf("성별 : 여자\n");
	}
	char con;
	printf("메인 화면으로 이동하려면 아무 키나 입력하세요\n");
	scanf_s("%s", &con, 1);
}

