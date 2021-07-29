//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list){
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head){
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL"<<endl;
}

bool insertAt (SLinkedList& list, Soldier element, int pos){
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise
    //TODO
    if(pos < 0 ) return false;
    if(pos > list.size) return false;
    SoldierNode* pNew=new SoldierNode;
    pNew->data=element;
    if(pos==0)
    {
        pNew->next=list.head;
        list.head=pNew;
        list.size++;
        return true;
    }
    SoldierNode* pre= list.head;
    int count=0;
    while(pre != NULL)
    {
        if(count == pos-1) break;
        pre=pre->next;
        count ++;
    }
    pNew->next=pre->next;
    pre->next=pNew;
    list.size++;
    return true;
}

bool removeAt (SLinkedList& list, int idx){
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO
    if(list.head==NULL) return false;
    if(idx < 0 || idx >= list.size) return false;
    if(idx==0)
    {
        SoldierNode* temp= list.head;
        list.head=list.head->next;
        list.size--;
        temp->next=NULL;
        delete temp;
        return true;
    }
    SoldierNode* current= list.head;
    int temp = 0;
    while(current != NULL)
    {
        if(temp == idx) break;
        current=current->next;
        temp ++;
    }
    SoldierNode* pre=list.head;
    int preTemp = 0;
    while(pre != NULL)
    {
        if(preTemp == idx-1) break;
        pre=pre->next;
        preTemp ++;
    }
    pre->next=current->next;
    current->next=NULL;
    delete current;
    list.size--;
    return true;
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    SoldierNode* current= list.head;
    int count=0;
    while(current != NULL)
    {
        if(current->data.HP==HP)
        {
            removeAt(list,count);
            return true;
        } 
        current = current->next;
        count ++;
    }
    return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    if(list.head == NULL) return -1;
    SoldierNode* current= list.head;
    int count=0;
    while(current != NULL)
    {
        if(current->data.HP==soldier.HP && current->data.ID==soldier.ID && current->data.isSpecial==soldier.isSpecial)
        {
            return count;
        }
        count ++;
        current= current->next;
    }
    return -1;
}

int size(SLinkedList& list){
    //Return size of the list
    //TODO
    return list.size;
}

bool empty(SLinkedList& list){
    if(list.head==NULL) return true;
    return false;
}

void clear(SLinkedList& list){
    //Delete all of the elements in list
    //TODO
    SoldierNode* temp;
    while(list.head!= NULL)
    {
        temp= list.head;
        list.head= list.head->next;
        temp->next= NULL;
        delete temp;
    }
    list.head= NULL;
    list.size= 0;
}

string getIDAt(SLinkedList& list, int pos){
    //Get ID of the Soldier at pos
    //TODO
    if(pos < 0 || pos >= list.size) return "-1";
    SoldierNode* current= list.head;
    int count = 0;
    while(current != NULL)
    {
        if(count == pos) return current->data.ID;
        count ++;
        current = current->next;
    }
    return "-1";
}

int getHPAt(SLinkedList& list, int pos){
    //Get HP of the Soldier at pos
    //TODO
    if(pos < 0 || pos >= list.size) return -1;
    SoldierNode* current= list.head;
    int count = 0;
    while(current != NULL)
    {
        if(count == pos) return current->data.HP;
        count ++;
        current = current->next;
    }
    return -1;
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    //Set value of HP at pos
    //TODO
    if(list.head==NULL) return false;
    //Return true if set successfully, false otherwise
    if(pos < 0 || pos >= list.size) return false;
    SoldierNode* current= list.head;
    int count = 0;
    while(current != NULL)
    {
        if(count == pos)
        {
            current->data.HP=HP;
            return true;
        }
        count ++;
        current = current->next;
    }
    return true;
}

bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    //TODO
    if(list.head==NULL) return false;
    SoldierNode* current= list.head;
    while(current != NULL)
    {
        if(current->data.HP == soldier.HP && current->data.ID == soldier.ID && current->data.isSpecial==soldier.isSpecial) return true;
        current = current->next;
    }
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
