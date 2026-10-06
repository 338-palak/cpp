#include<bits/stdc++.h>
using namespace std;
// brute force solution
void rightrotate(vector<int> &a , int k , int n){
    k = k % n;
    vector<int> temp(k);
    for(int i = 0 ; i < k ; i++){
        temp[i] = a[n-k+i];
    }
    for(int i = n-k-1 ; i >= 0 ; i--){
        a[i+k] = a[i];
    }
    for(int i = 0 ; i < k ; i++){
        a[i] = temp[i];
    }
}
int main(){
    int n;
    cout << "size of array:" ;
    cin >> n;

    int k ;
    cout << "enter the number of times you want to rotate:" ;
    cin >> k;

    vector<int> arr(n);
    cout << "enter the array elements" ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i]   ;

    }

     rightrotate(arr , k , n);
     for(int i = 0 ; i < n ; i++){
        cout   << arr[i] << endl;
     }
    return 0;

}
// optimal solution
void reverse(vector<int> &a ,int start , int end){
    while(start < end){
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}
void rightrotate(vector<int> &a , int k , int n){
    k = k % n;
    reverse(a , n-k ,n-1);
    reverse(a,0,n-k-1);
    reverse(a,0,n-1);

}
int main(){
    int n;
    cout << "size of array:" ;
    cin >> n;

    int k ;
    cout << "enter the number of times you want to rotate:" ;
    cin >> k;

    vector<int> arr(n);
    cout << "enter the array elements" ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i]   ;

    }

     rightrotate(arr , k , n);
     for(int i = 0 ; i < n ; i++){
        cout   << arr[i] << endl;
     }
    return 0;

}