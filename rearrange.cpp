#include<bits/stdc++.h>
using namespace std;
//when we have equal number of + & -;
/*//brute force approach 
void rearrange(vector<int> &arr , int n){
    vector<int> pos;
    vector<int> neg;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] >= 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    for(int i = 0 ;  i < n/2 ; i++){
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];  
    }

}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
cout << "Rearranged array is : " << endl;
    rearrange(arr , n);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}*/
/*
//optimal approach

vector<int> rearrange(vector<int> &arr , int n){
    vector<int> temp(n,0);

    int posindex = 0;
    int negindex = 1;

    for(int i = 0 ; i < n ; i++){
        if(arr[i] < 0){
            temp[negindex] = arr[i];
            negindex += 2;
        }
        else{
            temp[posindex] = arr[i];
            posindex += 2;
        }
    }

    return temp;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    vector<int> rearranged = rearrange(arr,n);

    cout << "Rearranged array is:\n";

    for(int i = 0 ; i < n ; i++){
        cout << rearranged[i] << " ";
    }
}*/
// if we have unequal number of + & - then we can use the below approach
//better approach

void rearrange(vector<int> &arr , int n){
    vector<int> pos;
    vector<int> neg;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] >= 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    if(pos.size()>neg.size()){
        for(int i = 0 ; i < neg.size();i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];  
        }
        int index = 2*neg.size();
        for(int i = neg.size(); i < pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }
   else{
        for(int i = 0 ; i < pos.size();i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];  
        }
        int index = 2*pos.size();
        for(int i = pos.size(); i < neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }
   }

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
cout << "Rearranged array is : " << endl;
    rearrange(arr , n);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }}
