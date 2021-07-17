//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Array
void print(Array& array){
    if (array.size<=0) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout <<"[";
    for(int i=0;i<array.size;i++){
        std::cout << array.arr[i].ID << " ";
    }
    std::cout <<"]" << endl;
}

void initArray (Array& array, int cap){
    //Init a new array with capacity equals to cap
    //TODO
    array.arr= new Soldier[cap];
    array.capacity=cap;
    array.size=0;
}

void ensureCapacity(Array& array, int newCap){
    //Extend the capacity of the array
    //TODO
    int capacity=newCap;
    Soldier* temp = new Soldier[capacity];
    for(int i = 0 ;i<array.size ; i++)
    {
        temp[i]=array.arr[i];
    }
    delete[] array.arr;
    array.arr=temp;
    array.capacity=capacity;
}

bool insertAt(Array& array, Soldier element, int pos) {
    if (pos == 0 && array.size == 0 && array.capacity >0) 
    {
        array.size++;
        array.arr[pos] = element;
        return true;
    }
    if (array.capacity == 0) initArray(array,1); 
    if (pos < 0 || pos > array.size || array.capacity < 0) return false;
    else
    {
        if (array.size==array.capacity)
        {
            int nCap;   
            if (array.capacity == 1) nCap = array.capacity+1;
            else nCap = array.capacity * 1.5;
            Soldier* temp = new Soldier[nCap];
            for (int i = 0; i < array.capacity; i++) {
                temp[i]=array.arr[i];
            }
            array.capacity = nCap;
            delete[] array.arr;
            array.arr = temp;    
        }
        array.size++;
        for (int i = array.size-1; i > pos; i--) 
        {
            array.arr[i] = array.arr[i - 1];
        }
        array.arr[pos] = element;
        return true;
    }
    return false;
}

bool removeAt (Array& array, int idx){
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO
    if(idx < 0 || idx >= array.size) return false;
    for(int i = idx ; i < array.size - 1; i++)
    {
        array.arr[i]=array.arr[i+1];
    }
    array.size--;
    return true;
}

bool removeFirstItemWithHP (Array& array, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    for(int i=0 ; i < array.size ; i++)
    {
        if(array.arr[i].HP==HP)
        {
            removeAt(array,i);
            return true;
        }
    }
    return false;
}

int indexOf(Array& array, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    for(int i = 0;i<array.size;i++)
    {
        if(array.arr[i].HP==soldier.HP && array.arr[i].ID==soldier.ID && array.arr[i].isSpecial==soldier.isSpecial)
        {
            return i;
        }
    }
    return -1;
}

int size(Array& array){
    //Return size of the array
    //TODO
    return array.size;
}

bool empty(Array& array){
    //Check whether the array is empty
    //TODO
    if(array.size<=0) return true;
    return false;
}

string getIDAt(Array& array, int pos){
    //Get ID of the Soldier at pos
    //TODO
    if(pos<0 || pos>=array.size || pos>array.capacity) return "-1";
    return array.arr[pos].ID;
}

int getHPAt(Array& array, int pos){
    //Get HP of the Soldier at pos
    //TODO
    if(pos<0 || pos>=array.size || pos>array.capacity) return -1;
    return array.arr[pos].HP;
}

bool setHPAt(Array& array, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if(pos<0 || pos>=array.size || pos>array.capacity) return false;
    array.arr[pos].HP=HP;
    return true;
}

void clear(Array& array){
    //Delete all of the elements in array
    //TODO
    delete[] array.arr;
    array.arr=NULL;
    array.capacity=-1;
    array.size=0;
}

bool contains (Array& array, Soldier soldier){
    //Check if array contains soldier
    //TODO
    for(int i=0;  i<array.size ; i++)
    {
        if(array.arr[i].HP==soldier.HP && array.arr[i].ID==soldier.ID && array.arr[i].isSpecial==soldier.isSpecial)
        {
            return true;
        }
    }
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
