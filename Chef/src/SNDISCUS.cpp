#include <bits/stdc++.h>
using namespace std;

typedef struct snake_{
	int x1,y1,x2,y2;
} snake;

void correctify(snake& s){
	int a1,b1,a2,b2;
	a1=(s.x1<=s.x2)?s.x1:s.x2;
	b1=(s.y1<=s.y2)?s.y1:s.y2;
	a2=s.x1+s.x2-a1;
	b2=s.y2+s.y1-b1;
	s.x1=a1; s.x2=a2; s.y1=b1; s.y2=b2;
}

int snakedist(snake s1, snake s2){
	int dist=0;
	if(s1.x1==s1.x2 && s2.x1==s2.x2){

		dist=(s1.x1>=s2.x1)?(s1.x1-s2.x1):(s2.x1-s1.x1);
		if(s1.y2<s2.y1) dist+=(s2.y1-s1.y2);
		else if(s2.y2<s1.y1) dist+=(s1.y1-s2.y2);
	}
	else if(s1.y1==s1.y2 && s2.y1==s2.y2){

		dist=(s1.y1>=s2.y1)?(s1.y1-s2.y1):(s2.y1-s1.y1);
		if(s1.x2<s2.x1) dist+=(s2.x1-s1.x2);
		else if(s2.x2<s1.x1) dist+=(s1.x1-s2.x2);
	}

	else{

		if(s1.x1==s1.x2){
			if(s2.x1<=s1.x1 && s2.x2>=s1.x2) return 0;
		}
		else if(s2.x1==s2.x2){
			if(s1.x1<=s2.x1 && s1.x2>=s2.x2) return 0;
		}

		if(s1.x1==s1.x2){
			dist=min(abs(s1.x1-s2.x1),abs(s1.x2-s2.x2))+min(abs(s1.y1-s2.y1),abs(s1.y2-s2.y2));
		}
		else{
			dist=min(abs(s2.x1-s1.x1),abs(s2.x2-s1.x2))+min(abs(s2.y1-s1.y1),abs(s2.y2-s1.y2));
		}
	}



	return dist;
}

int main(int argc, char const *argv[])
{
	int T,n;
	cin>>T;
	for(int t=0;t<T;t++){
		cin >>n;
		if(n==0){
			cout<<"0\n";
			continue;
		}
		vector<snake> snakes(n);
		for(int i=0;i<n;i++){
			cin>>snakes[i].x1>>snakes[i].y1>>snakes[i].x2>>snakes[i].y2;
			correctify(snakes[i]);
		}
		vector<vector<int> > maxdist(51,vector<int>(51,0));
		int maxdistance=INT_MAX;
		for(int i=0;i<n;i++)
			for(int j=1;j<51;j++)
				for(int k=1;k<51;k++){
					snake stemp;
					stemp.x1=stemp.x2=j;
					stemp.y1=stemp.y2=k;
					maxdist[j][k]=std::max(maxdist[j][k],snakedist(snakes[i],stemp));
				}

		for(int j=1;j<51;j++){
			for(int k=1;k<51;k++){
				maxdistance=min(maxdistance,maxdist[j][k]);
			}
		}

		
		cout<<(maxdistance)<<endl;

	}

	return 0;
}