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
node* sortnode(node* head){
    vector<int> arr;
    node* temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin() , arr.end());
    int i = 0 ;
    temp = head;
    while(temp != NULL){
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
  return head;
  

 }
int main() {
    vector<int> arr = {5,8,6,1,4,2,9};
    
    node* head = convert2LL(arr);
    head = sortnode(head);
    node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}*/

/*
// this is to merge two sorted arrays
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
node* sortnode(node* head1 , node* head2){
   node* t1 = head1;
   node* t2 = head2;
   node* dNode = new node(-1);
   node* temp = dNode;
   while(t1 != NULL && t2 != NULL){
    if(t1->data < t2->data){
        temp->next = t1;
        temp = t1;
        t1 = t1->next;
    } else {
        temp->next = t2;
        temp = t2;
        t2 = t2->next;
    }
   
   }
   if(t1) temp->next = t1;
   else temp->next = t2;
   return dNode->next;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    
    node* head1 = convert2LL(arr1);
    node* head2 = convert2LL(arr2);
    node* head = sortnode(head1, head2);
    node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}
*/

//merge sort method to sort a linked list;
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
node* findmiddle(node* head){// this is to find the middle
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next; 
    }
    return slow;

}
node* merge2ll(node* head1 , node* head2){ // THis is to merge the two sorted arrays after dividing them
    node dummy(-1);
    node* temp = &dummy;
    node* t1 = head1;
    node* t2 = head2;
   
    while(t1!=NULL && t2!=NULL){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
        if(t1) temp->next = t1;
        else temp->next = t2;
        return dummy.next;
}
node* ms(node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    node* middle = findmiddle(head);
    node* lefthead = head;
    node* righthead = middle->next;
    middle->next = NULL;
   lefthead =  ms(lefthead);
   righthead =  ms(righthead);
   node* merge = merge2ll(lefthead , righthead);
   return merge;

  
}

int main() {
    vector<int> arr = {5,8,6,1,4,2,9};
    
    node* head = convert2LL(arr);
    head = ms(head);
    node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}