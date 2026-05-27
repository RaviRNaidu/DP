#include<bits/stdc++.h>
using namespace std;

string wayToLong(string s){
    int n = s.length();
    if(n <= 10) return s;
    string newWord = "";
    newWord += s[0];
    newWord.append(to_string(n-2));
    newWord += s[n-1];
    return newWord;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        cout<<wayToLong(word)<<endl;
    }
    return 0;
}