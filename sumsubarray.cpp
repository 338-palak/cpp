#include<bits/stdc++.h>
using namespace std;
/*
//brute force approach
int sumsubarray(vector<int> &a , int n ){
    
    int maxi = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j<n ;j++){
            int sum = 0;
            for(int k = i ; k <j ; k++){
                sum += a[k];
                maxi = max(maxi , sum);
            }
        }
    }
return maxi;
}                           //O(n^3) approach
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    cout << sumsubarray(a , n) << endl;
}
*/

/* 
//better approach with o(n^2) time complexity
int sumsubarray(vector<int> &a , int n ){
    
    int maxi = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = i ; j<n ;j++){
            sum += a[j];
            maxi = max(maxi , sum);
        }
    }
return maxi;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    cout << sumsubarray(a , n) << endl;
}
*/
/*//optimal approach with o(n) time complexity using kadane's algorithm
int maxsubarray(vector<int> arr , int n){
    int sum = 0 ;
    int maxi = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        sum +=arr[i];
        maxi = max(maxi , sum);
         if(sum < 0){
        sum = 0;
    }
    }
   
return maxi;

}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    cout << maxsubarray(a , n) << endl;
}*/
int subarray(vector<int> &a , int n){
    int sum = 0 ;
    int maxi = INT_MIN;
    int start = 0;
    int ansstart = -1;
    int ansend = -1;
    for(int i = 0 ; i < n ; i++){
        if(sum == 0){
            start = i;
        }
        sum += a[i];
        if(sum > maxi){
            maxi = sum;
            ansstart = start;
            ansend = i;
        }
        if(sum < 0){
            sum = 0;
        } 
    }
    cout << "the maximum sum is " << maxi << endl;
    cout << "the subarray is " ;
    for(int i = ansstart ; i < ansend ; i++){
        cout << a[i] << " ";
    }

}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    cout << subarray(a , n) << endl;
}
























