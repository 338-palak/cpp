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
*/

/*// Convert array into a doubly linked list
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
int main(){
    vector<int> arr = {12,3,4,5};
    node* head = convertarrDLL(arr);
    print(head);
    return 0;

}*/

/*// Delete head
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
node* deletehead(node* head){
    if(head == NULL) return head;
    node* prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    delete prev;
    return head;
} 
int main(){
    vector<int> arr = {12,3,4,5};
    node* head = convertarrDLL(arr);
    node* headd = deletehead(head);
    print(headd);
    return 0;
}
*/

/*//delete tail
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
node* deletetail(node* head){
    if(head == NULL || head->next == NULL) return NULL;
    node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    node*  prev = tail->back;
    prev ->next = NULL;
    tail->back = NULL;
    delete tail; 
  return head;

   
} 
int main(){
    vector<int> arr = {12,3,4,5};
    node* head = convertarrDLL(arr);
    node* headd = deletetail (head);
    print(headd);
    return 0;
}
*/

/*//delete kth element
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
node* deletetail(node* head){
    if(head == NULL || head->next == NULL) return NULL;
    node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    node*  prev = tail->back;
    prev ->next = NULL;
    tail->back = NULL;
    delete tail; 
  return head;

} 
node* deletehead(node* head){
    if(head == NULL) return head;
    node* prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    delete prev;
    return head;
} 
node* deletekth(node* head , int k){
   if(head == NULL || k <=0) return NULL;
   int cnt = 0 ;
   node* temp = head;
   while(temp != NULL){
    cnt++;
    if(cnt == k){
        break;
    }
    temp = temp->next;
   }
   if(temp ==   NULL) return head;
   node* prev = temp->back;
   node* front = temp->next;
   if(prev == NULL && front == NULL){
    delete temp;
    return NULL;
  } 
    else if(prev == NULL){
    return deletehead(head);
  }
    else if(front == NULL){
    return deletetail(head);
  }else{
    prev->next = front;
    front->back = prev;
    temp->next = NULL;
    temp->back = NULL;
    delete temp;
    return head;
  }

   
} 
int main(){
    vector<int> arr = {12,3,4,5};
    int k = 3;
    node* head = convertarrDLL(arr);
    node* headd = deletekth(head , k);
    print(headd);
    return 0;
} */

// remove node
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
void deletenode(node* temp){
    if (temp == nullptr) return;
    node* front = temp->next;
    node* prev = temp->back;
    if(front == NULL){
        prev->next = NULL;
        temp->back = NULL;
        delete front;
        return ;
    }
    prev->next = front;
    front->back  = prev;

    temp->next = temp->back = nullptr;
    delete temp;

} 
int main(){
    vector<int> arr = {12,3,4,5};
    
    node* head = convertarrDLL(arr);
   node* target = head->next->next; // points to node with 4
    deletenode(target);
    print(head);
    return 0;
}
