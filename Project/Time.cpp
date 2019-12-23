//
// Created by ROVERDOGE on 2019/12/15.
//
#include "Time.h"

void Time::convert(double day, double hour,int flag) {
    while(hour>=4){hour-=4;day+=0.5;}
    while(hour<0){if(day-0.5>0){day-=0.5;hour+=4;} else{day=0;hour+=4;}}
    switch(flag){
        case 1:this->work_day=day;this->work_hour=hour;break;
        case 2:this->holiday_day=day;this->holiday_hour=hour;break;
        case 3:this->notwork_day;this->notwork_hour=hour;break;
    }
}
Time::Time(double work_day, double work_hour, double holiday_day, double holiday_hour, double notwork_day,
           double notwork_hour,int select2) {
    this->work_day=work_day;
    this->work_hour=work_hour;
    this->holiday_day=holiday_day;
    this->holiday_hour=holiday_hour;
    this->notwork_day=notwork_day;
    this->notwork_hour=notwork_hour;
    this->convert(this->work_day,this->work_hour,1);
    this->convert(this->holiday_hour,this->holiday_hour,2);
    this->convert(this->notwork_day,this->notwork_hour,3);
}
void Time::setTime(double work_day, double work_hour, double holiday_day, double holiday_hour, double notwork_day,
               double notwork_hour) {
    if(work_day>0){this->work_day=work_day;}else{this->work_day=0;}
    if(work_hour>0){this->work_hour=work_hour;}else{this->work_hour=0;}
    if(holiday_day>0){this->holiday_day=holiday_day;}else{this->holiday_day=0;}
    if(holiday_hour>0){this->holiday_hour=holiday_hour;}else{this->holiday_hour=0;}
    if(notwork_day>0){this->notwork_day=notwork_day;}else{this->notwork_day=0;}
    if(notwork_hour>0){this->notwork_hour=notwork_hour;}else{this->notwork_hour=0;}
}

double Time::getDay(int flag) {switch(flag){case 1:return this->work_day;case 2:return this->holiday_day;case 3: return this->notwork_day;default: return 0;}}
double Time::getHour(int flag) {switch(flag){case 1:return this->work_hour;case 2:return this->holiday_hour;case 3: return this->notwork_hour;default: return 0;}}

/*Time WorkTime::operator+(Time Time1) {
    Time Time2;
    Time2.setTime(Time1.getDay(1)+this->work_hour,Time1.getHour(1)+this->work_hour,\
    Time1.getDay(2),Time1.getHour(2),Time1.getDay(3),Time1.getHour(3));
    Time2.convert(Time2.getDay(1),Time2.getHour(1),1);
    return Time2;
}

Time WorkTime::operator-(Time Time1) {
    Time Time2;
    Time2.setTime(Time1.getDay(1)-this->work_hour,Time1.getHour(1)-this->work_hour,\
    Time1.getDay(2),Time1.getHour(2),Time1.getDay(3),Time1.getHour(3));
    Time2.convert(Time2.getDay(1),Time2.getHour(1),1);
    return Time2;
}

Time HolidayTime::operator+(Time Time1) {
    Time Time2;
    Time2.setTime(Time1.getDay(1),Time1.getHour(1),Time1.getDay(2)+this->holiday_day,Time1.getHour(2)+this->holiday_hour,Time1.getDay(3),Time1.getHour(3));
    Time2.convert(Time2.getDay(2),Time2.getHour(2),2);
    return Time2;
}

Time HolidayTime::operator-(Time Time1) {
    Time Time2;
    Time2.setTime(Time1.getDay(1),Time1.getHour(1),Time1.getDay(2)-this->holiday_day,Time1.getHour(2)-this->holiday_hour,Time1.getDay(3),Time1.getHour(3));
    Time2.convert(Time2.getDay(2),Time2.getHour(2),2);
    return Time2;
}

Time NotWorkTime::operator+(Time Time1) {
    Time Time2;
    Time2.setTime(Time1.getDay(1),Time1.getHour(1),Time1.getDay(2),Time1.getHour(2),Time1.getDay(3)+this->notwork_day,Time1.getHour(3)+this->notwork_hour);
    Time2.convert(Time2.getDay(3),Time2.getHour(3),3);
    return Time2;
}

Time NotWorkTime::operator-(Time Time1) {
    Time Time2;
    Time2.setTime(Time1.getDay(1),Time1.getHour(1),Time1.getDay(2),Time1.getHour(2),Time1.getDay(3)-this->notwork_day,Time1.getHour(3)-this->notwork_hour);
    Time2.convert(Time2.getDay(3),Time2.getHour(3),3);
    return Time2;
}*/
