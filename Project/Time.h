//
// Created by ROVERDOGE on 2019/12/15.
//
#include <string>
#ifndef PROJECT_TIME_H
#define PROJECT_TIME_H
using namespace std;

/*
 * flag:
 * 1、work
 * 2、holiday
 * 3、notwork
 * 4、select2 {1,2,4}
 */
class Time {
public:
    void convert(double ,double ,int );
    Time(double work_day=0,double work_hour=0,double holiday_day=0,double holiday_hour=0,double notwork_day=0,double notwork_hour=0,int select2=0);
    double getDay(int flag);
    double getHour(int flag);
    int getSelect(){return this->select2;}
    void setTime(double work_day=0,double work_hour=0,double holiday_day=0,double holiday_hour=0,double notwork_day=0,double notwork_hour=0);
    void setSelect(int select2){this->select2=select2;}
    //TODO::如果仅输入day，初始化时记得将其转换为hour，实现的时候记得转换回去
protected:
    double work_day;
    double holiday_day;
    double notwork_day;
    double work_hour;
    double holiday_hour;
    double notwork_hour;
    int select2;
};
class WorkTime : public Time{
public:
    WorkTime(double work_day=0,double work_hour=0):Time(work_day,work_hour){};
    Time operator+ (Time);
    Time operator- (Time);
};
class HolidayTime : public Time{
public:
    HolidayTime(double holiday_day=0,double holiday_hour=0):Time(holiday_day,holiday_hour){};
    Time operator+ (Time);
    Time operator- (Time);
};
class NotWorkTime : public Time{
public:
    NotWorkTime(double notwork_day=0,double notwork_hour=0):Time(notwork_day,notwork_hour){};
    Time operator+ (Time);
    Time operator- (Time);
};
#endif //PROJECT_TIME_H
