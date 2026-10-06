#include<bits/stdc++.h>
using namespace std;
/*
//brute force
vector<vector<int>> sum3(vector<int> nums , int n){
    set <vector<int>> st;
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            for(int k = j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k] == 0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;

}
int main(){
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<vector<int>> ans = sum3(nums, n);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/
/*
//better solution
vector<vector<int>> sum3(vector<int> nums , int n){
    set<vector<int>> st;
    for(int i = 0 ; i < n ; i++){
        set<int> hashset;
        for(int j = i+1 ; j < n ; j++){
            int third = -(nums[i]+nums[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);

            }
            hashset.insert(nums[j]);
        
    }
   
}
 vector<vector<int>> ans(st.begin(),st.end());
 return ans;
}
int main(){
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<vector<int>> ans = sum3(nums, n);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/
//optimal solution
//first sort the array 

vector<vector<int>> triplet(int n , vector<int> &nums){
   vector<vector<int>> ans;
   sort(nums.begin(), nums.end());
   for(int i = 0 ; i < n ; i++){
    if(i>0 && nums[i] == nums[i-1]) continue;
    int j = i+1;
    int k = n-1;
    while(j<k){
        int sum=nums[i]+nums[j]+nums[k];
        if(sum < 0){
            j++;
        }
        else if(sum > 0){
            k--;
        }
        else{
            vector<int> temp = {nums[i],nums[j],nums[k]};
            ans.push_back(temp);
            j++;
            k--;
            while(j < k && nums[j]==nums[j-1]) j++;
            while(j<k && nums[k]==nums[k+1]) k--;
        }
    }
   }
   return ans;
}
int main(){
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<vector<int>> ans = triplet(n, nums);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

