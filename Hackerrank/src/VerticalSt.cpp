#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;

int main(){
	ul T,N;
	cin>>T;
	for(int t_i=0; t_i<T; t_i++){
		cin>>N;

		vector<ul> sticks(N);
		for(ul i=0; i<N;i++)
			cin>>sticks[i];

		std::sort(sticks.begin(), sticks.end());
		map<ul,double> freq;
		ul curr=sticks[0];
		ul currfreq=0;

		for(int i=0; i<N; i++){
			if(curr==sticks[i]){
				currfreq++;
			}
			else{
				freq[curr]=N-i+currfreq;
				currfreq=1;
				curr=sticks[i];
			}

			if(i==N-1){
				freq[sticks[i]] = currfreq;
			}
		}

		double ans=0;

		for(ul i=0; i<N;i++)
			ans+=(double)(N+1)/(freq[sticks[i]]+1);

		cout.precision(2);
		cout.setf(ios::fixed);
		cout<<ans<<endl;

	}

}
