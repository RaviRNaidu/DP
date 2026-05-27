#include<bits/stdc++.h>
using namespace std;

string checking(int x, int y){
    if(x % 2 != 0 && y % 2 != 0){
        return "NO";
    }
    else{
        return "YES";
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int x, y;
        cin >> x >> y;
        string ans = checking(x , y);
        cout<<ans<<endl;
    }
    return 0;
}