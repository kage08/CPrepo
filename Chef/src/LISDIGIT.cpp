/*
 * =====================================================================================
 *
 *       Filename:  LISDIGIT.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/06/2017 22:17:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

int main(void){
	int test;
	string line,tline;
	char c;
	cin>>test;

	getline(cin,tline);
	for(int i=0;i<test;i++){
		getline(cin,tline);
		getline(cin,line);
		for(int j=0;j<line.size();j++){
			if(line[j]>='0' && line[j]<='9')
				cout<<line[j];
		}
		cout<<endl;
	}
	return 0;
}
