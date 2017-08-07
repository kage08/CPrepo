#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pb;
typedef unsigned long unt;

struct classcomp {
  bool operator() (pb a, pb b) 
  {return a.first>=b.first;}
};

int main(){
	unt t, n, m;
	cin>>t;
	for(unt i_t=0; i_t < t; i_t++){
		cin>>n>>m;
		vector<int> minSal(n);
		vector<int> offeredSal(m);
		vector<int> maxJobOffers(m);
		vector<int> presOffers(m,0);

		vector<set<pb, classcomp> > candCan(n,set<pb, classcomp>());

		for(unt i=0; i<n; i++)
			cin>>minSal[i];

		for(unt i=0; i<m; i++)
			cin>>offeredSal[i]>>maxJobOffers[i];

		unt qual;

		for(unt i=0; i<n; i++){
			string st;
			cin>>st;
			for(unt j=0; j<m; j++){
				qual=st[j]-'0';
				if(qual && offeredSal[j]>=minSal[i])
					candCan[i].insert(make_pair(offeredSal[j],j));
			}
		}

		ull sumSal=0;
		unt candSel=0;
		unt noHire=0;

		for(unt i=0; i<n; i++){
			for( auto p: candCan[i]){
				if(presOffers[p.second]<maxJobOffers[p.second]){
					candSel++;
					sumSal+=p.first;
					presOffers[p.second]++;
					break;
				}
			}
		}

		for(unt i=0; i<m;i++)
			if(presOffers[i]==0)
				noHire++;

		cout<<candSel<<" "<<sumSal<<" "<<noHire<<endl;

	}
}