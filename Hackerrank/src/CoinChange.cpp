#include <bits/stdc++.h>

using namespace std;



int main(){
	int N,M;
	cin>>N>>M;
	vector <int> change(M+1,0);
	for(int i=0; i<M; i++)
		cin>>change[i+1];

	vector<vector<unsigned long long> > soln (N+1,vector<unsigned long long>(M+1,-1));
	for(int i=0;i<=M;i++)
		soln[0][i]=1;
	for(int i=0;i<=N;i++)
		soln[i][0]=0;
	soln[0][0]=1;

	for(int i=1; i<=M; i++){
		for(int j=1; j<=N; j++){
			if(j>=change[i])
			soln[j][i] = soln[j][i-1] + soln[j-change[i]][i];
			else soln[j][i] = soln[j][i-1];
		}
	}

	cout<<soln[N][M]<<endl;
}
