#include <iostream>
#include <string>

using namespace std;

pair<bool,long long> isbeautiful(string s, int n){
	int index=0;
	long long pres_no = stoll(s.substr(index,n));
	if(to_string(pres_no) != s.substr(index,n))
		return make_pair(false,-1);
	long long next_no;
	int len_next;
	index+=n;
	while(index<s.length()){
		len_next = to_string(pres_no+1).length();
		next_no=stoll(s.substr(index,len_next));
		if(next_no!=pres_no+1){
			return make_pair(false,-1);
		}
		pres_no++;
		index+=len_next;
	}
	return make_pair(true,stoll(s.substr(0,n)));
}

/*  
bool isnumber(string s){
	auto i = s.begin();
	for(; i!=s.end() && isdigit(*i);i++);

	return !s.empty() && i==s.end();
}*/

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
	/*  if(!isnumber(s)){
		cout<<"NO"<<endl;
		continue;
	}*/
	int i,flag=0;
	int l = s.length();
        // your code goes here
	for(i=1;i<=l/2;i++){
		pair<bool,long long> result = isbeautiful(s,i);
		if(result.first){
			cout<<"YES "<<result.second<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0) cout<<"NO"<<endl;
    }
    return 0;
}
//stol prevented abort called. Still last 6 cases are failing!
//using stoll worked!
//Lesson: Always keep an eye for the range darn it!
