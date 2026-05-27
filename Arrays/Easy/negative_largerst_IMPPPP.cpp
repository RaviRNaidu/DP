#include<bits/stdc++.h>
using namespace std;

//optimal for negative
// Function to find the maximum length of subarray with sum equal to k
int hashh(int arr[], int n, long long k){
    // Create a map to store the sum of elements and their corresponding index
    map <long long, int> mpp;
    // Initialize the sum of elements and the maximum length of subarray
    long long sum = 0;
    int maxlen = 0;
    // Iterate through the array
    for(int i=0;i<n;i++){
        // Add the current element to the sum
        sum += arr[i];
        // If the sum is equal to k, update the maximum length of subarray
        if(sum == k){
            maxlen = max(maxlen, i+1);
        }

        // Calculate the remainder of the sum and k
        long long rem = sum - k;
        // If the remainder is found in the map, update the maximum length of subarray
        if(mpp.find(rem) != mpp.end()){ //this line is responsible for checking if the remainder is present in the map or not
            int len = i - mpp[rem];
            maxlen = max(maxlen, len);
        }

        // If the sum is not found in the map, add it to the map with the corresponding index
        if(mpp.find(sum) == mpp.end()){
            mpp[sum] = i; //this line is responsible for inserting the sum and index in the map
        }       // the above line is also responsible for not updating the same sum that already eists in the map
    }
    // Return the maximum length of subarray
    return maxlen;
}

//question number 14 in medium
int count(int arr[], int n, long k){
    map<long long,int>mpp;
    int sum = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];

        if(sum == k){
            ans ++; 
        }

        long rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            ans ++;
        }

        mpp[sum] = i;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long k;
    cin>>k;
    int ans = count(arr, n, k);
    cout<<ans;
    return 0;
}