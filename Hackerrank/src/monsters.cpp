#include <bits/stdc++.h>
using namespace std;

class lcomp{
  public:
    bool operator()(long a, long b){
      return a<=b;
    }
};

int main(){
  long n,hit,t,hel;
  cin>>n>>hit>>t;
  set<long,lcomp> health;
  for(long i=0;i<n;i++){
    cin>>hel;
    health.insert(hel);
  }
  long ct=0;
  for(long i=0;i<t && !health.empty();i++){
    long minM=*(health.begin());
    health.erase(health.begin());
    if(minM-hit<=0) ct++;
    else health.insert(minM-hit);
  }
  cout<<ct<<endl;

}
