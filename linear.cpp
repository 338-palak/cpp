#include<bits/stdc++.h>
using namespace std;
int linearsearch(vector<int> &a , int n , int k ){
    for(int i = 0 ; i < n ; i++){
        if(a[i] == k){
            return i;
        }
    }
    return -1;
}
int main(){
    int n , k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << linearsearch(arr , n , k);
    
}