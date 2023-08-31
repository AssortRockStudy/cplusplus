#pragma once
#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

// �ܼ��� ������ �޴����� ���۵Ǿ�� ��
// ��� �Ŵ����� ���۽���
// �޴����� ���;� �� ( 1. ȸ�� ���, 2. ȸ�� ���� ���, 3. ������ )
// ȸ�� Ŭ������ �ʿ���

// ���κ��� MemberManager ��ü ���� ��, start�Ұ���
// ����Ʈ(ȸ��), ȸ�� ��,
class MemberManager {
  public:
    enum Sex { NO, MAN, WOMAN };
    enum Menu { NONE, INPUT, SEARCH_NAME, PRINTALL, QUIT, END };

  private:
    // ����� �̸�, ����, ���̸� �Է¹���
    class Member {
        friend class MemberManager;

      private:
        string   name;
        uint32_t sex;
        uint32_t age;

      public:
        Member() : name(""), sex(0), age(0){};
        Member(string _name, uint32_t _sex, uint32_t _age)
            : name(_name), sex(_sex), age(_age){};
        ~Member(){};

      public:
        bool isValid();

        friend std::ostream& operator<<(std::ostream& os, const Member& mem) {

            os << "�̸�: " << mem.name << endl;
            if (mem.sex == Sex::MAN) {
                os << "����: ����" << endl;
            } else if (mem.sex == Sex::WOMAN) {
                os << "����: ����" << endl;
            } else {
                os << "����: �̻�" << endl;
            }
            os << "����: " << mem.age << endl;
            return os;
        }
    };

    list<Member> members;
    int          curCount;

  public:
    MemberManager() : curCount(0), members(){};
    ~MemberManager() { members.clear(); };

  public:
    void Run();
    int  inputMenu();

  private:
    void inputMember();
    void searchByName();
    list<MemberManager::Member>::iterator
         searchMemberByName(const string& name);
    void modifyMember();

    void printAllMember();
    void printMember(list<MemberManager::Member>::iterator& it);
    void printWelcomMsg();
    void printByeMsg();

    void printGoMainMenu();
};
