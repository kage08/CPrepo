#include <bits/stdc++.h>
#define MAXNUM 100000

using namespace std;

bool primes[MAXNUM+1];
int max_=59;

void extendlist(int n){
  for(int i=2;i*i<=n&&i<=MAXNUM;i++){
    if(primes[i]==false)
      for(int j=i*2;j<=n&&j<=MAXNUM;j++)
        primes[j]=true;
  }

}



bool isprime(int n){
  if(n<=max_)
    return !(primes[n]);
    extendlist(n);
    max_=max(max_,n);
  return !(primes[n]);
}


int main(){
  int T,N;
  cin>>T;
  vector<int> initp={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
  for(int i=0;i<=max_;i++)
    if(find(initp.begin(),initp.end(),i)==initp.end())
      primes[i]=true;
  for(int i=0;i<T;i++){
    cin>>N;
    if(isprime(N))
      cout<<"yes\n";
    else
      cout<<"no\n";

  }
}
