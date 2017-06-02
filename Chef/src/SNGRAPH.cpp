#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
	int T,n,m,u,v;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n>>m;
		vector<set<int> >edges(n,set<int>());
		queue<pair<int,int> >edgeset;
		vector<int> degree(n);
		for(int i=0;i<m;i++){
			cin>>u>>v;
			edges[u-1].insert(v-1);
			edges[v-1].insert(u-1);
			edgeset.push(make_pair(u-1,v-1));
		}
		for(int i=0;i<n;i++)
			degree[i]=edges[i].size();

		edgeset.push(make_pair(-1,-1));
		for(int i=0;i<n;i++){
			if(edgeset.size()==1) {
				cout<<(n-1)<<" ";
				continue;
			}
			
			while(1){
				auto pb=edgeset.front();
				edgeset.pop();
				if(pb.first==-1) break;
				if(degree[pb.first]<=i || degree[pb.second]<=i){
					edges[pb.first].erase(pb.second); 
					edges[pb.second].erase(pb.first);
				}
				else{
					edgeset.push(pb);
				}
			}
			edgeset.push(make_pair(-1,-1));
			int components=0;
			vector<bool> visited(n,false);

			for(int i=0;i<n;i++){
				if(!visited[i]){
					components++;
					stack<int> vertex;
					vertex.push(i);
					int v1;
					while(vertex.size()){
						v1=vertex.top();
						vertex.pop();
						visited[v1]=true;
						for(int j:edges[v1]){
							if(!visited[j]) vertex.push(j);
						}
					}
				}
			}

			cout<<(components-1)<<" ";
		}
		cout<<endl;
	}
	return 0;
}