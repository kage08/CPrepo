#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



vector<short> multiply_digit(vector<short>& a,short b, int offset=0){
    vector<short> ans(offset,0);
    if(b==0) return ans;
    
    int carry=0,prod=0,c;
    for(int i=0; i<a.size(); i++){
        prod=a[i]*b;
        c=(carry+prod)%10;
        ans.push_back(c);
        carry=(carry+prod)/10;
        
    }
    while(carry) {ans.push_back(carry%10); carry/=10;}
    
    
    while(ans.size())
    {
        if(ans[ans.size()-1]==0){
            ans.pop_back();
        }
        else break;
    }
    return ans;
}

vector<short> addition(vector<short>& a, vector<short>& b){
    int carry=0;
    vector<short> ans(0);
    for(int i=0;i<min(a.size(),b.size()); i++){
        ans.push_back((a[i]+b[i]+carry)%10);
        carry=(a[i]+b[i]+carry)/10;
    }
    if(a.size()>b.size()){
        for(int i=b.size();i<a.size();i++){
            ans.push_back((a[i]+carry)%10);
            carry=(a[i]+carry)/10;
        }
    }
    else if(b.size()>a.size()){
        for(int i=a.size();i<b.size();i++){
            ans.push_back((b[i]+carry)%10);
            carry=(b[i]+carry)/10;
        }
    }
    
    while(carry){
        ans.push_back(carry%10);
        carry/=10;
    }
    return ans;
}
void printnum(vector<short> a);
vector<short> multiply(vector<short> a, vector<short> b){
    vector<short> ans(0);
    vector<short> term;
    
    for(int i=0;i<a.size();i++){

        term=multiply_digit(b,a[i],i);
        
        ans=addition(ans,term);
    }
    
    return ans;
}

void printnum(vector<short> a){
    
    while(a.size()) {if(a[a.size()-1]==0) a.pop_back(); else break;}
    
    if(a.size()==0){
        cout<<0; return;
    }
    
    for(int i=a.size()-1;i>=0;i--)
        cout<<a[i];
}

vector<short> inputnum(string n){
	
	vector<short> ans;
	for(int i=n.length()-1;i>=0;i--)
		ans.push_back(n[i]-'0');
	while(ans.size())
    {
        if(ans[ans.size()-1]==0){
            ans.pop_back();
        }
        else break;
    }
    return ans;
}

vector<short> factorial(string a){
	vector<short> n=inputnum("1");
	int num=stoi(a);
	for(int i=1;i<=num;i++)
		n=multiply(n,inputnum(to_string(i)));

	return n;



}

int main(){
      string n;
    vector<short> n1;
    cin>>n;
    n1=factorial(n);
    printnum(n1);
    cout<<endl;
}

