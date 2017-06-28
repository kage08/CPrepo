#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	while(a && b){
		if(a>=b)
			a%=b;
		else
			b%=a;
	}

	return a+b;

}

int lcm (int a, int b){
	return (a*b)/gcd(a,b);
}

int main(){
	int n,m,factor, multiple;
	cin>>n>>m;
	int a[n], b[m];

	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];

	factor=1;
	multiple=0;

	for(int i: b)
		multiple=gcd(multiple,i);

	for(int i: a){
		factor=lcm(factor,i);
		if(factor>multiple){
		cout<<0<<endl;
		return 0;
	}
	}

	

	if(factor>multiple || multiple%factor){
		cout<<0<<endl;
		return 0;
	}

int value = multiple / factor;
	
        int totalX = 1;
        
        for (int i = factor; i < multiple; i++) {
            if (multiple % i == 0 && i % factor == 0) {
                totalX++;
            }
        }

        cout<<totalX<<endl;
}