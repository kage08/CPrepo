#include <iostream>
#include <vector>
using namespace std;

unsigned int nosubs(string t, string s){
    int l=t.length();
    unsigned int n=0;
    int ls = s.length();
    for(int i=0; i<=ls-l; i++){
        if(t == s.substr(i,l)) n++;
    }
    return n;
}

int main(){
    int n;
    int m;
    int q;
    int k;
    cin >> n >> m >> q >> k;
    string s;
    cin >> s;
    vector< vector<int> > pairs(m,vector<int>(2));
    for(int pairs_i = 0;pairs_i < m;pairs_i++){
       for(int pairs_j = 0;pairs_j < 2;pairs_j++){
          cin >> pairs[pairs_i][pairs_j];
       }
    }
    for(int a0 = 0; a0 < q; a0++){
        string w;
        int a;
        int b;
        cin >> w >> a >> b;
        // your code goes here
        int sum = 0;
        
        for(int i = a; i<=b; i++){
            sum+=nosubs(w.substr(pairs[i][0],pairs[i][1]-pairs[i][0]+1),s);
        }
        cout<<sum<<endl;
    }
    return 0;
}


