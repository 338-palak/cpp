#include<bits/stdc++.h>
using namespace std;
/* 
3-4-2
5-6-4
then 243 + 465 = 807 but well get 708
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


node* addtwo(  node* head1 , node* head2){
     node* dummyhead = new node(-1);
     node* current = dummyhead;
     node* t1 = head1;
     node* t2 = head2;
     int carry = 0;
     
     while(t1 != NULL || t2 != NULL){
        int sum = carry;
        if(t1) sum = sum + t1->data;
        if(t2) sum = sum + t2->data;

        node* newnode = new node(sum % 10);
        carry = sum/10;
        current->next = newnode;
        current = current->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next; 
     }
     if(carry == 1){
        node* newhead = new node(1);
        current->next = newhead;
       
             }
     return dummyhead->next;
    }
    
void printLL(node* head){
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    vector<int> arr1 = {2,4,3};
    vector<int> arr2 = {5,6,4};

    node* head1 = convert2LL(arr1);
    node* head2 = convert2LL(arr2);

    cout << "First number: ";
    printLL(head1);

    cout << "Second number: ";
    printLL(head2);

    node* result = addtwo(head1, head2);

    cout << "Result: ";
    printLL(result);

    return 0;
}
*/

// so if we dont it to reverse then
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
node* reverse(node* head){
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

node* addtwo(  node* head1 , node* head2){
     head1= reverse(head1);
     head2 = reverse(head2);
     node* dummyhead = new node(-1);
     node* current = dummyhead;
     node* t1 = head1;
     node* t2 = head2;
     int carry = 0;
     
     while(t1 != NULL || t2 != NULL){
        int sum = carry;
        if(t1) sum = sum + t1->data;
        if(t2) sum = sum + t2->data;

        node* newnode = new node(sum % 10);
        carry = sum/10;
        current->next = newnode;
        current = current->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next; 
     }
     if(carry == 1){
        node* newhead = new node(1);
        current->next = newhead;
       
             }
      node* ans = reverse(dummyhead->next);

      return ans;
    }
    
void printLL(node* head){
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    vector<int> arr1 = {2,4,3};
    vector<int> arr2 = {5,6,4};

    node* head1 = convert2LL(arr1);
    node* head2 = convert2LL(arr2);

    cout << "First number: ";
    printLL(head1);

    cout << "Second number: ";
    printLL(head2);

    node* result = addtwo(head1, head2);

    cout << "Result: ";
    printLL(result);

    return 0;
}
