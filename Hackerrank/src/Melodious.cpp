#include <bits/stdc++.h>

using namespace std;
char vowels[]="aeiou";
void printvowel(string,int);
void printconst(string st,int n){
    if(n>1){
        for(char i='a';i<='z';i++){
            if(!(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'))
                printvowel(st+i,n-1);      
        }
    }
    if(n==1){
        for(char i='a';i<='z';i++){
            if(!(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'))
                printf("%s%c\n",st.c_str(),i);      
        }
    }
    if(n==0) printf("%s\n",st.c_str()); 
    
}

void printvowel(string st,int n){
    if(n>1){
        for(char i='a';i<='z';i++){
            if((i=='a'||i=='e'||i=='i'||i=='o'||i=='u'||i=='y'))
                printconst(st+i,n-1);      
        }
    }
    if(n==1){
        for(char i='a';i<='z';i++){
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'||i=='y')
                printf("%s%c\n",st.c_str(),i);      
        }
    }
    if(n==0) printf("%s\n",st.c_str());
    
}

int main(){
    int n;
    cin >> n;
    for(char i='a';i<='z';i++){
        if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u')
            printconst(string(1,i),n-1);
        else if(i!='y')
            printvowel(string(1,i),n-1);
    }
    return 0;
}

