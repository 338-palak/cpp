#include<bits/stdc++.h>
using namespace std;
void FindCandidates(int ind , int target , vector<int>& arr , vector<int>& ds , vector<vector<int>>& ans ){
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    for(int i = ind ; i < arr.size();i++){
        if(i>ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;
        ds.push_back(arr[i]);
        FindCandidates(i+1,target-arr[i],arr,ds,ans);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        FindCandidates(0,target,candidates,ds,ans);
        return ans;
        
    }
   
int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

   
    vector<vector<int>> ans =combinationSum2(candidates, target);

    for(auto combination : ans) {
        for(int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}