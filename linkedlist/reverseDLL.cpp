#include<bits/stdc++.h>
using namespace std;
/*
class node{
    public:
    int data;
    node* next;
    node* back;

    public:
    node(int data1 , node* next1 , node*  back1){
    data = data1;
    next = next1;
    back = back1; 
}
public:
node(int data1){
    data = data1;
    next = nullptr;
    back = nullptr;
}
};
void print(node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
node* convertarrDLL(vector<int>& arr){
    if(arr.empty()) return nullptr;
    node* head = new node(arr[0]);
    node* prev = head;
    for(int i = 1 ; i < arr.size() ; i++){
        node* temp = new node(arr[i] , nullptr , prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
node* reversedll(node* head){
    node* temp = head;
    stack<int> s;
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
int main(){
    vector<int> arr = {12,3,4,5};
    node* head = convertarrDLL(arr);
    node* headd = reversedll (head);
    print(headd);
    return 0;
}
*/

class node{
    public:
    int data;
    node* next;
    node* back;

    public:
    node(int data1 , node* next1 , node*  back1){
    data = data1;
    next = next1;
    back = back1; 
}
public:
node(int data1){
    data = data1;
    next = nullptr;
    back = nullptr;
}
};
void print(node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
node* convertarrDLL(vector<int>& arr){
    if(arr.empty()) return nullptr;
    node* head = new node(arr[0]);
    node* prev = head;
    for(int i = 1 ; i < arr.size() ; i++){
        node* temp = new node(arr[i] , nullptr , prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
node* reversedll(node* head){
    node* current = head;
    node* last = NULL;
    while(current != NULL){
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
       node* newhead = last->back;
    return newhead;

   
} 
int main(){
    vector<int> arr = {12,3,4,5};
    node* head = convertarrDLL(arr);
    node* headd = reversedll (head);
    print(headd);
    return 0;
}