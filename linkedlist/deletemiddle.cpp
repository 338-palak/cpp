#include<bits/stdc++.h>
using namespace std;
/*class node {
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
void print(node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
node* deleteNode(node* head){
    node* temp = head;
    if(head == NULL || head -> next == NULL) return NULL;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    int res = cnt/2;
    temp = head;
    while(temp != NULL){
        res--;
        if(res == 0){
          node*  middle = temp->next;
            temp->next = temp->next->next;
            delete middle;
            break;
        }
        temp = temp ->next;
  }
return head;


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
   node* hello = deleteNode(head);
   print(hello);
    return 0;
}*/

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
void print(node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
node* deleteMiddle(node* head){
    if(head == NULL ||  head->next == NULL) return NULL;
    node* slow = head;
    node* fast = head;
    fast = head->next->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
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
   node* hello = deleteMiddle(head);
   print(hello);
    return 0;
}
  