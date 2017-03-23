#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<bool> istaken(n+1,false);
	int maxtable=0,currtable=0,now;
	for(int i=0;i<2*n;i++){
		cin>>now;
		if(!istaken[now]){
			istaken[now]=true;
			currtable++;
			maxtable=std::max(maxtable,currtable);
		}
		else
			currtable--;
	}
	cout<<maxtable<<endl;
}
