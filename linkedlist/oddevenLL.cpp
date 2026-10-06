#include<bits/stdc++.h>
using namespace std;
/*// brute force approach
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
node* oddeven(node* head){
      vector<int> arr; 
      node* temp = head;
      while(temp != NULL && temp->next != NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
      }
      if(temp) arr.push_back(temp->data);
        temp = head->next;
      while(temp !=NULL && temp->next != NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
      }
       if(temp) arr.push_back(temp->data);
       temp = head;
       int i = 0;
       while(temp != NULL){
        temp->data = arr[i];
        i++;
        temp = temp->next;
       }
return head;

}
int main() {
    vector<int> arr = {1, 3, 4, 2, 5,6};
    node* head = convert2LL(arr);
    head = oddeven(head);
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
node* oddeven(node* head){
    node* odd = head;
    node* even = head->next;
    node* evenhead = even;
    while(even!= NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;
    return head;

}
int main() {
    vector<int> arr = {1, 3, 4, 2, 5,6};
    node* head = convert2LL(arr);
    head = oddeven(head);
    node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << "\n";
    return 0;
}
 