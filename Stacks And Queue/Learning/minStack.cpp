#include<bits/stdc++.h>
using namespace std;

//TC -> O(1)    SC -> O(2N) 2N for the pair
class minStack{
    stack<pair<int,int>> st;

    void push(int val){
        if(st.empty()){
            st.push({val,val});
        }
        else{
            st.push({val,min(val,st.top().second)});
        }
    }

    void pop(){
        st.pop();
    }

    int top(){
        return st.top().first;
    }

    int getMin(){
        return st.top().second;
    }
};




//TC -> O(1) ALL OPERATIONS     SC -> O(N)
class minStackwithoutpair{
    stack<int> st;
    int min = INT_MAX;

    void push(int val){
        if(st.empty()){
            min = val;
            st.push(val);
        }
        else{
            if(val < min){
                st.push((2*val) - min);
                min = val;
            }
            else{
                st.push(val);
            }
        }
    }

    void pop(){
        if(st.empty()){
            return;
        }
        int num = st.top();
        st.pop();
        if(num < min){
            min = ((min*2) - num);
        }
    }

    int top(){
        int num = st.top();
        if(num < min){
            return min;
        }
        else{
            return num;
        }
    }

    int getMin(){
        return min;
    }
};