#include<bits/stdc++.h>
using namespace std;
// Iterative approach
/*// using stack to reverse the linked list
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data1, node* next1) {
        data = data1;
        next = next1;
    }

    node(int data1) {
        data = data1;
        next = nullptr;
    }
};

node* convert2LL(vector<int>& arr) {
    node* head = new node(arr[0]);
    node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(node* head) {
    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

node* reverseLL(node* head) {
  if(head == NULL) return NULL;
 
  stack<int> s;
  node* temp = head;
  while(temp != NULL){
    s.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while(temp != NULL){
     temp->data = s.top();
     s.pop();
     temp = temp->next;
}
return head;
}

int main() {

    vector<int> arr = {12, 5, 7, 4, 8};

    node* head = convert2LL(arr);

    node* reversed = reverseLL(head);

    print(reversed);

    return 0;
}*/

/*// using optimal approach to reverse the linked list
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data1, node* next1) {
        data = data1;
        next = next1;
    }
    node(int data1) {
        data = data1;
        next = nullptr;
    }
};

node* convert2LL(vector<int>& arr) {
    node* head = new node(arr[0]);
    node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(node* head) {
    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node* reverseLL(node* head){
    if(head == NULL) return NULL;
    node* temp = head;
    node* prev = NULL;
    while(temp != NULL){
        node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
int main() {

    vector<int> arr = {12, 5, 7, 4, 8};
    node* head = convert2LL(arr);
    node* reversed = reverseLL(head);
    print(reversed);
    return 0;
}*/

// Recursive approach
class node {
public:
    int data;
    node* next;
    node(int data1, node* next1) {
        data = data1;
        next = next1;
    }
    node(int data1) {
        data = data1;
        next = nullptr;
    }
};

node* convert2LL(vector<int>& arr) {
    node* head = new node(arr[0]);
    node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(node* head) {
    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node* reverseLL(node* head){
   if(head == NULL || head->next == NULL) return head;
   node* newhead = reverseLL(head->next);
   node* front = head->next;
   front->next = head;
   head->next = NULL;
   return newhead;
   
}
int main() {

    vector<int> arr = {12, 5, 7, 4, 8};
    node* head = convert2LL(arr);
    node* reversed = reverseLL(head);
    print(reversed);
    return 0;
}