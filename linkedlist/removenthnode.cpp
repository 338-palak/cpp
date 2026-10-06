#include<bits/stdc++.h>
using namespace std;
/*
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
node* deletenthnode(node* head , int N){
   node* temp = head;
   int cnt = 0;
   while(temp != NULL){
    cnt++;
    temp = temp->next;
   }  
   if(cnt == N){
    node* newhead = head->next;
    delete head;
    return newhead;
   }
   int res = cnt - N;
   temp = head;
   while(temp != NULL){
    res--;
    if(res == 0){
        break;
    }
    temp = temp->next;
   }
   node* tobedeleted = temp->next;
   temp->next = temp->next->next;
   delete tobedeleted;
   return head;

}
int main() {
    vector<int> arr = {1, 3, 4, 2, 5,6};
    int N = 2;
    node* head = convert2LL(arr);
    head = deletenthnode(head , N);
    node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}*/

// optimal soln

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
node* deletenthnode(node* head , int N){
  node* fast = head;
  for(int i = 0 ; i < N ; i++) fast = fast->next;
  if(fast==NULL){
    node* newhead = head->next;
    delete newhead;
    return newhead;
  }
  node* slow = head;
  while( fast->next != NULL){
    slow=slow->next;
    fast=fast->next;
  }

  node* deletnode = slow->next; 
  slow->next = slow->next->next;
  delete deletnode;
  return head;
  

 }
int main() {
    vector<int> arr = {1, 3, 4, 2, 5,6};
    int N = 2;
    node* head = convert2LL(arr);
    head = deletenthnode(head , N);
    node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}
