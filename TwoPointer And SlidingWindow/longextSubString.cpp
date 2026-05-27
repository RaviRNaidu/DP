#include<bits/stdc++.h>
using namespace std;
//THIS WONT WORK BECAUSE WE ARE NOT RE INITIALIZING IT FOR EACH ITERATION!!!
int brute1(string word){
    int n = word.length();
    int ans = 0;
    unordered_map<char, int> mpp;
    for(int i=0;i<n;i++){
        string letter = "";
        for(int j=i;j<n;j++){
            if(mpp.find(word[j]) != mpp.end()){
                break;
            }
            else{
                letter += word[j];
            }
            mpp[word[j]]++;
        }
        int len = letter.length();
        ans = max(ans, len);
    }
    return ans;
}

//TC -> O(N^2)  SC -> O(256)
int brute(string word){
    int n = word.length();
    int ans = 0;
    for(int i=0;i<n;i++){
        int hash[256] = {0};
        int len = 0;
        for(int j=i;j<n;j++){
            if(hash[word[j]] == 1){
                break;
            }
            else{
                len = j - i + 1;
                ans = max(ans, len);
            }
            hash[word[j]] = 1;
        }
    }
    return ans;
}

//TC -> O(2N)   SC -> O(256)
// SUPRIZINGLY IT WAS DONE BY MEE!!
int optimal(string word){
    int n = word.length();
    int ans = 0;
    int l = 0;
    int r = 0;
    int len = 0;
    int hash[256] = {0};
    while(r < n){
        if(hash[word[r]] == 1){
            while(hash[word[r]] != 0){
                hash[word[l]] = 0;
                l++;
            }
        }
        len = r - l + 1;
        ans = max(ans, len);
        hash[word[r]] = 1;
        r++;
    }
    return ans;
}

int striverME(string word){
    int n = word.length();
    int l = 0; int r = 0; int maxlen = 0;
    unordered_map<char, int> mpp;
    while(r < n){
        if(mpp[word[r]] >= l){
            l = mpp[word[r]] + 1;
            maxlen = max(maxlen, r - l + 1);
        }
        else{
            maxlen = max(maxlen, r - l + 1);
        }
        mpp[word[r]] = r;
        r++;
    }
    return maxlen;
}


//TC -> O(N)    sc -> o(256)
int striver(string word){
    int n = word.length();
    int l = 0; int r = 0; int maxlen = 0;
    int hash[256] = {-1};
    while(r < n){
        if(hash[word[r]] != -1){
            if(hash[word[r]] >= l){
                l = hash[word[r]] + 1;
            }
        }
        maxlen = max(maxlen, r - l + 1);
        hash[word[r]] = r;  
        r++;
    }
    return maxlen;
}

int main(){
    string word;
    cin>>word;
    int ans = striver(word);
    cout<<ans<<endl;
    return 0;
}