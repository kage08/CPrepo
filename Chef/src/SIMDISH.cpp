#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;
  set<string> ing1;
  string st;
  cin>>T;
  for(int t=0;t<T;t++){
    ing1.clear();
    for(int i=0;i<4;i++){
      cin>>st;
      ing1.insert(st);

    }
    int ct=0;
    for(int i=0;i<4;i++){
      cin>>st;
      if(ing1.find(st)!=ing1.end()) ct++;
    }
    if(ct>=2) cout<<"similar\n";
    else cout<<"dissimilar\n";
  }
}
