//
// Created by ROVERDOGE on 2019/12/15.
//
#include "Staff.h"
#include "Time.h"
#ifndef PROJECT_PERSON_H
#define PROJECT_PERSON_H
using namespace std;
/*
 * num��int,���
 * name:string,����
 * sex:int,�Ա�
 * section:string,����
 * level:int,����
 * work_day/hour:double,����ʱ��
 * holiday_day/hour:double,����ʱ��
 * notwork_day/hour:double,����û������ʱ��
 * select:int,{1,2,4,8,16}
 * select2:int,{1,2,4}
 */
class Manager: public Staff,public Time{
        friend std::ostream &operator<<(std::ostream &output, const Manager &Manager) {
        std::string sex;
        if(Manager.sex==1){sex="��";} else if(Manager.sex==-1){sex="Ů";}else{sex="";}
        int i=Manager.select;
        if(((i>>1)&1)==1){output<<"Ա�����Ϊ��"<<Manager.num<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<Manager.name<<"��";}
        if(((i>>1)&1)==1){output<<"Ա���Ա�Ϊ��"<<sex<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<Manager.section<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<Manager.level<<"��";}
        i=Manager.select2;
        if(((i>>1)&1)==1){output<<"�����˵��ճ�Ϊ��"<<Manager.work_day<<"��"<<"�����˵�ʱ��Ϊ��"<<Manager.work_hour<<"��";}
        if(((i>>1)&1)==1){output<<"��н�ݼٵ��ճ�Ϊ��"<<Manager.holiday_day<<"��"<<"��н�ݼٵ�ʱ��Ϊ��"<<Manager.holiday_hour<<"��";}
        if(((i>>1)&1)==1){output<<"����û�й������ճ�Ϊ��"<<Manager.work_day<<"��"<<"����û�й�����ʱ��Ϊ��"<<Manager.work_hour<<"��";}
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
        if(Technician.sex==1){sex="��";} else if(Technician.sex==-1){sex="Ů";}else{sex="";}
        int i=Technician.select;
        if(((i>>1)&1)==1){output<<"Ա�����Ϊ��"<<Technician.num<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<Technician.name<<"��";}
        if(((i>>1)&1)==1){output<<"Ա���Ա�Ϊ��"<<sex<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<Technician.section<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<Technician.level<<"��";}
        i=Technician.select2;
        if(((i>>1)&1)==1){output<<"�����˵��ճ�Ϊ��"<<Technician.work_day<<"��"<<"�����˵�ʱ��Ϊ��"<<Technician.work_hour<<"��";}
        if(((i>>1)&1)==1){output<<"��н�ݼٵ��ճ�Ϊ��"<<Technician.holiday_day<<"��"<<"��н�ݼٵ�ʱ��Ϊ��"<<Technician.holiday_hour<<"��";}
        if(((i>>1)&1)==1){output<<"����û�й������ճ�Ϊ��"<<Technician.work_day<<"��"<<"����û�й�����ʱ��Ϊ��"<<Technician.work_hour<<"��";}
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
        if(Salesman.sex==1){sex="��";} else if(Salesman.sex==-1){sex="Ů";}else{sex="";}
        int i=Salesman.select;
        if(((i>>1)&1)==1){output<<"Ա�����Ϊ��"<<Salesman.num<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<Salesman.name<<"��";}
        if(((i>>1)&1)==1){output<<"Ա���Ա�Ϊ��"<<sex<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<Salesman.section<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<Salesman.level<<"��";}
        i=Salesman.select2;
        if(((i>>1)&1)==1){output<<"�����˵��ճ�Ϊ��"<<Salesman.work_day<<"��"<<"�����˵�ʱ��Ϊ��"<<Salesman.work_hour<<"��";}
        if(((i>>1)&1)==1){output<<"��н�ݼٵ��ճ�Ϊ��"<<Salesman.holiday_day<<"��"<<"��н�ݼٵ�ʱ��Ϊ��"<<Salesman.holiday_hour<<"��";}
        if(((i>>1)&1)==1){output<<"����û�й������ճ�Ϊ��"<<Salesman.work_day<<"��"<<"����û�й�����ʱ��Ϊ��"<<Salesman.work_hour<<"��";}
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
        if(SalesManager.sex==1){sex="��";} else if(SalesManager.sex==-1){sex="Ů";}else{sex="";}
        int i=SalesManager.select;
        if(((i>>1)&1)==1){output<<"Ա�����Ϊ��"<<SalesManager.num<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<SalesManager.name<<"��";}
        if(((i>>1)&1)==1){output<<"Ա���Ա�Ϊ��"<<sex<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<SalesManager.section<<"��";}
        if(((i>>1)&1)==1){output<<"Ա������Ϊ��"<<SalesManager.level<<"��";}
        i=SalesManager.select2;
        if(((i>>1)&1)==1){output<<"�����˵��ճ�Ϊ��"<<SalesManager.work_day<<"��"<<"�����˵�ʱ��Ϊ��"<<SalesManager.work_hour<<"��";}
        if(((i>>1)&1)==1){output<<"��н�ݼٵ��ճ�Ϊ��"<<SalesManager.holiday_day<<"��"<<"��н�ݼٵ�ʱ��Ϊ��"<<SalesManager.holiday_hour<<"��";}
        if(((i>>1)&1)==1){output<<"����û�й������ճ�Ϊ��"<<SalesManager.work_day<<"��"<<"����û�й�����ʱ��Ϊ��"<<SalesManager.work_hour<<"��";}
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
