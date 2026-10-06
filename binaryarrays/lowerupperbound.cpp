#include<bits/stdc++.h>
using namespace std;
// linear approach whose time complexity is o(n);
/*int lowerbound(vector<int> &nums,int target){
    int n = nums.size();
    for(int i = 0 ; i < n ; i++){
        if(nums[i]  >= target ){
            return i;
        }
    }
    return n; 
}
int main() {
    vector<int> nums = {1, 3, 5, 5, 7, 9};
    int target1 = 5;
    cout << "Lower bound of " << target1 << " is at index: " 
         << lowerbound(nums, target1) << endl; 
   
    int target2 = 4;
    cout << "Lower bound of " << target2 << " is at index: " 
         << lowerbound(nums, target2) << endl; 

    int target3 = 12;
    cout << "Lower bound of " << target3 << " is at index: " 
         << lowerbound(nums, target3) << endl; 

    return 0;
}
// Binary approach whose time complexity is o(logn)

int lowerbound(vector<int> &nums , int target){
    int n = nums.size();
    int low = 0 , high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] >= target) {
            ans = mid;
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
   return ans ;
}
int main() {
    vector<int> nums = {1, 3, 5, 5, 7, 9};
    int target = 5;
    cout << "Lower bound of " << target << " is at index: " 
         << lowerbound(nums, target) << endl; 
         return 0;
}
*/
int upperbound(vector<int> &nums , int target){
    int n = nums.size();
    int low = 0 , high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] > target) {
            ans = mid;
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
   return ans ;
}
int main() {
    vector<int> nums = {1, 3, 5, 5, 7, 9};
    int target = 5;
    cout << "upper bound of " << target << " is at index: " 
         << upperbound(nums, target) << endl; 
         return 0;
}

