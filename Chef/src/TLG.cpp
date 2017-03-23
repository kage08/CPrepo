/*
 * =====================================================================================
 *
 *       Filename:  TLG.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/06/2017 21:38:23
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
	int games,maxplayer=-1,maxlead=0,p1=0,p2=0,t1,t2;
	cin>>games;
	for(int i=0;i<games;i++){
		cin>>t1>>t2;
		p1+=t1;
		p2+=t2;
		if(p1>p2){
			if(p1-p2>maxlead){
				maxlead=p1-p2;
				maxplayer=1;
			}
		}
		else{
			if(p2-p1>maxlead){
				maxlead=p2-p1;
				maxplayer=2;
			}
		}
	}
	cout<<maxplayer<<" "<<maxlead<<endl;
	
}
