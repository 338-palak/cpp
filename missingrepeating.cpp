#include<bits/stdc++.h>
using namespace std;
//brute force
/*pair<int,int> repeatmiss(const vector<int>& arr , int n){
    int repeating = -1;
    int missing = -1;
    for(int i = 1 ; i <= n ; i++){
        int cnt = 0 ;
        for(int j = 0 ; j < n ; j++){
            if(arr[j] == i){
                cnt++;
            }
        }
        if(cnt >= 2){
            repeating = i;
        }else if(cnt == 0){
            missing = i;
        }
        if(repeating != -1 && missing!=-1){
            break;
        }

    }
    return make_pair(repeating , missing);
}
int main(){
    vector<int> nums = {1,2,4,5,6,6};
    int n = nums.size();

    pair<int,int> ans = repeatmiss(nums, n);

    cout << "Repeating: " << ans[0] << endl;
    cout << "Missing: " << ans[1] << endl;

    return 0;
}
*/
// better approach using hashing
/*vector<int> repeatmiss(vector<int> arr ){
    int n = arr.size();
    int hasharray[n+1] = {0};
    for(int i = 0 ; i < n ; i++){
        hasharray[arr[i]]++;
    }
    int repeating = - 1 , missing = -1;
    for(int i = 1 ; i <= n ; i++){
        if(hasharray[i] == 2 ) repeating = i;
        else if(hasharray[i] == 0) missing = i;

          if(repeating != -1 && missing!=-1){
            break;
        }


    }
    return {repeating , missing};

}
int main(){
    vector<int> nums = {1,2,4,5,6,6};
    int n = nums.size();
      vector<int> ans = repeatmiss(nums);

    cout << "Repeating: " << ans[0] << endl;
    cout << "Missing: " << ans[1] << endl;

    return 0;
}

*/
//optimal approach
vector<int>  repeatmiss(vector<int> arr ){
    long long n = arr.size();
    //S - Sn = x - y
    //S2 - S2n
    long long Sn = (n*(n+1)) / 2 ;
    long long S2n = (n*(n+1)*(2*n+1)) / 6 ;
    long long S = 0 , S2 = 0 ;
    for(int i = 0 ; i < n ; i++){
        S += arr[i];
        S2 += arr[i] * arr[i];
    }
   long val1 = S-Sn ; // x-y
   long val2 = S2-S2n ;
    val2 = val2 / val1 ; // x+y
    long long x = (val1 + val2)/2 ;
    long long y = x-val1;
    return {(int)x,(int)y};
 
}
int main(){
    vector<int> nums = {1,2,4,5,6,6};
    int n = nums.size();
      vector<int> ans = repeatmiss(nums);

    cout << "Repeating: " << ans[0] << endl;
    cout << "Missing: " << ans[1] << endl;

    return 0;
}

     