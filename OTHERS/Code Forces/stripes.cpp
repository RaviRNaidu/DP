#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<vector<char>> matrix(8, vector<char> (8));
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                cin>>matrix[j][k];
            }
        }

        bool red = false;
        for(int r=0;r<8;r++){
            bool fullFill = true;
            for(int c=0;c<8;c++){
                if(matrix[r][c] != 'R'){
                    fullFill = false;
                    break;
                }
            }

            if(fullFill){
                red = true;
                break;
            }
        }

        if(red) cout<<'R'<<endl;
        else cout<<'B'<<endl;
    }
    return 0;
}