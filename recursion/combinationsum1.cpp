#include<bits/stdc++.h>
using namespace std;
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& current,
               vector<vector<int>>& ans) {

        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(current);
            }
            return;
        }

        // Pick
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);

            solve(index, candidates,
                  target - candidates[index],
                  current, ans);

            current.pop_back();
        }

        // Not pick
        solve(index + 1, candidates, target, current, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> ans;

        solve(0, candidates, target, current, ans);

        return ans;
    }
  
int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

   
    vector<vector<int>> ans =
        combinationSum(candidates, target);

    for (auto combination : ans) {
        cout << "[ ";

        for (int num : combination) {
            cout << num << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}