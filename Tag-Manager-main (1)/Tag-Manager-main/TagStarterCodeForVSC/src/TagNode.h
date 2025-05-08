// CS 133, Project 3: Tag
//
// Instructor-provided support code.  You should not modify this code!

#ifndef _tagnode_h_
#define _tagnode_h_

#include <string>

using namespace std;

/**
 * Each TagNode object represents a single node in a linked list
 * for a game of Tag.
 */
struct TagNode {
    string name;        // this person's name
    string tagger;      // name of who tagged this person ("" if alive)
    TagNode* next;      // next node in the list (nullptr if none)
    
    /**
     * Constructs a new node to store the given name and no next node.
     */
    TagNode(string name);

    /**
     * Constructs a new node to store the given name and a reference
     * to the given next node.
     */
    TagNode(string name, TagNode* next);
};

#endif