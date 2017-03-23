#include <bits/stdc++.h>
#define MODUL 1000000007

using namespace std;

typedef unsigned long ul;
typedef unsigned long long ull;

void initelev(vector<ull>& elev){
	elev[0]=1;
	ul len = elev.size();
	for(ul i=1; i<len; i++)
		elev[i] = (elev[i-1]*10 +1)%MODUL;
}

int main(){
	string st;
	cin>>st;
	ull ans=0;
	ul len = st.length();
	vector<ull> elev(len);
	initelev(elev);
	for(ul i=0; i<len; i++){
		short dig = st[i]-'0';
		ans = (ans + (ull)dig * (i+1) * elev[len-i-1])%MODUL;
	}
	cout<<ans<<endl;
}
