#include<bits/stdc++.h>
using namespace std;
/*
// brute force approach
vector<int> twosum(vector<int> &nums , int target ){
    int n = nums.size();
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(i == j) continue;
            if(nums[i] + nums[j] == target){
                return  {i , j} ;
            }

        }
    }

}
int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = twosum(nums , target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
*/
/*// better approach
vector<int> twosum(vector<int> &nums , int target , int n){
    map<int,int> mp;
    for(int i = 0 ; i < n ; i++){
        int a = nums[i];
        int more = target -a;
        if(mp.find(more) != mp.end()){
            return {mp[more] , i};
        }
        mp[a] = i; // we should not use the same element twice so we are storing the index of the element in the map

    }
    return {-1 , -1};

}
int main(){
    vector<int> nums = {2,7,11,15};
    int target = 18;
    int n = nums.size();
    vector<int> result = twosum(nums , target , n);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
*/
// optimal approach with two pointers
string twosum(vector<int> &nums , int target , int n){
    sort(nums.begin() , nums.end());
    int left = 0 ; int right = n-1;
    while(left < right){
        int sum = nums[left] + nums[right];
        if(sum == target){
            return "yes";
        }
        else if(sum < target) left++;
        else right--;
        
    }
    return "no";
}
    int main(){
        vector<int> nums = {2,11,15,6,3};
        int target = 18;
        int n = nums.size();
        string result = twosum(nums , target , n);
        cout << result[0] << " " << result[1] << endl;
        return 0;
    }
    // this is variety one of two sum problem where we have to return yes or no if the pair is present or not in the array.
    // this is the best approach with time complexity of O(nlogn) due to sorting and space complexity of O(1) as we are not using any extra space.
// for variety two where we have to return the indices of the pair we can use the map approach which has time complexity of O(n) for unordered and space complexity of O(n) as we are using a map to store the indices of the elements.


