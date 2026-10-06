#include<bits/stdc++.h>
using namespace std;

//brute force approach
int missingnumber(vector<int> &arr , int n ){
    for(int i = 1 ; i <= n ; i++){
        int flag = 0;
        for(int j = 0 ; j < arr.size() ; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n-1);
    for(int i = 0 ; i < n-1 ; i++){
        cin >> arr[i];
    }
    cout << missingnumber(arr , n) << endl;
}



//better approach using hash
int missingnumber(vector<int> &arr , int n){
    vector<int> hash(n+1 , 0);
    for(int i = 0 ; i < n-1 ; i++){
        hash[arr[i]] = 1;
    }
    for(int i = 1 ; i <= n ; i++){
        if(hash[i] == 0){
            return i;
        }
    } 
    return -1;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n-1);
    for(int i = 0 ; i < n-1 ; i++){
        cin >> arr[i];
    }
    cout << missingnumber(arr , n) << endl;
}

//optimal approach using sum formula
int missingnumber(vector<int> &arr , int n ){
   int sum = n*(n+1)/2;
   int arrsum = 0 ;
   for(int i = 0 ; i < n-1 ; i++){
    arrsum += arr[i];
   }
   return sum - arrsum;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n-1);
    for(int i = 0 ; i < n-1 ; i++){
        cin >> arr[i];
    }
    cout << missingnumber(arr , n) << endl;
}
//optimal approach using XOR
int missingnumber(vector<int> &arr , int N ){
    int xor1 = 0 , xor2 = 0;
    int n = N-1;
   for(int i = 0 ; i < n ; i++){
    xor1 = xor1 ^ arr[i];
    xor2 = xor2 ^ (i+1);
   } 
   xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n-1);
    for(int i = 0 ; i < n-1 ; i++){
        cin >> arr[i];
    }
    cout << missingnumber(arr , n) << endl;
}