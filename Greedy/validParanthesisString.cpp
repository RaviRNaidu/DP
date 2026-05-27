#include<bits/stdc++.h>
using namespace std;

bool recursion(string s, int index, int cnt){
    int n = s.length();
    if(cnt < 0) return false;
    else if(index == n) return (cnt == 0);
    else if(s[index] == '('){
        return recursion(s,index+1,cnt+1);
    }
    else if(s[index] == ')'){
        return recursion(s,index+1,cnt-1);
    }
    else{
        return recursion(s,index+1,cnt+1) || recursion(s,index+1,cnt-1) || recursion(s,index+1,cnt);
    }
}

//TC -> O(N)    SC -> O(1)
bool greedy(string s){
    int n = s.length();
    int min = 0;
    int max = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            min++;
            max++;
        }
        else if(s[i] == ')'){
            min--;
            max--;
        }
        else{
            min = min-1;
            max = max+1;
        }
        if(min < 0) min = 0;
        if(max < 0) return false;
    }
    return (min == 0);
}

int main(){
    string s;
    cin>>s;
    // int ans = recursion(s,0,0);
    int ans = greedy(s);
    cout<<ans<<endl;
    return 0;
}