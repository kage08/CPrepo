#include <bits/stdc++.h>
#include <cmath>

int main(){
	int T,N;
	std::string s;
	std::cin>>T;
	for(int t_i=0; t_i<T; t_i++){
		std::cin>>N>>s;
		int prefixz=s.find('1'),presz,maxz=0;
		int totz=prefixz;
		for(auto it = s.begin()+prefixz;it!=s.end();it++){
			presz=0;
			while(it!=s.end() && (*it)!='1'){
				presz++; it++;
			}
			maxz=std::max(maxz,presz);
			totz+=presz;
			if(it==s.end()) break;
		}
		maxz = std::max(maxz, presz+prefixz);

		std::cout<<totz-maxz<<std::endl;

	}
}