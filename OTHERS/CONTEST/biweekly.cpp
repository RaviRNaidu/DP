#include<bits/stdc++.h>
using namespace std;


string largestEven(string s) {
    int n = s.length();
    for(int i=n-1;i>=0;i--){
        if(s[i] == '2'){
            break;
        }
        else{
            s.erase(i,1);
        }
    }
    return s;
}

int main(){
    string str;
    cin>>str;
    string ans = largestEven(str);
    cout<<ans<<endl;
    return 0;
}