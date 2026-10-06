#include<bits/stdc++.h>
using namespace std;
/*
pair<int,int> firstlast(vector<int> &nums , int x){
    int n = nums.size();
    int first = -1 , last = -1;
    for(int i = 0 ; i < n ; i++){
        if(nums[i] == x){
            if(first == -1){
                first = i;
            }last = i;
        }

    }
    return {first , last};
}
int main(){
    vector<int> nums = {1, 2, 2, 2, 3, 4, 4, 5};
    int x = 2;
  pair<int, int> result = firstlast(nums, x);
    cout << "First occurrence: " << result.first << ", Last occurrence: " << result.second;
}*/
//o(n) time complexity and o(1) space complexity
/*int lowerbound(vector<int> &nums , int x){
    int n = nums.size();
    int low = 0 , high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] >= x) {
            ans = mid;
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
   return ans ;
}
int upperbound(vector<int> &nums , int x){
    int n = nums.size();
    int low = 0 , high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] > x) {
            ans = mid;
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
   return ans ;
}

pair<int , int> firstlast(vector<int> &nums , int x){
    int first = lowerbound(nums,x);
    int last = upperbound(nums,x)-1;
    if(first == nums.size() || nums[first] != x){
        return {-1,-1};
    }
    return {first, last};
}
 int main(){
    vector<int> nums = {1, 2, 2, 2, 3, 4, 4, 5};
    int x = 2;
    pair<int, int> result = firstlast(nums, x);
    cout << "First occurrence: " << result.first << ", Last occurrence: " << result.second;
 }
 //o(log n) time complexity and o(1) space complexity */
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
int main(){
    vector<int> nums = {1, 2, 2, 2, 3, 4, 4, 5};
    int x = 2;
    pair<int, int> result = firstlast(nums, x);
    cout << "" << result.first << " , " << result.second;
 }
