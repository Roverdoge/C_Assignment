//
// Created by ROVERDOGE on 2019/12/16.
//

#include "Person.h"



template<class T>
bool Manager::operator>(T T1) {
    //获取select参数
    int i=T1.getselect();
    int j=T1.getSelect();
    //根据参数构建对应关系
    if(i>0){
        switch(i){
            case 1: return this->num>T1.getnum();
            case 16:return this->level>T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)>(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)>(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)>(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return false;
}

template<class T>
bool Manager::operator<(T T1) {
    //与上一个相同，符号相反
    int i=T1.getselect();
    int j=T1.getSelect();
    if(i>0){
        switch(i){
            case 1: return this->num<T1.getnum();
            case 16:return this->level<T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)<(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)<(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)<(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return false;
}

template<class T>
bool Manager::operator==(T T1) {
    //与上一个相同，判断相等
    int i=T1.getselect();
    int j=T1.getSelect();
    if(i>0){
        switch(i){
            case 1: return this->num==T1.getnum();
            case 2: return this->name==T1.getname();
            case 4: return this->sex==T1.getsex();
            case 8: return this->section==T1.getsection();
            case 16:return this->level==T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)==(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)==(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)==(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return true;
}





template<class T>
bool Technician::operator>(T T1) {
    //获取select参数
    int i=T1.getselect();
    int j=T1.getSelect();
    //根据参数构建对应关系
    if(i>0){
        switch(i){
            case 1: return this->num>T1.getnum();
            case 16:return this->level>T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)>(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)>(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)>(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return false;
}

template<class T>
bool Technician::operator<(T T1) {
    //与上一个相同，符号相反
    int i=T1.getselect();
    int j=T1.getSelect();
    if(i>0){
        switch(i){
            case 1: return this->num<T1.getnum();
            case 16:return this->level<T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)<(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)<(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)<(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return false;
}

template<class T>
bool Technician::operator==(T T1) {
    //与上一个相同，判断相等
    int i=T1.getselect();
    int j=T1.getSelect();
    if(i>0){
        switch(i){
            case 1: return this->num==T1.getnum();
            case 2: return this->name==T1.getname();
            case 4: return this->sex==T1.getsex();
            case 8: return this->section==T1.getsection();
            case 16:return this->level==T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)==(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)==(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)==(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return false;
}




template<class T>
bool SalesMan::operator>(T T1) {
    //获取select参数
    int i=T1.getselect();
    int j=T1.getSelect();
    //根据参数构建对应关系
    if(i>0){
        switch(i){
            case 1: return this->num>T1.getnum();
            case 16:return this->level>T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)>(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)>(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)>(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return false;
}

template<class T>
bool SalesMan::operator<(T T1) {
    //与上一个相同，符号相反
    int i=T1.getselect();
    int j=T1.getSelect();
    if(i>0){
        switch(i){
            case 1: return this->num<T1.getnum();
            case 16:return this->level<T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)<(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)<(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)<(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return false;
}

template<class T>
bool SalesMan::operator==(T T1) {
    //与上一个相同，判断相等
    int i=T1.getselect();
    int j=T1.getSelect();
    if(i>0){
        switch(i){
            case 1: return this->num==T1.getnum();
            case 2: return this->name==T1.getname();
            case 4: return this->sex==T1.getsex();
            case 8: return this->section==T1.getsection();
            case 16:return this->level==T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)==(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)==(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)==(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return false;
}




template<class T>
bool SalesManager::operator>(T T1) {
    //获取select参数
    int i=T1.getselect();
    int j=T1.getSelect();
    //根据参数构建对应关系
    if(i>0){
        switch(i){
            case 1: return this->num>T1.getnum();
            case 16:return this->level>T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)>(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)>(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)>(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return false;
}

template<class T>
bool SalesManager::operator<(T T1) {
    //与上一个相同，符号相反
    int i=T1.getselect();
    int j=T1.getSelect();
    if(i>0){
        switch(i){
            case 1: return this->num<T1.getnum();
            case 16:return this->level<T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)<(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)<(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)<(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return false;
}

template<class T>
bool SalesManager::operator==(T T1) {
    //与上一个相同，判断相等
    int i=T1.getselect();
    int j=T1.getSelect();
    if(i>0){
        switch(i){
            case 1: return this->num==T1.getnum();
            case 2: return this->name==T1.getname();
            case 4: return this->sex==T1.getsex();
            case 8: return this->section==T1.getsection();
            case 16:return this->level==T1.getlevel();
        }
    }else{
        if(j>0){
            switch(j){
                case 1:return ((this->work_day)*4+this->work_hour)==(T1.getDay(1)*4+T1.getHour(1));
                case 2:return ((this->holiday_day)*4+this->holiday_hour)==(T1.getDay(2)*4+T1.getHour(2));
                case 4:return ((this->notwork_day)*4+this->notwork_hour)==(T1.getDay(3)*4+T1.getHour(3));
            }
        }
    }
    //默认情况
    return false;
}

