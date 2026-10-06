#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* back;

    node(int data1 , node* next1 , node* back1){
        data = data1;
        next = next1;
        back = back1;

    }

    node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
node* convertArr2LL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1 ; i < arr.size() ; i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp ; //mover = mover->next
    }
    return head;
}
void print(node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;

    }
    cout << endl;
}
node* removeduplicates(node* head){
    node* temp = head;
  while(temp != NULL && temp->next != NULL){
       node* nextnode = temp->next;
       while(nextnode != NULL && nextnode->data == temp->data){
        node* duplicate = nextnode;
        nextnode = nextnode->next;
        delete duplicate;
       }
       temp->next = nextnode;
      if(nextnode) nextnode->back = temp;
      temp = temp->next;

  }
     
    return head;
}
int main(){
    vector<int> arr = {12,5,4,4,4,4,7,8};
    node* head = convertArr2LL(arr);
    head = removeduplicates(head);
    print(head);
}