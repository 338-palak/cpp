#include<bits/stdc++.h>
using namespace std;
/*struct Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1 , Node* next1 ){
        data = data1;
        next = next1;
    }
};
int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* y = new Node(arr[0] , nullptr);
    cout << y;
}*/
/*
struct Node{
    int data ;
    Node* next;

    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
};

int main(){
    vector<int> arr = { 1,2,3,4};
    Node* y = new Node(arr[2] , nullptr);
  //  cout << y.data ;
  //  cout << y.next;
    cout << y->data;

}*/

/*// #Convert array to Linked List
class Node{
    public:
    int data;
    Node* next;

    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp ; //mover = mover->next

    }
return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArr2LL(arr);
    cout << head->data;
}*/

/*// Traverse a linked list
class Node{
    public:
    int data;
    Node* next;
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* traverseArr(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1 ; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main(){
    vector<int> arr = {12,5,6,7};
   Node* head = traverseArr(arr);
   Node* temp = head;
   while(temp){
    cout << temp->data << " ";
    temp = temp->next;
   }
}
*/

/*// length of LL;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* traverseLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1 ; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int LengthLL(Node* head){
    int cnt = 0;
    Node* temp =  head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
int main(){
    vector<int> arr = {12,5,6,7};
    Node* head = traverseLL(arr);
    cout << LengthLL(head);
}
*/

/*// search an eleement

class Node{
    public:
    int data;
    Node* next;
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* traverseLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1 ; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int searchinlinked(Node* head , int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}
int main(){
     vector<int> arr = {12,5,6,7};
    Node* head = traverseLL(arr);
    cout << searchinlinked(head,53);
}*/


