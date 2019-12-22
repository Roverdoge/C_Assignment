//
// Created by ROVERDOGE on 2019/12/15.
//

#include "Staff.h"

void Staff::setnum(int a){this->num=a;}
void Staff::setname(std::string a) {this->name=a;}
void Staff::setsex(int a) {this->sex=a;}
void Staff::setsection(std::string a) {this->section=a;}
void Staff::setlevel(int a) {this->level=a;}
void Staff::setselect(int a) {this->select=a;}
int Staff::getnum() {return this->num;}
std::string Staff::getname() {return this->name;}
int Staff::getsex() {return this->sex;}
std::string Staff::getsection() {return this->section;}
int Staff::getlevel() {return this->level;}
int Staff::getselect() {return this->select;}
