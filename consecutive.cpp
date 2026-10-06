#include<bits/stdc++.h>
using namespace std;
 int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0 ;
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 1){
                cnt++;
                maxi = max(maxi , cnt);
            }
            else{
                cnt = 0;
            }
        }
        return maxi;
    }
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << findMaxConsecutiveOnes(arr) << endl;

}