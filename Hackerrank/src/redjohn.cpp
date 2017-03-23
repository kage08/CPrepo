#include <bits/stdc++.h>
typedef unsigned long long uLong;
typedef long long Long;
typedef unsigned long ulong;
typedef unsigned int uint;

using namespace std;

uLong noprimes(uLong n){
	vector<bool> isprime(n+1,true);
	for(uLong i=2;i*i<=n;i++){
		if(isprime[i]){
			for(uLong j=i*2;j<=n;j+=i)
				isprime[j]=false;
		}
	}
	uLong nop=0;
	for(uLong i=2;i<=n;i++){
		if(isprime[i]) nop++;
	}
	return nop;
}

int main(){
	uint T,N;
	cin>>T;
	for(uint tt=0; tt<T;tt++){
		cin>>N;
		vector<uLong> soln(N+1,0);
		soln[0]=1;
		for(uint i=0;i<=N && i<5; i++)
			soln[i]=1;
		for(uint i=5;i<=N;i++){
			soln[i]=soln[i-1]+soln[i-5];
		}
		cout<<soln[N]<<endl;
		cout<<noprimes(soln[N])<<endl;
	}
	return 0;
}
