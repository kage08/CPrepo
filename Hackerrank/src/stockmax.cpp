#include <bits/stdc++.h>

using namespace std;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef unsigned int ut;

int main(){
	ut T,N;
	cin>>T;
	for(ut tt=0;tt<T;T++){
		cin>>N;
		vector<ut> prices(N);
		for(ut i=0;i<N;i++)
			cin>>prices[i];
		ull maxprofit=0;
		ut maxprice=0;
		for(int i=N-1;i>=0;i--){
			if(prices[i]>maxprice) maxprice=prices[i];
			maxprofit+=(maxprice-prices[i]);
		}
		cout<<maxprofit<<endl;
	}
}
