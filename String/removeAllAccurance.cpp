#include<bits/stdc++.h>
using namespace std;

string removing(string str, string part){
    while(str.length() > 0 && str.find(part) < str.length()){
        str.erase(str.find(part),part.length());
    }
    return str;
}

int main(){
    char str[] = "abcBabcIabcTabcCH";
    char part[] = "abc";
    string strAns = removing(str,part);
    cout<<strAns<<endl;
    return 0;
}