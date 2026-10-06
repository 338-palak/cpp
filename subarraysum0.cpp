#include<bits/stdc++.h>
using namespace std;
int subarraysum(vector<int> &nums , int n){
    // TC : o(n){o(n2 worst case)}
    //  SC  : o(n)

unordered_map<int,int> mpp;
int maxi = 0;
int sum = 0 ;
for(int i = 0 ; i < n ; i++){
    sum+=nums[i];
    if(sum == 0){
        maxi = i+1;
    }
    else{
        if(mpp.find(sum) != mpp.end()){
            maxi = max(maxi , i-mpp[sum]);
        }
        else{
            mpp[sum] = i;
        }
    }
}

    return maxi;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<subarraysum(nums,n)<<"\n";
    return 0;
}