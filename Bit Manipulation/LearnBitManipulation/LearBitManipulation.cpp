#include<bits/stdc++.h>
using namespace std;

//DONE BY ME
vector<int> covert2binary(int n){
    vector<int> ans;
    while(n > 1){
        int rem = n % 2;
        ans.push_back(rem);
        n = n/2;
    }
    ans.push_back(n);
    reverse(ans.begin(),ans.end());
    return ans;
}


//TC -> O(LOG BASE 2 N)
//SC -> O(LOG BASE 2 N)
string covert2binaryUsingStr(int n){
    string ans = "";
    while(n > 1){
        if(n % 2 == 1){
            ans += '1';
        }
        else{
            ans += '0';
        }
        n = n/2;
    }
    if(n == 0){
        ans += '0';
    }
    else{
        ans += '1';
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    string ans = covert2binaryUsingStr(n);
    for(auto ch:ans){
        cout<<ch<<" ";
    }
    cout<<endl;
    return 0;
}