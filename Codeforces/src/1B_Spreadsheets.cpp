/*
 * =====================================================================================
 *
 *       Filename:  1B_Spreadsheets.cpp
 *
 *    Description:  Convert numeration of spreadsheets
 *
 *        Version:  1.0
 *        Created:  01/14/2017 09:56:12
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Harshavardhan.P.K. 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

typedef unsigned long long ull;

ull numindex(string s){
	ull ans=0;
	while(isalpha(s[ans])) ans++;
	return ans;
}

ull convert(string s){
	ull l=s.length();
	ull ans=0,term=1;
	for(ull i=l-1;;i--){
		ans+=term*(s[i]-'A'+1);
		term=term*26;
		if (i==0) break;
	}
	return ans;

}

string reconvert(ull n){
	string ans = "";
	while(n!=0){
		if(n%26==0) {ans.insert(ans.begin(),'Z');n--;}
		else ans.insert(ans.begin(),(char)('A'+n%26-1));
		n/=26;
	}
	return ans;
}

string xltorc(string xl){
	ull p=numindex(xl);
	ull col=convert(xl.substr(0,p));
	string ans="R"+xl.substr(p)+"C"+to_string(col);
	return ans;
}

string rctoxl(string rc){
	ull c=rc.find('C');
	string co=rc.substr(c+1);
	string col=reconvert(stoi(co,nullptr,10));
	string row=rc.substr(1,c-1);
	return col+row;
}

int main (void){
	ull t;
	cin>>t;
	cin.clear();
	cin.ignore(INT_MAX,'\n');
	for(ull i=0;i<t;i++){
		string q;
		getline(cin,q);
		if(q[0]=='R' && !isalpha(q[1]) && q.find('C')!=q.npos) cout<<rctoxl(q)<<endl;
		else cout<<xltorc(q)<<endl;
	}
	return 0;
}
