#include <iostream>
#include <conio.h>
#include <Windows.h>

char u_Name[100][10] = {};
int u_Sex[100] = {};
int u_Age[100] = {};

int u_Count = 0;


void initUser()
{
	while (true)
	{
		system("cls");
		int answer = 0;
		if (u_Count > 99)
		{
			printf("�� �̻� �߰��� �� �����ϴ�. �ƹ� ���� �Է��ϸ� ���� ȭ������ �����մϴ�...");
			scanf_s("%d", &answer);
		}
		printf("�̸� �Է�(���� ���� �ִ� 9����, ����): ");
		scanf_s("%9s", &u_Name[u_Count], sizeof(u_Name[u_Count] - 1));
		printf("���� �Է�(����-> 1, ����-> 2): ");
		scanf_s("%d", &u_Sex[u_Count]);		
		printf("���� �Է�: ");
		scanf_s("%d", &u_Age[u_Count]);

		++u_Count;

		printf("ȸ�� ����� �� �� �� �����ұ��? (yes-> 1, no-> 2): ");
		scanf_s("%d", &answer);

		if (answer == 2)
		{
			break;
		}

	}
}

void printUser()
{
	system("cls");
	int i = 0;
	for (; i < u_Count; ++i)
	{
		printf("+++++���� %d\n", i + 1);
		printf("- ���� �̸�: %s\n", u_Name[i]);
		printf("- ���� ����: %s\n", u_Sex[i] == 1 ? "����" : "����");
		printf("- ���� ����: %d\n", u_Age[i]);
	}
	printf("��� ȸ���� ����߽��ϴ�. �ƹ� ���ڸ� �Է��ϸ� ���� ȭ������ �����մϴ�...");
	_getwch();
}

int main()
{
	while (true)
	{
		system("cls");
		int answer = 0;
		printf("+++++ȸ������ ����� ���α׷�+++++\n");
		printf("1. ȸ�� ���\n");
		printf("2. ȸ�� ���� ���\n");
		printf("3. ������\n\n\n");
		printf("���ϴ� ����� �Է��ϼ���: ");

		scanf_s("%d", &answer);
		switch (answer) // ���ӵ� ������ case�� jump table�� ���
		{
		case 1:
			initUser();
			break;
		case 2:
			printUser();
			break;
		case 3:
			printf("���α׷��� �����մϴ�.\n");
			return 0;
			break;
		default:
			break;
		}
	}
}