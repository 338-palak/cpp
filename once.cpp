#include<bits/stdc++.h>
using namespace std;
//brute force solution
int once(vector<int> &arr , int n ){
    for(int i = 0 ; i < n ; i++){
      int num = arr[i];
    
    int cnt = 0 ;
    for(int j = 0 ; j < n ; j++){
        if(arr[j] == num){
            cnt++;
        }
        
    }
    if(cnt == 1){
        return num;
    }
}
return -1;
}
int main(){
    int n;
    cout << "enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter the elements of the array: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
     }
     cout << "the number which is present only once is : " << once(arr , n) << endl;
     return 0;
}
//better approach using map 
int once(vector<int> &arr , int n){
    map<int,int> mpp;
    for(int i = 0 ; i < n ; i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
    
}
int main(){
    int n;
    cout << "enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter the elements of the array: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
     }
     cout << "the number which is present only once is : " << once(arr , n) << endl;
     return 0;
}
     //optimal approach
int once(vector<int> &arr , int n){
    int xor1 = 0 ; 
    for(int i = 0 ; i < n ; i++){
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}
int main(){
    int n;
    cout << "enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter the elements of the array: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
     }
     cout << "the number which is present only once is : " << once(arr , n) << endl;
     return 0;
}

