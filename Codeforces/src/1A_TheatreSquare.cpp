/*
 * =====================================================================================
 *
 *       Filename:  1A_TheatreSquare.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/14/2017 09:49:43
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
int main(void){
	unsigned long long n,m,a;
	cin>>n>>m>>a;
	unsigned long long col=n/a, row=m/a;
	if(n%a!=0) col++;
	if(m%a!=0) row++;
	cout<<col*row<<endl;
	return 0;
}
