#include<bits/stdc++.h>
using namespace std;

//TC -> O(N)    SC -> O(1)
bool brute(vector<int> &arr, int n){
    int maxIndex = 0;
    for(int i=0;i<n;i++){
        if(maxIndex < i){
            return false;
        }
        maxIndex = max(maxIndex, i + arr[i]);

        if(maxIndex >= n){
            return true;
        }
    }

    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = brute(arr,n);
    cout<<ans<<endl;
    return 0;
}