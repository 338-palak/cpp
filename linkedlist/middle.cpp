#include<bits/stdc++.h>
using namespace std;
/*// find middle of linked list using two pass method
 class node{
    public:
    int data;
    node* next;

    node(int data1, node* next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1; 
        next = nullptr;
    }
};
node* convert2LL(vector<int>& arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1 ; i < arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}


node* findmiddle(node* head){
    if(head == NULL) return NULL;
    int cnt = 0 ;
    node* temp = head;
    
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
  // It will count the number of nodes
  int mid = (cnt/2) + 1;
   temp = head;
   while(temp != NULL ){
    mid--;
    if(mid == 0){
       return temp;}
        temp = temp->next;
    
   
   }
   return NULL;
}
int main(){
    vector<int> arr = {12,5,7,4,8};
    node* head = convert2LL(arr);
    node* mid = findmiddle(head);
    cout << mid->data << endl;
    return 0;

}
*/
// find middle using Tortoise and hare method
 class node{
    public:
    int data;
    node* next;

    node(int data1, node* next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1; 
        next = nullptr;
    }
};
node* convert2LL(vector<int>& arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1 ; i < arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
node* findmiddle(node* head){
    if(head == NULL) return NULL;
    node* slow  = head; 
    node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){
    vector<int> arr = {12,5,7,4,8};
    node* head = convert2LL(arr);
    node* mid = findmiddle(head);
    cout << mid->data << endl;
    return 0;

}