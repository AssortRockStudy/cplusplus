#pragma once

struct Member
{
	char name[10];
	int gender;
	int age;
};

struct Members
{
	int curCnt;
	int maxCnt;
	Member* member;
};

void initM(Members* ms)
{
	ms->curCnt = 0;
	ms->maxCnt = 10;
	ms->member = (Member*) malloc(sizeof(Member) * 10);
	//ms->member[ms->maxCnt-1];
}

void resize(Members* ms)
{
	//Member* newM = (Member*)malloc(sizeof(Member) * 10* 2);


	//for (int i = 0; i < ms->curCnt; ++i)
	//{
	//	newM[i].name = ms->member[i].name;
	//	newM[i].gender = ms->member[i].gender;
	//	newM[i].age = ms->member[i].age;
	//}
}



void freeM(Members *ms)
{
	ms->curCnt = 0;
	ms->maxCnt = 10;
	free(ms->member);

}