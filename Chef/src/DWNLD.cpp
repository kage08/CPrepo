#include <bits/stdc++.h>

int main(){
	int TC, N, K;
	std::cin>>TC;
	for(int t_i; t_i<TC; t_i++){
		std::cin>>N>>K;

		int consumed=0,tottime=0;
		int time,bytes;
		for(int i=0;i<N;i++){
			std::cin>>time>>bytes;
			if(K>0){
				if(K-time<0) consumed+=(time-K)*bytes;
				K-=time;
			}
			else
				consumed+=time*bytes;
		}
		std::cout<<consumed<<std::endl;
	}
	return 0;
}