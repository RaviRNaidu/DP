#include<bits/stdc++.h>
using namespace std;

int compression(vector<int> chars){
    int n = chars.size();
    int index = 0;
    for(int i=0;i<n;i++){
        char c = chars[i];
        int cnt = 0;
        while(i < n && chars[i] != c){
            cnt++;
            i++;
        }
        if(cnt == 1){
            chars[index] = c;
            index++;
        }
        else{
            chars[index] = c;
            index++;
            string str = to_string(cnt);
            for(char ch : str){
                chars[index++] = ch;
            }
            i--;
        }
    }
    return index; 
}

int main(){
    vector<int> s1;
    for(int i=0;i<s1.size();i++){
        cin>>s1[i];
    }
    int ans = compression(s1);
    cout<<"count is: "<<ans;
    return 0;
}