#include<bits/stdc++.h>
using namespace std;
/*
// 
 int search(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0 , high = n-1;
        while(low <= high){
            int mid = (low + high )/2;
            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) low = mid +1 ;
            else high = mid -1 ;
        }
        return -1;
}
int main(){
    vector<int> arr = {2,3,4,5,6,7};
    int target = 6;
    cout << search(arr, target) << endl;
    return 0;
}*/
// recursion method
int bs(const vector<int>& nums , int low , int high , int target){
    if(low > high) return -1;
    int mid = low +  ((high - low)/2);
    if(nums[mid] == target) return mid;
    else if(target > nums[mid]) return bs(nums,mid+1 ,high,target);
    return bs(nums,low,mid -1 , target);
}

int binary(const vector<int>& nums , int target){
    return bs(nums, 0 , (int)nums.size()-1 , target);
}

int main(){
    vector<int> arr = {2,3,4,5,6,7};
    int target = 6;
    cout << binary(arr, target) << endl;
    return 0;
}