// Write your code here
#include "TagManager.h"
#include <iostream>
#include <iomanip>

void TagManager::push_back(string value){
    if(front == nullptr){
        front = new TagNode(value);
    } else{
        TagNode* curr = front;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = new TagNode(value);
    }
}

TagManager::TagManager(std::vector<std::string> names){
    if(names.size() == 0){
        throw "list of names should not be empty";
    }else{
        for(int i = 0; i < names.size(); i++){
            push_back(names[i]);
        }
    }
}
void TagManager::printTagRing(){
    TagNode* temp = front;
    int x;
    while(temp->next != nullptr){
        x = 5 + temp->name.size() + temp->next->name.size();
        std::cout << setw(x) << right << temp->name << " is trying to tag " << temp->next->name << endl;
        temp = temp->next;
    }
    x = 5 + temp->name.size() + front->name.size();
    std::cout << setw(x) << right << temp->name << " is trying to tag " << front->name;
}
void TagManager::printOutList(){

}
bool TagManager::tagRingContains(string name){

}
bool TagManager::outListContains(string name){

}
bool TagManager::isGameOver(){

}
string TagManager::winner(){

}
void TagManager::tag(string name){

}