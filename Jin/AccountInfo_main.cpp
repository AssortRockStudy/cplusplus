#include <iostream>
#include <stdlib.h>
#include "member.h"



//ȸ�� ����� �̸�, ����(��1, ��2), ���̸� �Է¹ް� �߰��� �Է� ���� �������� ����� �߰��Է°� ����ȭ�� �б�


void AddMembers(Members * ms);
void OutputMember(Members* ms);

int main()
{
	Members members = {};
	initM(&members);

	int sel = 0;
	while (sel != 3)
	{
		printf(" ================================ \n");
		printf(" < ȸ�� ���� �ý��� >\n");
		printf(" 1. ȸ�� ��� \n");
		printf(" 2. ȸ�� ���� ��� \n");
		printf(" 3. ������\n");
		printf(" ��� ����  : ");
		scanf_s("%d", &sel);

		switch (sel)
		{
		case 1:
			AddMembers(&members);
			break;
		case 2:
			OutputMember(&members);
			break;
		case 3:
			break;
		default:
			printf(" �ùٸ� ���ڸ� �Է����ּ���. \n");
			break;
		}
	}
	freeM(&members);
	return 0;
}

//ȸ�� ����� �̸�, ����(��1, ��2), ���̸� �Է¹ް� �߰��� �Է� ���� �������� ����� �߰��Է°� ����ȭ�� �б�
void AddMembers(Members* ms)
{
	system("cls");
	printf(" ================================ \n");
	if (ms->curCnt >= ms->maxCnt)
	{
		//resize();
		exit(0);
	}
	else
	{
		printf(" ȸ�� ���� : ");
		scanf_s("%s", ms->member[ms->curCnt].name, 10);
		printf(" \n ȸ�� ���� (���� 1, ���� 2)  : ");
		scanf_s("%d", ms->member[ms->curCnt].gender);
		printf(" \n ȸ�� ���� : ");
		scanf_s("%d", ms->member[ms->curCnt].age);
		++ms->curCnt;
	}

	printf(" \n ȸ���� �� �Է��Ͻðڽ��ϱ� ? (Yes : 1, No : 2) : ");
	int yn = 0;
	scanf_s("%d", yn);
	if (yn == 1)
	{
		return AddMembers(ms);
	}
	printf(" ================================ \n");
}

//ȸ�� ���� ����� ���� �Է¹��� ȸ���� ��� ����ϸ� ����ȭ������
void OutputMember(Members *ms)
{
	system("cls");
	printf(" ================================ \n");
	for (int i = 0; i >= ms->curCnt; ++i)
	{
		printf(" ȸ�� ���� :%s\n", ms->member[i].name);
		if ((ms->member[i].age) == 1) { printf(" ȸ�� ���� : ����\n "); }
		else { printf("ȸ�� ���� : ����\n"); }
		printf(" ȸ�� ���� :%s��\n", ms->member[i].age);
	}
	printf(" ================================ \n");
}