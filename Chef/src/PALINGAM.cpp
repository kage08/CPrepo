#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	string s,t;
	cin>>T;
	while(T--){
		cin>>s;
		cin>>t;
		vector<int> freq1(26,0);
		vector<int> freq2(26,0);
		vector<int> freq1_2(26,0);
		int l1=s.length();
		for(int i=0; i<l1; i++){
			freq1[s[i]-'a']++;
			freq2[t[i]-'a']++;
			freq1_2[s[i]-'a']++;
			freq1_2[t[i]-'a']++;
		}

		bool isanagram=true, isdistinct=true;
		bool d1=false, d2= false;
		for(int i=0; i<26; i++){
			if(freq1[i]!=freq2[i]) isanagram=false;
			if(freq1_2[i]>1) isdistinct=false;
			if(freq1[i]==0 && freq2[i]) d2=true;
			if(freq2[i]==0 && freq1[i]==1) d1=true;
		}

		if(isanagram || isdistinct || (d1 && d2)) cout<<"B"<<endl;
		else cout<<"A"<<endl;
	}
}