#include<bits/stdc++.h>
using namespace std;

int largestelement(vector<int> &nums , int n){
    int largest = nums[0];
    for(int i = 1 ; i < n ; i++){
        if(nums[i] > largest ){
            largest = nums[i];

        }
    }
    return largest;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    cout << "The largest element in the array is: " << largestelement(nums, n) << endl;
    return 0;
}