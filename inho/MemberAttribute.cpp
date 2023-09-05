#include "MemberAttribute.h"
#include "memberManager.h"
MemberName::MemberName() : MemberAttribute("이름"){};

void MemberName::inputData() {
    cout << "이름을 입력해주세요: ";
    cin >> data;
}

void MemberName::modifyData() {
    cout << "변경할 ";
    inputData();
}

void MemberName::printData() {
    if (data == "")
        return;
    cout << "이름: " << data;
}
bool MemberName::isValid() { return true; };

void MemberSex::printData() {
    if (!data) {
        return;
    }
    if (data == MemberManager::Sex::MAN) {
        cout << "성별 : 남성";
    } else {
        cout << "성별: 여성";
    }
}

bool MemberSex::isValid() {
    if (data == MemberManager::Sex::MAN || data == MemberManager::Sex::WOMAN) {
        return true;
    } else {
        return false;
    }
}