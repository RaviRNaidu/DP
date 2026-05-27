#include<bits/stdc++.h>
using namespace std;


//TC -> N * wordLenth * 26 * log n
//SC -> o(n) + o(n)
int wordLadderLength(string start, string end, vector<string> &wordList){
    queue<pair<string,int>> q;
    unordered_set<string> st(wordList.begin(), wordList.end());
    q.push({start,1});
    st.erase(start);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        if(word == end){
            return steps;
        }

        int n = word.length();
        for(int i=0;i<n;i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z';ch++){
                word[i] = ch;
                if(st.count(word) > 0){
                    q.push({word, steps + 1});
                    st.erase(word);
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main(){
    string s;
    cin>>s;
    string e;
    cin>>e;
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<wordLadderLength(s,e,arr)<<endl;
    return 0;
}