#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* back;

    public:
    node(int data1 , node* next1 , node*  back1){
    data = data1;
    next = next1;
    back = back1; 
}
public:
node(int data1){
    data = data1;
    next = nullptr;
    back = nullptr;
}
};
void print(node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
node* convertarrDLL(vector<int>& arr){
    if(arr.empty()) return nullptr;
    node* head = new node(arr[0]);
    node* prev = head;
    for(int i = 1 ; i < arr.size() ; i++){
        node* temp = new node(arr[i] , nullptr , prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
node* deleteoccurence(node* head , int key){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            if(temp == head){
                head = head->next;
            }
            node* newnode = temp->next;
            node* prevnode = temp->back;
            if(newnode){
                 newnode->back = prevnode;
            }
            if(prevnode){
                prevnode->next  = newnode;
            }
        delete temp;
        temp = newnode;
    }
    else{
        temp = temp->next;
    }

    }
    return head;
}
int main(){
    vector<int> arr = {12,3,4,5,4,6,5,4,3,4,4};
    node* head = convertarrDLL(arr);
    node* headd = deleteoccurence (head , 4);
    print(headd);
    return 0;
}