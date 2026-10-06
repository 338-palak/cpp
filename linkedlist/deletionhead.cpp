#include<bits/stdc++.h>
using namespace std;
/*// deletion of head
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
node* deletedhead(node* head){
    if(head == NULL) return head;
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
int main(){
    vector<int> arr = {12,5,7,8};
    node* head = convertArr2LL(arr);
    head = deletedhead(head);
    print(head);
}
*/

/*// delete the tail of the linked list

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
void print(node* head){
    while(head != NULL) {
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;

}

node* deletetail(node* head){
    node* temp = head;
    if(head == NULL || head->next == NULL) return NULL;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
int main(){
    vector<int> arr = {12,5,7,8};
    node* head = convert2LL(arr);
    node* tail = deletetail(head);
    print(tail);
}
*/

/*//delete kth element

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
void print(node* head){
    while(head != NULL) {
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;

}
node* deletek(node* head , int k){
    if(head == NULL) return head;
    if(k==1){
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0 ;
    node* temp = head ;
    node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;

}
int main(){
    vector<int> arr = {12,5,7,8};
    int k = 2;
    node* head = convert2LL(arr);
    node* remove = deletek(head , k);
    print(remove);
}
*/

// delete the given element
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
void print(node* head){
    while(head != NULL) {
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;

}
node* deletek(node* head , int ele){
    if(head == NULL) return head;
    if(head->data == ele){
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
   
    node* temp = head ;
    node* prev = NULL;
    while(temp != NULL){
       
        if(temp->data == ele){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;

}
int main(){
    vector<int> arr = {12,5,7,8};
    int ele = 5;
    node* head = convert2LL(arr);
    node* remove = deletek(head , ele);
    print(remove);
}
