#include<bits/stdc++.h>
using namespace std;
/*//next permutation
vector<int> nextpermutation(vector<int> &A){
    next_permutation(A.begin(),A.end());
    return A;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    vector<int> ans = nextpermutation(arr);
    cout << "Next permutation is : " << endl;
    for(int i = 0 ; i < n ; i++){
        cout << ans[i] << " ";
    }
}*/
//optimal approach
 void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i = n-2 ; i>=0 ; i--){
            if(nums[i] < nums[i+1]){
                ind = i ;
                break;
            }
        }
        if(ind == -1){
            reverse(nums.begin() , nums.end());
            return;
        }
        for(int i = n-1 ; i >=ind ;i--){
            if(nums[i] > nums[ind]){
                swap(nums[i] , nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1 , nums.end() );
        
    }
    int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];  

    }
    nextPermutation(arr);
    cout << "Next permutation is : " << endl;
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}