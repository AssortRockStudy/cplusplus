#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class MemberAttribute {

  protected:
    string name;

  public:
    MemberAttribute(){};
    MemberAttribute(string _name) : name(_name){};
    ~MemberAttribute(){};

  public:
    virtual void inputData() = 0;
    virtual void modifyData() = 0;
    virtual void printData() = 0;
    virtual bool isValid() = 0;
};

class MemberName : public MemberAttribute {
  public:
    string data;

  public:
    MemberName();
    ~MemberName(){};

  public:
    virtual void inputData() override;
    virtual void modifyData() override;
    virtual void printData() override;
    virtual bool isValid() override;
};

class MemberSex : public MemberAttribute {
  public:
    int data;

  public:
    MemberSex() : MemberAttribute("성별"), data(0){};
    ~MemberSex(){};

  public:
    virtual void inputData() override {
        cout << "성별을 입력해 주세요(남성: 1, 여성: 2): ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> data;
    }
    virtual void modifyData() override {
        cout << "변경할 ";
        inputData();
    }
    virtual void printData() override;
    virtual bool isValid() override;
};

class MemberAge : public MemberAttribute {
  public:
    int data;

  public:
    MemberAge() : MemberAttribute("나이"), data(0) {}
    ~MemberAge(){};

  public:
    virtual void inputData() override {
        cout << "나이를 입력해주세요: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> data;
    }
    virtual void modifyData() override {
        cout << "변경할 ";
        inputData();
    }
    virtual void printData() override {
        if (!data) {
            return;
        }
        cout << "나이: " << data;
    }
    virtual bool isValid() override {
        if (0 <= data && data < 200) {
            return true;
        } else {
            return false;
        }
    }
};

class MemberGroup : public MemberAttribute {
  public:
    string data;

  public:
    MemberGroup() : MemberAttribute("그룹"){};
    ~MemberGroup(){};

  public:
    virtual void inputData() {
        cout << "그룹을 입력해주세요: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> data;
    }
    virtual void modifyData() {
        cout << "변경할 ";
        inputData();
    }
    virtual void printData() {
        if (data == "") {
            return;
        }
        cout << "그룹: " << data;
    }
    virtual bool isValid() { return true; }
};