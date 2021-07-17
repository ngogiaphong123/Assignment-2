//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////
void swap1(Soldier& a, Soldier& b)
{
    Soldier temp=a;
    a=b;
    b=temp;
}
bool push(Array& array, Soldier soldier){
    //Return true if push successfully, false otherwis
    if(array.capacity==0) initArray(array,1);
    if(array.size==array.capacity)
    {
        int nCap;
        if(array.capacity==1) nCap=array.capacity+1;
        else nCap=array.capacity*1.5;
        Soldier* temp=new Soldier[nCap];
        for(int i=0; i<array.capacity;i++)
        {
            temp[i]=array.arr[i];
        }
        delete[] array.arr;
        array.arr=temp;
        array.capacity=nCap;
    }
    array.arr[array.size++]=soldier;
    return true;
}

bool pop(Array& array){
    //Return true if pop successfully, false otherwise
    //TODO
    if(array.size==0) return false;
    array.size--;
    return true;
}

Soldier top(Array& array){
    //TODO
    if(array.size<=0) return Soldier();
    //return this if cannot get top
    return array.arr[array.size-1];
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier){
    //Return true if enqueue successfully, false otherwise
    //TODO
    SoldierNode* newNode=new SoldierNode;
    newNode->data=soldier;
    newNode->next=NULL;
    SoldierNode* temp=list.head;
    if(list.head==NULL)
    {
        list.size++;
        list.head=newNode;
        return true;
    }
    while(temp!=NULL)
    {
        if(temp->next==NULL) 
        {
            list.size++;
            temp->next=newNode;
            return true;
        }
        temp=temp->next;
    }
    return true;
}

bool dequeue(SLinkedList& list){
    //Return true if dequeue successfully, false otherwise
    //TODO
    if(list.head==NULL) return false;
    SoldierNode* temp=list.head;
    list.head=list.head->next;
    temp->next=NULL;
    delete temp;
    list.size--;
    return true;
}
Soldier front(SLinkedList& list){
    //TODO
    if(list.head==NULL) return Soldier();//Return this if cannot get front
    SoldierNode* temp=list.head;
    return temp->data;
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list){
    //TODO
    SoldierNode* curr=list.head;
    SoldierNode* prev=NULL;
    SoldierNode* next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    list.head=prev;
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////

SLinkedList merge(SLinkedList& list1, SLinkedList& list2){
    //TODO
    int size=list1.size+list2.size;
    SoldierNode* connect=list1.head;
    while(connect->next!=NULL)
    {
        connect=connect->next;
    }
    connect->next=list2.head;
    SoldierNode* constNode = list1.head;
    SoldierNode* movingNode= constNode->next;
    for(int i = 0 ; i < size-1 ;i++)
    {
        if(i>0) 
        {
            constNode = constNode->next;
            movingNode= constNode->next;
        }
        for(int j = i+1 ; j < size ; j++)
        {
            if(constNode->data.HP > movingNode->data.HP)
            {
                swap1(constNode->data, movingNode->data);
            }
            movingNode=movingNode->next;
        }
    }
    constNode = list1.head;
    movingNode= constNode->next;
    for(int i = 0 ; i < size-1 ;i++)
    {
        if(i>0) 
        {
            constNode = constNode->next;
            movingNode= constNode->next;
        }
        for(int j = i+1 ; j < size ; j++)
        {
            if(constNode->data.HP == movingNode->data.HP)
            {
                if(constNode->data.isSpecial==true && movingNode->data.isSpecial==false)
                swap1(constNode->data, movingNode->data);
            }
            movingNode=movingNode->next;
        }
    }
    constNode = list1.head;
    movingNode= constNode->next;
    for(int i = 0 ; i < size-1 ;i++)
    {
        if(i>0) 
        {
            constNode = constNode->next;
            movingNode= constNode->next;
        }
        for(int j = i+1 ; j < size ; j++)
        {
            if(constNode->data.HP == movingNode->data.HP && constNode->data.isSpecial==movingNode->data.isSpecial)
            {
                if(constNode->data.ID > movingNode->data.ID)
                swap1(constNode->data, movingNode->data);
            }
            movingNode=movingNode->next;
        }
    }
    return list1;
    return SLinkedList();
}

//You can write your own functions here

//End your own functions
#endif /* thirdBattle_h */
