// Write your code here
#include "TagManager.h"
#include <iostream>
#include <iomanip>
#include <cctype>

void TagManager::push_back(std::string value){
    if(front == nullptr){ //if the front list is empty then adds value to front
        front = new TagNode(value);
    } else{ //if front has atleast one element it goes until it reaches the last node through the curr pointer then adds a value to the end
        TagNode* curr = front;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = new TagNode(value);
    }
}

std::string TagManager::properCapital(std::string name){
    std::string result = "";
    int x = name.find(' ') + 1; //sets x to the index of the first letter of the last name
    for(int i = 0; i < name.size(); i++){ //loops through the name and capitalizes the first letter of the first and last name while making everything else lowercase
        char c = name[i];
        if(i == 0 || i == x){ //if the index is the first letter in the first or last name it capitalizes the character
            c = toupper(c);
        } else{ //lowercases every other character
            c = tolower(c);
        }
        result += c; //adds the character to the result string
    }
    return result;
}

int TagManager::indexOfName(string name){
    int x = 0; //used to track the index of the name
    TagNode* temp = front;
    while(temp != nullptr){
        if(temp->name == name){ //returns the index of name if the current node data equals the name
            return x;
        }else{
            x++; //increments the index
            temp = temp->next; //prgresses the pointer
        }
    }
    return x;
}

TagManager::TagManager(std::vector<std::string> names){
    if(names.size() == 0){ //if size of the vector is 0 it will throw the string exception below
        throw "list of names should not be empty";
    }else{
        for(int i = 0; i < names.size(); i++){ //loops through the name vector and pushes it into the linked list
            push_back(names[i]);
        }
        out = nullptr; //establishes the out list as empty
    }
}
void TagManager::printTagRing(){
    TagNode* temp = front;
    while(temp->next != nullptr){ //loops through a temporary pointer to print out who is trying to tag who
        std::cout << "  " << temp->name << " is trying to tag " << temp->next->name << std::endl;
        temp = temp->next;
    }
    std::cout << "  " << temp->name << " is trying to tag " << front->name; //couts the last node and who they are trying to tag
}

void TagManager::printReverse(TagNode* temp){
    if(temp == nullptr){
        return;
    }
    printReverse(temp->next); //recurssively loops through temp until temp equals nullptr 
    std::cout << "  " << temp->name << " was tagged by " << temp->tagger << std::endl; //outputs who tagged who in reverse order due to being after the recurrsive call
}

void TagManager::printOutList(){
    if(out == nullptr){ //if out list is empty then returns and prints nothing
        return;
    }
    TagNode* temp = out; //temp pointer to out list
    printReverse(temp); //goes through and prints who has been tagged
}
bool TagManager::tagRingContains(std::string name){
    string newName = properCapital(name);
    TagNode* temp = front;
    while(temp != nullptr){ //loops through temp until node is nullptr
        if(temp->name == newName){ //if the node name is equal to the inputted name with proper capitalization then returns true
            return true;
        } else{ //otherwise moves to the next node
            temp = temp->next;
        }
    }
    return false;
}
bool TagManager::outListContains(std::string name){
    string newName = properCapital(name);
    TagNode* temp = out;
    while(temp != nullptr){ //loops through temp until node is nullptr
        if(temp->name == newName){ //if the node name is equal to the inputted name with proper capitalization then returns true
            return true;
        } else{ //otherwise moves to the next node
            temp = temp->next;
        }
    }
    return false;
}
bool TagManager::isGameOver(){
    if(front->next == nullptr){ //if there is only one person in the front list returns true
        return true;
    } else{ //otherwise returns false
        return false;
    }
}
std::string TagManager::winner(){
    if(isGameOver()){ //if the game is over returns the name of the only person in the list
        return front->name;
    }
}
void TagManager::tag(std::string name){
    string newName = properCapital(name);
    if(isGameOver()){ //if the game is over then throw string exception below
        throw "game over";
    } else if (!tagRingContains(newName)){ //if inputted name is not in the list throws string exception below
        throw "not in ring";
    }else{
        int index = indexOfName(newName);
        TagNode* temp = front; //creates a temp pointer for the players still in
        TagNode* temp2 = out; //creates a temp2 pointer for the players that are out
        for(int i = 0; i < index-1; i++){ //loops through temp until it reaches the person before the person that got tagged
            temp = temp->next;
        }
        if(temp2 == nullptr){ //if the out list is empty it utilize out instead of temp2
            if(newName == front->name){ //if the name inputted is in the front adds it to out
                out = front; //adds the name of the person tagged to the out list
                front = front->next; //removes person tagged from front list
                while(temp->next != nullptr){ //loops through to the end of temp to get the tagger
                    temp = temp->next;
                }
                out->tagger = temp->name;
                out->next = nullptr; //makes out next nullptr so if name is in middle of list it does not add multiple people
            } else{
                out = temp->next; //adds person tagged to out list
                temp->next = out->next; //removes person tagged from temp/front list
                out->tagger = temp->name;
                out->next = nullptr; //makes out next nullptr so if name is in middle of list it does not add multiple people
            }
            
        } else{
            while(temp2->next != nullptr){ //loops through to the end of temp2/out list to add the next person to the end of the list
                temp2 = temp2->next;
            }
            if(newName == front->name){ //if the name inputted is in the front adds it to out
                temp2->next = front; //adds the name of the person tagged to the out list
                front = front->next; //removes person tagged from front list
                while(temp->next != nullptr){ //loops through to the end of temp to get the tagger
                    temp = temp->next;
                }
                temp2->next->tagger = temp->name;
                temp2->next->next = nullptr; //makes temp2 next next nullptr so if name is in middle of list it does not add multiple people
            } else{
                temp2->next = temp->next; //adds person tagged to temp2/out list
                temp->next = temp->next->next; //removes person tagged from temp/front list
                temp2->next->tagger = temp->name;
                temp2->next->next = nullptr; //makes temp2 next next nullptr so if name is in middle of list it does not add multiple people
            }  
        }
    }
}