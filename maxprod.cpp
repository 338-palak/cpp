#include<bits/stdc++.h>
using namespace std;
/*int maxproductsubarray(vector<int> &nums){
    int n = nums.size();
    int maxi = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        int prod = 1;
        for(int j = i ; j < n ; j++){
            prod = prod * nums[j];
            maxi = max(maxi , prod);
        }
    }
    return maxi;

}

int main() {
    vector<int> nums = {1, -2, 3, 4, -4, -3};
    cout << maxproductsubarray(nums);
}*/
//optimal solution
int maxproductsubarray(vector<int> &nums){
    int pre = 1 , suff = 1;
    int ans = INT_MIN;
    int n = nums.size();
    for(int i = 0 ; i < n ; i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;
        pre = pre * nums[i];
        suff = suff * nums[n-i-1];
        ans = max(ans , max(pre,suff));
    }
    return ans;
}
int main() {
    vector<int> nums = {1, -2, 3, 4, -4, -3};
    cout << maxproductsubarray(nums);
}