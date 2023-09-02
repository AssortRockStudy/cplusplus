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
        case Menu::PRINT_FILTER:
            printFilteredMember();
            break;
        case Menu::MODIFY:
            modifyMember();
            break;
        case Menu::ERASE:
            eraseMember();
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
        cout << Menu::PRINT_FILTER << ". 회원 필터 출력" << endl;
        cout << Menu::MODIFY << ". 회원 정보 수정" << endl;
        cout << Menu::ERASE << ". 회원 정보 삭제" << endl;
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
list<MemberManager::Member*>::iterator
MemberManager::searchMemberByName(const string& name) {
    auto first = members.begin();
    auto last = members.end();
    while (first != last) {
        if ((*first)->name->data == name)
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

void MemberManager::modifyMember() {
    string name;
    system("cls");

    cout << "변경할 회원의 이름을 입력해주세요: ";
    cin >> name;

    auto member = searchMemberByName(name);

    if (member == members.end()) {
        cout << "해당 이름의 회원이 없습니다." << endl;

    } else {
        bool loop = true;
        int  mask = 0;
        while (loop) {
            loop = false;

            int idx = 0;
            cout << Member::Attribute::ALL << ". 모든 정보" << endl;
            cout << Member::Attribute::NAME << ". 이름" << endl;
            cout << Member::Attribute::AGE << ". 나이" << endl;
            cout << Member::Attribute::SEX << ". 성별" << endl;
            cout << Member::Attribute::GROUP << ". 그룹" << endl;

            cout << "수정할 정보를 선택하세요: ";
            cin >> idx;
            cin.clear();
            cin.ignore(256, '\n');

            switch (idx) {
            case Member::Attribute::ALL:
                mask |= INPUT_ALL;
                break;
            case Member::Attribute::NAME:
                mask |= INPUT_NAME;
                break;
            case Member::Attribute::AGE:
                mask |= INPUT_AGE;
                break;
            case Member::Attribute::SEX:
                mask |= INPUT_SEX;
                break;
            case Member::Attribute::GROUP:
                mask |= INPUT_GROUP;
                break;
            default:
                system("cls");
                cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
                loop = true;
                break;
            }
        }
        modifyMemberByAttribute(member, mask);
    }
    printGoMainMenu();
}

void MemberManager::modifyMemberByAttribute(std::list<Member*>::iterator& _it,
                                            int _mask) {
    if (_mask & INPUT_NAME) {
        cout << "변경할 이름을 입력해주세요: ";
        cin >> (*_it)->name->data;
    }
    if (_mask & INPUT_SEX) {
        cout << "변경할 성별을 입력해주세요(남성: 1, 여성: 2): ";
        cin >> (*_it)->sex->data;
        cin.clear();
        cin.ignore(256, '\n');
    }
    if (_mask & INPUT_AGE) {
        cout << "변경할 나이를 입력해주세요: ";
        cin >> (*_it)->age->data;
        cin.clear();
        cin.ignore(256, '\n');
    }
    if (_mask & INPUT_GROUP) {
        cout << "변경할 그룹을 입력해주세요: ";
        cin >> (*_it)->group->data;
    }
}

bool MemberManager::isDuplicate(Member* _chk) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if ((*(*it)) == *_chk)
            return true;
    }
    return false;
}

void MemberManager::inputMember() {
    cout << "회원 정보 입력 기능입니다. " << endl << endl;
    int more = 0;
    while (true) {
        Member* newMember = new Member;
        while (true) {
            // 멤버 입력용 출력
            // cin.clear();
            // cin.ignore(256, '\n');
            // cout << "이름을 입력해주세요: ";
            // cin >> newMember.name;
            // cout << "성별을 입력해주세요(남성: 1, 여성: 2): ";
            // cin >> newMember.sex;
            // cin.clear();
            // cin.ignore(256, '\n');
            // cout << "나이를 입력해주세요: ";
            // cin >> newMember.age;
            // cin.clear();
            // cin.ignore(256, '\n');
            // cout << "그룹을 입력해주세요: ";
            // cin >> newMember.group;
            newMember->inputData();

            if (newMember->isValid()) {
                if (!isDuplicate(newMember)) {
                    break;
                } else {
                    cout << "중복되는 회원입니다! " << endl << endl;
                }
            } else {
                cout << "유효하지 않은 정보입니다. " << endl << endl;
            }

            int quit = 0;
            cout << "그만 입력하시겠습니까(yes: 1, no: 0): ";
            cin >> quit;
            cin.clear();
            cin.ignore(256, '\n');
            if (quit) {
                break;
            }
        }

        members.push_back(newMember);
        curCount++;

        cout << "추가로 회원을 입력하시겠습니까(yes: 1, no: 0): ";

        cin >> more;
        cin.clear();
        cin.ignore(256, '\n');

        if (!more) {
            break;
        } else {
            cout << endl << "====================== 멤버 추가" << endl << endl;
        }
    }
    system("cls");
}

bool MemberManager::isAscending() {
    while (true) {
        int answer = 0;
        cout << "정렬방법을 선택해주세요(오름차순: 1, 내림차순: 2): ";
        cin >> answer;
        cin.clear();
        cin.ignore(256, '\n');
        if (answer == 1) {
            return true;
        } else if (answer == 2) {
            return false;
        } else {
            cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
        }
    }
}

void MemberManager::printAllMember() {
    if (curCount == 0) {
        cout << "입력된 회원 정보가 없습니다." << endl;
        printGoMainMenu();
        return;
    }

    bool ascending = isAscending();
    members.sort();
    if (!ascending) {
        members.reverse();
    }

    for (auto it = members.begin(); it != members.end(); ++it) {
        (*it)->printData();
    }
    cout << "=====================" << endl << endl;
    cout << "총 " << curCount << "명 입니다." << endl;

    printGoMainMenu();
}

void MemberManager::printFilteredMember() {
    if (curCount == 0) {
        cout << "입력된 회원 정보가 없습니다." << endl;
        printGoMainMenu();
        return;
    }

    int filteredSex;
    while (true) {
        cout << "어떤 성별만 확인할 지 고르세요(1. 남성, 2. 여성, 3.모두): ";
        cin >> filteredSex;
        cin.clear();
        cin.ignore(256, '\n');
        if (filteredSex >= 1 && filteredSex <= 3) {
            break;
        } else {
            cout << "잘못된 입력입니다. 다시입력하세요 " << endl;
        }
    }

    int ageQuot;
    while (true) {
        cout
            << "어떤 나이대를 확인할 지 고르세요(1. 10대, 2. 20대, 3. 30대, 4. "
               "40대, 5. 이외, 6. 모두)"
            << endl;
        cin >> ageQuot;
        cin.clear();
        cin.ignore(256, '\n');
        if (ageQuot >= 1 && ageQuot <= 6) {
            break;
        } else {
            cout << "잘못된 입력입니다. 다시입력하세요 " << endl;
        }
    }

    int cnt = 0;
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (filteredSex == (*it)->sex->data || filteredSex == 3) {
            cnt++;
            if (ageQuot == 6) {
                cout << *it << endl;

            } else if ((*it)->age->data / 10 == ageQuot) {
                cout << **it << endl;
            } else if (ageQuot == 5 && (((*it)->age->data / 10) >= ageQuot)) {
                cout << (**it) << endl;
            } else {
                cnt--;
            }
        }
    }
    cout << "총 " << cnt << "명 입니다." << endl;

    printGoMainMenu();
}

void MemberManager::printMember(list<Member*>::iterator& it) {
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

void MemberManager::eraseMember() {
    if (curCount == 0) {
        cout << "입력된 회원 정보가 없습니다." << endl;
        printGoMainMenu();
        return;
    }
    string dName;
    cout << "삭제할 멤버의 이름을 입력하세요: ";
    cin >> dName;

    auto it = searchMemberByName(dName);

    if (it == members.end()) {
        cout << "해당 이름의 멤버가 없습니다." << endl;

    } else {
        members.erase(it);
        curCount--;
        cout << "성공적으로 삭제되었습니다. " << endl;
    }

    printGoMainMenu();
}

void MemberManager::printGoMainMenu() {
    uint32_t wait;
    cout << endl << "아무키나 입력시 메인 메뉴로 돌아갑니다." << endl;

    cin >> wait;
    cin.clear();
    cin.ignore(256, '\n');

    system("cls");
}