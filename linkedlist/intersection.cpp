#include<bits/stdc++.h>
using namespace std;
/*
// Brute Force
class node{
    public:
    int data;
    node* next;

    node(int data1, node* next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1; 
        next = nullptr;
    }
};
node* convert2LL(vector<int>& arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1 ; i < arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(node* head){
    while(head != NULL) {
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;

}
node* intersection(node* head1 , node* head2){
    node* temp = head1;
    map<node* , int>mp;
    while(temp != NULL){
        mp[temp]++;
        temp = temp ->next;
    }
    temp = head2;
    while(temp != NULL){
        if(mp.find(temp) != mp.end()){
            return temp;
        }
        temp = temp ->next;
    }

   return NULL;
}
int main(){

    // First linked list
    node* head1 = new node(1);
    head1->next = new node(3);
    head1->next->next = new node(1);

    // Common part
    node* common = new node(6);
    common->next = new node(9);
    common->next->next = new node(11);

    // Attach common part to first list
    head1->next->next->next = common;

    // Second linked list
    node* head2 = new node(7);
    head2->next = new node(2);
    head2->next->next = new node(4);

    // Attach SAME common node to second list
    head2->next->next->next = common;

    // Find intersection
    node* result = intersection(head1, head2);

    if(result != NULL){
        cout << "Intersection found at: " << result->data << endl;
    }
    else{
        cout << "No intersection found" << endl;
    }

    return 0;
}*/

/*
//Better
class node{
    public:
    int data;
    node* next;

    node(int data1, node* next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1; 
        next = nullptr;
    }
};
node* convert2LL(vector<int>& arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1 ; i < arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(node* head){
    while(head != NULL) {
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;

}
node* collision(node* t1 , node* t2 , int D){
    while(D){
        D--;
        t2 = t2->next;
    }
    while(t2 != t1){
        t1=t1->next;
        t2=t2->next;
    }
    return t1;

}
node* intersection(node* head1 , node* head2){
   node* t1 = head1;
   int N1 = 0;
   while(t1 != NULL){
    N1++;
    t1 = t1->next;
   }
   node* t2 = head2;
   int N2 = 0;
   while(t2 != NULL){
    N2++;
    t2 = t2->next;
   }
   if(N1 < N2){
    return collision(head1 , head2 , N2-N1);
   }else{
    return collision(head2 , head1 , N1-N2);
   }

}
int main(){

    // First linked list
    node* head1 = new node(1);
    head1->next = new node(3);
    head1->next->next = new node(1);

    // Common part
    node* common = new node(6);
    common->next = new node(9);
    common->next->next = new node(11);

    // Attach common part to first list
    head1->next->next->next = common;

    // Second linked list
    node* head2 = new node(7);
    head2->next = new node(2);
    head2->next->next = new node(4);

    // Attach SAME common node to second list
    head2->next->next->next = common;

    // Find intersection
    node* result = intersection(head1, head2);

    if(result != NULL){
        cout << "Intersection found at: " << result->data << endl;
    }
    else{
        cout << "No intersection found" << endl;
    }
}
*/

//optimal approach
class node{
    public:
    int data;
    node* next;

    node(int data1, node* next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1; 
        next = nullptr;
    }
};
node* convert2LL(vector<int>& arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1 ; i < arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(node* head){
    while(head != NULL) {
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;

}

node* intersection(node* head1 , node* head2){
  node*  t1 = head1;
  node* t2 = head2;
 while(t1 != t2){
    t1 = t1->next;
    t2 = t2->next;
    if(t1 == NULL) t1 = head2;
    if(t2 == NULL) t2 = head1;
 } 
 return t1; 
}
int main(){

    // First linked list
    node* head1 = new node(1);
    head1->next = new node(3);
    head1->next->next = new node(1);

    // Common part
    node* common = new node(6);
    common->next = new node(9);
    common->next->next = new node(11);

    // Attach common part to first list
    head1->next->next->next = common;

    // Second linked list
    node* head2 = new node(7);
    head2->next = new node(2);
    head2->next->next = new node(4);

    // Attach SAME common node to second list
    head2->next->next->next = common;

    // Find intersection
    node* result = intersection(head1, head2);

    if(result != NULL){
        cout << "Intersection found at: " << result->data << endl;
    }
    else{
        cout << "No intersection found" << endl;
    }
}


