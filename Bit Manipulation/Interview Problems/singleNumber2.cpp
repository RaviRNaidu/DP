#include<bits/stdc++.h>
using namespace std;

//Here M is number of elements stored in the map and that is N/3 + 1
//TC -> O(N * log m) + O(M)
//SC -> O(M)
int finding(vector<int> &arr, int n){
    unordered_map<int, int> mpp;
    for(int i=0;i<n;i++){ //TC -> O(N)
        mpp[arr[i]]++;  //TC -> O(LOG M)
    }

    for(auto it : mpp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}

//BETTER
//TC -> O(M * N)    SC -> O(1)          M IS 32
int better(vector<int> &arr, int n){
    int ans = 0;
    for(int bitIndex = 0; bitIndex <= 31; bitIndex++){   //TC -> O(M) WHERE M IS 32
        int cnt = 0;
        for(int i=0;i<n;i++){                               //TC -> O(N)
            if((arr[i] & 1<<bitIndex)){
                cnt++;
            }
        }
        if(cnt % 3 == 1){   
            ans = ans | (1<<bitIndex);
        }
    }
    return ans;
}

//OPTIMAL
//tc -> o(n log n) + o(n/3)     sc -> o(1)
int optimal(vector<int> &arr, int n){
    sort(arr.begin(),arr.end());    //tc -> o(n log n)
    for(int i=1;i<n;i += 3){        //tc -> o(n/3)
        if(arr[i] != arr[i-1]){
            return arr[i-1];
        }
    }
    return arr[n-1];
}

//TC -> O(N)    SC -> O(1)
int MostOptimal(vector<int> &arr, int n){
    int ones = 0;
    int twos = 0;
    for(int i=0;i<n;i++){
        ones = (ones ^ arr[i]) & ~twos;
        twos = (twos ^ arr[i]) & ~ones;
    }
    return ones;
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