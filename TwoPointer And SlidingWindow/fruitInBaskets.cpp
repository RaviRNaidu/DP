#include<bits/stdc++.h>
using namespace std;

//TC -> O(N^2)  SC -> O(2)
int brute(vector<int> &arr, int n){
    int maxFruits = 0;
    for(int i=0;i<n;i++){
        unordered_map<int, int> mpp;
        int unique = 0;
        int len = 0;
        for(int j=i;j<n;j++){
            if(mpp.find(arr[j]) == mpp.end()){
                if(unique == 2){
                    break;
                }
                unique++;
                mpp[arr[j]]++;
            }
            else{
                len = j - i + 1;
                maxFruits = max(maxFruits,len);
            }
        }
    }
    return maxFruits;
}

//TC -> O(N^2)  SC -> O(2)
int brute2(vector<int> &arr, int n){
    int maxFruits = 0;
    for(int i=0;i<n;i++){
        set<int> st;
        int len = 0;
        for(int j=i;j<n;j++){
            st.insert(arr[j]);
            if(st.size() <= 2){
                len = j - i + 1;
                maxFruits = max(maxFruits,len);
            }
            else{
                break;   
            }
        }
    }
    return maxFruits;
}

//TC -> O(2N)   SC -> O(3)
int better(vector<int> &arr, int n){
    int maxFruits = 0;
    unordered_map<int, int> mpp;
    int l = 0; int r = 0;
    while(r < n){
        mpp[arr[r]]++;
        if(mpp.size() > 2){
            while(mpp.size() > 2){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }
        if(mpp.size() <= 2){
            int fruit = r - l + 1;
            maxFruits = max(maxFruits, fruit);
        }
        r++;
    }
    return maxFruits;
}

//TC -> O(N)   SC -> O(3)
int optimal(vector<int> &arr, int n){
    int maxFruits = 0;
    unordered_map<int, int> mpp;
    int l = 0; int r = 0;
    while(r < n){
        mpp[arr[r]]++;
        if(mpp.size() > 2){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0){
                mpp.erase(arr[l]);
            }
            l++;
        }
        if(mpp.size() <= 2){
            int fruit = r - l + 1;
            maxFruits = max(maxFruits, fruit);
        }
        r++;
    }
    return maxFruits;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = optimal(arr, n);
    cout<<ans<<endl;
    return 0;
}