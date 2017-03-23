#include <bits/stdc++.h>

using namespace std;

int main(){
	int T,N;

	cin>>T;
	for(int i_t=0;i_t<T;i_t++){
		cin>>N;
		vector<unsigned long> A(N);
		for(int i=0;i<N;i++)
			cin>>A[i];
		std::sort(A.begin(),A.end());
		int ind=-1;
		for(int i=0; i<N-2;i++){
			if(A[i]+1!=A[i+1]){
				ind=i; break;
			}
		}
		if(A[N-2]+1!=A[N-1]) ind = N-1;
		cout<<A[ind]<<endl;
	}

}
