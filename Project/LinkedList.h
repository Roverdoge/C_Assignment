//
// Created by ROVERDOGE on 2019/12/15.
//
#include<iostream>
#include <vector>
#include <algorithm>
#include "Person.h"
#ifndef PROJECT_LINKEDLIST_H
#define PROJECT_LINKEDLIST_H
using namespace std;


template <class T>
class Node{
public:
    Node<T>(){};
    Node<T>(const T &T1,Node<T> *next){this->data=T1;this->next=next;}
    T data;
    Node *next;
};
template <class T1/*LinkedList*/,class T2/*Person*/>
class LinkedList{
public:
    LinkedList();//initializing
    ~LinkedList();//delete all
    void Add(T2);
    int Delete(T2);
    vector<T1>* Search(T2,int,int);//return pointer to a vector container.
    vector<T1>* RangeSearch(T2,T2,int,int);
    void View();//
    vector<T1*>* Edit(T2,int,int);
    void Sort();
    Node<T2>* gethead(){return this->head;}
    //vector's sort rule

private:
    Node<T2> *head;
    int length;
};

static LinkedList<Node<Manager>,Manager> *Managers;

static LinkedList<Node<Technician>,Technician> *Technicians;

static LinkedList<Node<SalesMan>,SalesMan> *SalesMans;

static LinkedList<Node<SalesManager>,SalesManager> *SalesManagers;

#endif //PROJECT_LINKEDLIST_H