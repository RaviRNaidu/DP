#include<bits/stdc++.h>
using namespace std;

string reverseWord(string s1){
    string ans = "";
    reverse(s1.begin(), s1.end());
    for(int i=0;i<s1.length();i++){
        string word = "";
        while(i < s1.length() && s1[i] != ' '){
            word += s1[i];
            i++;
        }
        reverse(word.begin(),word.end());
        if(word.length() > 0){
            ans += " "+ word;
        }
    }
    return ans.substr(1);
}

int main(){
    string s1;
    getline(cin,s1);
    string ans = reverseWord(s1);
    for(char ch : ans){
        cout<<ch<<" ";
    }
    cout<<endl;
    return 0;
}