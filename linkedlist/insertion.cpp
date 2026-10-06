#include<bits/stdc++.h>
using namespace std;
/*
// Insertion at head of the linked list 
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
// maintain tail for O(1) insertion at tail
Node* tail = nullptr;
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;

    }
    cout << endl;
}
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
Node* insertathead(Node* head , int val){
    Node* temp = new Node(val,head);
    return temp;
}
int main(){
    vector<int> arr = {1 ,2,3,4,5};
    Node* head = convertArr2LL(arr);
    head = insertathead(head , 10);
    print(head);

}*/

/*// Insertion at tail of the linked list o(n) soln
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
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;

    }
    cout << endl;
}
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
Node* insertattail(Node* head , int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
   
   
}
int main(){
    vector<int> arr = {1 ,2,3,4,5};
    Node* head = convertArr2LL(arr);
    head = insertattail(head , 10);
    print(head);

}*/

/*//Insertion at tail o(1) soln
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
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;

    }
    cout << endl;
}
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
Node* insertattail(Node* head , int val){
   Node* temp = new Node(val);
   Node* tail = nullptr;
   if(head == nullptr){
    head = temp;
    tail = temp;
    return head;
   }
   tail->next = temp;
   tail = temp;
   return head;
   
}
int main(){
    vector<int> arr = {1 ,2,3,4,5};
    Node* head = convertArr2LL(arr);
    head = insertattail(head , 10);
    print(head);

}*/

/*//Insertion at kth position of the linked list
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
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;

    }
    cout << endl;
}
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
Node* insertatK(Node* head , int val , int k){
    if(head == NULL){
        if(k==1) return new Node(val);
        else return NULL;
    }
    if(k==1){
        Node* temp = new Node(val , head);
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt == k-1 ){
            Node* x = new Node(val);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
return head;
   
}
int main(){
    vector<int> arr = {1 ,2,3,4,5};
    Node* head = convertArr2LL(arr);
    head = insertatK(head , 1000 , 1);
    print(head);
}*/
// Insertion of element before value x;
class node{
    public:
    int data;
    node* next;

    node(int data1 , node* next1){
        data = data1;
        next = next1;
    }

    node(int data1){
        data = data1;
        next = nullptr;
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
node* insertbeforeval(node* head,int ele , int val){
    if(head == NULL){
       return NULL;
    }
    if(head->data==val){
        node* temp = new node(ele , head);
        return temp;
    }
   
    node* temp = head;
    while(temp != NULL){
       
        if(temp->next->data == val){
            node* x = new node(ele,temp->next);
            temp->next = x;
            break;

        }
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {12,5,7,8};
    node* head = convertArr2LL(arr);
    head = insertbeforeval(head,100,7);
    print(head);
}


