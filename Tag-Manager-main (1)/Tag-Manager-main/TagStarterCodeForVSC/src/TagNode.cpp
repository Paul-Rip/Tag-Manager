// CS 133, Project 3: Tag
//
// Instructor-provided support code.  You should not modify this code!

#include <string>
#include "TagNode.h"

using namespace std;

/**
 * Constructs a new node to store the given name and no next node.
 */
TagNode::TagNode(string name) : TagNode(name, nullptr) {}

/**
 * Constructs a new node to store the given name and a reference
 * to the given next node.
 */
TagNode::TagNode(string name, TagNode* next) {
    this->name = name;
    this->tagger = "";
    this->next = next;
}
