#include <bits/stdc++.h>
using namespace std;

int main(){
  int T,N,K,n,no,st1;
  short status;
  cin>>T;
  for(int t=0;t<T;t++){
    status=0;
    st1=0;
    cin>>N>>K;
    vector<short> freq(K+1,0);
    for(int i=0;i<N;i++){
      cin>>n;
      int ct=0;
      for(int j=0;j<n;j++){
        cin>>no;
        if(freq[no]==0) st1++;
        if(freq[no]>0) ct++;
        freq[no]++;
      }
      if(ct==n) status=1;

    }
    if(st1<K) cout<<"sad\n";
    else{
      if(status==0) cout<<"all\n";
      else cout<<"some\n";
    }
  }
}

