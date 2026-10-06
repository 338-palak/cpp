#include<bits/stdc++.h>
using namespace std;
/*//floor
int floor(vector<int> & nums , int x){
    int n = nums.size();
    int low = 0 ; int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] <= x){
            ans = nums[mid];
            low = mid + 1;
        }
        else{ high = mid - 1;}
    }
    return ans;
}
int main(){
    vector<int> nums = {10,20,30,40,50};
    int x = 25;
    cout << floor(nums , x);

}*/
//ceil
int ceil(vector<int> &nums, int x){
    int n = nums.size();
    int low = 0 , high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] >= x){
            ans = nums[mid];
            high = mid - 1;
        }
        else{ low = mid + 1;}
    }
    return ans;
}
int main(){
    vector<int> nums = {10,20,30,40,50};
    int x = 25;
    cout << ceil(nums , x);
}
