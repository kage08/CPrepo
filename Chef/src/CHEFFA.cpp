#include <bits/stdc++.h>
#define MODUL 1000000007
#define ll long long
#define ull unsigned long long
using namespace std;
typedef pair<int*, ull> pa;



struct classcomp {
  bool operator() (pa a, pa b) 
  {if(a.second<b.second) return true;
  	if(a.second> b.second) return false;
  	ull l = a.second;
  	for(ull i=0; i<l; i++){
  		if(a.first[i]<b.first[i]) return true;
  		if(b.first[i]<a.first[i]) return false;
  	}

  	return false;
  }
};

void addterms(set<pa, classcomp>& vecset, pa& term){
	
	ull l = term.second;

	for(ull i=0; i<l-2; i++){
		
		if(term.first[i]>0 && term.first[i+1]>0){
			pa temp;
			temp.second=term.second;
			      //temp = term;
			temp.first=new int[temp.second];
			for(ull i=0; i<temp.second; i++)
				temp.first[i]=term.first[i];
			temp.first[i]--; temp.first[i+1]--;
			temp.first[i+2]++;
			vecset.insert(temp);
		}
	}

	if(term.first[l-2]>0 && term.first[l-1]>0){
		pa temp;
		temp.second=term.second+1;
			      //temp = term;
			temp.first=new int[temp.second];
			for(ull i=0; i<temp.second-1; i++)
				temp.first[i]=term.first[i];
		temp.first[l-2]--; temp.first[l-1]--;
		temp.first[l]=1;
		vecset.insert(temp);
	}
}

int main(){
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		pa arr;
		arr.first = new int[n];
		arr.second = n;
		for(int i=0; i<n; i++)
			cin>>arr.first[i];

		set<pa , classcomp> vecset[2];
		vecset[0].insert(arr);
		ull tot=0;
		ull depth = 0;

		while(!vecset[depth%2].empty()){
			tot++;
			tot=tot%MODUL;
			pa term = *(vecset[depth].begin());
			/*for(ull i=0; i<term.size(); i++)
				cout<<term[i]<<" ";
			cout<<endl;*/
			vecset[depth%2].erase(vecset[depth%2].begin());
			addterms(vecset[(depth+1)%2],term);
			free(term.first);
			if(vecset[depth%2].empty()) {
				if(depth) depth=0;
				else depth=1;
			}
		}
		cout<<tot<<endl;
	}
}