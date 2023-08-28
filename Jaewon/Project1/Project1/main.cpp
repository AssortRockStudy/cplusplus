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
		printf("1. ȸ�����\n");
		printf("2. ȸ�� ��� ���\n");
		printf("3. ����\n");
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
		printf("�̸� �Է�\n");
		User user = {};
		scanf_s("%s", &user.name, sizeof(user.name));
		printf("���� �Է�(���ڴ� 1, ���ڴ� 2)\n");
		scanf_s("%hhd", &user.sex);
		save(user);
		int flag = 0;
		printf("�߰��� �����Ͻðڽ��ϱ�?(y=1/n=0)\n");
		scanf_s("%d", &flag);
		if (flag == 0)
			break;
	}
}

void printData() {
	system("cls");
	for (int i = 0; i < s.uCnt; ++i) {
		printf("ȸ�� %d\n", i + 1);
		printf("�̸� : %s\n", s.u[i].name);
		if (s.u[i].sex == 1)
			printf("���� : ����\n");
		else
			printf("���� : ����\n");
	}
	char con;
	printf("���� ȭ������ �̵��Ϸ��� �ƹ� Ű�� �Է��ϼ���\n");
	scanf_s("%s", &con, 1);
}

