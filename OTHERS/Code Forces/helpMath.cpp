#include<bits/stdc++.h>
using namespace std;

string fun(string s){
    int n = s.length();
    vector<int> arr;
    for(int i=0;i<n;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            arr.push_back(s[i] - '0');
        }
    }
    sort(arr.begin(),arr.end());
    string ans = "";
    for(int i=0;i<arr.size();i++){
        ans.append(to_string(arr[i]));
        if(i < arr.size()-1)ans += '+';
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    string ans = fun(s);
    cout<<ans<<endl;
    return 0;
}