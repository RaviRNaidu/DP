#include<bits/stdc++.h>
using namespace std;

//Here M is number of elements stored in the map and that is N/3 + 1
//TC -> O(N * log m) + O(M)
//SC -> O(M)
int finding(vector<int> &arr, int n){
    unordered_map<int, int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it : mpp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}

int optimal(vector<int> &arr, int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = optimal(arr, n);
    cout<<"this number appeared only once: "<<ans<<endl;
    return 0;
}