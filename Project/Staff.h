//
// Created by ROVERDOGE on 2019/12/15.
//


#include<string>
#include<iostream>
#ifndef PROJECT_STAFF_H
#define PROJECT_STAFF_H


/*
 * flag说明：
 * 1、编号
 * 2、名字
 * 3、性别（1：男，-1：女）
 * 4、部门
 * 5、级别
 * 6、select{1,2,4,8,16}
 */
class Staff {
public:
    Staff(int num,std::string name,int sex,std::string section,int level=0,int select=0){
        this->num=num;
        this->name=name;
        this->sex=sex;
        this->section=section;
        this->level=level;
        this->select=select;
    }
    void setnum(int a);
    void setname(std::string a);
    void setsex(int a);
    void setsection(std::string a);
    void setlevel(int a);
    void setselect(int a);
    int getnum();
    std::string getname();
    int getsex();
    std::string getsection();
    int getlevel();
    int getselect();
    virtual double getSalary() = 0;
protected:
    int num;
    std::string name;
    int sex;//man=1,woman=-1
    std::string section;
    int level;
    int select;

};
#endif //PROJECT_STAFF_H
