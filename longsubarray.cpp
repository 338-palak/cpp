#include<bits/stdc++.h>
using namespace std;
//brute force with O(n^3) time complexity
int longsubarray(vector<int> &arr , int n , int k){
    int len = 0;
    int start = -1 ;
    int end = -1;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            int s=0;
            for(int l = i ; l <= j ; l++){
                s+=arr[l];
            }
            if( s == k)
              {
                if(len < j - i + 1){
                    len = j - i + 1;
                    start = i;
                    end = j;
                }
              }
        }
    }
    if(start == -1){
        cout << "no such subarray is there";
        return 0;
    }
    cout << "the longest subarray with sum " << k << " is: ";
    for(int i = start ; i <= end ; i++){
        cout << arr[i] << " ";
    }
   
    }
int main(){
    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    int k;
    cout << "enter the sum: ";
    cin >>k;
    vector<int> arr(n);
    cout << "enter the elements: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
   longsubarray(arr , n , k);
    return 0;
}
/*// brute force with O(n^2) time complexity
int longsubarray(vector<int> &arr , int n , int k){
    int len = 0;
    int start = -1 ;
    int end = -1;
    for(int i = 0 ; i < n ; i++){
        int s=0;
        for(int j = i ; j < n ; j++){
            s+=arr[j];
            if( s == k)
              {
                if(len < j - i + 1){
                    len = j - i + 1;
                    start = i;
                    end = j;
                }
              }
        }
    }
    if(start == -1){
        cout << "no such subarray is there";
        return 0;
    }
    cout << "the longest subarray with sum " << k << " is: ";
    for(int i = start ; i <= end ; i++){
        cout << arr[i] << " ";
    }
    }
int main(){
    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    int k;
    cout << "enter the sum: ";
    cin >>k;
    vector<int> arr(n);
    cout << "enter the elements: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
   longsubarray(arr , n , k);
    return 0;
}*/
/*// to find length of longest subarray with sum k with O(n) time complexity
int longsubarray(vector<int> &arr , int n , int k){
    int len = 0 ;
    for(int i = 0 ; i < n ; i++){
        int s = 0;
        for(int j = i ; j < n ; j++){
            s+=arr[j];
            if(s == k){
                len = max(len , j - i + 1);
            }
        }
    }
    return len;
}
int main(){
    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    int k;
    cout << "enter the sum: ";
    cin >>k;
    vector<int> arr(n);
    cout << "enter the elements: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
   int result = longsubarray(arr , n , k);
   if(result == 0){
       cout << "no such subarray is there";
   }else{
       cout << "the length of longest subarray with sum " << k << " is: " << result;
   }
    return 0;
}*/
/*// better solution using hashing for positives and negatives with O(n) time complexity
int longestsubarray(vector<int> &a , long long k){
    map<long long , int > preSumMap;
    long long sum = 0 ;
    int maxLen = 0 ;
    for(int i = 0 ; i < a.size() ; i++){
        sum += a[i];
        if(sum == k){
            maxLen = max(maxLen , i + 1);
        }
        int rem = sum -k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen , len);
        }
            if(preSumMap.find(sum) == preSumMap.end()){

        preSumMap[sum] = i;
            }
    }
    return maxLen;

}
int main(){
    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    long long k;
    cout << "enter the sum: ";
    cin >>k;
    vector<int> arr(n);
    cout << "enter the elements: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
   int result = longestsubarray(arr , k);
   if(result == 0){
       cout << "no such subarray is there";
   }else{
       cout << "the length of longest subarray with sum " << k << " is: " << result;
   }
    return 0;
    // this is the optimal solution for both positive and negative elements with O(n) time complexity
}*/
/*// optimal solution using 2 pointer 
int longestsubarray(vector<int> &a , long long k){
    int left = 0 ; 
    int right = 0 ; 
    long long sum = a[0];
    int maxlen = 0 ;
    int n = a.size();
    while(right < n ) {
        while(left <= right && sum > k){
            sum -=a[left];
            left++;
        }
        if(sum ==k){
            maxlen = max(maxlen , right - left + 1);
        }
        right++;
        if(right < n) sum += a[right];

    }
    return maxlen;

}
int main(){
    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    long long k;
    cout << "enter the sum: ";
    cin >>k;
    vector<int> arr(n);
    cout << "enter the elements: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
   int result = longestsubarray(arr , k);
   if(result == 0){
       cout << "no such subarray is there";
   }else{
       cout << "the length of longest subarray with sum " << k << " is: " << result;
   }
    return 0;
}*/
// this is the optimal solution for positive and zero elements only with O(n) time complexity

 

































//g++ longsubarray.cpp -o longarray_run
//./longarray_run