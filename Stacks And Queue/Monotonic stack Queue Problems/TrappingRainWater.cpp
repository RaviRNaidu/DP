#include<bits/stdc++.h>
using namespace std;


//TC -> O(3N) SC -> O(2N)
int brute(vector<int> &arr, int n){
    vector<int> prefixMax(n);
    vector<int> suffixMax(n);

    prefixMax[0] = arr[0];
    for(int i=1;i<n;i++){                            // TC -> O(N)  SC -> O(N)
        prefixMax[i] = max(prefixMax[i-1],arr[i]);
    }

    suffixMax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){                            // TC -> O(N)  SC -> O(N)
        suffixMax[i] = max(suffixMax[i+1],arr[i]);
    }

    int ans = 0;
    for(int i=0;i<n;i++){                            // TC -> O(N)
        if(arr[i] < prefixMax[i] && arr[i] < suffixMax[i]){
            int sum = min(prefixMax[i],suffixMax[i]) - arr[i];
            ans += sum;
        }
    }
    return ans;
}


//TC -> O(2N) SC -> O(N)
int better(vector<int> &arr, int n){
    vector<int> suffixMax(n);

    suffixMax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){                            // TC -> O(N)  SC -> O(N)
        suffixMax[i] = max(suffixMax[i+1],arr[i]);
    }

    int ans = 0;
    int prefixMax = arr[0];
    for(int i=0;i<n;i++){                            // TC -> O(N)
        prefixMax = max(prefixMax,arr[i]);
        if(arr[i] < prefixMax && arr[i] < suffixMax[i]){
            int sum = min(prefixMax,suffixMax[i]) - arr[i];
            ans += sum;
        }
    }
    return ans;
}


//TC -> O(N)    SC -> O(1)
int optimal(vector<int> &arr, int n){
    int lPtr = 0;
    int rPtr = n-1;
    int leftMax = 0;
    int rightMax = 0;
    int ans = 0;
    while(lPtr < rPtr){
        if(arr[lPtr] <= arr[rPtr]){
            if(leftMax > arr[lPtr]){
                ans += leftMax - arr[lPtr];
            }
            else{
                leftMax = arr[lPtr];
            }
            lPtr++;
        }
        else{
            if(rightMax > arr[rPtr]){
                ans += rightMax - arr[rPtr];
            }
            else{
                rightMax = arr[rPtr];
            }
            rPtr--;
        }
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
    cout<<ans<<endl;
    return 0;
}