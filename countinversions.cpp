#include<bits/stdc++.h>
using namespace std;
/*//brute force
int inversion(vector<int> &arr , int n){
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(arr[i]>arr[j]){
               cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    vector<int> arr = {5, 3, 2, 4, 1};
    int n = arr.size();
    cout << inversion(arr, n) << endl;
    return 0;
}
//TC: o(n2) , SC:o(1);*/

//optimal using merge sort

int merge_count(vector<int> &arr , int low , int mid , int high){
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    int cnt = 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
    return cnt;
}

int ms(vector<int> &arr , int low , int high){
    if(low >= high) return 0;
    int mid = (low + high) / 2;
    int count = 0;
    count += ms(arr, low, mid);
    count += ms(arr, mid + 1, high);
    count += merge_count(arr, low, mid, high);
    return count;
}

int countinversions(vector<int> &a , int n){
    return ms(a, 0, n - 1);
}
//tc : o(nlogn)
//sc: o(n)
int main(){
    vector<int> arr = {5, 3, 2, 4, 1};
    int n = arr.size();
    cout << countinversions(arr, n) << endl;
    return 0;
}
