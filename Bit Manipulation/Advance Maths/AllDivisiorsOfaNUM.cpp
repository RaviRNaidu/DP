#include<bits/stdc++.h>
using namespace std;

//TC -> O(N) SC -> O(1)
vector<int> allDivisiors(int n){
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(n%i == 0){
            ans.push_back(i);
        }
    }
    return ans;
}

//TC -> O(sqrt(n))  sc -> o(1)
vector<int> optimal(int n){
    vector<int> ans;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            ans.push_back(i);
            if(n / i != i){
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> ans = optimal(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}