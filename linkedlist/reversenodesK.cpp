#include<bits/stdc++.h>
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
node* getkthnode(node* temp , int k){
    k-=1;
    while(temp != NULL && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;

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

node* reversenode(node* head , int k){
    node* temp = head;
    node* prevnode = NULL;
    while(temp != NULL){
        node* kthnode = getkthnode(temp , k);
      if(kthnode == NULL){
        if(prevnode)
        prevnode->next = temp;
        break;
      }
      node* nextnode = kthnode->next;
      kthnode->next = NULL;
      reverseLL(temp);
      if(temp == head){
        head = kthnode;
      }else{
        prevnode->next = kthnode;
      }
      prevnode = temp;
      temp = nextnode;

    }
    return head;
 
 }
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9,10,22};
    node* head = convert2LL(arr);
    int k = 3;
    head = reversenode(head, k);
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
