#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T,n,l;
	string s;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		cin>>s;
		l=s.length();
		int cm=0,cs=0;
		for(int j=0;j<l;j++){
			if(s[j]=='m') {cm++;

			}
			else{
				cs++;
			}
		}
		for(int j=0;j<l;j++){
			if(s[j]=='m'){
				if((j>0)&& s[j-1]=='s'){
					s[j-1]='S';
					cs--;
				}
				else if(j<l-1 && s[j+1]=='s'){
					s[j+1]='S';
					cs--;
				}
			}
		}
		if(cs>cm) cout<<"snakes\n";
		else if(cs<cm) cout<<"mongooses\n";
		else cout<<"tie\n";
	}
	return 0;
}