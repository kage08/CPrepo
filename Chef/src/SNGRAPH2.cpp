#include <bits/stdc++.h>
using namespace std;


int findparent(int a, vector<int>& disjset){
	if(disjset[a]<0) return a;
	int curr=a;
	while(disjset[curr]>=0) curr=disjset[curr];
	return curr;
}

int unite(int a, int b, vector<int>& disjset){
	if(a==b) return 0;
	if(disjset[a]<0 && disjset[b]<0){
		if(disjset[a]<disjset[b]) disjset[b]=a;
		else if(disjset[b]<disjset[a]) disjset[a]=b;
		else {disjset[a]--; disjset[b]=a;}
		return 1;
	}
	else{
		int ap=findparent(a,disjset);
		int bp=findparent(b,disjset);
		if(ap==bp) return 0;
		else return unite(ap,bp,disjset);
	}
}

int main(int argc, char const *argv[])
{
	int T,n,m,u,v;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n>>m;
		vector<set<int> >edges(n,set<int>());
		vector<pair<int,int> >edgeset;
		vector<int> degree(n);
		vector<vector<int> >degmap(n,vector<int>());
		vector<vector<pair<int,int> > >degedgemap(n,vector<pair<int,int> >());
		for(int i=0;i<m;i++){
			cin>>u>>v;
			edges[u-1].insert(v-1);
			edges[v-1].insert(u-1);
			edgeset.push_back(make_pair(u-1,v-1));
		}
		for(int i=0;i<n;i++){
			degree[i]=edges[i].size();
			degmap[edges[i].size()].push_back(i);
		}
		for(auto pb:edgeset){
			degedgemap[std::min(degree[pb.first],degree[pb.second])].push_back(pb);
		}

		vector<int> components(n,0);
		components[n-1]=n;
		int presentcomponent=n;
		vector<int> disjset(n,-1);
		for(int i=n-2;i>=0;i--){
			for(auto pb: degedgemap[i+1]){
				presentcomponent-=(unite(pb.first,pb.second,disjset));

			}
			components[i]=presentcomponent;
		}

		for(int i=0;i<n;i++)
			cout<<(components[i]-1)<<" ";
		cout<<endl;
	}
	return 0;
}