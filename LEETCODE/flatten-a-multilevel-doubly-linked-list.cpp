#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
/**
 * we can just iterate through the list and once a node with child is found, just merge the list between current and current->next
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void removeChildren(Node* head) {
        Node* next = head->next;
        head->child->prev = head;
        head->next = head->child;
        
        while (head->next != NULL)
            head = head->next;
        
        head->next = next;
        if (next != NULL)
            next->prev = head;
    }
    
    Node* flatten(Node* head) {
        Node* current = head;
        
        while (current != NULL) {
            if (current->child != NULL) {
                removeChildren(current);
                current->child = NULL;
            }
            
            current = current->next;
        }
        
        return head;
    }
};