#include <bits/stdc++.h>
#define PRECISION 0.0000001

using namespace std;
typedef unsigned long ul;
typedef unsigned long long ull;

double mL(double time, vector<ul>& x, vector<ul>& v){
	double ans=DBL_MIN;ul len=x.size();
	for(ul i=0;i<len;i++){
		ans=max(ans,(double)x[i]-(double)v[i]*time);
	}
	return ans;
}

double mR(double time, vector<ul>& x, vector<ul>& v){
	double ans=DBL_MAX;ul len=x.size();
	for(ul i=0;i<len;i++){
		ans=min(ans,(double)x[i]+(double)v[i]*time);
	}
	return ans;
}

int main(){
	ul n;
	cin>>n;
	vector<ul> x(n);
	vector<ul> v(n);
	ul maxind=0, minind=INT_MAX;
	for(ul i=0;i<n;i++){
		cin>>x[i];
		maxind=max(maxind,x[i]);
		minind=min(minind,x[i]);
	}
	double maxtime=0;
	for(ul i=0;i<n;i++){
		cin>>v[i];
		maxtime=max(maxtime,(double)(x[i]-minind)/(double)v[i]);
		maxtime=max(maxtime,(double)(maxind-x[i])/(double)v[i]);
	}
	double curr=maxtime/2.0, prevL=0,prevR=maxtime,prev=0;
	while(((curr>prev)?curr-prev:prev-curr)>PRECISION){
		double maxL=mL(curr,x,v);
		double minR=mR(curr,x,v);
		prev=curr;
		if(maxL>minR){
			prevL=curr;
			curr=(prevL+prevR)/2.0;
		}
		else{
			prevR=curr;
			curr=(prevL+prevR)/2.0;
		}

	}
	cout<<fixed;
	cout<<setprecision(12)<<curr<<endl;
}
