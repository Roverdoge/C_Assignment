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
    Node<T2> *temp=new Node<T2>(t1, head);
    head=temp;
    length++;
}

template<class T1,class T2>
int LinkedList<T1,T2>::Delete(T2 t1) {
    t1.setselect(1);
    //查找删除位置
    Node<T2> *temp=head;
    if(t1==temp->data){
        head=temp->next;
        delete temp;
        length--;
        return 1;
    }
    for(;temp->next!= nullptr;temp=temp->next){
        if(t1 == temp->next->data ){
            Node<T2> *temp2=temp->next->next;
            delete temp->next;
            length--;
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




