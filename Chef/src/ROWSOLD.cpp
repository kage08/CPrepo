#include <bits/stdc++.h>
using namespace std;

int main(){
  int T,picks,moves;
  unsigned long long ans;
  string st;
  cin>>T;
  for(int t=0;t<T;t++){
    ans=0;
    picks=moves=0;
    cin>>st;
    int len=st.length();
    while(len>0 && st[len-1]=='1') len--;
    for(int i=len-1;i>=0;i--){
      if(st[i]=='0') moves++;
      else if(st[i]=='1'){
        picks++;
        while(i>=0 && st[i]=='1'){
          ans+=picks+moves;
          i--;
        }
        i++;
      }
    }
    cout<<ans<<endl;
  }
}
