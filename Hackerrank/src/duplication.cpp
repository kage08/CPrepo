#include <iostream>
#include <vector>
using namespace std;

void growstring(vector<bool>& str){
  int l=str.size();
  for(int i=0;i<l;i++){
    str.push_back(!str[i]);
  }
}

int main(){
  int q,x;
  cin>>q;
  vector<bool> str=vector<bool>(1,false);
  while(str.size()<=1000)
    growstring(str);
  for(int i=0;i<q;i++){
    cin>>x;
    cout<<str[x]<<endl;
  }
}
