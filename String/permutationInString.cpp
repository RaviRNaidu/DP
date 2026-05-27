#include<bits/stdc++.h>
using namespace std;

bool comparing(int freq1[], int freq2[]){
    for(int i=0;i<26;i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}

bool permutationn(string s1, string s2){
    int freq[26] = {0};
    for(int i=0;i<s1.length();i++){
        freq[s1[i] - 'a']++;
    }

    int windowSize = s1.length();
    for(int i=0;i<s2.length();i++){
        int windInx = 0; 
        int inx = i;
        int winFreq[26] = {0};
        while(windInx < windowSize && inx < s2.length()){
            winFreq[s2[inx] - 'a']++;
            windInx++;
            inx++;
        }
        if(comparing(freq,winFreq) == 1){
            return true;
        }
    }
    return false;
}

bool mine(string s1, string s2){
    unordered_map<char,int> mpp;
    for(int i=0;i<s1.length();i++){
        mpp[s1[i] - 'a']++;
    }

    int windSize = s1.length();
    for(int i=0;i<s2.length();i++){
        int windInx = 0;
        int indx = i;
        unordered_map<char,int> mpp2;
        while(windInx < windSize && indx < s2.length()){
            mpp2[s2[indx] - 'a']++;
            windInx++;
            indx++;
        }
        //dont know how to compare two maps
    }
}





// using unordered map
bool mostoptimall(string s1, string s2){
    if(s1.length() > s2.length()) return false;
    unordered_map<char, int> mpp1;
    unordered_map<char, int> mpp2;
    for(int i=0;i<s1.length();i++){
        mpp1[s1[i]]++;
        mpp2[s2[i]]++;
    }

    if(mpp1 == mpp2){
        return true;
    }

    int left = 0;
    for(int right=s1.length();right<s2.length();right++){
        mpp2[s2[right]]++;
        mpp2[s2[left]]--;

        if(mpp2[s2[left]] == 0){
            mpp2.erase(s2[left]);
        }

        left++;

        if(mpp1 == mpp2){
            return true;
        }
    }
    return false;
}

int main(){
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    int n = mostoptimall(s1, s2);
    if(n == 1){
        cout<<"permutation exists"<<endl;
    }
    else{
        cout<<"premutation dosent exists"<<endl;
    }
    return 0;
}