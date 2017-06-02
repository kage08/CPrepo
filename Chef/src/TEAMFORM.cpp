#include <bits/stdc++.h>
using namespace std;

int main(){
  int T,n,m,u,v;
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>n>>m;
    for(int i=0;i<m;i++)
      cin>>u>>v;
    if(n%2) cout<<"no\n";
    else cout<<"yes\n";
  }
  return 0;
}
