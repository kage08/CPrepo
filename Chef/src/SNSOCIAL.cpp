#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T,n,m,time;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n>>m;
		vector<vector<int> >city(n,vector<int>(m));
		int maxwealth=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cin>>city[i][j];
				maxwealth=std::max(maxwealth,city[i][j]);
			}
		stack<pair<int,int> > maxaddr;
		stack<pair<int,int> > maxaddr1;
		time=0;
		int ct=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(city[i][j]==maxwealth) {maxaddr.push(make_pair(i,j)); ct++;}
		while(ct<n*m){
			time++;
			while(maxaddr.size()){
				auto pb=maxaddr.top();
				maxaddr.pop();
			
				if(pb.first>0 && city[pb.first-1][pb.second]<maxwealth){city[pb.first-1][pb.second]=maxwealth; maxaddr1.push(make_pair(pb.first-1,pb.second));ct++;}
				if(pb.first>0 && pb.second>0 && city[pb.first-1][pb.second-1]<maxwealth){city[pb.first-1][pb.second-1]=maxwealth; maxaddr1.push(make_pair(pb.first-1,pb.second-1));ct++;}
				if(pb.first>0 && pb.second<m-1 && city[pb.first-1][pb.second+1]<maxwealth){city[pb.first-1][pb.second+1]=maxwealth; maxaddr1.push(make_pair(pb.first-1,pb.second+1));ct++;}
				if(pb.first<n-1 && city[pb.first+1][pb.second]<maxwealth){city[pb.first+1][pb.second]=maxwealth; maxaddr1.push(make_pair(pb.first+1,pb.second));ct++;}
				if(pb.first<n-1 && pb.second>0  && city[pb.first+1][pb.second-1]<maxwealth){city[pb.first+1][pb.second-1]=maxwealth; maxaddr1.push(make_pair(pb.first+1,pb.second-1));ct++;}
				if(pb.first<n-1 && pb.second<m-1 && city[pb.first+1][pb.second+1]<maxwealth){city[pb.first+1][pb.second+1]=maxwealth; maxaddr1.push(make_pair(pb.first+1,pb.second+1));ct++;}
				if(pb.second>0 && city[pb.first][pb.second-1]<maxwealth){city[pb.first][pb.second-1]=maxwealth; maxaddr1.push(make_pair(pb.first,pb.second-1));ct++;}
				if(pb.second<m-1 && city[pb.first][pb.second+1]<maxwealth){city[pb.first][pb.second+1]=maxwealth; maxaddr1.push(make_pair(pb.first,pb.second+1));ct++;}
			}
			while(maxaddr1.size()){
				auto pb=maxaddr1.top();
				maxaddr.push(pb);
				maxaddr1.pop();
			}

				
			
			

		}
		cout<<time<<endl;
	}
	return 0;
}