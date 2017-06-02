#include <bits/stdc++.h>
using namespace std;


typedef unsigned long long ull;
typedef long long Long;

int main(){
  ull A,B,C,D,ct=0;
  cin>>A>>B;
  C=__gcd(A,B);
  if(C==1){
    cout<<1<<endl; return 0;
  }
  D=(ull)sqrt(C);
  for(ull i=1;i<=D+1;i++)
    if(C%i==0) ct++;
  cout<<(ct+1)<<endl;
  return 0;
}
