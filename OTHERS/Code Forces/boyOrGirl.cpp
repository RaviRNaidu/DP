#include<bits/stdc++.h>
using namespace std;

bool checking(string name){
    int hash[26] = {0};
    int n = name.length();
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(!hash[name[i] - 'a']){
            cnt++;
            hash[name[i] - 'a']++;
        }
    }
    if(cnt % 2 == 0) return true;
    else return false;
}

int main(){
    string name;
    cin >> name;
    if(checking(name)){
        cout<<"CHAT WITH HER!"<<endl;
    }
    else{
        cout<<"IGNORE HIM!"<<endl;
    }
    return 0;
}

