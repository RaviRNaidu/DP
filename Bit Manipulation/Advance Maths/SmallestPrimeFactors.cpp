#include<bits/stdc++.h>
using namespace std;

//TC -> n log(log n) + o(quries * log base2 n)
//SC -> o(n) or 100 in this case
void better(vector<int> &arr){
    vector<int> SPF(100+1); // ASSUMING THAT THE MAX NUM THAT THEY CAN ASK IS 100, IF ITS GREATER THEN THE ARRAY SIZE SHOULD ALSO BE GREATER
    for(int i=0;i<100;i++){
        SPF[i] = i;
    }

    for(int i=2;i<=100;i++){        //AS U KNOW THIS WHOLE THING TAKES n log(log n)
        if(SPF[i] == i){
            for(int j=2*i;j<=100;j+=i){
                if(SPF[j] == j){
                    SPF[j] = i;
                }
            }
        }
    }

    for(int i=0;i<arr.size();i++){  //o(quries * log base2 n)
        int num = arr[i];
        while(num != 1){
            cout<<SPF[num]<<" ";
            num = num / SPF[num];
        }
        cout<<endl;
    }
}

//TC -> O(queries) + O(sqrt(n));
void brute(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        vector<int> result;
        int num = arr[i];
        for(int i=2;i*i<=num;i++){
            if(num % i == 0){
                while(num % i == 0){
                    result.push_back(i);
                    num = num/i;
                }
            }
        }
        if(num != 1) result.push_back(num);
        for(int j=0;j<result.size();j++){
            cout<<result[j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> query(n);
    for(int i=0;i<n;i++){
        cin>>query[i];
    }
    better(query);
    return 0;
}