#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef unsigned long long int ull;

void mult(ull c[][2], ull a[][2],ull b[][2]){
    c[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])/MOD;
    c[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])/MOD;
    c[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])/MOD;
    c[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])/MOD;

}

void powmat(ull ans[][2], ull mat[][2], ull pw){
    if(pw==0){ans[0][0]=ans[1][1]=1; ans[0][1]=ans[1][0]=0; return;}

    if(pw==1){
        ans[0][0]=mat[0][0];
        ans[0][1]=mat[0][1];
        ans[1][0]=mat[1][0];
        ans[1][1]=mat[1][1];
        return;
    }

    ull ans1[2][2], ans2[2][2];
    powmat(ans1,mat,pw/2);
    if(pw%2==0){
        mult(ans,ans1,ans1);
    }
    else{
        mult(ans2,ans1,ans1);
        mult(ans,ans2,mat);
    }
}


int main() {
    int T;
    ull a,b,n;
    ull mat[2][2]={{1,1},{1,0}};
    cin>>T;
    while(T--){
        ull ans[2][2];
        cin>>a>>b>>n;
        if(n==0) {
            cout<<a<<endl; continue;
        }
        if(n==1) {
            cout<<b<<endl; continue;
        }
        powmat(ans,mat,n-1);
        cout<<((ans[0][0]*b)/MOD+(ans[0][1]*a)/MOD)/MOD<<endl;
    }
    return 0;
}