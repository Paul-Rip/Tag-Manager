// Write your code here
#ifndef _TAGMANAGER_H_
#define _TAGMANAGER_H_
#include "TagNode.h"
#include <vector>
class TagManager{
    private:
        TagNode* front;
        TagNode* out;
    public:
        TagManager(std::vector<std::string> names);
        void push_back(string value);
        void printTagRing();
        void printOutList();
        void printReverse(TagNode* front); //function added to help with printing out list in most recent order
        string properCapital(string name); //function added to help with making sure inputted name is formated correctly
        int indexOfName(string name); //function added to find index of name inside the front list
        bool tagRingContains(string name);
        bool outListContains(string name);
        bool isGameOver();
        string winner();
        void tag(string name);
};
#endif