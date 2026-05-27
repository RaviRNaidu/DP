#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    
    //precompute only for smaller case letters
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a'] ++;
    }


    int q;
    cin>>q;
    while(q--){
        char character;
        cin>>character;
        //fetching
        cout<<hash[character-'a']<<endl;
    }
    return 0;
}

//do not forget to comment out any one


int main(){
    string s;
    cin>>s;

    //precomputing for both uppercase and lower case 
    int hash[256]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]] += 1;
    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        //fetching
        cout<<hash[c]<<endl;
    }
}
