#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTU 100
#define MAXLEN 10000

int main(void){
    int N;
    scanf("%d",&N);
    int arr[N-1][MAXSTU];
    int mainq[MAXSTU];
    int arrlen[N-1];
    
    
    int mainsz=0;

    int i,j;
    char input[MAXLEN];
    while(getchar()!='\n');

    fgets(input,MAXLEN-1,stdin);
    i=0;
    char* temp;
    
    mainq[i]=atoi(strtok(input," \n\t"));
    mainsz++;i++;
    
    while((temp=strtok(NULL," \n\t"))){
        mainq[i]=atoi(temp);
        mainsz++;i++;
    }
    
    for(j=0;j<N-1;j++){
        fgets(input,MAXLEN-1,stdin);
        arrlen[j]=0;
        if((temp=strtok(input," \n\t"))){
        	arr[j][0]=atoi(temp);
        	arrlen[j]++;
    	}
	 while((temp=strtok(NULL," \n\t"))){
        	arr[j][arrlen[j]]=atoi(temp);
        	arrlen[j]++;
    	}

    }
    
    int subarraylen[N-1];
    int index[N-1];
    for(j=0;j<N-1;j++){
        index[j]=j;
        subarraylen[j]=0;
        i=0;
	if(mainq[0]!=arr[j][i]){
		subarraylen[j]=0;break;
	}
        while(mainq[i]==arr[j][i]){
            subarraylen[j]++;i++;  
        }
        subarraylen[j]=arrlen[j]-subarraylen[j];
    }
    
    for(j=1;j<N-1;j++){
        int l=subarraylen[j],ind=index[j];
        int i=j;
        while(i>0 && subarraylen[i-1]>l){
            subarraylen[i]=subarraylen[i-1];
            index[i]=index[i-1];
            i--;
        }
        subarraylen[i]=l;
        index[i]=ind;
    }
    
    for(j=0;j<N-1;j++){
        int i=arrlen[index[j]]-subarraylen[j];
        while(i!=arrlen[index[j]]){
            mainq[mainsz]=arr[index[j]][i];
            i++; mainsz++;
        }
        
    }
    
    for(j=0;j<mainsz;j++)
        printf("%d ",mainq[j]);
    putchar('\n');
    
    return 0;
    
}
