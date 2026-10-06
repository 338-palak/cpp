#include<bits/stdc++.h>
using namespace std;

// using set
int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

set<int> st;

for(int i = 0 ; i < n ; i++){
    st.insert(arr[i]);
}

int index = 0;
for(auto it : st){
    arr[index] = it;
    index++;
}

for(int i = 0 ; i < index ; i++){
    cout << arr[i] << " ";
}
}

//using unordered set
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    unordered_set<int> st;
    vector<int> result;

    for(int i = 0 ; i < n;i++){
        if(st.find(arr[i]) == st.end()){
            result.push_back(arr[i]);
            st.insert(arr[i]);
        }
    }
    cout << "The array after removing duplicates: ";
    for(int x : result){
        cout << x << " ";   
    }

    return 0;

}

int main(){
    int n; 
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    unordered_set<int> st;
    for(int i = 0 ; i < n ; i++){
        st.insert(arr[i]);
    }

    cout << "count:" << st.size() << endl;
    return 0;
}

// two pointer approach
int  main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int i = 0;
    for(int j = 1 ; j < n ; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;

        }
    } 
    cout << "The array after removing duplicates: ";
    for(int k = 0 ; k <=i ; k++){
        cout << arr[k] << " ";
    }
    cout << "\nCount:" << i+1;
    return 0;
   
}

