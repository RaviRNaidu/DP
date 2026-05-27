#include<bits/stdc++.h>
using namespace std;

string convert(string s){
    int n = s.length();
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            cnt++;
        }
    }
    if(cnt > n / 2) transform(s.begin(), s.end(), s.begin(), ::toupper);
    else transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int main(){
    string s;
    cin>>s;
    cout<<convert(s)<<endl;
    return 0;
}