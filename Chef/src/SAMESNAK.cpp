#include <bits/stdc++.h>

using namespace std;
typedef long long Long;

int main(void){
  int T;
  Long X11,X12,X21,X22,Y11,Y12,Y21,Y22;
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>X11>>Y11>>X12>>Y12;
    cin>>X21>>Y21>>X22>>Y22;
    if(X11==X12){
      if(X21==X22){
        if((Y11>=Y21 && Y11<=Y22)||(Y12>=Y21 && Y12<=Y22) ||(Y11>=Y22 && Y11<=Y21)||(Y12>=Y22 && Y12<=Y21)) cout<<"yes\n";
        else cout<<"no\n";
      }
      else if((X11==X21 && Y11==Y21)||(X11==X22 && Y11==Y22)|| (X12==X21 && Y12==Y21)||(X12==X22 && Y12==Y22)) cout<<"yes\n";
      else cout<<"no\n";
    }
    else if(Y11==Y12){
      if(Y21==Y22){
       if((X11>=X21 && X11<=X22)||(X12>=X21 && X12<=X22) || (X11>=X22 && X11<=X21)||(X12>=X22 && X12<=X21)) cout<<"yes\n";
        else cout<<"no\n";
      }
      else if((X11==X21 && Y11==Y21)||(X11==X22 && Y11==Y22)|| (X12==X21 && Y12==Y21)||(X12==X22 && Y12==Y22)) cout<<"yes\n";
      else cout<<"no\n";

    }
  }
}
