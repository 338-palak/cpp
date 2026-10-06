#include<bits/stdc++.h>
using namespace std;
/*
// linear search in rotated sorted array tc is o(n) and sc is o(1)
int rotatedarray(vector<int> &nums , int target){
    int n  = nums.size();
    for(int i = 0 ; i < n ; i++){
        if(nums[i] == target ){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {7,8,9,1,2,3,4,5,6};
    int target = 1;
    cout<<rotatedarray(nums , target);
    return 0;
}
*/
// binary search method tc is o(logn) and sc is o(1)
  int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n-1;
        while(low <= high){
            int mid =  low + (high - low)/2;
            if(nums[mid] == target) return mid;
            // left sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;}
                    else {
                        low = mid + 1;
            }  
            }
            // right sorted
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;}
                    else {
                        high = mid -1;
                    }
                }
        }
        return -1;
    }
    int main(){
        vector<int> nums = {7,8,9,1,2,3,4,5,6};
        int target = 1;
        cout<<search(nums , target);
        return 0;
    }