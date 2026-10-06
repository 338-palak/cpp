#include<bits/stdc++.h>
using namespace std;
/*// Count subarrays with XOR as k

int subarrayxor(vector<int> &nums , int n, int k ){
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            int Xor = 0 ;
            for(int l = i ; l <= j ; l++){
                Xor = Xor^nums[l];
            }
            if(Xor == k) cnt++;
    }
 }
 return cnt;
}
int  main(){
    vector<int> nums = {4,2,2,6,4};
    int k = 6;
    int result = subarrayxor(nums, nums.size(), k);
    cout << result << endl;
    return 0;
}

// Count subarrays with xor whose sum is k in this we print the subarrays

#include <bits/stdc++.h>
using namespace std;

void printSubarraysXorK(vector<int> &nums, int k) {
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {

            int Xor = 0;

            for(int l = i; l <= j; l++) {
                Xor ^= nums[l];
            }

            if(Xor == k) {
                cout << "Subarray: ";
                for(int l = i; l <= j; l++) {
                    cout << nums[l] << " ";
                }
                cout << "\n";
            }
        }
    }
}

int main() {
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;

    printSubarraysXorK(nums, k);

    return 0;
}*/


/*// better solution
int subarrayxor(vector<int> &nums , int n, int k ){
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++){
        int xor1 = 0 ;
        for(int j = i ; j < n ; j++){
            xor1 = xor1 ^ nums[j];
             if(xor1 == k) cnt++; 
        }
       
    }
    return cnt;
}
int  main(){
    vector<int> nums = {4,2,2,6,4};
    int k = 6;
    int result = subarrayxor(nums, nums.size(), k);
    cout << result << endl;
    return 0;
}*/

//optimal solution
int subarraysum(vector<int> a , int k){
    int cnt = 0;
    int n = a.size();
    int xr = 0 ;
    map<int , int > mp;
    mp[xr]++;
    for(int i = 0 ; i < n ; i++){
       xr = xr ^ a[i];
       int x = xr ^ k;
       if(mp.find(x) != mp.end()){
        cnt += mp[x];
       }
       mp[xr]++;

    }
    return cnt;
}
int  main(){
    vector<int> nums = {4,2,2,6,4};
    int k = 6;
    int result = subarraysum(nums, k);
    cout << result << endl;
    return 0;
}







           

