    #include<bits/stdc++.h>
    using namespace std;

int findgcd(int n1, int n2){
    
    int gcd=1;
    for(int i=1;i<=min(n1,n2);i++){
        if(n1%i == 0 && n2%i == 0){
            gcd=i;
        }
    }

    return gcd;

}
int findhcf(int n1, int n2){
    
    int gcd=1;
    for(int i=min(n1,n2);i>0;i--){
        if(n1%i == 0 && n2%i == 0){
            gcd=i;
            break;
        }
    }

    return gcd;

}
int findgcdOPT(int n1, int n2){
    while(n1>0 && n2>0){
        if(n1>n2){
            n1=n1%n2;
        }
        else{
            n2=n2%n1;
        }
    }
    if(n1==0) return n2;
    else return n1;

}

int main(){
    int n1,n2;
    cin>>n1;
    cin>>n2;
    int gcd=findgcdOPT(n1, n2);
    cout<<"the greatest common divisior is: "<<gcd<<endl;
    return 0;
}