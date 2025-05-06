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
        bool tagRingContains(string name);
        bool outListContains(string name);
        bool isGameOver();
        string winner();
        void tag(string name);
};
#endif