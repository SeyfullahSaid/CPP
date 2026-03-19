/*
Seyfullah Sait ŞAHİN
150180097
10.11.2021
*/



#include <iostream>
#include <stdio.h>
#include <string.h>

#include "linkedList.h"

using namespace std;

void Train::create(){
    head = NULL;
}; 

void Train::addMaterial(char material, int weight){
        //FILL THIS FUNCTION ACCORDINGLY

        wagonNode *tempWagon = head;
        tempWagon->id = 1;
        materialNode *tempMat = head->material;
        materialNode *addMat;
        addMat->id = material;
        addMat->weight = weight;
        addMat->next = NULL;

        if(tempMat == NULL){
            tempMat->id = material;
            tempMat->weight = weight;
            tempMat->next = NULL;
        } 


        while(tempMat != NULL){
            if(tempMat->id > material){
                addMat->next = tempMat;
                tempMat = addMat;
                break;

            }
            else if(tempMat->id == material){
                tempMat->weight = tempMat->weight + weight;
                break;
            }
            else{
                if(tempMat->next == NULL){
                    tempMat->next = addMat;
                    break;
                }
                if(tempMat->id < material && tempMat->next->id > material){
                    addMat->next = tempMat->next
                    tempMat->next = addMat;
                }
            }
            tempMat = tempMat->next;
        }

        if(weight>2000){
            tempMat->weight = 2000;
            wagonNode *temp1 = tempWagon->next;
            temp1->weight = weight-2000
        }
        else{
            tempMat->weight = weight;
        }


}; 


void Train::deleteFromWagon(char material, int weight){
        //FILL THIS FUNCTION ACCORDINGLY

        materialNode *head;
        materialNode *temp;
        wagonNode *head = headWagon;

        while(headWagon->next != NULL){
             headWagon = headWagon->next
        }
        materialNode *headMat = headWagon->material;


        if(head->material == material){
            head->next = temp;
            delete head;
            head = temp;
        }


        while(head->next->material != material){
            head = head->next;
        }
        temp = head->next;
        head->next = temp->next;
        delete temp;



        if(head->next == NULL){
            delete head;
        }

        while(head->next->weight==2000){
            head = head->next;
        }
};  


void Train::printWagon(){
    wagonNode* tempWagon = head;

    if(tempWagon == NULL){
            cout<<"Train is empty!!!"<<endl;
            return;
    }

    while(tempWagon != NULL){
        materialNode* tempMat = tempWagon->material;
        cout<<tempWagon->wagonId<<". Wagon:"<<endl; 
        while (tempMat != NULL){
            cout<<tempMat->id<<": "<<tempMat->weight<<"KG, "; 
            tempMat = tempMat->next;  
        }
        cout<<endl; 
        tempWagon = tempWagon->next;
    }
    cout<<endl;
}; 