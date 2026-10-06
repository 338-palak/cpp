#include<bits/stdc++.h>
using namespace std;
// hash map
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class node {
public:
    int data;
    node* next;
    node* random; // Added random pointer

    node(int data1, node* next1 = nullptr, node* random1 = nullptr) {
        data = data1;
        next = next1;
        random = random1;
    }
};

// Clones a linked list with next and random pointers using a Hash Map
node* cloneLL(node* head) {
    if (head == nullptr) return nullptr;

    unordered_map<node*, node*> mp;
    node* temp = head;

    // Step 1: Create all copy nodes and store in map
    while (temp != nullptr) {
        mp[temp] = new node(temp->data);
        temp = temp->next;
    }

    // Step 2: Connect next and random pointers
    temp = head;
    while (temp != nullptr) {
        node* copyNode = mp[temp];
        copyNode->next = mp[temp->next];
        copyNode->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
}

// Helper to print node values along with their random target
void printListWithRandom(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << "Data: " << temp->data;
        if (temp->random) {
            cout << ", Random: " << temp->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << "\n";
        temp = temp->next;
    }
}

int main() {
    // Constructing test list: 1 -> 2 -> 3 -> 4
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);

    // Assigning random pointers
    head->random = head->next->next;             // 1 -> 3
    head->next->random = head;                   // 2 -> 1
    head->next->next->random = head->next->next->next; // 3 -> 4
    head->next->next->next->random = head->next; // 4 -> 2

    cout << "Original List:\n";
    printListWithRandom(head);

    node* clonedHead = cloneLL(head);

    cout << "\nCloned List:\n";
    printListWithRandom(clonedHead);

    return 0;
}