#include<bits/stdc++.h>
using namespace std;

//tc --> o(n^2)   sc --> o(1)
vector<int> brute(vector<int> &arr, int n){
    vector<int> ans;
    int repeating;
    int missing;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(i == arr[j]){
                cnt += 1;
            }
        }
        if(cnt == 2){
            repeating = i;
        }
        else if(cnt == 0){
            missing = i;
        }
    }
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}

//instead to adding them to vector and returning the vector i could return it directly
//tc  --> o(2n)   sc --> o(n)
vector<int> better(vector<int> &arr, int n){
    int repetation;
    int missing;
    int hash_arr[n+1]={0};
    for(int i=0;i<n;i++){
        hash_arr[arr[i]]++;
    }

    for(int i=1;i<=n;i++){
        if(hash_arr[i] == 2){
            repetation = i;
        }
        else if(hash_arr[i] == 0){
            missing = i;
        }
    }

    return {repetation, missing};
}

//tc  --> o(n)   sc --> o(1)
vector<int> optimall(vector<int> &arr, int n){
    long long sum = 0;
    long long sumN = (n*(n+1)) / 2;
    long long sqsum = 0;
    long long sqsumN = (n * (n+1) * (2*n+1)) / 6;
    for(int i=0;i<n;i++){
        sum +=  arr[i];
        sqsum += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = sum - sumN;  // by doing this we get x - y (x is the repeating number and y is missing number)
    long long val2 = sqsum - sqsumN;  // by doing this we get x^2 - y^2 (x is the repeating number and y is missing number)
    //(x+y) = val3
    long long val3 = val2 / val1;
    int x = (val1 + val3) / 2;   // x - y = -4
                                 // x + y = 6
                                 // 2x = 2
                                 // x = sum / 2;
    // now for y
    int y = x - val1;
    return {(int)x , (int)y};
}


// using xor
//tc --> o(3n)  sc --> o(1)
vector<int> optimalXOR(vector<int> &arr, int n){
    int xr = 0;
    for(int i=0;i<n;i++){
        xr = xr ^ arr[i];
        xr = xr ^ i+1;
    }
    int bitNo = 0;
    while(1){
        if(xr & (1<<bitNo) != 0){
            break;
        }
        bitNo++;
    }
    int one = 0;
    int zero = 0;
    for(int i=0;i<n;i++){
        //part of 1 club
        if((arr[i] & (1<<bitNo)) != 0){
            one = one ^ arr[i];
        }
        //part of zero club
        else{
            zero = zero ^ arr[i];
        }
    }
    for(int i=1;i<=n;i++){
        //part of 1 club
        if( (i & (1<<bitNo)) != 0){
            one = one ^ i;
        }
        //part of zero club
        else{
            zero = zero ^ i;
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(one == arr[i]){
            cnt++;
        }
    }
    if(cnt == 0){
        return {zero,one};
    }
    else return {one, zero};
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans = optimalXOR(arr, n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}