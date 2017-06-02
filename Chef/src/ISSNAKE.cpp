#include <bits/stdc++.h>
#define MAXCHAR 500
using namespace std;

char row1[MAXCHAR];
char row2[MAXCHAR];
int len;

short issnake(int l){
  if(len<=0) return 0;
  if(l==len-1){
    if(row1[l]=='#'){
      if(row2[l]=='#') return 3;
      else return 1;
    }
    else return 2;
  }
  short ans1=issnake(l+1);
  short ans2;

  if(1){
    if(row1[l]=='#'){
      if(row2[l]=='#') ans2= 3;
      else ans2= 1;
    }
    else {
      if(row2[l]=='#') ans2=2;
      else ans2=0;
    }
  }

  switch(ans2){
    case 0: if(ans1>0) return 4;
              else return 0;
    case 1: if(ans1==1) return 1;
              else if(ans1==2) return 0;
              else if(ans1==3) return 1;
              else if(ans1==4) return 0;
              else if(ans1==0) return 0;


    case 2: if(ans1==2) return 2;
              else if(ans1==1) return 0;
              else if(ans1==3) return 2;
              else if(ans1==4) return 0;
              else if(ans1==0) return 0;
    case 3: if(ans1==1) return 2;
              else if(ans1==2) return 1;
              else if(ans1==3) return 3;
              else return 0;
  }
  return 0;
}

int main(void){
  int T;
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>len;
    for(int i=0;i<len;i++)
      cin>>row1[i];
    for(int i=0;i<len;i++)
      cin>>row2[i];
    while(len>0 && row1[len-1]=='.' && row2[len-1]=='.') len--;
    short ans=issnake(0);
    if(ans>=1) cout<<"yes\n";
    else cout<<"no\n";
  }
}
