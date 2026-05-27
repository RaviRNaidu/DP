#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr, int n, int k){
    int maxlen = 0;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=i;j<n;j++){
            if(arr[j] == 0){
                if(cnt == k){
                    break;
                }
                else{
                    cnt++;
                }
            }
            maxlen = max(maxlen, j - i + 1);
        }
    }
    return maxlen;
}

// TC -> O(2N)  SC -> O(1)
int optimal(vector<int> &arr, int n, int k){
    int maxlen = 0;
    int l = 0; int r = 0; int zeros = 0;
    while(r < n){
        if(arr[r] == 0){
            zeros++;
        }
        while(zeros > k){
            if(arr[l] == 0){
                zeros--;
            }
            l++;
        }
        if(zeros <= k){
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}

// TC -> O(N)  SC -> O(1)
int MostOptimal(vector<int> &arr, int n, int k){
    int maxlen = 0;
    int l = 0; int r = 0; int zeros = 0;
    while(r < n){
        if(arr[r] == 0){
            zeros++;
        }
        if(zeros > k){
            if(arr[l] == 0){
                zeros--;
            }
            l++;
        }
        if(zeros <= k){
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans = MostOptimal(arr, n, k);
    cout<<ans<<endl;
    return 0;
}