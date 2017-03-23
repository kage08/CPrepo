#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long long ll;

ul myabs(int n){
	return (n<0)?(-n):n;
}

int main(){
	ul T,N;
	cin>>T;
	for(int t_i=0; t_i<T; t_i++){
		cin>>N;
		vector<ul> b(N);
		for(ul i=0; i<N; i++)
			cin>>b[i];

		vector<ull> soln1(N,0);
		vector<ull> soln2(N,0);
		for(ul i=1;i<N;i++){
			soln1[i]= std::max(soln1[i-1], soln2[i-1] + myabs(b[i-1]-1));
			soln2[i]= std::max(soln2[i-1]+myabs(b[i]-b[i-1]), soln1[i-1] + myabs(b[i]-1));
		}

		cout<<std::max(soln1[N-1], soln2[N-1])<<endl;


	}
}
