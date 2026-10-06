#include<bits/stdc++.h>
using namespace std;
/*//brute force approach
int majorityelement(vector<int> &arr , int n){
    for(int i = 0 ; i < n ; i++){
        int cnt = 0;
        for(int j = 0 ; j < n ; j++){
            if(arr[i] == arr[j]){
                cnt++;
            }
        }
        if(cnt > n/2){
            return arr[i];
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << majorityelement(arr , n) << endl;
}*/
/*//better approach using hash
int majorityelement(vector<int> &arr , int n){
    map<int , int> mp;
    for(int i = 0 ; i < n ; i++){
        mp[arr[i]]++;
    }
    for(auto it : mp){
        if(it.second > n/2){
            return it.first;
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << majorityelement(arr , n) << endl;
}*/
//optimal approach using moore's voting algorithm
int majorityelement(vector<int> &arr , int n){
    int cnt = 0 ;
    int ele;
   for(int i = 0 ; i < n ; i++){
    if(cnt == 0){
        ele = arr[i];
    }
    else if(arr[i] == ele){
        cnt++;
    }
    else{
        cnt--;
    }
   }
   int cnt1 = 0;
   for(int i = 0 ; i < n ; i++){
    if(arr[i] == ele) cnt1++;
   }
    if(cnt1 > n/2){
        return ele;
    
   }
   return -1;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << majorityelement(arr , n) << endl;

    

}