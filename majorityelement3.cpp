#include<bits/stdc++.h>
using namespace std;
/*list<int> majorityelement3(vector<int> nums , int n){
    list<int> ls;
    for(int i = 0 ; i < n ; i++){
        if(find(ls.begin() , ls.end() , nums[i]) != ls.end())
            continue;
        int cnt = 0 ;
        for(int j = 0 ; j < n ; j++){
            if(nums[i] == nums[j])
                cnt++;
        }
        if(cnt > n/3)
            ls.push_back(nums[i]);
        if(ls.size() > 2)
            break;
       
    }
   return ls;
  
    }

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }
    list<int> ans = majorityelement3(nums , n);
    for(auto it = ans.begin() ; it != ans.end() ; it++){
        cout << *it << " ";
    }
}
// Time Complexity : O(n^2)
// Space Complexity : O(1)
*/


/*//hashing solution
vector<int> majorityelement(vector<int> ans , int n){
    map<int,int> mp;
    for(int i = 0 ; i < n ; i++){
        mp[ans[i]]++;

    }
    for(auto it : mp){
        if(it.second > n/3){
           ans.push_back(it.first);
        }
        if(ans.size() > 2)
            break;
    }
return ans;
}
int main (){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }
    vector<int> ans = majorityelement(nums , n);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
}

// Time Complexity : O(nlogn)  
// Space Complexity : O(n)
*/

// Boyer-Moore Voting Algorithm
vector<int> majorityelement(vector<int> &nums , int n){
    int cnt1 = 0 ,cnt2=0, el1 = INT_MIN , el2 = INT_MIN;
    for(int i = 0 ; i <n ; i++){
        if(cnt1 == 0 && nums[i] != el2){
            cnt1 = 1;
            el1 = nums[i];
        }
        else if(cnt2 == 0 && nums[i] != el1){
            cnt2 = 1;
            el2 = nums[i];
        }
        else if(nums[i] == el1)
            cnt1++;
        else if(nums[i] == el2)
            cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;
    cnt1 = 0,cnt2=0;
    for(int i = 0 ; i < n ; i++){
        if(el1 == nums[i]) cnt1++;
        if(el2 == nums[i]) cnt2++;


    }
   
    if(cnt1 > n/3) ls.push_back(el1);
    if(cnt2 > n/3) ls.push_back(el2);
    sort(ls.begin(),ls.end());
    return ls;

}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> ans = majorityelement(nums, n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
// tc is o(n)
// sc is o(1) excluding ans vector



























// g++  majorityelement3.cpp -o m_run
