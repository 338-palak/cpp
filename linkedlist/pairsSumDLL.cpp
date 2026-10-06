#include<bits/stdc++.h>
using namespace std;
/*#include<bits/stdc++.h>
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
// Finds and returns all pairs that sum to the target value
vector<pair<int, int>> pairsSum(node* head, int sum) {
    vector<pair<int, int>> ds;
    node* temp1 = head;

    while (temp1 != nullptr) {
        node* temp2 = temp1->next;
        while (temp2 != nullptr) {
            if (temp1->data + temp2->data == sum) {
                ds.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next; // Advance inner pointer
        }
        temp1 = temp1->next;     // Advance outer pointer
    }
    return ds;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6};
    node* head = convertarrDLL(arr);

    int targetSum = 5;
    vector<pair<int, int>> pairs = pairsSum(head, targetSum);

    cout << "Pairs with sum " << targetSum << ":\n";
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}*/

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
// Helper to get the last node of the DLL
node* findtail(node* head) {
    node* tail = head;
    while (tail != nullptr && tail->next != nullptr) {
        tail = tail->next;
    }
    return tail;
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
// Finds and returns all pairs that sum to the target value
vector<pair<int, int>> pairsSum(node* head, int sum) {
  vector<pair<int, int>> ds;
  if(head == NULL) return ds;
    node* left = head;
    node* right = findtail(head);
    while(left->data < right->data){
        if(left->data + right->data == sum){
            ds.push_back({left->data,right->data});
            left = left->next;
            right = right->back;
        }else if(left->data + right->data < sum){
             left = left->next;
        }else{
            right = right->back;
        }

    } 

    return ds;

}

int main() {
    vector<int> arr = {1,2,3,4,5,6};
    node* head = convertarrDLL(arr);

    int targetSum = 5;
    vector<pair<int, int>> pairs = pairsSum(head, targetSum);

    cout << "Pairs with sum " << targetSum << ":\n";
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}