#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	for(int i_t = 0; i_t<t;i_t++){
		cin>>n;
		vector<int> arr(n);
		vector<int> freq(7,0);
		int i;
		int state = 0;

		for(i=0;i<n; i++){
			cin>>arr[i];
			if(arr[i]>7) state = -1;
		}

		if(state == -1) {cout<<"no"<<endl; continue;}

		for(i=0 ; i<n && arr[i]<7; i++){
			freq[arr[i]-1]++;
			if(state == arr[i]) continue;
			if(state+1 == arr[i]){
				state++; continue;
			}


			state=-1;
			break;
		}

		if(i>=n-6) state = -1;
		else if (arr[i] == 7) state = 7;

		if(state == -1) {cout<<"no"<<endl; continue;}
		while(arr[i]==7) i++;

		for(; i<n; i++){
			
			freq[arr[i]-1]--;
		}

		for(i=0;i<6;i++){
			if(freq[i]!=0) {state=-1;  break;}
		}

		if(state != -1) cout<<"yes"<<endl;
		else cout<<"no"<<endl;


	}
}