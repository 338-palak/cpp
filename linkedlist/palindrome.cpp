#include<bits/stdc++.h>
using namespace std;
/*// using stack to check if the linked list is palindrome or not
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
int palindrome(node* head){
   node* temp = head;
   stack<int> s;
   while(temp != NULL){
    s.push(temp->data);
    temp = temp ->next;
   }
   temp = head;
   while(temp != NULL){
    if(temp->data != s.top()){
        return false;
    }
    temp = temp->next;
    s.pop();
   }
   return true;

}

int main() {
    int n;
    if (!(cin >> n)) {
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n == 0) {
        cout << "true\n";
        return 0;
    }
    node* head = convert2LL(arr);
    cout << (palindrome(head) ? "true" : "false") << '\n';
    return 0;
  
}*/
// two-pointer + tortoise & hare approach
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
    node* prev = NULL;
    node* temp = head;
    while(temp != NULL){
        node* front = temp->next ;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;

}
int palindrome(node* head){
 node* slow = head;
 node* fast = head;
 while(fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
 } 

 node* newhead = reverse(slow->next);
 node* first = head ; node* second =  newhead;
 while(second != NULL){
    if(first->data != second->data){
       
        return false;
    }
    first = first->next;
    second = second->next;

 }
  reverse(newhead);
 return true;

}

int main() {
    int n;
    if (!(cin >> n)) {
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n == 0) {
        cout << "true\n";
        return 0;
    }
    node* head = convert2LL(arr);
    cout << (palindrome(head) ? "true" : "false") << '\n';
    return 0;
}
  