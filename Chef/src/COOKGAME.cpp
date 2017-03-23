#include <bits/stdc++.h>
#define MODUL 1000000007





int main(){
	

	int T,N;
	std::cin>>T;

	for (int t_i = 0; t_i < T; ++t_i)
	{
		//N = 1 + std::rand()%15;
		//std::srand(std::time(NULL));
		//std::cout<<N<<std::endl;
		std::cin>>N;
		std::vector<int> arr(N);
		bool impossible = true;
		//std::srand(time(NULL)+t_i);
		for(int i=0;i<N;i++){
			//arr[i]=(std::rand()%2)?(1+std::rand()%N):-1;
			//std::srand(std::time(NULL)+i);
			//std::cout<<arr[i]<<" ";
			std::cin>>arr[i];
			if(arr[i]==-1) impossible = false;
		}
		//std::cout<<std::endl;

		

		for(auto it = arr.rbegin()+1; it!=arr.rend(); it++){
			if(*(it-1) > 1){
				if(*it ==-1) *it = *(it-1) - 1;
				else if(*it != *(it-1)-1) {impossible = true; break;}
			}
		}

		if(arr[0]==-1) arr[0]=1;

		if(arr[0]>1) impossible = true;

		if(impossible){
			std::cout<<"0\n";
			continue;
		}

		impossible = true;
		unsigned long long res = 1;
		for(int i: arr){
			if(i==-1){
				res=(res*2)%MODUL;
				impossible = false;
			}
		}
		if(impossible) std::cout<<"0\n";
		else
			std::cout<<res<<std::endl;



	}
	return 0;
}
