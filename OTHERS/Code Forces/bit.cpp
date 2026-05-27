#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 0;
    int n;
    cin>>n;
    while(n != 0){
        string s1;
        cin>>s1;
        if(s1 == "++X"){
            ++x;
        }
        else if(s1 == "X++"){
            x++;
        }
        else if(s1 == "--X"){
            --x;
        }
        else{
            x--;
        }
        n--;
    }
    cout<<x;
    return 0;
}