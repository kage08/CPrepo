#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max4(int a, int b, int c, int d){
    int max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    if(d>max) max=d;
    
    return max;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q,n;
    
    cin>>q;
    
    for(int i=0;i<q;i++){
        cin>>n;
        int mat[n][n];
        for(int j=0;j<2*n;j++)
            for(int k=0;k<2*n;k++)
                cin>>mat[j][k];
        
        int sum = 0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                sum+=max4(mat[j][k],mat[2*n-j-1][k],mat[j][2*n-k-1],mat[2*n-j-1][2*n-k-1]);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

