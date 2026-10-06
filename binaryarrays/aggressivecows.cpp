#include<bits/stdc++.h>
using namespace std;
   long long canweplace(vector<int>& position , int distance , int m){
        int n = position.size();
        long long cntm = 1 , lastposition = position[0];
        for(int i = 0 ; i < n ; i++){
            if(position[i] - lastposition >= distance){
                cntm ++;
                lastposition = position[i];
            }
        }
        if(cntm >= m) {return true;}
        else{
            return false;
        }
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 1 , high = position[n-1] - position[0];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canweplace(position,mid,m) == true){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high; 
    }
    int main(){
        vector<int> position = {2,3,4,7,11};
        int m = 5;
        cout<<maxDistance(position,m);

    }
