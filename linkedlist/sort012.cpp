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

node* sort012(node* head){
   node* temp = head;
   int cnt0 = 0 , cnt1 = 0 , cnt2 = 0;
   while(temp != NULL){
    if(temp->data == 0) cnt0++;
    else if(temp->data ==1) cnt1++;
    else cnt2++;
    temp = temp->next;
   }
   temp = head;
   while(temp != NULL){
    if(cnt0){
        temp->data = 0;
        cnt0--;
    }else if(cnt1){
           temp->data = 1;
           cnt1--;
    }else{
        temp->data = 2;
        cnt2--;
    }
    temp = temp->next;

   }
   return head;

}

int main() {
    vector<int> arr = {0,2,1,2,0,2,1,0};
    
    node* head = convert2LL(arr);
    head = sort012(head);
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

// optimal solution
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

node* sort012(node* head){
    if(head == NULL || head->next == NULL)  {return head;}
    node* zerohead = new node(-1); 
    node* onehead = new node(-1);
    node* twohead = new node(-1);
    node* one = onehead;
    node*  two = twohead;
    node* zero = zerohead;
    node* temp = head;
    while(temp != NULL){
        if(temp ->data == 0) {
            zero->next = temp;
            zero = temp;
        }
        else if(temp ->data == 1) {
            one->next = temp;
            one = temp;
        }else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;

    }
    zero->next = onehead->next;
    one->next = twohead->next;
    two->next = NULL;
   node* newhead = zerohead->next;
   delete  zerohead;
   delete onehead;
   delete twohead;
   return newhead;
    
}

int main() {
    vector<int> arr = {0,2,1,2,0,2,1,0};
    
    node* head = convert2LL(arr);
    head = sort012(head);
    node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}

