#include <bits/stdc++.h>

using namespace std;

int main(){
	int T,N;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		vector<int> Xenny (N);
		for(int j=0;j<N;j++)
			cin>>Xenny[j];

		unsigned long long t1=0, t2=0;
		int yenna;
		for(int j=0;j<N;j++){
			cin>>yenna;
			if(j%2){
				t1+=Xenny[j];
				t2+=yenna;
			}
			else{
				t1+=yenna;
				t2+=Xenny[j];
			}
		}

		cout<<std::min(t1,t2)<<endl;
	}
	return 0;
}
