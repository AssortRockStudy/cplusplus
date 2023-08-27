#pragma once
#include <iostream>
#include <list>
#include <string>

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
   private:
    // 멤버는 이름, 성별, 나이를 입력받음
    class Member {
       private:
        string name;
        uint32_t sex;
        uint8_t age;

       public:
        Member() : name(""), sex(0), age(0){};
        Member(string _name, uint32_t _sex, uint8_t _age)
            : name(_name), sex(_sex), age(_age){};
        ~Member(){};
    };

    enum Menu { NONE, INPUT, PRINTALL, QUIT, END };

    list<Member> members;
    int curCount;

   public:
    MemberManager() : curCount(0), members(){};
    ~MemberManager(){};

   public:
    void Start();
    int inputMenu();

    void inputMember();
    void printAllMember();
    void printWelcomMsg();
};
