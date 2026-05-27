#include<bits/stdc++.h>
using namespace std;
//me
void palindrome(int i,string s){
    if(i>=s.size()/2){
        cout<<"it is an palindrome";
        return;
    }
    if(s[i]!=s[s.size()-i-1]){
        cout<<"it is not a palindrome";
        return;
    }
    palindrome(i+1, s);
}

//striver
bool check(int i, string s){
    if(i>=s.size()/2) return true;
    if(s[i]!=s[s.size()-i-1]) return false;
    return check(i+1, s);//why did i add return? cuz i will be returning what ever the last guy says
}

int main(){
    string s;
    cin>>s;
    cout<<check(0,s);
    return 0;
}