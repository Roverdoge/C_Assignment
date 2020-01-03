//
// Created by ROVERDOGE on 2019/12/16.
//

#include "Person.h"



template<class T>
bool Manager::operator>(T T1) {
    //��ȡselect����
    int i=T1.getselect();
    int j=T1.getSelect();
    //���ݲ���������Ӧ��ϵ
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
    //Ĭ�����
    return false;
}

template<class T>
bool Manager::operator<(T T1) {
    //����һ����ͬ�������෴
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
    //Ĭ�����
    return false;
}

template<class T>
bool Manager::operator==(T T1) {
    //����һ����ͬ���ж����
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
    //Ĭ�����
    return true;
}





template<class T>
bool Technician::operator>(T T1) {
    //��ȡselect����
    int i=T1.getselect();
    int j=T1.getSelect();
    //���ݲ���������Ӧ��ϵ
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
    //Ĭ�����
    return false;
}

template<class T>
bool Technician::operator<(T T1) {
    //����һ����ͬ�������෴
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
    //Ĭ�����
    return false;
}

template<class T>
bool Technician::operator==(T T1) {
    //����һ����ͬ���ж����
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
    //Ĭ�����
    return false;
}




template<class T>
bool SalesMan::operator>(T T1) {
    //��ȡselect����
    int i=T1.getselect();
    int j=T1.getSelect();
    //���ݲ���������Ӧ��ϵ
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
    //Ĭ�����
    return false;
}

template<class T>
bool SalesMan::operator<(T T1) {
    //����һ����ͬ�������෴
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
    //Ĭ�����
    return false;
}

template<class T>
bool SalesMan::operator==(T T1) {
    //����һ����ͬ���ж����
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
    //Ĭ�����
    return false;
}




template<class T>
bool SalesManager::operator>(T T1) {
    //��ȡselect����
    int i=T1.getselect();
    int j=T1.getSelect();
    //���ݲ���������Ӧ��ϵ
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
    //Ĭ�����
    return false;
}

template<class T>
bool SalesManager::operator<(T T1) {
    //����һ����ͬ�������෴
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
    //Ĭ�����
    return false;
}

template<class T>
bool SalesManager::operator==(T T1) {
    //����һ����ͬ���ж����
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
    //Ĭ�����
    return false;
}

