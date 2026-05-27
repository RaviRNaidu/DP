#include<bits/stdc++.h>
using namespace std;

//ME
int binaryToDecimal(string bin){
    int res = 0;
    int i = 0;
    int len = bin.length();
    for(int j=len-1;j>=0;j--){
        if(bin[j] == '1'){
            res += pow(2,i);
        }
        i++;
    }
    return res;
}


int binaryToDecimalStriver(string bin){
    int res = 0;
    int pow = 1;
    int len = bin.length();
    for(int j=len-1;j>=0;j--){
        if(bin[j] == '1'){
            res += pow;
        }
        pow *= 2;
    }
    return res;
}


int main(){
    string binary;
    getline(cin,binary);
    int res = binaryToDecimalStriver(binary);
    cout<<"integer number is : "<<res<<endl;
    return 0;
}