using namespace std;
#include <bits/stdc++.h>
/*// using map to detect starting point of loop
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

node* startingloop(node* head){
    map<node* , int> mp;
    node* temp = head;
    while(temp != NULL){
        if(mp.find(temp) != mp.end()){
            return temp;
        }
        mp[temp] = 1;
        temp = temp->next;
    }
    return NULL;
   
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
    node* loopStart = startingloop(head);
    cout << (loopStart ? "Loop starts at node with data: " + to_string(loopStart->data) : "No loop detected") << endl;
    return 0;
}*/

// using tortoise and hare algorithm
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

node* startingloop(node* head){
   node* slow = head;
   node* fast = head;
   while(fast != NULL && fast->next != NULL){
    slow = slow ->next;
    fast = fast->next->next;
    if(slow == fast){
        slow = head;
        while(slow != fast){
            slow = slow ->next;
            fast = fast->next;
        }
        return slow;
    }
   }
   return NULL;
   
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
    node* loopStart = startingloop(head);
    cout << (loopStart ? "Loop starts at node with data: " + to_string(loopStart->data) : "No loop detected") << endl;
    return 0;
}