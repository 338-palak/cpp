#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*// brute
class node {
public:
    int data;
    node* next;
    node* child;

    node(int data1, node* next1 = nullptr, node* child1 = nullptr) {
        data = data1;
        next = next1;
        child = child1;
    }
};

// Converts 1D vector into a regular linked list (linked via 'next')
node* convert2LL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    node* head = new node(arr[0]);
    node* mover = head;
    for (size_t i = 1; i < arr.size(); i++) {
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Converts sorted vector into a flattened linked list (linked via 'child' or 'next')
node* convert(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    node* head = new node(arr[0]);
    node* temp = head;
    for (size_t i = 1; i < arr.size(); i++) {
        node* newnode = new node(arr[i]);
        temp->child = newnode; // or temp->next depending on problem requirement
        temp = temp->child;
    }
    return head;
}

node* flatteningnode(node* head) {
    vector<int> arr;
    node* temp = head;

    // Traverse all nodes across both 'next' and 'child' pointers
    while (temp != nullptr) {
        node* t2 = temp;
        while (t2 != nullptr) {
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());
    return convert(arr);
}

int main() {

    // First list: 5 -> 7 -> 8 -> 30
    node* head = new node(5);
    head->child = new node(7);
    head->child->child = new node(8);
    head->child->child->child = new node(30);

    // Second list: 10 -> 20
    head->next = new node(10);
    head->next->child = new node(20);

    // Third list: 19 -> 22 -> 50
    head->next->next = new node(19);
    head->next->next->child = new node(22);
    head->next->next->child->child = new node(50);

    // Fourth list: 28 -> 35 -> 40 -> 45
    head->next->next->next = new node(28);
    head->next->next->next->child = new node(35);
    head->next->next->next->child->child = new node(40);
    head->next->next->next->child->child->child = new node(45);

    // Flatten the multi-level linked list
    node* flatHead = flatteningnode(head);

    // Print the sorted flattened list
    cout << "Flattened and Sorted Linked List:\n";
    node* temp = flatHead;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->child != nullptr) cout << " ";
        temp = temp->child;
    }
    cout << " -> NULL\n";

    return 0;
}*/

// optimal solution 
#include <iostream>
#include <vector>

using namespace std;

class node {
public:
    int data;
    node* next;
    node* child;

    node(int data1, node* next1 = nullptr, node* child1 = nullptr) {
        data = data1;
        next = next1;
        child = child1;
    }
};

// Merges two sorted vertical lists
node* flatteningnode(node* head1 , node* head2) {
    node* dummynode = new node(-1);
    node* res = dummynode;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            res->child = head1;
            res = head1;
            head1 = head1->child;
        }else{
            res->child = head2;
            res = head2;
            head2 = head2->child;
        }
        res ->next = NULL;

    }
     if(head1)   res->child = head1;  
     else        res->child = head2;
     return dummynode-> child;
}

node* flattendeep(node* head){
    if(head == NULL || head->next ==NULL) return head;
    node* mergehead = flattendeep(head->next);
    return flatteningnode(head , mergehead );

}


int main() {

    // First list: 5 -> 7 -> 8 -> 30
    node* head = new node(5);
    head->child = new node(7);
    head->child->child = new node(8);
    head->child->child->child = new node(30);

    // Second list: 10 -> 20
    head->next = new node(10);
    head->next->child = new node(20);

    // Third list: 19 -> 22 -> 50
    head->next->next = new node(19);
    head->next->next->child = new node(22);
    head->next->next->child->child = new node(50);

    // Fourth list: 28 -> 35 -> 40 -> 45
    head->next->next->next = new node(28);
    head->next->next->next->child = new node(35);
    head->next->next->next->child->child = new node(40);
    head->next->next->next->child->child->child = new node(45);

    // Flatten the multi-level linked list
    node* flatHead = flattendeep(head);

    // Print the sorted flattened list
    cout << "Flattened and Sorted Linked List:\n";
    node* temp = flatHead;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->child != nullptr) cout << " ";
        temp = temp->child;
    }
    cout << " -> NULL\n";

    return 0;
}