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
    int input;
    while (true) {
        cout << "1. 회원 정보 추가" << endl;
        cout << "2. 회원 모두 출력" << endl;
        cout << "3. 끝내기" << endl;

        cout << "실행할 번호를 입력해주세요: ";
        cin >> input;
        system("cls");
        if (input < Menu::INPUT || input > Menu::END) {
            cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
        } else {
            break;
        }
    }

    return input;
};

void MemberManager::printWelcomMsg() {
    cout << "안녕하세요 회원 정보 관리 시스템입니다!" << endl;
};

void MemberManager::printByeMsg() {
    system("cls");
    cout << "이용해주셔서 감사합니다!" << endl;
};
