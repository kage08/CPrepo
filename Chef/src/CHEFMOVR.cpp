#include <bits/stdc++.h>
using namespace std;
typedef long long ull ;

ull myabs(ull a){
	return (a>=0)?a:-a;
}

int main(){
	int t,n,d;
	cin>>t;
	for(int i_t = 0; i_t<t;i_t++){
		cin>>n>>d;

		vector<int> arr(n);
		vector<ull> cum(n,0);
		vector<int> ct(d,0);
		ull sum = 0;
		for(int i=0;i<n;i++){
			ct[i%d]++;
			cin>>arr[i];
			if(i-d>=0) cum[i]=cum[i-d]+arr[i];
			else cum[i]=arr[i];
			sum+=arr[i];
		}


		if(sum%n!=0){
			cout<<"-1"<<endl;
			continue;
		}

		ull partsum=sum/n; bool st=true;

		for(int i=0;i<n%d;i++){
			if(partsum*ct[i]!=cum[n-(n%d-i)]){
				st= false;
				break;
			}

		}
		for(int i = n%d,j=0; i<d; i++,j++){
			if(partsum*ct[i] != cum[n-d+j]){
				st= false;
				break;
			}
		}

		if(!st) {
			cout<<"-1"<<endl;
			continue;
		}

		ull moves=0;

		for(int i=0;i<d;i++){
			for(int j=i,k=1;j<n;j+=d,k++)
				moves+=myabs(cum[j]-partsum*k);
		}

		cout<<moves<<endl;
	}
}