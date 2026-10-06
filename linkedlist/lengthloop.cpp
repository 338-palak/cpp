#include<bits/stdc++.h>
using namespace std;
/* hash 
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

int lengthloop(node* head){
     node* temp = head;
     int timer = 1;
     map<node* , int>mp;
     if(head == NULL) return 0;
     while(temp != NULL){
        if(mp.find(temp) != mp.end()){
            int value = mp[temp];
            return timer - value;
        }
       mp[temp] = timer;
        timer++;
        temp = temp->next;
     }
return 0;

}

int main() {

    vector<int> arr = {12, 5, 7, 4, 8};
    node* head = convert2LL(arr);
      node* temp = head;
    node* loopNode = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Move loopNode to node containing 7
    loopNode = head->next->next;

    // Last node (8) points back to 7
    temp->next = loopNode;

    int looplength = lengthloop(head);
    cout << "loop length = " << looplength << endl;
    return 0;
}*/

// tortoise and hare method
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
int findlength(node* slow , node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow != fast){
    cnt++;
    fast = fast->next;

   }
    return cnt;

}
int lengthloop(node* head){
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow ->next ;
        fast = fast ->next ->next;
        int cnt = 0;
        if(slow == fast){
            return findlength(slow,fast);

        }
    }

}

int main() {

    vector<int> arr = {12, 5, 7, 4, 8};
    node* head = convert2LL(arr);
      node* temp = head;
    node* loopNode = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Move loopNode to node containing 7
    loopNode = head->next->next;

    // Last node (8) points back to 7
    temp->next = loopNode;

    int looplength = lengthloop(head);
    cout << "loop length = " << looplength << endl;
    return 0;
}
