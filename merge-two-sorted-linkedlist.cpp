
// ------------------------------------------------ Merge Two Sorted Lists ------------------------------------------------
/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20           */

#include <iostream>
using namespace std;
 
/* Link list Node */
struct Node {
    int key;
    struct Node* next;
};
 
// Function to reverse a given Linked List using Recursion
Node* reverseList(Node* head)
{
    if (head->next == NULL)
        return head;
    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

Node* sortedMerge(Node* a, Node* b)
{
    a = reverseList(a);
    b = reverseList(b);
    Node* head = NULL;
    Node* temp;
    while (a != NULL && b != NULL) {
        if (a->key >= b->key) {
            temp = a->next;
            a->next = head;
            head = a;
            a = temp;
        }
        else {
 
            temp = b->next;
            b->next = head;
            head = b;
            b = temp;
        }
    }
    while (a != NULL) {
        temp = a->next;
        a->next = head;
        head = a;
        a = temp;
    }
    while (b != NULL) {
        temp = b->next;
        b->next = head;
        head = b;
        b = temp;
    }
    return head;
}
 
/* Function to print Nodes in a given linked list */
void printList(struct Node* Node)
{
    while (Node != NULL) {
        cout << Node->key << "->";
        Node = Node->next;
    }
}

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
 
/* Driver program to test above functions*/
int main()
{
    struct Node* res = NULL;
 
    /* Let us create two sorted linked lists to test
       the above functions. Created lists shall be
         a: 5->10->15->40
         b: 2->3->20  */
    Node* a = newNode(5);
    a->next = newNode(10);
    a->next->next = newNode(15);
    a->next->next->next = newNode(40);
 
    Node* b = newNode(2);
    b->next = newNode(3);
    b->next->next = newNode(20);
 
    cout << "List A before merge: \n";
    printList(a);
 
    cout << "\nList B before merge: \n";
    printList(b);
 
    /* merge 2 sorted Linked Lists */
    res = sortedMerge(a, b);
 
    cout << "\nMerged Linked List is: \n";
    printList(res);
 
    return 0;
}