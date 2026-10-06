#include<bits/stdc++.h>
using namespace std;
 long long func(vector<int>& weights, int cap){
        int day = 1 , load = 0;
        for(int i = 0 ; i < weights.size() ; i++){
            if(load+weights[i] > cap){
                day = day + 1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low <= high){
            int mid = low + (high - low)/2;
            int ship = func(weights,mid);
            if(ship <= days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
        
    }
    int main(){
        vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
        int days = 5;
        cout<<shipWithinDays(weights,days);
    }