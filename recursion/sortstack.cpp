#include<bits/stdc++.h>
using namespace std;
/*// Recursive approach
void sorttheplates(stack<int>& st , int topElement){
    if(st.empty() || topElement >= st.top()){
        st.push(topElement);
        return;
    }
    int element = st.top();
    st.pop();
    sorttheplates(st , topElement);
    st.push(element);
     
}
void taketheplatesout(stack<int>& st){
    if(st.empty()) return;
    int topElement =  st.top() ;
    st.pop();
    taketheplatesout(st);

    sorttheplates(st , topElement);
}
int main() {
    stack<int> st;
    // Pushing elements into the stack
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);
    // Call the sorting function
    taketheplatesout(st);
    // Print the sorted stack (top to bottom)
    cout << "Sorted stack: ";
    while (!st.empty()) {
        cout << st.top() << " "; // Output: 4 3 2 1
        st.pop();
    }
    cout << endl;
    return 0;
}*/

/*// Iterative approach
void sortStackIterative(stack<int>& inputStack) {
    stack<int> tempStack;
    while(!inputStack.empty()){
        int current = inputStack.top();
        inputStack.pop();
    
    while(!tempStack.empty() && tempStack.top() < current){
        inputStack.push(tempStack.top());
        tempStack.pop();
    }
    tempStack.push(current);
}
   while(!tempStack.empty()){
    inputStack.push(tempStack.top());
    tempStack.pop();
   }

}
int main() {
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);
    sortStackIterative(st);
    while (!st.empty()) {
        cout << st.top() << " "; 
        st.pop();
    }
    cout << endl;

    return 0;
}*/

// recursive merge approach
void merge(stack<int>& st , stack<int>& firsthalf, stack<int>& secondhalf ){
    stack<int> temp;
    while(!firsthalf.empty() && !secondhalf.empty()){
        if(firsthalf.top() >= secondhalf.top()){
            temp.push(firsthalf.top());
                firsthalf.pop();
            
        }else{
            temp.push(secondhalf.top());
            secondhalf.pop(); 
        }
    }
    while(!firsthalf.empty()){
          temp.push(firsthalf.top());
                firsthalf.pop();
    }
    while(!secondhalf.empty()){
         temp.push(secondhalf.top());
            secondhalf.pop(); 
    }
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}
void mergesortstack(stack<int>& st){
    if(st.size() <= 1) return ;
    stack<int> firsthalf , secondhalf;
    int mid = st.size() / 2;
    for(int i = 0 ; i < mid ; ++i){
        firsthalf.push(st.top());
        st.pop();
    }
    while(!st.empty()){
        secondhalf.push(st.top());
        st.pop();
    }
    mergesortstack(firsthalf);
    mergesortstack(secondhalf);

    merge(st , firsthalf , secondhalf);
}
int main() {
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    mergesortstack(st);

    // Print sorted stack from top to bottom
    while (!st.empty()) {
        cout << st.top() << " "; // Output: 4 3 2 1
        st.pop();
    }
    cout << endl;

    return 0;
}
