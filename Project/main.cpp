#include "File.cpp"
#include "LinkedList.cpp"
#include "Person.cpp"
#include <windows.h>
using namespace std;

void color(int a=7){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);}
void getTime(){string dayofweek;SYSTEMTIME sys;GetLocalTime( &sys );switch(sys.wDayOfWeek){case 1:dayofweek="一";break; case 2: dayofweek="二";break; case 3:dayofweek="三";break; case 4:dayofweek="四";break; case 5:dayofweek="五";break; case 6:dayofweek="六";break; case 7:dayofweek="日";break;}printf("%4d/%02d/%02d %02d:%02d:%02d 星期", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond);cout<<dayofweek<<endl;}
void Add();
void Write();
void Read();
void Search();
void View();
void Edit();
void Delete();

int main() {
    //初始化，建立四个链表
    Managers =new LinkedList<Node<Manager>,Manager>;
    Technicians= new LinkedList<Node<Technician>, Technician>;
    SalesMans =new LinkedList<Node<SalesMan>,SalesMan>;
    SalesManagers =new LinkedList<Node<SalesManager>,SalesManager>;
    while(true){
        cout<<endl<<"您好！现在是";getTime();
        color(2);
        cout<<"##############################################"<<endl;
        cout<<"#            公司员工考勤管理系统            #"<<endl;
        cout<<"#                                            #"<<endl;
        cout<<"#                 1、添加人员                #"<<endl;
        cout<<"#                 2、查询信息                #"<<endl;
        cout<<"#                 3、显示记录                #"<<endl;
        cout<<"#                 4、编辑信息                #"<<endl;
        cout<<"#                 5、删除信息                #"<<endl;
        cout<<"#                 6、保存信息                #"<<endl;
        cout<<"#                 7、读取信息                #"<<endl;
        cout<<"#                 8、退出系统                #"<<endl;
        cout<<"#                                            #"<<endl;
        cout<<"#                Hello World!                #"<<endl;
        cout<<"##############################################"<<endl;
        cout<<"请输入你的选择：";
        color();
        int a;
        cin>>a;
        switch(a){
            case 1:Add();break;
            case 2:Search();break;
            case 3:View();break;
            case 4:Edit();break;
            case 5:Delete();break;
            case 6:Write();break;
            case 7:Read();break;
            case 8:cout<<"再见~"<<endl;return 0;
            default:cout<<"输入错误！请重新输入";break;
        }
    }
}
void Add(){
    int a;
    cout<<"请输入你打算添加人员的职位，经理输入1，技术人员输入2，销售人员输入3，销售经理输入4，退出输入0。";
    cin>>a;
    string data,s;
    int index,pos,flag;
    char *c;
    Manager m;m.setselect(16);
    Technician t;t.setselect(16);
    SalesMan sale;sale.setselect(16);
    SalesManager sm;sm.setselect(16);
    switch(a){
        case 0:return;
        case 1:
            cout<<"请以空格为分隔符，按照编号，姓名，性别（男为1，女为-1），部门，级别，已工作日长，已工作时长，已带薪休假日长，已带薪休假时长，已请病假日长，已请病假时长的顺序，在一行中输入该人员的各种信息，以回车结尾"<<endl;
            cout<<"示例：1 张三 1 售前 0 0 0 0 0 0 0"<<endl;
            getchar();
            getline(std::cin,data);
            for(index=0,pos=0,flag=0,c=&data[0];*c!='\0';c++,index++){
                if(*c==' '){
                flag++;
                s=data.substr(pos,index-pos);
                switch(flag){ // NOLINT(hicpp-multiway-paths-covered)
                    case 1:m.setnum(stoi(s));break;
                    case 2:m.setname(s);break;
                    case 3:m.setsex(stoi(s));break;
                    case 4:m.setsection(s);break;
                    case 5:m.setlevel(stoi(s));break;
                    case 6:m.setTime(stod(s),0,0,0,0,0);break;
                    case 7:m.setTime(0,stod(s),0,0,0,0);break;
                    case 8:m.setTime(0,0,stod(s),0,0,0);break;
                    case 9:m.setTime(0,0,0,stod(s),0,0);break;
                    case 10:m.setTime(0,0,0,0,stod(s),0);break;
                    case 11:m.setTime(0,0,0,0,0,stod(s));m.setSelect(4);break;
                }
                pos=index+1;
                }
            }if(m.getDay(2)*4+m.getHour(2)>24){cout<<"带薪休假时间过长！";return;}if(m.getDay(3)*4+m.getHour(3)>16){cout<<"病假时间过长！";return;}t.setnum(m.getnum());sale.setnum(m.getnum());sm.setnum(m.getnum());
            if(Managers->Search(m,1,0)==nullptr&&Technicians->Search(t,1,0)==nullptr&&SalesMans->Search(sale,1,0)==nullptr&&SalesManagers->Search(sm,1,0)==nullptr){Managers->Add(m);Managers->Sort();}else{cout<<"员工号码已存在！";}
            return;
        case 2:
            cout<<"请以空格为分隔符，按照编号，姓名，性别（男为1，女为-1），部门，级别，已工作日长，已工作时长，已带薪休假日长，已带薪休假时长，已请病假日长，已请病假时长的顺序，在一行中输入该人员的各种信息，以回车结尾"<<endl;
            cout<<"示例：1 张三 1 售前 0 0 0 0 0 0 0"<<endl;
            getchar();
            getline(std::cin,data);
            for(index=0,pos=0,flag=0,c=&data[0];*c!='\0';c++,index++){
                if(*c==' '){
                    flag++;
                    s=data.substr(pos,index-pos);
                    switch(flag){ // NOLINT(hicpp-multiway-paths-covered)
                        case 1:t.setnum(stoi(s));break;
                        case 2:t.setname(s);break;
                        case 3:t.setsex(stoi(s));break;
                        case 4:t.setsection(s);break;
                        case 5:t.setlevel(stoi(s));break;
                        case 6:t.setTime(stod(s),0,0,0,0,0);break;
                        case 7:t.setTime(0,stod(s),0,0,0,0);break;
                        case 8:t.setTime(0,0,stod(s),0,0,0);break;
                        case 9:t.setTime(0,0,0,stod(s),0,0);break;
                        case 10:t.setTime(0,0,0,0,stod(s),0);break;
                        case 11:t.setTime(0,0,0,0,0,stod(s));t.setSelect(4);break;
                    }
                    pos=index+1;
                }
            }if(t.getDay(2)*4+t.getHour(2)>24){cout<<"带薪休假时间过长！";return;}if(t.getDay(3)*4+t.getHour(3)>16){cout<<"病假时间过长！";return;}
            m.setnum(t.getnum());sale.setnum(t.getnum());sm.setnum(t.getnum());
            if(Managers->Search(m,1,0)==nullptr&&Technicians->Search(t,1,0)==nullptr&&SalesMans->Search(sale,1,0)==nullptr&&SalesManagers->Search(sm,1,0)==nullptr){Technicians->Add(t);Technicians->Sort();}else{cout<<"员工号码已存在！";}
            return;
        case 3:
            cout<<"请以空格为分隔符，按照编号，姓名，性别（男为1，女为-1），部门，级别，已工作日长，已工作时长，已带薪休假日长，已带薪休假时长，已请病假日长，已请病假时长的顺序，在一行中输入该人员的各种信息，以回车结尾"<<endl;
            cout<<"示例：1 张三 1 售前 0 0 0 0 0 0 0"<<endl;
            getchar();
            getline(std::cin,data);
            for(index=0,pos=0,flag=0,c=&data[0];*c!='\0';c++,index++){
                if(*c==' '){
                    flag++;
                    s=data.substr(pos,index-pos);
                    switch(flag){ // NOLINT(hicpp-multiway-paths-covered)
                        case 1:sale.setnum(stoi(s));break;
                        case 2:sale.setname(s);break;
                        case 3:sale.setsex(stoi(s));break;
                        case 4:sale.setsection(s);break;
                        case 5:sale.setlevel(stoi(s));break;
                        case 6:sale.setTime(stod(s),0,0,0,0,0);break;
                        case 7:sale.setTime(0,stod(s),0,0,0,0);break;
                        case 8:sale.setTime(0,0,stod(s),0,0,0);break;
                        case 9:sale.setTime(0,0,0,stod(s),0,0);break;
                        case 10:sale.setTime(0,0,0,0,stod(s),0);break;
                        case 11:sale.setTime(0,0,0,0,0,stod(s));sale.setSelect(4);break;
                    }
                    pos=index+1;
                }
            }if(sale.getDay(2)*4+sale.getHour(2)>24){cout<<"带薪休假时间过长！";return;}if(sale.getDay(3)*4+sale.getHour(3)>16){cout<<"病假时间过长！";return;}
            m.setnum(sale.getnum());t.setnum(sale.getnum());sm.setnum(sale.getnum());
            if(Managers->Search(m,1,0)==nullptr&&Technicians->Search(t,1,0)==nullptr&&SalesMans->Search(sale,1,0)==nullptr&&SalesManagers->Search(sm,1,0)==nullptr){SalesMans->Add(sale);SalesMans->Sort();}else{cout<<"员工号码已存在！";}
            return;
        case 4:
            cout<<"请以空格为分隔符，按照编号，姓名，性别（男为1，女为-1），部门，级别，已工作日长，已工作时长，已带薪休假日长，已带薪休假时长，已请病假日长，已请病假时长的顺序，在一行中输入该人员的各种信息，以回车结尾"<<endl;
            cout<<"示例：1 张三 1 售前 0 0 0 0 0 0 0"<<endl;
            getchar();
            getline(std::cin,data);
            for(index=0,pos=0,flag=0,c=&data[0];*c!='\0';c++,index++){
                if(*c==' '){
                    flag++;
                    s=data.substr(pos,index-pos);
                    switch(flag){ // NOLINT(hicpp-multiway-paths-covered)
                        case 1:sm.setnum(stoi(s));break;
                        case 2:sm.setname(s);break;
                        case 3:sm.setsex(stoi(s));break;
                        case 4:sm.setsection(s);break;
                        case 5:sm.setlevel(stoi(s));break;
                        case 6:sm.setTime(stod(s),0,0,0,0,0);break;
                        case 7:sm.setTime(0,stod(s),0,0,0,0);break;
                        case 8:sm.setTime(0,0,stod(s),0,0,0);break;
                        case 9:sm.setTime(0,0,0,stod(s),0,0);break;
                        case 10:sm.setTime(0,0,0,0,stod(s),0);break;
                        case 11:sm.setTime(0,0,0,0,0,stod(s));sm.setSelect(4);break;
                    }
                    pos=index+1;
                }
            }if(sm.getDay(2)*4+sm.getHour(2)>24){cout<<"带薪休假时间过长！";return;}if(sm.getDay(3)*4+sm.getHour(3)>16){cout<<"病假时间过长！";return;}
            m.setnum(sm.getnum());t.setnum(sm.getnum());sale.setnum(sm.getnum());
            if(Managers->Search(m,1,0)==nullptr&&Technicians->Search(t,1,0)==nullptr&&SalesMans->Search(sale,1,0)==nullptr&&SalesManagers->Search(sm,1,0)==nullptr){SalesManagers->Add(sm);SalesManagers->Sort();}else{cout<<"员工号码已存在！";}
            return;
        default:cout<<"输入错误！"<<endl;break;
    }
}
void Write(){
    cout<<"请输入要写入的文件名（如果已存在会覆盖）,输入0为默认（1.dat）"<<endl;
    string s;
    cin>>s;
    if(s=="0"){s="1.dat";}
    File f;
    f.writeFile_Managers<LinkedList<Node<Manager>,Manager>,Manager>(s);
    f.writeFile_Technicians<LinkedList<Node<Technician>,Technician>,Technician>(s);
    f.writeFile_SalesMans<LinkedList<Node<SalesMan>,SalesMan>,SalesMan>(s);
    f.writeFile_SalesManagers<LinkedList<Node<SalesManager>,SalesManager>,SalesManager>(s);
}
void Read(){
    cout<<"请输入要读取的文件名,输入0为默认（1.dat）"<<endl;
    string s;
    cin>>s;
    if(s=="0"){s="1.dat";}
    File f;
    ifstream infile;
    infile.open(s,ios::in);
    try {
        f.readFile_Managers<LinkedList<Node<Manager>,Manager>,Manager>(s,infile);
    }catch(string e){
        cout<<e<<endl;return;
    }
    f.readFile_Technicians<LinkedList<Node<Technician>,Technician>,Technician>(s,infile);
    f.readFile_SalesMans<LinkedList<Node<SalesMan>,SalesMan>,SalesMan>(s,infile);
    f.readFile_SalesManagers<LinkedList<Node<SalesManager>,SalesManager>,SalesManager>(s,infile);
    infile.close();
}
void Search(){
    int i,i1,a;
    string s;
    cout<<"本系统支持根据单一确定条件的查询和单一条件的范围查询！请选择你要的查询方式"<<endl;
    cout<<"确定查询请输入1，范围查询请输入2：";
    cin>>a;
    Manager m;Technician t;SalesMan sale;SalesManager sm;
    Manager m1;Technician t1;SalesMan sale1;SalesManager sm1;
    vector<Node<Manager> > *vecm;vector<Node<Technician> > *vect;vector<Node<SalesMan> > *vecs;vector<Node<SalesManager> > *vecsm;
    vector<Node<Manager> >::iterator itm;vector<Node<Technician> >::iterator itt;vector<Node<SalesMan> >::iterator its;vector<Node<SalesManager> >::iterator itsm;
    if(a==1){
        while(true){
            cout<<"请输入你要查询的条件，员工编号请输入1，姓名请输入2，性别请输入3，部门请输入4，级别请输入5，工作时间请输入6，带薪休假时间请输入7，生病请假时间请输入8，结束请输入9：";
            cin>>a;
            switch(a){
                case 1:
                    cout<<"请输入你要查询的员工编号：";
                    cin>>i;m.setnum(i);t.setnum(i);sale.setnum(i);sm.setnum(i);
                    vecm=Managers->Search(m,1,0);vect=Technicians->Search(t,1,0);vecs=SalesMans->Search(sale,1,0);vecsm=SalesManagers->Search(sm,1,0);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";break;}
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                    break;
                case 2:cout<<"请输入你要查询的员工姓名：";
                    cin>>s;m.setname(s);t.setname(s);sale.setname(s);sm.setname(s);
                    vecm=Managers->Search(m,2,0);vect=Technicians->Search(t,2,0);vecs=SalesMans->Search(sale,2,0);vecsm=SalesManagers->Search(sm,2,0);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";break;}
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                case 3:cout<<"请输入你要查询的员工性别(男为1，女为-1)：";
                    cin>>i;if(i!=1&&i!=-1){cout<<"输入错误!";break;}
                    m.setsex(i);t.setsex(i);sale.setsex(i);sm.setsex(i);
                    vecm=Managers->Search(m,4,0);vect=Technicians->Search(t,4,0);vecs=SalesMans->Search(sale,4,0);vecsm=SalesManagers->Search(sm,4,0);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";break;}
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                case 4:cout<<"请输入你要查询的部门名称：";
                    cin>>s;m.setsection(s);t.setsection(s);sale.setsection(s);sm.setsection(s);
                    vecm=Managers->Search(m,8,0);vect=Technicians->Search(t,8,0);vecs=SalesMans->Search(sale,8,0);vecsm=SalesManagers->Search(sm,8,0);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";break;}
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                case 5:cout<<"请输入你要查询的员工级别：";
                    cin>>i;m.setlevel(i);t.setlevel(i);sale.setlevel(i);sm.setlevel(i);
                    vecm=Managers->Search(m,16,0);vect=Technicians->Search(t,16,0);vecs=SalesMans->Search(sale,16,0);vecsm=SalesManagers->Search(sm,16,0);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";break;}
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                case 6:cout<<"请输入你要查询的工作时间(小时数)：";
                    cin>>i;m.setTime(0,i,0,0,0,0);t.setTime(0,i,0,0,0,0);sale.setTime(0,i,0,0,0,0);sm.setTime(0,i,0,0,0,0);
                    vecm=Managers->Search(m,0,1);vect=Technicians->Search(t,0,1);vecs=SalesMans->Search(sale,0,1);vecsm=SalesManagers->Search(sm,0,1);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";break;}
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                case 7:cout<<"请输入你要查询的带薪休假时间(小时数)：";
                    cin>>i;m.setTime(0,0,0,i,0,0);t.setTime(0,0,0,i,0,0);sale.setTime(0,0,0,i,0,0);sm.setTime(0,0,0,i,0,0);
                    vecm=Managers->Search(m,0,2);vect=Technicians->Search(t,0,2);vecs=SalesMans->Search(sale,0,2);vecsm=SalesManagers->Search(sm,0,2);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";break;}
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                case 8:cout<<"请输入你要查询的病假时间(小时数)：";
                    cin>>i;m.setTime(0,0,0,0,0,i);t.setTime(0,0,0,0,0,i);sale.setTime(0,0,0,0,0,i);sm.setTime(0,0,0,0,0,i);
                    vecm=Managers->Search(m,0,2);vect=Technicians->Search(t,0,2);vecs=SalesMans->Search(sale,0,2);vecsm=SalesManagers->Search(sm,0,2);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";break;}
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                case 9: return;     
                default:cout<<"输入错误！"<<endl;break;
            }
        }
    }else if(a==2){
        cout<<"请输入你要查询的条件，员工编号请输入1，级别请输入2，工作时间请输入3，带薪休假时间请输入4，生病请假时间请输入5，结束请输入6：";
        cin>>a;
        switch(a){
            case 1:
                cout<<"请输入你要查询的员工编号范围（不包括）,以空格分隔：";
                cin>>i>>i1;
                vecm=Managers->RangeSearch(m,m1,1,0);vect=Technicians->RangeSearch(t,t1,1,0);vecs=SalesMans->RangeSearch(sale,sale1,1,0);vecsm=SalesManagers->RangeSearch(sm,sm1,1,0);
                if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此类员工！";break;}
                if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                break;
            case 2:cout<<"请输入你要查询的员工级别范围（不包括）,以空格分隔：";
                cin>>i>>i1;
                vecm=Managers->RangeSearch(m,m1,16,0);vect=Technicians->RangeSearch(t,t1,16,0);vecs=SalesMans->RangeSearch(sale,sale1,16,0);vecsm=SalesManagers->RangeSearch(sm,sm1,16,0);
                if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此类员工！";break;}
                if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                break;
            case 3:cout<<"请输入你要查询的员工工作时间（小时）范围（不包括）,以空格分隔：";
                cin>>i>>i1;
                vecm=Managers->RangeSearch(m,m1,0,1);vect=Technicians->RangeSearch(t,t1,0,1);vecs=SalesMans->RangeSearch(sale,sale1,0,1);vecsm=SalesManagers->RangeSearch(sm,sm1,0,1);
                if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此类员工！";break;}
                if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                break;
            case 4:cout<<"请输入你要查询的员工带薪休假时间（小时）范围（不包括）,以空格分隔：";
                cin>>i>>i1;
                vecm=Managers->RangeSearch(m,m1,0,2);vect=Technicians->RangeSearch(t,t1,0,2);vecs=SalesMans->RangeSearch(sale,sale1,0,2);vecsm=SalesManagers->RangeSearch(sm,sm1,0,2);
                if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此类员工！";break;}
                if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}
                break;
            case 5:cout<<"请输入你要查询的员工病假时间（小时）范围（不包括）,以空格分隔：";
                cin>>i>>i1;
                vecm=Managers->RangeSearch(m,m1,0,4);vect=Technicians->RangeSearch(t,t1,0,4);vecs=SalesMans->RangeSearch(sale,sale1,0,4);vecsm=SalesManagers->RangeSearch(sm,sm1,0,4);
                if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此类员工！";break;}
                if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){cout<<itm->data;}}
                if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){cout<<itt->data;}}
                if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){cout<<its->data;}}
                if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){cout<<itsm->data;}}break;
            case 6:return;
            default:cout<<"输入错误！"<<endl;break;
        }
    }else{cout<<"输入错误！请重新选择";}
}
void View(){
    Managers->View();Technicians->View();SalesMans->View();SalesManagers->View();
}
void Edit(){
    int i,a;
    string s;
    cout<<"本系统暂时仅支持根据单一确定条件的修改(因为作者肝莫得了)！"<<endl;
    Manager m;Technician t;SalesMan sale;SalesManager sm;
    Manager m1;Technician t1;SalesMan sale1;SalesManager sm1;
    vector<Node<Manager>* > *vecm;vector<Node<Technician>* > *vect;vector<Node<SalesMan>* > *vecs;vector<Node<SalesManager>* > *vecsm;
    vector<Node<Manager>* >::iterator itm;vector<Node<Technician>* >::iterator itt;vector<Node<SalesMan>* >::iterator its;vector<Node<SalesManager>* >::iterator itsm;
        while(true){
            cout<<"请输入你要查询的条件，员工编号请输入1，姓名请输入2，性别请输入3，部门请输入4，级别请输入5，工作时间请输入6，带薪休假时间请输入7，生病请假时间请输入8，结束请输入9：";
            cin>>a;
            switch(a){
                case 1:
                    cout<<"请输入你要修改的员工编号：";
                    cin>>i;m.setnum(i);t.setnum(i);sale.setnum(i);sm.setnum(i);
                    vecm=Managers->Edit(m,1,0);vect=Technicians->Edit(t,1,0);vecs=SalesMans->Edit(sale,1,0);vecsm=SalesManagers->Edit(sm,1,0);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";return;}
                    break;
                case 2:cout<<"请输入你要修改的员工姓名：";
                    cin>>s;m.setname(s);t.setname(s);sale.setname(s);sm.setname(s);
                    vecm=Managers->Edit(m,2,0);vect=Technicians->Edit(t,2,0);vecs=SalesMans->Edit(sale,2,0);vecsm=SalesManagers->Edit(sm,2,0);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";return;}
                case 3:cout<<"请输入你要修改的员工性别(男为1，女为-1)：";
                    cin>>i;if(i!=1&&i!=-1){cout<<"输入错误!";break;}
                    m.setsex(i);t.setsex(i);sale.setsex(i);sm.setsex(i);
                    vecm=Managers->Edit(m,4,0);vect=Technicians->Edit(t,4,0);vecs=SalesMans->Edit(sale,4,0);vecsm=SalesManagers->Edit(sm,4,0);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";return;}
                case 4:cout<<"请输入你要修改的部门名称：";
                    cin>>s;m.setsection(s);t.setsection(s);sale.setsection(s);sm.setsection(s);
                    vecm=Managers->Edit(m,8,0);vect=Technicians->Edit(t,8,0);vecs=SalesMans->Edit(sale,8,0);vecsm=SalesManagers->Edit(sm,8,0);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";return;}
                case 5:cout<<"请输入你要修改的员工级别：";
                    cin>>i;m.setlevel(i);t.setlevel(i);sale.setlevel(i);sm.setlevel(i);
                    vecm=Managers->Edit(m,16,0);vect=Technicians->Edit(t,16,0);vecs=SalesMans->Edit(sale,16,0);vecsm=SalesManagers->Edit(sm,16,0);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";return;}
                case 6:cout<<"请输入你要修改的工作时间(小时数)：";
                    cin>>i;m.setTime(0,i,0,0,0,0);t.setTime(0,i,0,0,0,0);sale.setTime(0,i,0,0,0,0);sm.setTime(0,i,0,0,0,0);
                    vecm=Managers->Edit(m,0,1);vect=Technicians->Edit(t,0,1);vecs=SalesMans->Edit(sale,0,1);vecsm=SalesManagers->Edit(sm,0,1);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";return;}
                case 7:cout<<"请输入你要修改的带薪休假时间(小时数)：";
                    cin>>i;m.setTime(0,0,0,i,0,0);t.setTime(0,0,0,i,0,0);sale.setTime(0,0,0,i,0,0);sm.setTime(0,0,0,i,0,0);
                    vecm=Managers->Edit(m,0,2);vect=Technicians->Edit(t,0,2);vecs=SalesMans->Edit(sale,0,2);vecsm=SalesManagers->Edit(sm,0,2);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";return;}
                case 8:cout<<"请输入你要修改的病假时间(小时数)：";
                    cin>>i;m.setTime(0,0,0,0,0,i);t.setTime(0,0,0,0,0,i);sale.setTime(0,0,0,0,0,i);sm.setTime(0,0,0,0,0,i);
                    vecm=Managers->Edit(m,0,2);vect=Technicians->Edit(t,0,2);vecs=SalesMans->Edit(sale,0,2);vecsm=SalesManagers->Edit(sm,0,2);
                    if(vecm==nullptr&&vect==nullptr&&vecs==nullptr&&vecsm==nullptr){cout<<"无此员工！";return;}
                case 9: return;
                default:cout<<"输入错误！"<<endl;return;
            }
            cout<<"请输入你要修改的数据，员工编号请输入1，姓名请输入2，性别请输入3，部门请输入4，级别请输入5，工作时间请输入6，带薪休假时间请输入7，生病请假时间请输入8，结束请输入9：";
            cin>>a;
            switch(a){
                case 1:
                    cout<<"请输入修改后的员工编号：";cin>>i;
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){(*itm)->data.setnum(i);}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){(*itt)->data.setnum(i);}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){(*its)->data.setnum(i);}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){(*itsm)->data.setnum(i);}}
                    break;
                case 2:
                    cout<<"请输入修改后的员工姓名：";cin>>s;
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){(*itm)->data.setname(s);}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){(*itt)->data.setname(s);}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){(*its)->data.setname(s);}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){(*itsm)->data.setname(s);}}
                    break;
                case 3:
                    cout<<"请输入修改后的员工性别(男为1，女为-1)：";cin>>i;
                    if(i!=1&&i!=-1){cout<<"输入错误！";return;}
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){(*itm)->data.setsex(i);}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){(*itt)->data.setsex(i);}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){(*its)->data.setsex(i);}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){(*itsm)->data.setsex(i);}}
                    break;
                case 4:
                    cout<<"请输入修改后的员工部门：";cin>>s;
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){(*itm)->data.setsection(s);}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){(*itt)->data.setsection(s);}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){(*its)->data.setsection(s);}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){(*itsm)->data.setsection(s);}}
                    break;
                case 5:
                    cout<<"请输入修改后的员工级别：";cin>>i;
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){(*itm)->data.setlevel(i);}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){(*itt)->data.setlevel(i);}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){(*its)->data.setlevel(i);}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){(*itsm)->data.setlevel(i);}}
                    break;
                case 6:
                    cout<<"请输入修改后的员工工作时间（小时）：";cin>>i;
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){(*itm)->data.setTime(0,i,0,0,0,0);}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){(*itt)->data.setTime(0,i,0,0,0,0);}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){(*its)->data.setTime(0,i,0,0,0,0);}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){(*itsm)->data.setTime(0,i,0,0,0,0);}}
                    break;
                case 7:
                    cout<<"请输入修改后的员工带薪休假时间（小时）：";cin>>i;if(i>24){cout<<"时间超过规定！"<<endl;return;}
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){(*itm)->data.setTime(0,0,0,i,0,0);}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){(*itt)->data.setTime(0,0,0,i,0,0);}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){(*its)->data.setTime(0,0,0,i,0,0);}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){(*itsm)->data.setTime(0,0,0,i,0,0);}}
                    break;
                case 8:
                    cout<<"请输入修改后的员工病假时间（小时）：";cin>>i;if(i>16){cout<<"时间超过规定！"<<endl;return;}
                    if(vecm!=nullptr){for(itm=vecm->begin();itm!=vecm->end();itm++){(*itm)->data.setTime(0,0,0,0,0,i);}}
                    if(vect!=nullptr){for(itt=vect->begin();itt!=vect->end();itt++){(*itt)->data.setTime(0,0,0,0,0,i);}}
                    if(vecs!=nullptr){for(its=vecs->begin();its!=vecs->end();its++){(*its)->data.setTime(0,0,0,0,0,i);}}
                    if(vecsm!=nullptr){for(itsm=vecsm->begin();itsm!=vecsm->end();itsm++){(*itsm)->data.setTime(0,0,0,0,0,i);}}
                    break;
                case 9:return;
            }
        }

}
void Delete(){
    int i;
    cout<<"本系统支持以员工编号为键值的删除！"<<endl;
    cout<<"请输入你要删除信息的员工编号：";cin>>i;
    Manager m;Technician t;SalesMan sale;SalesManager sm;
    m.setnum(i);t.setnum(i);sale.setnum(i);sm.setnum(i);
    i=Managers->Delete(m)+Technicians->Delete(t)+SalesMans->Delete(sale)+SalesManagers->Delete(sm);
    if(i==0){cout<<"无此用户！";}
    if(i==1){cout<<"删除成功！";}
}