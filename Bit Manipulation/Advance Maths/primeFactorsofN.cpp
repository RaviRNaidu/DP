#include<bits/stdc++.h>
using namespace std;

// bool prime(int n){
//     int counter=0;
//     for(int i=1;i*i<=n;i++){
//         if(n%i==0)
//         {
//             counter=counter+1;
//             if((n/i)!=i){
//                 counter=counter+1;
//             }
//         }
//     }
//     if(counter==2)
//     {
//         return true;
//     }
//     else return false;
// }

bool isprime(int n){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(n % i == 0){
            cnt++;
        }
    }
    if(cnt == 2){
        return true;
    }
    else{
        return false;
    }
}


// TC -> O(13) because we are dividing the n
//its basically O(n * log n)
vector<int> optimal(int n){
    vector<int> ans;
    for(int i=2;i<=n;i++){
        if(n % i == 0){
            ans.push_back(i);
            while(n % i == 0){
                n = n / i;
            }
        }
    }
    return ans;
}

// TC -> O(13) because we are dividing the n
//its basically O(n * log n)
vector<int> Mostoptimal(int n){
    vector<int> ans;
    for(int i=2;i*i<=n;i++){
        if(n % i == 0){
            ans.push_back(i);
            while(n % i == 0){
                n = n / i;
            }
        }
    }
    if(n != 1) ans.push_back(n);
    return ans;
}

//TC -> O(sqrt(n))  sc -> o(1)
vector<int> brute(int n){
    vector<int> ans;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            if(isprime(i)){
                ans.push_back(i);
            }
            if(n / i != i){
                if(isprime(n/i))ans.push_back(n/i);
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> ans = optimal(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}