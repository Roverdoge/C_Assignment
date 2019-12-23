//
// Created by ROVERDOGE on 2019/12/15.
//
#include "Staff.h"
#include "Time.h"
#ifndef PROJECT_PERSON_H
#define PROJECT_PERSON_H
using namespace std;
/*
 * num：int,编号
 * name:string,名字
 * sex:int,性别
 * section:string,部门
 * level:int,级别
 * work_day/hour:double,工作时间
 * holiday_day/hour:double,假期时间
 * notwork_day/hour:double,生病没工作的时间
 * select:int,{1,2,4,8,16}
 * select2:int,{1,2,4}
 */
class Manager: public Staff,public Time{
        friend std::ostream &operator<<(std::ostream &output, const Manager &Manager) {
        std::string sex;
        if(Manager.sex==1){sex="男";} else if(Manager.sex==-1){sex="女";}else{sex="";}
        int i=Manager.select;
        if(((i>>1)&1)==1){output<<"员工编号为："<<Manager.num<<"；";}
        if(((i>>1)&1)==1){output<<"员工姓名为："<<Manager.name<<"；";}
        if(((i>>1)&1)==1){output<<"员工性别为："<<sex<<"；";}
        if(((i>>1)&1)==1){output<<"员工部门为："<<Manager.section<<"；";}
        if(((i>>1)&1)==1){output<<"员工级别为："<<Manager.level<<"；";}
        i=Manager.select2;
        if(((i>>1)&1)==1){output<<"工作了的日长为："<<Manager.work_day<<"；"<<"工作了的时长为："<<Manager.work_hour<<"；";}
        if(((i>>1)&1)==1){output<<"带薪休假的日长为："<<Manager.holiday_day<<"；"<<"带薪休假的时长为："<<Manager.holiday_hour<<"；";}
        if(((i>>1)&1)==1){output<<"生病没有工作的日长为："<<Manager.work_day<<"；"<<"生病没有工作的时长为："<<Manager.work_hour<<"；";}
        output<<std::endl;
        return output;
    }
public:
    Manager(int num=0,std::string name="",int sex=0,std::string section="",int level=0,int select=0,\
    double work_day=0,double work_hour=0,double holiday_day=0,double holiday_hour=0,double notwork_day=0,double notwork_hour=0,int select2=0)\
    :Staff(num,name,sex,section,level,select),Time(work_day,work_hour,holiday_day,holiday_hour,notwork_day,notwork_hour,select2){
        this->salary_per_level=1;
        this->salary_per_day=4;
    };
    template <class T>
    bool operator>(T);
    template <class T>
    bool operator<(T);
    template <class T>
    bool operator==(T);
    double getSalary() override{
        return (salary_per_day*(work_day+work_hour/4+holiday_day+holiday_hour/4)+level*salary_per_level);
    }
private:
    int salary_per_level;
    double salary_per_day;
};
class Technician: public Staff,public Time{
    friend std::ostream &operator<<(std::ostream &output, const Technician &Technician) {
        std::string sex;
        if(Technician.sex==1){sex="男";} else if(Technician.sex==-1){sex="女";}else{sex="";}
        int i=Technician.select;
        if(((i>>1)&1)==1){output<<"员工编号为："<<Technician.num<<"；";}
        if(((i>>1)&1)==1){output<<"员工姓名为："<<Technician.name<<"；";}
        if(((i>>1)&1)==1){output<<"员工性别为："<<sex<<"；";}
        if(((i>>1)&1)==1){output<<"员工部门为："<<Technician.section<<"；";}
        if(((i>>1)&1)==1){output<<"员工级别为："<<Technician.level<<"；";}
        i=Technician.select2;
        if(((i>>1)&1)==1){output<<"工作了的日长为："<<Technician.work_day<<"；"<<"工作了的时长为："<<Technician.work_hour<<"；";}
        if(((i>>1)&1)==1){output<<"带薪休假的日长为："<<Technician.holiday_day<<"；"<<"带薪休假的时长为："<<Technician.holiday_hour<<"；";}
        if(((i>>1)&1)==1){output<<"生病没有工作的日长为："<<Technician.work_day<<"；"<<"生病没有工作的时长为："<<Technician.work_hour<<"；";}
        output<<std::endl;
        return output;
    }
public:
    Technician(int num=0,std::string name="",int sex=0,std::string section="",int level=0,int select=0,\
    double work_day=0,double work_hour=0,double holiday_day=0,double holiday_hour=0,double notwork_day=0,double notwork_hour=0,int select2=0)\
    :Staff(num,name,sex,section,level,select),Time(work_day,work_hour,holiday_day,holiday_hour,notwork_day,notwork_hour,select2){
        this->salary_per_level=5;
        this->salary_per_day=3;
    };
    template <class T>
    bool operator>(T);
    template <class T>
    bool operator<(T);
    template <class T>
    bool operator==(T);
    double getSalary() override{
        return (salary_per_day*(work_day+work_hour/4+holiday_day+holiday_hour/4)+level*salary_per_level);
    }
private:
    int salary_per_level;
    double salary_per_day;
};
class SalesMan: public Staff, public Time{
    friend std::ostream &operator<<(std::ostream &output, const SalesMan &Salesman) {
        std::string sex;
        if(Salesman.sex==1){sex="男";} else if(Salesman.sex==-1){sex="女";}else{sex="";}
        int i=Salesman.select;
        if(((i>>1)&1)==1){output<<"员工编号为："<<Salesman.num<<"；";}
        if(((i>>1)&1)==1){output<<"员工姓名为："<<Salesman.name<<"；";}
        if(((i>>1)&1)==1){output<<"员工性别为："<<sex<<"；";}
        if(((i>>1)&1)==1){output<<"员工部门为："<<Salesman.section<<"；";}
        if(((i>>1)&1)==1){output<<"员工级别为："<<Salesman.level<<"；";}
        i=Salesman.select2;
        if(((i>>1)&1)==1){output<<"工作了的日长为："<<Salesman.work_day<<"；"<<"工作了的时长为："<<Salesman.work_hour<<"；";}
        if(((i>>1)&1)==1){output<<"带薪休假的日长为："<<Salesman.holiday_day<<"；"<<"带薪休假的时长为："<<Salesman.holiday_hour<<"；";}
        if(((i>>1)&1)==1){output<<"生病没有工作的日长为："<<Salesman.work_day<<"；"<<"生病没有工作的时长为："<<Salesman.work_hour<<"；";}
        output<<std::endl;
        return output;
    }
public:
    SalesMan(int num=0, std::string name="", int sex=0, std::string section="", int level=0, int select=0,\
    double work_day=0, double work_hour=0, double holiday_day=0, double holiday_hour=0, double notwork_day=0, double notwork_hour=0, int select2=0)\
    :Staff(num,name,sex,section,level,select),Time(work_day,work_hour,holiday_day,holiday_hour,notwork_day,notwork_hour,select2){
        this->salary_per_level=2;
        this->salary_per_day=1;
    };
    template <class T>
    bool operator>(T);
    template <class T>
    bool operator<(T);
    template <class T>
    bool operator==(T);
    double getSalary() override{
        return (salary_per_day*(work_day+work_hour/4+holiday_day+holiday_hour/4)+level*salary_per_level);
    }
private:
    int salary_per_level;
    double salary_per_day;
};
class SalesManager: public Staff,public Time{
    friend std::ostream &operator<<(std::ostream &output, const SalesManager &SalesManager) {
        std::string sex;
        if(SalesManager.sex==1){sex="男";} else if(SalesManager.sex==-1){sex="女";}else{sex="";}
        int i=SalesManager.select;
        if(((i>>1)&1)==1){output<<"员工编号为："<<SalesManager.num<<"；";}
        if(((i>>1)&1)==1){output<<"员工姓名为："<<SalesManager.name<<"；";}
        if(((i>>1)&1)==1){output<<"员工性别为："<<sex<<"；";}
        if(((i>>1)&1)==1){output<<"员工部门为："<<SalesManager.section<<"；";}
        if(((i>>1)&1)==1){output<<"员工级别为："<<SalesManager.level<<"；";}
        i=SalesManager.select2;
        if(((i>>1)&1)==1){output<<"工作了的日长为："<<SalesManager.work_day<<"；"<<"工作了的时长为："<<SalesManager.work_hour<<"；";}
        if(((i>>1)&1)==1){output<<"带薪休假的日长为："<<SalesManager.holiday_day<<"；"<<"带薪休假的时长为："<<SalesManager.holiday_hour<<"；";}
        if(((i>>1)&1)==1){output<<"生病没有工作的日长为："<<SalesManager.work_day<<"；"<<"生病没有工作的时长为："<<SalesManager.work_hour<<"；";}
        output<<std::endl;
        return output;
    }
public:
    SalesManager(int num=0,std::string name="",int sex=0,std::string section="",int level=0,int select=0,\
    double work_day=0,double work_hour=0,double holiday_day=0,double holiday_hour=0,double notwork_day=0,double notwork_hour=0,int select2=0)\
    :Staff(num,name,sex,section,level,select),Time(work_day,work_hour,holiday_day,holiday_hour,notwork_day,notwork_hour,select2){
        this->salary_per_level=3;
        this->salary_per_day=2;
    };
    template <class T>
    bool operator>(T);
    template <class T>
    bool operator<(T);
    template <class T>
    bool operator==(T);
    double getSalary() override{
        return (salary_per_day*(work_day+work_hour/4+holiday_day+holiday_hour/4)+level*salary_per_level);
    }
private:
    int salary_per_level;
    double salary_per_day;
};


#endif //PROJECT_PERSON_H
