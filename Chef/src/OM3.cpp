#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long uLong;




int main(int argc, char const *argv[])
{
	int A,B;
	cin>>A>>B;
	uLong sum;
	vector<uLong> sump(B+1,0);
	for(int i=1;i<=B;i++){

		for(int j=i*2;j<=B;j+=i)
			sump[j]+=i;

	}
	uLong ans=0;
	for(int i=A;i<=B;i++)
		ans+=sump[i];
	cout<<ans<<endl;
}

