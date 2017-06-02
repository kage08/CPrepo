#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

double combo(Long n,Long r){
	double ans=log(n);
	for(Long i=n-1;i>=n-r+1;i--)
		ans+=log(i);
	double ans2=0;
	for(Long i=1;i<=r;i++)
		ans2+=log(i);
	ans-=ans2;
	return ans;
}

int main(){
	double p1,p2,p3,p4,p5,pa,pb;
	cin>>p1>>p2>>p3>>p4>>p5;
	pa=p1+p2+p3+p4+p5;
	pb=log(1-pa);
	pa=log(pa);
	Long n,k; double na;
	cin>>n>>k;
	na=combo(n,k);
	double ans=na+pa*k+pb*(n-k);
	ans=ans/(log(10));
	cout<<floor(ans)<<endl;

}

