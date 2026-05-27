#include<bits/stdc++.h>
using namespace std;

//TC -> O(N^2 + N)      SC -> O(2N)
int brute(vector<vector<int>> &arr, int n){
    vector<int> KnowMe(n,0);        //SC -> O(N)
    vector<int> IKnow(n,0);         //SC -> O(N)
    for(int i=0;i<n;i++){           //TC -> O(N^2)
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1){
                IKnow[i] += 1;
                KnowMe[j] += 1;
            }
        }
    }

    for(int i=0;i<n;i++){                   //TC -> O(N)
        if(IKnow[i] == 0 && KnowMe[i] == n-1){
            return i;
        }
    }

    return -1;
}

//TC -> O(2N)       SC -> O(1)
int optimal(vector<vector<int>> &arr, int n){
    int top = 0;
    int bottom = n-1;
    while(top < bottom){        // TC -> O(N)
        if(arr[top][bottom] == 1){
            top++;
        }
        else if(arr[bottom][top] == 1){
            bottom--;
        }
        else{
            top++;
            bottom--;
        }
    }

    if(top > bottom) return -1;

    for(int i=0;i<n;i++){       //TC -> O(N)
        if(i == top){
            continue;
        }
        if((arr[top][i] == 0) && arr[i][top] == 1){
            continue;
        }
        else{
            return -1;
        }
    }

    return top;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int ans = optimal(arr, n);
    cout<<ans<<endl;
    return 0;
}