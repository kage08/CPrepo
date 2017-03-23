/*
 * =====================================================================================
 *
 *       Filename:  KOL16B.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/06/2017 23:01:30
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
	int test,n,t,t1;
	cin>>test;
	for(int i=0;i<test;i++){
		cin>>n;
		int A[n], B[n];
		for(int j=0; j<n;j++){
			cin>>t;
			B[j]=t>>16;
			A[j]=t-(B[j]<<16);
		}
		cout<<"Case "<<i+1<<":"<<endl;
		for(int j=0;j<n;j++)
			cout<<A[j]<<" ";
		cout<<endl;
		for(int j=0;j<n;j++)
			cout<<B[j]<<" ";
		cout<<endl;
	}
	return 0;
}
