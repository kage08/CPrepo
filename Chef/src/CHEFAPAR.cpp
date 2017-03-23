#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t,n;
	cin>>t;
	for(int tno=0;tno<t;tno++){
		cin>>n;
		int rent=0,ones=0,flag=0;
		vector<short> rentrep(n);
		for(int i=0;i<n;i++){
			cin>>rentrep[i];
			if(rentrep[i]==0) {flag=1; rent++;}
			if(flag==0) ones++;

		}
		cout<<rent*1000+(n-ones)*100<<endl;


	}
	return 0;
}
