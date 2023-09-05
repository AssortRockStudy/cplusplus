#include "app.h"



void app::run()
{

	while (true)
	{
		system("cls");

		int inp;

		cout << "1. 회원 정보 등록" << endl;
		cout << "2. 회원 정보 출력" << endl;
		cout << "3. 회원 정보 검색" << endl;
		cout << "4. 회원 정보 수정" << endl;
		cout << "5. 회원 정보 삭제" << endl;
		cout << "6. 끝내기" << endl;

		cin >> inp;

		if (inp < 1 || inp >6)
		{
			cout << endl << "잘못된 번호입니다." << endl;
			_getch();
			continue;
		}

		if (inp == 1)
		{
			userRegister();
		}
		else if (inp == 2)
		{
			userPrint();
		}
		else if (inp == 3)
		{
			userSearch();
		}
		else if (inp == 4)
		{
			userEdit();
		}
		else if (inp == 5)
		{
			userDel();
		}
		else if (inp == 6)
		{
			break;
		}

	}

}

void app::userRegister()
{
	while (true)
	{
		system("cls");

		tUser* user = new tUser;

		cout << "회원 등록" << endl;
		cout << "이름을 입력하세요." << endl;
		cin >> user->Name;
		cout << endl;

		cout << "성별을 입력해주세요(남자1, 여자2) " << endl;
		cin >> user->Sex;
		cout << endl;

		cout << "나이를 입력하세요." << endl;
		cin >> user->Age;
		cout << endl;

		int inp;
		cout << "그룹을 입력하세요(1~3)." << endl;
		cin >> inp;
		user->Type = (GROUP_TYPE)inp;
		cout << endl;

		// 중복 체크
		bool flag = false;
		for (int i = 0; i < m_vecUser.size(); ++i)
		{
			if (m_vecUser[i]->Name == user->Name && m_vecUser[i]->Age == user->Age && m_vecUser[i]->Sex == user->Sex && m_vecUser[i]->Type == user->Type)
				flag = true;
		}

		if (!flag)
		{
			m_vecUser.push_back(user);
		}

		cout << "1. 추가 입력" << endl;
		cout << "2. 메인 화면" << endl;
		cout << "입력 : ";
		cin >> inp;

		if (inp == 2)
		{
			break;
		}
	}

}

bool desc(tUser* first, tUser* second)
{
	return first->Name > second->Name;
}

bool asc(tUser* first, tUser* second)
{
	return first->Name < second->Name;
}

void app::userPrint()
{
	system("cls");

	int inp;
	cout << "유저의 정보를 출력합니다.(1:오름차순, 2:내림차순)" << endl << endl;
	cin >> inp;

	if (inp == 1)
	{
		sort(m_vecUser.begin(), m_vecUser.end(),asc);
	}
	else if (inp == 2)
	{
		sort(m_vecUser.begin(), m_vecUser.end(), desc);
	}
	else 
	{
		cout << "잘못 입력하셨습니다.";
		_getch();
		return;
	}

	for (int i = 0; i < m_vecUser.size(); ++i)
	{
		cout << i << " 번 째 User " << endl;

		m_vecUser[i]->print();

		cout << endl;
	}

	_getch();
}

void app::userSearch()
{
	system("cls");

	string target;
	cout << "검색하실 유저의 이름을 입력해주세요.\n";
	cin >> target;


	int flag = -1;
	for (int i = 0; i < m_vecUser.size(); ++i)
	{
		if (m_vecUser[i]->Name == target)
			flag = i;
	}

	if (flag == -1)
	{
		cout << "해당 이름을 가진 유저를 찾을 수 없습니다.\n";
		_getch();
	}
	else
	{
		m_vecUser[flag]->print();
		_getch();
	}
}

void app::userEdit()
{
	string target;
	cout << "수정하실 유저의 이름을 입력해주세요.\n";
	cin >> target;

	int flag = -1;
	for (int i = 0; i < m_vecUser.size(); ++i)
	{
		if (m_vecUser[i]->Name == target)
			flag = i;
	}

	if (flag == -1)
	{
		cout << "해당 이름을 가진 유저를 찾을 수 없습니다.\n";
		_getch();
	}
	else
	{
		int inp;
		cout << "변경하실 정보를 입력해주세요(1.이름, 2:성별, 3:나이, 4:그룹)\n";
		cin >> inp;

		switch (inp)
		{
		case 1:
			cout << "수정하실 이름을 입력해주세요.\n";
			cin >> m_vecUser[flag]->Name;

			break;
		case 2:
			cout << "수정하실 성별을 입력해주세요(남자:1, 여자:2).\n";
			cin >> m_vecUser[flag]->Sex;
			break;
		case 3:
			cout << "수정하실 나이을 입력해주세요.\n";
			cin >> m_vecUser[flag]->Age;
			break;
		case 4:
			cout << "수정하실 그룹을 입력해주세요.\n";
			int tmp;
			cin >> tmp;
			m_vecUser[flag]->Type = (GROUP_TYPE)tmp;
			break;

		default:
			cout << "잘못 입력하셨습니다.\n";
			break;
		}


		cout << "정보가 수정되었습니다.\n";
		_getch();
	}

}

void app::userDel()
{
	system("cls");

	string target;
	cout << "삭제하실 유저의 이름을 입력해주세요.\n";
	cin >> target;


	vector<tUser*>::iterator iter = m_vecUser.begin();

	for (; iter!=m_vecUser.end(); ++iter)
	{
		if ((*iter)->Name == target)
		{
			break;
		}
	}



	if (iter == m_vecUser.end())
	{
		cout << "해당 이름을 가진 유저를 찾을 수 없습니다.\n";
	}
	else
	{
		delete *iter;
		m_vecUser.erase(iter);
	}

	cout << "해당 유저의 정보가 삭제되었습니다.\n";
	_getch();
}
