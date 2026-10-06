#include<bits/stdc++.h>
using namespace std;
/*
bool possibility(vector<int>& arr, int day, int m, int k) {
    int cnt = 0;
    int noofbouquets = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= day) {
            cnt++;
        } else {
            noofbouquets += cnt / k;
            cnt = 0;
        }
    }

    // Count bouquets from the last consecutive segment
    noofbouquets += cnt / k;

    return noofbouquets >= m;
}

int minimumDay(vector<int>& arr, int m, int k) {

    // Impossible to make m bouquets
    if ((long long)m * k > arr.size()) {
        return -1;
    }

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    // Brute Force
    for (int day = low; day <= high; day++) {
        if (possibility(arr, day, m, k)) {
            return day;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    cout << minimumDay(arr, m, k);

    return 0;
}*/

bool possibilty(vector<int> &arr , int day , int m , int k){
    int n = arr.size();
    int cnt = 0 ;
    int noofbouques = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] <= day){
            cnt++;
        }else{
            noofbouques += cnt/k;
            cnt = 0;
        }

    }
      noofbouques += cnt/k;
        return noofbouques >= m;
}
int minimumday(vector<int> &arr , int m , int k){
    int n = arr.size();
    if((long long)m*k > n){return -1;}
    int low = *min_element(arr.begin(),arr.end());
    int high = *max_element(arr.begin(),arr.end());
    for(int i = low ; i <= high ; i++){
        if(possibilty(arr , i , m , k)){
            return i;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    cout << minimumday(arr, m, k);

    return 0;}
    //binaryapproach
        int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int n = bloomDay.size();
        
        while(low <= high){
            if((long long)m * k > n){return -1;}
            int mid = low + (high - low)/2;
            if(possible(bloomDay,mid ,m,k)){
                 high = mid - 1;
            }else {
              
                low = mid + 1;
            }
        }
        return low; 
    }
    int possible(vector<int>& bloomDay , int days , int m , int k){
        int n = bloomDay.size();
        int cnt = 0 ;
        int boque=0;
        for(int i = 0 ; i < n ; i++){
            if(bloomDay[i] <= days){
                cnt++;
            }else{
                boque += cnt/k ;
                cnt = 0;
            }
        }
        boque  += cnt/k;
        return boque >= m;
    }