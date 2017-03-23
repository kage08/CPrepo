#include <iostream>
#include <vector>


using namespace std;

int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        int m;
        long long x;
        cin >> n >> m >> x;
        vector<long long> a(n+1,0);
        for(int a_i = 1; a_i <= n; a_i++){
           cin >> a[a_i];
            a[a_i]+=a[a_i-1];
        }
        vector<long long> b(m+1,0);
        for(int b_i = 1; b_i <= m; b_i++){
           cin >> b[b_i];
            b[b_i]+=b[b_i-1];
        }
        // your code goes here
	//
	//
	
	if(a[n] +b[m] <= x){
		cout<<m+n<<endl;
		continue;
	}

	int aindex=0,bindex=0;
	while(aindex<=n && a[aindex]<=x) aindex++;

	if(aindex==n+1 || a[aindex]>x) aindex--;


	while(bindex<=m && a[aindex]+b[bindex]<=x) bindex++;
	if(bindex==m+1 || a[aindex]+b[bindex]>x) bindex--;

	int maxbox=aindex+bindex;

	while(1){
		
		aindex--;
		if(aindex<0) break;

		while(bindex<=m && a[aindex] + b[bindex] <= x){
			bindex++;
		}
		if(bindex==m+1 || a[aindex]+b[bindex]>x) bindex--;

		if(aindex+bindex>maxbox) maxbox=aindex+bindex;
	}

	cout<<maxbox<<endl;
    }
    return 0;
}
//Concern : passing only 2 cases ()
