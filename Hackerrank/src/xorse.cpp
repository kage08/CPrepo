#include <bits/stdc++.h>
#define MAXNUM 1000002
using namespace std;

unsigned long long B[MAXNUM];

void initB(){
  B[0]=0;B[1]=1;
  for(unsigned long long i=2;i<MAXNUM; i++){
    B[i]=B[i-2]^i;
  }
}

int main(int argc, const char *argv[])
{
  initB();
  unsigned int Q,L,R;
  cin>>Q;
  for(unsigned int i=0;i<Q;i++){
    cin>>L>>R;
    cout<<(unsigned long long)(B[R]^B[L-1])<<endl;
  }
  return 0;
}
