#include<bits/stdc++.h>
using namespace std;

// int checking(string s1, string s2){
//     transform(s1.begin(),s1.end(),s1.begin(), ::tolower);
//     transform(s2.begin(),s2.end(),s2.begin(), ::tolower);

//     for(int i=0;i<s1.length();i++){
//         if(s1[i] < s2[i]){
//             return -1;
//         }
//         else if(s1[i] > s2[i]){
//             return 1;
//         }
//     }
//     return 0;
// }

// int main(){
//     string s1;
//     string s2;
//     cin>>s1;
//     cin>>s2;
//     cout<<checking(s1, s2)<<endl;
//     return 0;
// }




int main(){
    string s;
    cin>>s;
    char prev = '$';
    int cnt = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] != prev){
            cnt = 1;
            prev = s[i];
        }
        else{
            cnt++;
        }
        if(cnt >= 7){
            cout<<"YES"<<endl;
            break;
        }
    }
    if(cnt < 7) cout<<"NO"<<endl;
    return 0;
}