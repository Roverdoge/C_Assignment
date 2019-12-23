//
// Created by ROVERDOGE on 2019/12/15.
//

#include "LinkedList.h"

template<class T1,class T2>
LinkedList<T1,T2>::LinkedList() {
    head= new Node<T2>;
    head->next=nullptr;
    length=0;
}
template<class T1,class T2>
bool cmp(T1 t1,T1 t2) {return t1.data.getnum()>t2.data.getnum();}

template<class T1,class T2>
vector<T1>* LinkedList<T1,T2>::Search(T2 t1,int s1,int s2) {
    static vector<T1> vec;
    vec.clear();
    Node<T2>* temp=head;
    for(;temp->next!= nullptr;temp=temp->next){
        temp->data.setselect(s1);temp->data.setSelect(s2);
        if(t1 == temp->data){temp->data.setselect(32),temp->data.setSelect(7);vec.push_back(*temp);}
    }
    //如果vec为空，返回空指针
    if(vec.empty()){return nullptr;}
    //如果vector不为空，根据num排序后返回vec的地址
    if(vec.size() <= 1) return &vec;
    Node<T2> *p = &vec[0];
    Node<T2> *q;
    //TODO::Node<T> *p = head->next;可能有问题（大概率没问题）
    for(int i=0;i<vec.size()-1;i++){
        for (int j=i+1;j<vec.size();j++){
            q=&vec[j];
            if(p->data.getnum()>q->data.getnum()){
                T2 temp = q->data;
                q->data = p->data;
                p->data = temp;
            }
        }
        p = p->next;
    }
    return &vec;
}

template<class T1,class T2>
void LinkedList<T1,T2>::Add(T2 t1) {
    //TODO::记得在最大的vector数组里进行search，查看编号是否重复
    Node<T2> *temp=new Node<T2>(t1, head);
    head=temp;
    length++;
}

template<class T1,class T2>
int LinkedList<T1,T2>::Delete(T2 t1) {
    t1.setselect(1);
    //查找删除位置
    Node<T2> *temp=head;
    for(;temp->next!= nullptr;temp=temp->next){
        if(t1 == temp->next->data ){
            Node<T2> *temp2=temp->next->next;
            delete temp->next;
            temp->next=temp2;
            return 1;
        }
    }
    return 0;
}

template<class T1,class T2>
void LinkedList<T1,T2>::View() {
    Node<T2>* node;
    for(node=head;node->next!=nullptr;node=node->next){
        node->data.setselect(31);
        node->data.setSelect(7);
        std::cout<<node->data;
    }
}

template<class T1,class T2>
LinkedList<T1,T2>::~LinkedList() {
    while(head->next!= nullptr){
        Node<T2>* temp =head;
        head=head->next;
        delete temp;
        length--;
    }
    if(length==0){
        delete head;
    }
}


template<class T1,class T2>
vector<T1*>* LinkedList<T1,T2>::Edit(T2 t1,int s1,int s2) {
    int local_length=0;
    static vector<T1*> vec;
    vec.clear();
    Node<T2>* temp=head;
    for(;temp->next!= nullptr;temp=temp->next){
        temp->data.setselect(s1);temp->data.setSelect(s2);
        if(t1 == temp->data){temp->data.setselect(32),temp->data.setSelect(7);vec.push_back(temp);}
    }
    //如果vec为空，返回0
    if(vec.empty()){return nullptr;}
    //如果vector不为空，根据num排序后返回vec的地址
    if(vec.size() > 1){
        Node<T2> **p = &vec[0];
        Node<T2> **q;
        //TODO::Node<T> *p = head->next;可能有问题（大概率没问题）
        for(int i=0;i<vec.size()-1;i++){
            for (int j=i+1;j<vec.size();j++){
                q=&vec[j];
                if((*p)->data.getnum()>(*q)->data.getnum()){
                    T2 temp = (*q)->data;
                    (*q)->data = (*p)->data;
                    (*p)->data = temp;
                }
            }
            *p = (*p)->next;
        }
    }
    return &vec;
   /* vector<T1*>::iterator it;
    for(it=vec.begin();it!=vec->end();it++){
        int i=it->data->getselect();
        int j=it->data->getSelect();
        if(i>0){
            switch(i){
                case 1: *node->data.setnum(t1.getnum());break;
                case 2: *node->data.setname(t1.getname());break;
                case 4: *node->data.setsex(t1.getsex());break;
                case 8: *node->data.setsection(t1.getsection());break;
                case 16:*node->data.setlevel(t1.getlevel());break;
            }
            local_length++;
        }else{
            if(j>0){
                switch(j){
                    //TODO::what the hell?
                    case 1:return ((this->work_day)*4+this->work_hour)<(t1.getDay(1) * 4 + t1.getHour(1));
                    case 2:return ((this->holiday_day)*4+this->holiday_hour)<(t1.getDay(2) * 4 + t1.getHour(2));
                    case 4:return ((this->notwork_day)*4+this->notwork_hour)<(t1.getDay(3) * 4 + t1.getHour(3));
                }
                local_length++;
            }
        }
    }*/
}

template<class T1,class T2>
vector<T1> *LinkedList<T1,T2>::RangeSearch(T2 t1, T2 t2,int s1,int s2) {
    static vector<T1> vec;
    vec.clear();
    Node<T2>* temp=head;
    t1.setselect(s1);t1.setSelect(s2);t2.setselect(s1);t2.setSelect(s2);
    if(t1 > t2){
        for(;temp->next!= nullptr;temp=temp->next){
            temp->data.setselect(s1);temp->data.setSelect(s2);
            if((t1 > temp->data) && (temp->data > t2)){vec.push_back(*temp);}
        }
        return &vec;
    }else{
        for(;temp->next!= nullptr;temp=temp->next){
            temp->data.setselect(s1);temp->data.setSelect(s2);
            if((t1 < temp->data) && (temp->data < t2)){vec.push_back(*temp);}
        }
        return &vec;
    }
}

template<class T1,class T2>
void LinkedList<T1,T2>::Sort() {
    if(length <= 1) return;
    Node<T2> *p = head;
    //TODO::Node<T> *p = head->next;可能有问题（大概率没问题）
    for(int i=0;i<length-1;i++){
        Node<T2> *q = p->next;
    for (int j=i+1;j<length;j++){
        if(p->data.getnum()>q->data.getnum()){
            T2 temp = q->data;
            q->data = p->data;
            p->data = temp;
        }
        q=q->next;
    }
    p = p->next;
    }
}




