#include<bits/stdc++.h>
using namespace std;
/*//brute force approach with time complexity of O(n^3)
int countsubarray(vector<int> &arr , int n,int k){
    int cnt = 0 ;
    for(int i = 0 ; i<n ; i++){
        for(int j = i ; j < n ; j++){
            int sum = 0 ;
            for(int s = i ; s <= j ; s++){
                sum +=arr[s];
            
                if(sum == k)
                    cnt++;
                    }
        }
    }
      return cnt;
}
int main(){
    int n ;
    int k;
    cout << "Enter the size of array : ";


    
    cin >> n;
    cout << "Enter the value of k : ";
    cin >> k;
    vector<int> arr(n);
    cout << "Enter the elements of array : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << "The count of subarray with sum equal to k is : " << countsubarray(arr,n,k);
     return 0;
}
*/
/*//better approach with time complexity of O(n^2)
int countsubarray(vector<int> &arr , int n , int k){
    int cnt = 0 ; 
    for(int i = 0 ; i < n ; i++){
        int sum = 0 ;
        for(int j = i ; j < n ; j++){
            sum += arr[j];
        
        if(sum == k){ cnt++;
        }
    }}
    return cnt;

}
int main(){
    int n ;
    int k;
    cout << "Enter the size of array : ";
    cin >> n;
    cout << "Enter the value of k : ";
    cin >> k;
    vector<int> arr(n);
    cout << "Enter the elements of array : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << "The count of subarray with sum equal to k is : " << countsubarray(arr,n,k);
     return 0;
}*/
//optimal approach with time complexity of O(n)
int countsubarray(vector<int> &arr , int n , int k){
    map<int,int> mpp;
    mpp[0] = 1;
    int preSum = 0 ;
    int cnt = 0 ;
    for(int i = 0 ; i < n ;i++){
        preSum +=arr[i];
        int remove = preSum - k ;
        cnt += mpp[remove];
        mpp[preSum]++;



    }
    return cnt;
}
int main(){
    int n ;
    int k;
    cout << "Enter the size of array : ";
    cin >> n;
    cout << "Enter the value of k : ";
    cin >> k;
    vector<int> arr(n);
    cout << "Enter the elements of array : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << "The count of subarray with sum equal to k is : " << countsubarray(arr,n,k);
     return 0;
}
//tc: o(nlogn) sc: o(n)
//if you use unordered map then tc will be o(n) and sc will be o(n)