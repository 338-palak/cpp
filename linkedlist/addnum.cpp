#include<bits/stdc++.h>
using namespace std;
/*// brute 
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
node* reverse(node* head){
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
node* addone(  node* head){
   head = reverse(head);
   node* temp = head;
   int carry = 1;
   while(temp != NULL){
    temp->data = temp->data + carry;
    if(temp->data < 10){
        carry = 0;
        break;
    }else{
        temp->data = 0;
        carry = 1; 
    }
    temp = temp->next;

   }
   if(carry == 1){
    node* newnode = new node(1);
    head =  reverse(head);
    newnode->next = head;
    return newnode;
   }
   head = reverse(head);
   return head;
}

int main() {
    vector<int> arr = {1,5,9};
    
    node* head = convert2LL(arr);
    head = addone(head);
    node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}*/

// optimal 
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

int helper(node* temp){
    if(temp == NULL){
        return 1;
    }
   int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10)
        return 0;
    temp->data = 0;
    return 1; 
}
node* addone(  node* head){
    int carry = helper(head);
    if(carry == 1){
        node* newNode = new node(1);
        newNode->next = head;
        return newNode;
    }
    return head; 
}

int main() {
    vector<int> arr = {9,9,9,9};
    
    node* head = convert2LL(arr);
    head = addone(head);
    node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}
