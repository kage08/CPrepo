#include <bits/stdc++.h>
#define FOR(i,x,y) for(ul i=(x); i<= (y); i++)


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;


int main(){
	ul n,u,v;
	vector<vector<ul> > graph(n+1,vector<ul>());
	FOR(i,1,n-1){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}


}
