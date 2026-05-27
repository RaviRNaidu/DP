#include <bits/stdc++.h>
using namespace std;

//tc --> o(n^3) sc --> o(1)
int brute1(vector<int> &arr, int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int product = 1;
            for(int k=i;k<=j;k++){
                product = product * arr[k];
            }
            maxi = max (maxi, product);
        }
    }
    return maxi;
}

//tc --> o(n^2) sc --> o(1)
int brute2(vector<int> &arr, int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int product = 1;
        for(int j=i;j<n;j++){
            product = product * arr[j];
            maxi = max (maxi, product);
        }
    }
    return maxi;
}

//tc --> o(n) sc --> o(1)
int kadenoptimal(vector<int> &arr, int n){
    int maxi = INT_MIN;
    int sum = 1;
    for(int i=0;i<n;i++){
        if(sum == 0){
            sum = 1;
        }
        sum = sum * arr[i];
        maxi = max(maxi, sum);
    }
    return maxi;
}

//tc --> o(n) sc --> o(1)
int optimalStriver(vector<int> &arr, int n){
    int prefix = 1;
    int suffix = 1;
    int result = INT_MIN;
    for(int i=0;i<n;i++){
        if(prefix == 0){
            prefix = 1;
        }
        if(suffix == 0){
            suffix = 1;
        }
        prefix = prefix * arr[i];
        suffix = suffix * arr[n - 1 - i];
        result = max(result, max(prefix, suffix));
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<optimalStriver(arr,n);
    return 0;
}