#include <bits/stdc++.h>

using namespace std;

vector<int> euclid (int A, int X){
	if(A==0) {
		vector<int> ans = {X,0,1};
		return ans;
	}
	vector<int> ans = euclid(X%A,A);
	int temp = ans[1];
	ans[1]= ans[2]-(X/A)*ans[1];
	ans[2]=temp;
	return ans;
}


int inverse(int A, int X){
	A=A%X;
	vector<int> ans = euclid(A,X);
       return (ans[1]+X)%X;	
}

int mypow(int A, int B, int X){
	assert(B>=0);
	if(B==0) return 1%X;
	else if(B==1) return A%X;
	int C = mypow(A,B/2,X);
	if(X%2==0) return (C*1LL*C)%X;
	else return (((C*1LL*C)%X)*1LL *A)%X;
}





int main(){
	int T, A, B, X;
	cin>>T;

	while(T--){
		cin>>A>>B>>X;
		if(B==0) {cout<<1%X<<endl; continue;}

		if(B<0) {A=inverse(A,X); B= -B;}

		cout<<mypow(A,B,X)<<endl;
	}
}
