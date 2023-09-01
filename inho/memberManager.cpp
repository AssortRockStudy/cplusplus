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
        cout << Menu::INPUT << ". ȸ�� ���� �߰�" << endl;
        cout << Menu::SEARCH_NAME << ". ȸ�� �̸����� �˻�" << endl;
        cout << Menu::PRINTALL << ". ȸ�� ��� ���" << endl;
        cout << Menu::PRINT_FILTER << ". ȸ�� ���� ���" << endl;
        cout << Menu::MODIFY << ". ȸ�� ���� ����" << endl;
        cout << Menu::ERASE << ". ȸ�� ���� ����" << endl;
        cout << Menu::QUIT << ". ������" << endl;

        cout << endl << "������ ��ȣ�� �Է����ּ���: ";
        cin >> input;
        system("cls");
        if (input < Menu::INPUT || input > Menu::END) {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���" << endl << endl;
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
    // �̸����� Ž��
    // ã���� Member ����, ��ã���� nullptr ����
    // vector ��ȸ? map�� vector �� �� �����ֱ�?'

    system("cls");
    string name;
    cout << "�˻��� �̸��� �Է����ּ���: ";
    cin >> name;

    auto member = searchMemberByName(name);
    printMember(member);

    printGoMainMenu();
}

void MemberManager::modifyMember() {
    string name;
    system("cls");

    cout << "������ ȸ���� �̸��� �Է����ּ���: ";
    cin >> name;

    auto member = searchMemberByName(name);

    if (member == members.end()) {
        cout << "�ش� �̸��� ȸ���� �����ϴ�." << endl;

    } else {
        bool loop = true;
        int  mask = 0;
        while (loop) {
            loop = false;

            int idx = 0;
            cout << Member::Attribute::ALL << ". ��� ����" << endl;
            cout << Member::Attribute::NAME << ". �̸�" << endl;
            cout << Member::Attribute::AGE << ". ����" << endl;
            cout << Member::Attribute::SEX << ". ����" << endl;

            cout << "������ ������ �����ϼ���: ";
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
            default:
                system("cls");
                cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���" << endl;
                loop = true;
                break;
            }
        }
        modifyMemberByAttribute(member, mask);
    }
    printGoMainMenu();
}

void MemberManager::modifyMemberByAttribute(std::list<Member>::iterator& _it,
                                            int _mask) {
    if (_mask & INPUT_NAME) {
        cout << "������ �̸��� �Է����ּ���: ";
        cin >> _it->name;
    }
    if (_mask & INPUT_SEX) {
        cout << "������ ������ �Է����ּ���(����: 1, ����: 2): ";
        cin >> _it->sex;
    }
    if (_mask & INPUT_AGE) {
        cout << "������ ���̸� �Է����ּ���: ";
        cin >> _it->age;
    }
}

bool MemberManager::isDuplicate(const Member& _chk) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (*it == _chk)
            return true;
    }
    return false;
}

void MemberManager::inputMember() {
    cout << "ȸ�� ���� �Է� ����Դϴ�. " << endl << endl;
    int more = 0;
    while (true) {
        Member newMember;
        while (true) {
            // ��� �Է¿� ���
            cin.clear();
            cout << "�̸��� �Է����ּ���: ";
            cin >> newMember.name;
            cout << "������ �Է����ּ���(����: 1, ����: 2): ";
            cin >> newMember.sex;
            cout << "���̸� �Է����ּ���: ";
            cin >> newMember.age;

            if (newMember.isValid()) {
                if (!isDuplicate(newMember)) {
                    break;
                } else {
                    cout << "�ߺ��Ǵ� ȸ���Դϴ�! " << endl << endl;
                }
            } else {
                cout << "��ȿ���� ���� �����Դϴ�. " << endl << endl;
            }
            int quit = 0;
            cout << "�׸� �Է��Ͻðڽ��ϱ�(yes: 1, no: 0): ";
            cin >> quit;
            cin.clear();
            cin.ignore(256, '\n');
            if (quit) {
                break;
            }
        }

        members.push_back(newMember);
        curCount++;

        cout << "�߰��� ȸ���� �Է��Ͻðڽ��ϱ�(yes: 1, no: 0): ";

        cin >> more;
        cin.clear();
        cin.ignore(256, '\n');

        if (!more) {
            break;
        } else {
            cout << endl << "====================== ��� �߰�" << endl << endl;
        }
    }
    system("cls");
}

bool MemberManager::isAscending() {
    while (true) {
        int answer = 0;
        cout << "���Ĺ���� �������ּ���(��������: 1, ��������: 2): ";
        cin >> answer;
        cin.clear();
        cin.ignore(256, '\n');
        if (answer == 1) {
            return true;
        } else if (answer == 2) {
            return false;
        } else {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
        }
    }
}

void MemberManager::printAllMember() {
    if (curCount == 0) {
        cout << "�Էµ� ȸ�� ������ �����ϴ�." << endl;
        printGoMainMenu();
        return;
    }

    bool ascending = isAscending();
    members.sort();
    if (!ascending) {
        members.reverse();
    }

    for (auto it = members.begin(); it != members.end(); ++it) {

        cout << *it << endl << endl;
    }
    cout << "=====================" << endl << endl;
    cout << "�� " << curCount << "�� �Դϴ�." << endl;

    printGoMainMenu();
}

void MemberManager::printFilteredMember() {
    if (curCount == 0) {
        cout << "�Էµ� ȸ�� ������ �����ϴ�." << endl;
        printGoMainMenu();
        return;
    }

    int filteredSex;
    while (true) {
        cout << "� ������ Ȯ���� �� ������(1. ����, 2. ����, 3.���): ";
        cin >> filteredSex;
        cin.clear();
        cin.ignore(256, '\n');
        if (filteredSex >= 1 && filteredSex <= 3) {
            break;
        } else {
            cout << "�߸��� �Է��Դϴ�. �ٽ��Է��ϼ��� " << endl;
        }
    }

    int ageQuot;
    while (true) {
        cout
            << "� ���̴븦 Ȯ���� �� ������(1. 10��, 2. 20��, 3. 30��, 4. "
               "40��, 5. �̿�, 6. ���)"
            << endl;
        cin >> ageQuot;
        cin.clear();
        cin.ignore(256, '\n');
        if (ageQuot >= 1 && ageQuot <= 6) {
            break;
        } else {
            cout << "�߸��� �Է��Դϴ�. �ٽ��Է��ϼ��� " << endl;
        }
    }

    int cnt = 0;
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (filteredSex == it->sex || filteredSex == 3) {
            cnt++;
            if (ageQuot == 6) {
                cout << *it << endl;

            } else if (it->age / 10 == ageQuot) {
                cout << *it << endl;
            } else if (ageQuot == 5 && ((it->age / 10) >= ageQuot)) {
                cout << *it << endl;
            } else {
                cnt--;
            }
        }
    }
    cout << "�� " << cnt << "�� �Դϴ�." << endl;

    printGoMainMenu();
}

void MemberManager::printMember(list<Member>::iterator& it) {
    if (it == members.end()) {
        cout << "�������� �ʴ� ȸ���Դϴ�." << endl;
    } else {

        cout << *it;
    }
}

void MemberManager::printWelcomMsg() {
    cout << "�ȳ��ϼ��� ȸ�� ���� ���� �ý����Դϴ�!" << endl;
};

void MemberManager::printByeMsg() {
    system("cls");
    cout << "�̿����ּż� �����մϴ�!" << endl;
};

void MemberManager::eraseMember() {
    if (curCount == 0) {
        cout << "�Էµ� ȸ�� ������ �����ϴ�." << endl;
        printGoMainMenu();
        return;
    }
    string dName;
    cout << "������ ����� �̸��� �Է��ϼ���: ";
    cin >> dName;

    auto it = searchMemberByName(dName);
    int  answer;
    if (it == members.end()) {
        cout << "�ش� �̸��� ����� �����ϴ�." << endl;

    } else {
        members.erase(it);
        curCount--;
        cout << "���������� �����Ǿ����ϴ�. " << endl;
    }

    printGoMainMenu();
}

bool MemberManager::Member::isValid() {
    bool valid = false;
    // name ������ ���߿�

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
    cout << endl << "�ƹ�Ű�� �Է½� ���� �޴��� ���ư��ϴ�." << endl;

    cin >> wait;
    cin.clear();
    cin.ignore(256, '\n');

    system("cls");
}