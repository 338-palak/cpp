#include<bits/stdc++.h>
using namespace std;
//brute force solution
void leftrotate(vector<int> &arr , int k , int n){
    k = k % n;
    int temp[k] ;
    for(int i = 0 ; i < k ; i++){  // we put our arrays part in the start to a new array because they will go to the end 
        temp[i] = arr[i];
    }
    for(int i = k ; i < n ; i++){ //shifting
        arr[i - k] = arr[i];
    }
    for(int i = n-k ; i < n ; i++){ // putting the elements back to the array
        arr[i] = temp[i-(n-k)];
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

     leftrotate(arr , k , n);
     for(int i = 0 ; i < n ; i++){
        cout << "\n"  << arr[i] << endl;
     }
    return 0;

} 
// optimal solution
void reverse(vector<int> &a , int start , int end){
    while(start < end){
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;        end--;
    }
}
void leftrotate(vector<int> &a , int k , int n){
    k = k % n;
    reverse(a ,0 , k-1);
    reverse(a , k , n-1);
    reverse(a ,0 , n-1);

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

     leftrotate(arr , k , n);
     for(int i = 0 ; i < n ; i++){
        cout << "\n"  << arr[i] << endl;
     }
    return 0;

}
