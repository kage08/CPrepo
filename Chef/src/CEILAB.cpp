#include <bits/stdc++.h>

class Solution{
	unsigned ind;
public:
	Solution(int n):ind(n){}
	std::string operator()(int A, int B){
		B=A-B;
		std::string s = std::to_string(B);
		int ind = ind % s.length();
		if(ind==0 && s.length()>1) ind++;
		s[ind] = '0' + (s[ind] + 1) % 10;
		return s;
	}
};

int main(){
	int A,B;
	std::cin>>A>>B;
	Solution sln(abs(rand()%B));
	std::cout<<sln(A,B)<<std::endl;
	return 0;
}