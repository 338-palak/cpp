#include<bits/stdc++.h>
using namespace std;
/*// Insert before head;
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
node* inserthead(node* head , int val){
    node* newhead = new  node(val , head , NULL);
    head->back = newhead;
    return newhead;

} 
int main(){
    vector<int> arr = {12,3,4,5};
    node* head = convertarrDLL(arr);
    node* headd = inserthead (head , 6);
    print(headd);
    return 0;
}*/

/*// Insert before tail
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
node* inserthead(node* head , int val){
    node* newhead = new  node(val , head , NULL);
    head->back = newhead;
    return newhead;

} 
node* inserttail(node* head , int val){
    if(head->next == nullptr){
        return inserthead(head , val);
    }
   node* tail = head;
   while(tail ->next != NULL){
    tail = tail->next;
   }
   node* prev = tail->back;
   node* newnode = new node(val,tail,prev);
   prev->next = newnode;
   tail->back = newnode; 
   return head;

} 
int main(){
    vector<int> arr = {12,3};
    node* head = convertarrDLL(arr);
    node* headd = inserttail (head , 6);
    print(headd);
    return 0;
}*/

/*// Insert before kth
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
node* inserthead(node* head , int val){
    node* newhead = new  node(val , head , NULL);
    head->back = newhead;
    return newhead;

} 
node* inserttail(node* head , int val){
    if(head->next == nullptr){
        return inserthead(head , val);
    }
   node* tail = head;
   while(tail ->next != NULL){
    tail = tail->next;
   }
   node* prev = tail->back;
   node* newnode = new node(val,tail,prev);
   prev->next = newnode;
   tail->back = newnode; 
   return head;

} 
node* insertbeforekth(node* head , int val , int k){
    if(k==1) return inserthead(head,val);
    if(head == NULL || k <= 0) return NULL;
    node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
             break;
        }
        temp = temp->next;
    }
    if(temp == NULL) return nullptr;
    node* prev = temp->back;
    node* newnode = new node(val , temp ,prev);
    prev->next = newnode;
    temp->back = newnode;
    return head;


}
int main(){
    vector<int> arr = {12,3};
    node* head = convertarrDLL(arr);
    node* headd = insertbeforekth(head , 6 ,2);
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

node* insertnode(node* current , int val){

    node* prev = current->back;
    node* newnode = new node(val , current , prev);
    prev->next = newnode;
    current->back = newnode;

}
int main(){
    vector<int> arr = {12,3,22,11};
    node* head = convertarrDLL(arr);
    insertnode(head->next->next ,100 );
    print(head);
    return 0;
}