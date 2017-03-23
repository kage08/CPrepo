#include <bits/stdc++.h>
using namespace std;
typedef unsigned long ul;
typedef unsigned int ui;
typedef unsigned long long ull;

void dfs(ui vertex, ui parent,vector<vector<ul> >& edges,vector<ui>& color,ui maxcolor){
	ui vcolor=color[vertex],pcolor=-1;
	if(parent!=-1) pcolor=color[parent];
	ui ccolor=(vcolor+1)%maxcolor;
	for(auto v:edges[vertex]){
		if(v==parent) continue;
		if(ccolor==pcolor) ccolor=(ccolor+1)%maxcolor;
		color[v]=ccolor;
		dfs(v,vertex,edges,color,maxcolor);
		ccolor=(ccolor+1)%maxcolor;
	}
}

int main(){
	ul n,u,v;
	cin>>n;
	vector<vector<ul> >edges(n,vector<ul>());
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		edges[u-1].push_back(v-1);
		edges[v-1].push_back(u-1);
	}

	int maxdeg=0;
	for(int i=0;i<n;i++){
		if(edges[i].size()>maxdeg) maxdeg=edges[i].size();
	}
	cout<<maxdeg+1<<endl;
	vector<ui> color(n,0);
	color[0]=0;
	dfs(0,-1,edges,color,maxdeg+1);

	for(int i=0;i<n;i++)
		cout<<color[i]+1<<" ";
	cout<<endl;
}
