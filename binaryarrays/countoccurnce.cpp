#include<bits/stdc++.h>
using namespace std;
/*
int countoccurence(vector<int> & arr , int target){
    int n = arr.size();
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == target){
            count++;
        }
    }
    return count;
}
int main(){
    vector<int> nums = {0,0,1,1,1,2,3};
    int target = 1;
    int result = countoccurence(nums,target);
    cout << result;
}
*/
 int firstoccurence(vector<int> &nums , int x){
    int low = 0 , high = nums.size()-1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == x){
            first = mid ;
            high = mid -1;
            
        }
        else if(nums[mid] < x){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return first;
 }
 int lastoccurence(vector<int> &nums , int x){
    int low = 0 , high = nums.size()-1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == x){
            low = mid +1 ;
            last = mid;
        }else if(nums[mid] < x){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
return last;
}
pair<int , int> firstlast(vector<int> &nums , int x){
    int first = firstoccurence(nums,x);
    int last = lastoccurence(nums,x);
    return {first, last};
}
int countoccurence(vector<int> &nums , int x){
    pair<int , int > ans = firstlast(nums,x);
    if(ans.first == -1){
        return 0;
    }
    return ans.second - ans.first + 1;
}
int main(){
    vector<int> nums = {1, 2, 2, 2, 3, 4, 4, 5};
    int x = 2;
    int result = countoccurence(nums, x);
    cout << result;
}
