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
        cout << "1. 회원 정보 추가" << endl;
        cout << "2. 회원 모두 출력" << endl;
        cout << "3. 끝내기" << endl;
       
        
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
    cout << "안녕하세요 회원 정보 관리 시스템입니다!" << endl;
};
