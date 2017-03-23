#include <bits/stdc++.h>
#define MODUL 1000000007
using namespace std;

typedef unsigned long ul;
typedef unsigned long long ull;

int main(){
	string st;
	cin>>st;
	ul len=st.length();
	vector<ull> soln(len);
	vector<short> dig(len);
	for(int i=0;i<len;i++)
		dig[i]=st[i]-'0';
	soln[0]=dig[0];
	ull ans=dig[0];

	for(ul i=1;i<len;i++){
		soln[i]=((ull)(i+1)*(ull)dig[i]+10*soln[i-1])%MODUL;
		ans=(ans+soln[i])%MODUL;
	}
	cout<<ans<<endl;
}
