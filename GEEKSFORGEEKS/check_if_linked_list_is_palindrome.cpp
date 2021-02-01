#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    if (head->next == NULL)
        return true;
    else if (head->next->next == NULL)
        return head->data == head->next->data;
        
    //Your code here
    Node* curr = head;
    Node* fast = head;
    stack<int> st;
    while (fast != NULL && fast->next != NULL)
    {
        st.push(curr->data);
        curr = curr->next;
        fast = fast->next->next;
    }
    
    if (fast != NULL && fast->next == NULL)
        curr = curr->next;
        
    while (curr != NULL)
    {
        if (curr->data != st.top())
            return false;
        st.pop();
        curr = curr->next;
    }
    
    return true;
}
