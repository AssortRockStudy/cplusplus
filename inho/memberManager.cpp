#include "memberManager.h"

#include <Windows.h>

void MemberManager::Start() {
    bool quit = false;
    while (!quit) {
        printWelcomMsg();
        int select = inputMenu();
        switch (select) {
        case Menu::INPUT:
            break;
        case Menu::PRINTALL:
            break;
        case Menu::QUIT:
            quit = true;
            break;
        }
    }
};

//
int MemberManager::inputMenu() {
    cout << "menu is open " << endl;
    int input;
    while (true) {
        cout << "1. ȸ�� ���� �߰�" << endl;
        cout << "2. ȸ�� ��� ���" << endl;
        cout << "3. ������" << endl;
       
        
        cin >> input;
        system("cls");
        if (input < Menu::INPUT || input > Menu::END) {
            
        }
        else {
            break;
        }
    }

    return input;
};

void MemberManager::printWelcomMsg() {
    cout << "�ȳ��ϼ��� ȸ�� ���� ���� �ý����Դϴ�!" << endl;
};
