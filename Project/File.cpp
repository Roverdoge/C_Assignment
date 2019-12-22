//
// Created by ROVERDOGE on 2019/12/15.
//

#include "File.h"
template <class T1,class T2>
void File::writeFile_Managers(string fname) {
    ofstream outfile;
    outfile.open(fname, ios::out);
    Node<T2>* temp;
    outfile << "Manager" << endl;
    for(temp=Managers->gethead();temp->next!= nullptr;temp++){
        outfile << temp->data.getnum() << " " << temp->data.getname() << " " << temp->data.getsex() << " " << temp->data.getsection() << " " << temp->data.getlevel() << " "<< temp->data.getselect() << " "\
        <<temp->data.getDay(1)<<" "<<temp->data.getHour(1)<<" "<<temp->data.getDay(2)<<" "<<temp->data.getHour(2)<<" "<<temp->data.getDay(3)<<" "<<temp->data.getHour(3)<<" "<<std::endl;
    }
    outfile.close();
}
template <class T1,class T2>
void File::writeFile_Technicians(string fname) {
    ofstream outfile;
    outfile.open(fname, ios::app);
    Node<T2>* temp;
    outfile << "Technician" << endl;
    for(temp=Technicians->gethead();temp->next!= nullptr;temp++){
        outfile << temp->data.getnum() << " " << temp->data.getname() << " " << temp->data.getsex() << " " << temp->data.getsection() << " " << temp->data.getlevel() << " "<< temp->data.getselect() << " "\
        <<temp->data.getDay(1)<<" "<<temp->data.getHour(1)<<" "<<temp->data.getDay(2)<<" "<<temp->data.getHour(2)<<" "<<temp->data.getDay(3)<<" "<<temp->data.getHour(3)<<" "<<std::endl;
    }
    outfile.close();
}

template <class T1,class T2>
void File::writeFile_SalesMans(string fname) {
    ofstream outfile;
    outfile.open(fname, ios::app);
    Node<T2>* temp;
    outfile << "SalesMan" << endl;
    for(temp=SalesMans->gethead();temp->next!= nullptr;temp++){
        outfile << temp->data.getnum() << " " << temp->data.getname() << " " << temp->data.getsex() << " " << temp->data.getsection() << " " << temp->data.getlevel() << " "<< temp->data.getselect() << " "\
        <<temp->data.getDay(1)<<" "<<temp->data.getHour(1)<<" "<<temp->data.getDay(2)<<" "<<temp->data.getHour(2)<<" "<<temp->data.getDay(3)<<" "<<temp->data.getHour(3)<<" "<<std::endl;
    }
    outfile.close();
}
template <class T1,class T2>
void File::writeFile_SalesManagers(string fname) {
    ofstream outfile;
    outfile.open(fname, ios::app);
    Node<T2>* temp;
    outfile << "SalesManager" << endl;
    for(temp=SalesManagers->gethead();temp->next!= nullptr;temp++){
        outfile << temp->data.getnum() << " " << temp->data.getname() << " " << temp->data.getsex() << " " << temp->data.getsection() << " " << temp->data.getlevel() << " "<< temp->data.getselect() << " "\
        <<temp->data.getDay(1)<<" "<<temp->data.getHour(1)<<" "<<temp->data.getDay(2)<<" "<<temp->data.getHour(2)<<" "<<temp->data.getDay(3)<<" "<<temp->data.getHour(3)<<" "<<std::endl;
    }
    outfile.close();
}

template <class T1,class T2>
void File::readFile_Managers(string fname,ifstream &infile) {
    char *c;
    int index, pos;
    int flag;
    T2 t2;
    string s;
    getline(infile, data);
    if(data!="Manager"){throw "File error!";}
    while (true) {
        getline(infile, data);
        if (data == "Technician") {
            break;
        }
        for (index = 0, pos = 0, flag = 0, c = &data[0]; *c != '\0'; c++, index++) {
            if (*c == ' ') {
                flag++;
                s = data.substr(pos, index - pos);
                switch (flag) {
                    case 1:t2.setnum(stoi(s));break;
                    case 2:t2.setname(s);break;
                    case 3:t2.setsex(stoi(s));break;
                    case 4:t2.setsection(s);break;
                    case 5:t2.setlevel(stoi(s));t2.setselect(31);break;
                    case 6:t2.setTime(stod(s), 0, 0, 0, 0, 0);break;
                    case 7:t2.setTime(0, stod(s), 0, 0, 0, 0);break;
                    case 8:t2.setTime(0, 0, stod(s), 0, 0, 0);break;
                    case 9:t2.setTime(0, 0, 0, stod(s), 0, 0);break;
                    case 10:t2.setTime(0, 0, 0, 0, stod(s), 0);break;
                    case 11:t2.setTime(0, 0, 0, 0, 0,  stod(s));t2.setSelect(7);break;
                }
                pos = index + 1;
            }
        }Technician t;t.setnum(t2.getnum());SalesMan sale;sale.setnum(t2.getnum());SalesManager sm;sm.setnum(t2.getnum());
        if((Managers->Search(t2,1,0)==nullptr&&Technicians->Search(t,1,0)==nullptr&&SalesMans->Search(sale,1,0)==nullptr&&SalesManagers->Search(sm,1,0)==nullptr)&&(t2.getDay(2)*4+t2.getHour(2)<24)&&(t2.getDay(3)*4+t2.getHour(3)<16)){Managers->Add(t2);}
    }
    Managers->Sort();
    }
template <class T1,class T2>
void File::readFile_Technicians(string fname,ifstream &infile){
    char *c;
    int index, pos;
    int flag;
    T2 t2;
    string s;
    while (true) {
        getline(infile, data);
        if (data == "SalesMan") {
            break;
        }
        for (index = 0, pos = 0, flag = 0, c = &data[0]; *c != '\0'; c++, index++) {
            if (*c == ' ') {
                flag++;
                s = data.substr(pos, index - pos);
                switch (flag) {
                    case 1:t2.setnum(stoi(s));break;
                    case 2:t2.setname(s);break;
                    case 3:t2.setsex(stoi(s));break;
                    case 4:t2.setsection(s);break;
                    case 5:t2.setlevel(stoi(s));t2.setselect(31);break;
                    case 6:t2.setTime(stod(s), 0, 0, 0, 0, 0);break;
                    case 7:t2.setTime(0, stod(s), 0, 0, 0, 0);break;
                    case 8:t2.setTime(0, 0, stod(s), 0, 0, 0);break;
                    case 9:t2.setTime(0, 0, 0, stod(s), 0, 0);break;
                    case 10:t2.setTime(0, 0, 0, 0, stod(s), 0);break;
                    case 11:t2.setTime(0, 0, 0, 0, 0,  stod(s));t2.setSelect(7);break;
                }
                pos = index + 1;
            }
        }Manager m;m.setnum(t2.getnum());SalesMan sale;sale.setnum(t2.getnum());SalesManager sm;sm.setnum(t2.getnum());
        if((Managers->Search(m,1,0)==nullptr&&Technicians->Search(t2,1,0)==nullptr&&SalesMans->Search(sale,1,0)==nullptr&&SalesManagers->Search(sm,1,0)==nullptr)&&(t2.getDay(2)*4+t2.getHour(2)<24)&&(t2.getDay(3)*4+t2.getHour(3)<16)){Technicians->Add(t2);}
    }
    Technicians->Sort();
}
template <class T1,class T2>
void File::readFile_SalesMans(string fname,ifstream &infile){
    char *c;
    int index, pos;
    int flag;
    T2 t2;
    string s;
    while (true) {
        getline(infile, data);
        if (data == "SalesManager") {
            break;
        }
        for (index = 0, pos = 0, flag = 0, c = &data[0]; *c != '\0'; c++, index++) {
            if (*c == ' ') {
                flag++;
                s = data.substr(pos, index - pos);
                switch (flag) {
                    case 1:t2.setnum(stoi(s));break;
                    case 2:t2.setname(s);break;
                    case 3:t2.setsex(stoi(s));break;
                    case 4:t2.setsection(s);break;
                    case 5:t2.setlevel(stoi(s));t2.setselect(31);break;
                    case 6:t2.setTime(stod(s), 0, 0, 0, 0, 0);break;
                    case 7:t2.setTime(0, stod(s), 0, 0, 0, 0);break;
                    case 8:t2.setTime(0, 0, stod(s), 0, 0, 0);break;
                    case 9:t2.setTime(0, 0, 0, stod(s), 0, 0);break;
                    case 10:t2.setTime(0, 0, 0, 0, stod(s), 0);break;
                    case 11:t2.setTime(0, 0, 0, 0, 0,  stod(s));t2.setSelect(7);break;
                }
                pos = index + 1;
            }
        }Technician t;t.setnum(t2.getnum());Manager m;m.setnum(t2.getnum());SalesManager sm;sm.setnum(t2.getnum());
        if((Managers->Search(m,1,0)==nullptr&&Technicians->Search(t,1,0)==nullptr&&SalesMans->Search(t2,1,0)==nullptr&&SalesManagers->Search(sm,1,0)==nullptr)&&(t2.getDay(2)*4+t2.getHour(2)<24)&&(t2.getDay(3)*4+t2.getHour(3)<16)){SalesMans->Add(t2);}
    }
    SalesMans->Sort();return;
}
template <class T1,class T2>
void File::readFile_SalesManagers(string fname,ifstream &infile){
    char *c;
    int index, pos;
    int flag;
    T2 t2;
    string s;
    getline(infile, data);
    while (true) {
        if (data.empty()) {
            break;
        }
        for (index = 0, pos = 0, flag = 0, c = &data[0]; *c != '\0'; c++, index++) {
            if (*c == ' ') {
                flag++;
                s = data.substr(pos, index - pos);
                switch (flag) {
                    case 1:t2.setnum(stoi(s));break;
                    case 2:t2.setname(s);break;
                    case 3:t2.setsex(stoi(s));break;
                    case 4:t2.setsection(s);break;
                    case 5:t2.setlevel(stoi(s));t2.setselect(31);break;
                    case 6:t2.setTime(stod(s), 0, 0, 0, 0, 0);break;
                    case 7:t2.setTime(0, stod(s), 0, 0, 0, 0);break;
                    case 8:t2.setTime(0, 0, stod(s), 0, 0, 0);break;
                    case 9:t2.setTime(0, 0, 0, stod(s), 0, 0);break;
                    case 10:t2.setTime(0, 0, 0, 0, stod(s), 0);break;
                    case 11:t2.setTime(0, 0, 0, 0, 0,  stod(s));t2.setSelect(7);break;
                }
                pos = index + 1;
            }
        }Technician t;t.setnum(t2.getnum());SalesMan sale;sale.setnum(t2.getnum());Manager m;m.setnum(t2.getnum());
        if((Managers->Search(m,1,0)==nullptr&&Technicians->Search(t,1,0)==nullptr&&SalesMans->Search(sale,1,0)==nullptr&&SalesManagers->Search(t2,1,0)==nullptr)&&(t2.getDay(2)*4+t2.getHour(2)<24)&&(t2.getDay(3)*4+t2.getHour(3)<16)){SalesManagers->Add(t2);}
    }
    SalesManagers->Sort();return;
}