#include<bits/stdc++.h>
using namespace std;
/*//brute force approach
int findhours(vector<int>  &arr , int hourly){
    int n = arr.size();
    int totalhours = 0 ;
    for(int i = 0 ; i < n ; i++){
        totalhours += ceil((double)arr[i]/hourly);

    }
    return totalhours;
}
int integerk(vector<int> &piles , int h){
    int maxi = *max_element(piles.begin() , piles.end());
    for(int i = 1 ; i <= maxi ; i++){
        int ttotaltime = findhours(piles , i);
        if(ttotaltime <= h){
            return i;
        }

    }
    return -1;
}
int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout<<integerk(piles , h);
}*/

//optimized approach

int funct(vector<int> &arr , int hourly){
    int totalh = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        totalh += ceil((double)arr[i]/hourly);
    }
    return totalh;
}
int binaryfindhours(vector<int> &arr , int h){
    int low = 1 , high = *max_element(arr.begin() , arr.end());
    
    while(low <= high){
        int mid = low + (high - low)/2;
        int totalhours = funct(arr,mid);
        if(totalhours <= h){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;

}
int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout<<binaryfindhours(piles , h);
}