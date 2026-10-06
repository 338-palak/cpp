#include<bits/stdc++.h>
using namespace std;
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
node* getkthnode(node* temp , int k){
    k-=1;
    while(temp != NULL && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;

}
node* findKthNode(node* head , int k){
    node* temp = head;
    int cnt = 1;
    while(temp != NULL){
        if(cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}
node* rotateRight(node* head, int k) {
    if(head == NULL || k == 0) return head;
    int len = 1 ;
    node* tail = head;
    while(tail->next != NULL){
        len++;
        tail = tail->next;
    }
    if(k % len == 0) return head;
    k = k % len;
    tail->next = head;
    node* newnode = findKthNode(head , len-k);
    head = newnode->next;
    newnode->next = NULL;
    
    return head;
}


int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    node* head = convert2LL(arr);
    int k = 2;
    head = rotateRight(head, k);
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}

