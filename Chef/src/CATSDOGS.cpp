/*
 * =====================================================================================
 *
 *       Filename:  CATSDOGS.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/06/2017 22:33:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main(){
	int test,C,D,L;
	cin>>test;
	for(int i=0;i<test;i++){
		cin>>C>>D>>L;
		if(L%4!=0 || L>(C+D)*4 || 4*D>L){cout<<"no"<<endl; continue;}
		L=L/4;
		if(L<(C-D)){cout<<"no"<<endl; continue;}
		cout<<"yes"<<endl;
	}
	return 0;
}
