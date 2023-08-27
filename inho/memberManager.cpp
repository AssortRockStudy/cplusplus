#include "memberManager.h"

#include <Windows.h>

void MemberManager::Run() {
    bool quit = false;
    printWelcomMsg();
    while (!quit) {
        int select = inputMenu();
        switch (select) {
            case Menu::INPUT:
                inputMember();
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
        cout << "1. ȸ�� ���� �߰�" << endl;
        cout << "2. ȸ�� ��� ���" << endl;
        cout << "3. ������" << endl;

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

void MemberManager::inputMember() {
    cout << "ȸ�� ���� �Է� ����Դϴ�. " << endl << endl;
    int more = 0;
    while (true) {
        Member* newMember = new Member();
        while (true) {
            // ��� �Է¿� ���
            cin.clear();
            cout << "�̸��� �Է����ּ���: ";
            cin >> newMember->name;
            cout << "������ �Է����ּ���(����: 1, ����: 2): ";
            cin >> newMember->sex;

            cout << "���̸� �Է����ּ���: ";
            cin >> newMember->age;

            if (newMember->isValid()) {
                break;
            } else {
                cout << "��ȿ���� ���� �����Դϴ�. " << endl;
            }
        }
        cout << "������ " << newMember->sex << "�Դϴ�." << endl;
        members.push_back(newMember);

        cout << "�߰��� ȸ���� �Է��Ͻðڽ��ϱ�(yes: 1, no: 0)";

        cin >> more;

        if (!more) {
            break;
        } else {
            cout << endl << "====================== ��� �߰�" << endl << endl;
        }
    }
    system("cls");
}

void MemberManager::printAllMember() {}

void MemberManager::printWelcomMsg() {
    cout << "�ȳ��ϼ��� ȸ�� ���� ���� �ý����Դϴ�!" << endl;
};

void MemberManager::printByeMsg() {
    system("cls");
    cout << "�̿����ּż� �����մϴ�!" << endl;
};

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