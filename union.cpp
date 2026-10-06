#include<bits/stdc++.h>
using namespace std;
// Brute force approach
vector<int> unionarray(vector<int> &arr1 , vector<int> &arr2 ){
    int n1= arr1.size();
    int n2 = arr2.size();
    set<int> st;
    for(int i = 0 ; i < n1 ; i++){
        st.insert(arr1[i]);
    }
    for(int i = 0 ; i < n2 ; i++){
        st.insert(arr2[i]);
    }
    vector<int> unionarr;
    for(auto it: st){
        unionarr.push_back(it);
    }
    return unionarr;
}
int main(){
    int n1 , n2;
    cout << "Enter the size of first array and second array : ";
    cin >> n1 >> n2;
    vector<int> arr1(n1) , arr2(n2);
    cout << "Enter the elements of first array : ";
    for(int i = 0 ; i < n1 ; i++){
        cin >> arr1[i];
    }
    cout << "Enter the elements of second array : ";
    for(int i = 0 ; i < n2 ; i++){
        cin >> arr2[i];
    }
    cout << "The union of two arrays is : ";
    vector<int> ans = unionarray(arr1 , arr2);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
}
// optimal approach
vector<int> Union(vector<int> &a , vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    int i = 0 ;
    int j = 0;
    vector<int> unionarray;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            if(unionarray.size() == 0 || unionarray.back() != a[i]){
                unionarray.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionarray.size() == 0 || unionarray.back() != b[j]){
                unionarray.push_back(b[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if(unionarray.size() == 0 || unionarray.back() != b[j]){
            unionarray.push_back(b[j]);
        }
        j++;
    }
    while (i<n1)
    {
      if(unionarray.size() == 0 || unionarray.back() != a[i]){
            unionarray.push_back(a[i]);
        }
        i++;
    }
    return unionarray;
}
int main(){
    int n1 , n2;
    cout << "Enter the size of first array and second array : ";
    cin >> n1 >> n2;
    vector<int> arr1(n1) , arr2(n2);
    cout << "Enter the elements of first array : ";
    for(int i = 0 ; i < n1 ; i++){
        cin >> arr1[i];
    }
    cout << "Enter the elements of second array : ";
    for(int i = 0 ; i < n2 ; i++){
        cin >> arr2[i];
    }
    cout << "The union of two arrays is : ";
    vector<int> ans = Union(arr1 , arr2);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
}