#include "memberManager.h"

#include <Windows.h>
#include <algorithm>

void MemberManager::Run() {
    bool quit = false;
    printWelcomMsg();
    while (!quit) {
        int select = inputMenu();
        switch (select) {
        case Menu::INPUT:
            inputMember();
            break;
        case Menu::SEARCH_NAME:
            searchByName();
            break;
        case Menu::PRINTALL:
            printAllMember();
            break;
        case Menu::QUIT:
            printByeMsg();
            quit = true;
            break;
        }
    }
};

//
int MemberManager::inputMenu() {
    int input;
    while (true) {
        cout << Menu::INPUT << ". 회원 정보 추가" << endl;
        cout << Menu::SEARCH_NAME << ". 회원 이름으로 검색" << endl;
        cout << Menu::PRINTALL << ". 회원 모두 출력" << endl;
        cout << Menu::QUIT << ". 끝내기" << endl;

        cout << endl << "실행할 번호를 입력해주세요: ";
        cin >> input;
        system("cls");
        if (input < Menu::INPUT || input > Menu::END) {
            cout << "잘못된 입력입니다. 다시 입력해주세요" << endl << endl;
        } else {
            break;
        }
    }

    return input;
};
list<MemberManager::Member>::iterator
MemberManager::searchMemberByName(const string& name) {

    auto first = members.begin();
    auto last = members.end();
    while (first != last) {
        if (first->name == name)
            break;
        ++first;
    }
    return first;
}
void MemberManager::searchByName() {
    // 이름으로 탐색
    // 찾으면 Member 리턴, 못찾으면 nullptr 리턴
    // vector 순회? map과 vector 둘 다 갖고있기?'

    system("cls");
    string name;
    cout << "검색할 이름을 입력해주세요: ";
    cin >> name;

    auto member = searchMemberByName(name);
    printMember(member);

    printGoMainMenu();
}

void MemberManager::inputMember() {
    cout << "회원 정보 입력 기능입니다. " << endl << endl;
    int more = 0;
    while (true) {
        Member newMember;
        while (true) {
            // 멤버 입력용 출력
            cin.clear();
            cout << "이름을 입력해주세요: ";
            cin >> newMember.name;
            cout << "성별을 입력해주세요(남성: 1, 여성: 2): ";
            cin >> newMember.sex;
            cout << "나이를 입력해주세요: ";
            cin >> newMember.age;

            if (newMember.isValid()) {
                break;
            } else {
                cout << "유효하지 않은 정보입니다. " << endl << endl;
            }
        }

        members.push_back(newMember);
        curCount++;

        cout << "추가로 회원을 입력하시겠습니까(yes: 1, no: 0): ";

        cin >> more;

        if (!more) {
            break;
        } else {
            cout << endl << "====================== 멤버 추가" << endl << endl;
        }
    }
    system("cls");
}

void MemberManager::printAllMember() {
    if (curCount == 0) {
        cout << "입력된 회원 정보가 없습니다." << endl;
    }
    for (auto it = members.begin(); it != members.end(); ++it) {
        cout << "=====================" << endl << endl;
        cout << *it << endl << endl;
    }
    cout << "=====================" << endl << endl;
    cout << "총 " << curCount << "명 입니다." << endl;

    printGoMainMenu();
}

void MemberManager::printMember(list<MemberManager::Member>::iterator& it) {
    if (it == members.end()) {
        cout << "존재하지 않는 회원입니다." << endl;
    } else {
        cout << *it;
    }
}

void MemberManager::printWelcomMsg() {
    cout << "안녕하세요 회원 정보 관리 시스템입니다!" << endl;
};

void MemberManager::printByeMsg() {
    system("cls");
    cout << "이용해주셔서 감사합니다!" << endl;
};

bool MemberManager::Member::isValid() {
    bool valid = false;
    // name 검증은 나중에

    if (this->sex == Sex::MAN || this->sex == Sex::WOMAN) {
        valid = true;
    } else {
        return false;
    }

    if (age > 0 && age < 120) {
        valid = true;
    } else {
        return false;
    }

    return valid;
}

void MemberManager::printGoMainMenu() {
    uint32_t wait;
    cout << endl << "아무키나 입력시 메인 메뉴로 돌아갑니다." << endl;

    cin >> wait;
    cin.clear();
    cin.ignore(256, '\n');

    system("cls");
}