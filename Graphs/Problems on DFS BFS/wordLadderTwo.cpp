#include<bits/stdc++.h>
using namespace std;


//TC -> N * wordLenth * 26 * log n
//SC -> o(n) + o(n)
vector<vector<string>> wordLadderLength(string start, string end, vector<string> &wordList){
    vector<vector<string>> ans;
    queue<vector<string>> q;
    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<string> ini = {start};
    q.push(ini);
    int level = 0;
    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        if(vec.size() > level){
            level++;
            for(int e=0;e<ini.size();e++) st.erase(ini[e]);
            ini.clear();
        }

        string word = vec.back();
        if(word == end){
            if(ans.size() == 0) ans.push_back(vec);
            else{
                if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
        }

        for(int i=0;i<word.length();i++){
            int original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(st.count(word) > 0){
                    vec.push_back(word);
                    q.push(vec);
                    ini.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}

//DEPENDING ON EXAMPLES TO EXAMPLE IT VARIES 
vector<vector<string>> striver(string start, string end, vector<string> &wordList){
    vector<vector<string>> ans;
    queue<vector<string>> q;
    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<string> usedOnLevel = {start};
    q.push(usedOnLevel);
    int level = 0; 
    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        if(vec.size() > level){
            level++;
            for(auto it : usedOnLevel) st.erase(it);
            usedOnLevel.clear();
        }

        string word = vec.back();
        if(word == end){
            if(ans.size() == 0) ans.push_back(vec);
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }

        for(int i=0;i<word.length();i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(st.count(word) > 0){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
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
    vector<vector<string>> ans = wordLadderLength(s, e, arr);
    for(auto it : ans){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}