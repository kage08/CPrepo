#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T,n,wall;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n;
		wall=0;
		vector<vector<char> >plan(2,vector<char>(n));
		bool present[2];
		present[0]=present[1]=false;
		for(int i=0;i<2;i++)
			for(int j=0;j<n;j++){
				cin>>plan[i][j];
				if(plan[i][j]=='*') present[i]=true;
			}
		if(!present[0] && !present[1]) {
			cout<<"0\n";
			continue;
		}
		if(present[0] && present[1]){
			wall=1;
			int presentstate=-1;
			for(int i=0;i<n;i++){
				if(presentstate==0){
					if(plan[1][i]=='*' && plan[0][i]=='*') wall++;
					else if(plan[1][i]=='*') {presentstate=2;wall++;}
					else if(plan[0][i]=='*') {presentstate=1;wall++;}
				}
				else if(presentstate==1){
					if(plan[1][i]=='*' && plan[0][i]=='*') {wall++;presentstate=0;}
					else if(plan[1][i]=='*') {presentstate=0;}
					else if(plan[0][i]=='*') {presentstate=1; wall++;}
				}
				else if(presentstate==2){
					if(plan[1][i]=='*' && plan[0][i]=='*') {wall++;presentstate=0;}
					else if(plan[1][i]=='*') {presentstate=2; wall++;}
					else if(plan[0][i]=='*') {presentstate=0;}
				}
				else if(presentstate==-1){
					if(plan[1][i]=='*' && plan[0][i]=='*') presentstate=0;
					else if(plan[1][i]=='*') presentstate=2;
					else if(plan[0][i]=='*') presentstate=1;
				}
			}

		}
		else{
			if(present[0]){
				for(int i=0;i<n;i++) if(plan[0][i]=='*') wall++;
			}
			else
				if(present[1]){
				for(int i=0;i<n;i++) if(plan[1][i]=='*') wall++;
			}
			wall--;

		}
		cout<<wall<<endl;
	}

	return 0;
}