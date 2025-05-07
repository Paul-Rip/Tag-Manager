// Write your code here
#include "TagManager.h"
#include <iostream>
#include <iomanip>
#include <cctype>

void TagManager::push_back(std::string value){
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

std::string TagManager::properCapital(std::string name){
    std::string result = "";
    int x = name.find(' ') + 1;
    for(int i = 0; i < name.size(); i++){
        char c = name[i];
        if(i == 0 || i == x){
            c = toupper(c);
        } else{
            c = tolower(c);
        }
        result += c;
    }
    return result;
}

int TagManager::indexOfName(string name){
    int x = 0;
    TagNode* temp = front;
    while(temp != nullptr){
        if(temp->name == name){
            return x;
        }else{
            x++;
            temp = temp->next;
        }
    }
    return x;
}

TagManager::TagManager(std::vector<std::string> names){
    if(names.size() == 0){
        throw "list of names should not be empty";
    }else{
        for(int i = 0; i < names.size(); i++){
            push_back(names[i]);
        }
        out = nullptr;
    }
}
void TagManager::printTagRing(){
    TagNode* temp = front;
    while(temp->next != nullptr){
        std::cout << "  " << temp->name << " is trying to tag " << temp->next->name << std::endl;
        temp = temp->next;
    }
    std::cout << "  " << temp->name << " is trying to tag " << front->name;
}

void TagManager::printReverse(TagNode* temp){
    if(temp == nullptr){
        return;
    }
    printReverse(temp->next);
    std::cout << "  " << temp->name << " was tagged by " << temp->tagger << std::endl;
}

void TagManager::printOutList(){
    if(out == nullptr){
        return;
    }
    TagNode* temp = out;
    printReverse(temp);
}
bool TagManager::tagRingContains(std::string name){
    string newName = properCapital(name);
    TagNode* temp = front;
    while(temp != nullptr){
        if(temp->name == newName){
            return true;
        } else{
            temp = temp->next;
        }
    }
    return false;
}
bool TagManager::outListContains(std::string name){
    string newName = properCapital(name);
    TagNode* temp = out;
    while(temp != nullptr){
        if(temp->name == newName){
            return true;
        } else{
            temp = temp->next;
        }
    }
    return false;
}
bool TagManager::isGameOver(){
    if(front->next == nullptr){
        return true;
    } else{
        return false;
    }
}
std::string TagManager::winner(){
    if(isGameOver()){
        return front->name;
    }
}
void TagManager::tag(std::string name){
    string newName = properCapital(name);
    if(isGameOver()){
        throw "game over";
    } else if (!tagRingContains(newName)){
        throw "not in ring";
    }else{
        int index = indexOfName(newName);
        TagNode* temp = front;
        TagNode* temp2 = out;
        for(int i = 0; i < index-1; i++){
            temp = temp->next;
        }
        if(temp2 == nullptr){
            if(newName == front->name){
                out = front;
                front = front->next;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                out->tagger = temp->name;
                out->next = nullptr;
            } else{
                out = temp->next;
                temp->next = out->next;
                out->tagger = temp->name;
                out->next = nullptr;
            }
            
        } else{
            while(temp2->next != nullptr){
                temp2 = temp2->next;
            }
            if(newName == front->name){
                temp2->next = front;
                front = front->next;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp2->next->tagger = temp->name;
                temp2->next->next = nullptr;
            } else{
                temp2->next = temp->next;
                temp->next = temp->next->next;
                temp2->next->tagger = temp->name;
                temp2->next->next = nullptr;
            }  
        }
    }
}