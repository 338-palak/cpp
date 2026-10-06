#include<bits/stdc++.h>
using namespace std;
void func(int ind , int sum , vector<int>& arr ,int N , vector<int>& sumsubset){
     if(ind == N){
        sumsubset.push_back(sum);
        return;
     }
     //pick
     func(ind+1, sum + arr[ind], arr, N, sumsubset);
     //not pick
     func(ind+1, sum, arr, N, sumsubset);
}
vector<int> subset(vector<int>& arr){
    vector<int> sumsubset;
    int N = arr.size();
    func(0,0,arr, N , sumsubset);
    sort(sumsubset.begin(),sumsubset.end());
    return sumsubset;

}
int main() {
    vector<int> arr = {3,1,2};

    vector<int> ans = subset(arr);

    for(int sum : ans) {
        cout << sum << " ";
    }

    return 0;
}
