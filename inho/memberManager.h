#pragma once
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

// 콘솔이 켜지면 메뉴판이 시작되어야 함
// 멤버 매니저를 시작시켜
// 메뉴판이 나와야 함 ( 1. 회원 등록, 2. 회원 전부 출력, 3. 끝내기 )
// 회원 클래스가 필요함

// 메인부터 MemberManager 객체 생성 후, start할거임
// 리스트(회원), 회원 수,
class MemberManager {
  public:
    enum Sex { NO, MAN, WOMAN };
    enum Menu {
        NONE,
        INPUT,
        SEARCH_NAME,
        PRINTALL,
        PRINT_FILTER,
        MODIFY,
        ERASE,
        QUIT,
        END
    };

  public:
    // 멤버는 이름, 성별, 나이를 입력받음
    class Member {
        friend class MemberManager;
        enum Attribute { NONE, ALL, NAME, AGE, SEX };

#define INPUT_NAME 0x01
#define INPUT_AGE 0x02
#define INPUT_SEX 0x04
#define INPUT_ALL 0x07

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
            cout << "=====================" << endl << endl;
            os << "이름: " << mem.name << endl;
            if (mem.sex == Sex::MAN) {
                os << "성별: 남자" << endl;
            } else if (mem.sex == Sex::WOMAN) {
                os << "성별: 여자" << endl;
            } else {
                os << "성별: 미상" << endl;
            }
            os << "나이: " << mem.age << endl;
            return os;
        }

        bool operator==(const Member& _oth) {
            if (this->name != _oth.name)
                return false;
            if (this->age != _oth.age)
                return false;
            if (this->sex != _oth.sex)
                return false;

            return true;
        }

        bool operator!=(const Member& _oth) { return !(*this == _oth); }

        bool operator<(const Member& _oth) {
            return this->name < _oth.name ? true : false;
        }
        bool operator>(const Member& _oth) {
            return this->name > _oth.name ? true : false;
        }
    };

    list<Member> members;
    int          curCount;

  public:
    MemberManager() : curCount(0), members(){};
    ~MemberManager() { members.clear(); };

  public:
    void Run();

  private:
    int                    inputMenu();
    void                   inputMember();
    void                   searchByName();
    list<Member>::iterator searchMemberByName(const string& name);
    void                   modifyMember();
    void modifyMemberByAttribute(std::list<Member>::iterator& _it, int _mask);

    bool isDuplicate(const Member& _chk);
    bool isAscending();
    void printAllMember();
    void printFilteredMember();
    void eraseMember();

    void printMember(list<Member>::iterator& it);
    void printWelcomMsg();
    void printByeMsg();

    void printGoMainMenu();
};
