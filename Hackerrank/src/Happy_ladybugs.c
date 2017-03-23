#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 102

void compute(int);
void findfreq(char[],int*);

int main(void){
	int g;
	scanf("%d",&g);
	int i;
	for(i=0;i<g;i++){
		int n;
		scanf("%d",&n);
		compute(n);
	}
	return 0;
}

void compute(int n){
	char board[MAXLEN];
	while(getchar()!='\n');
	fgets(board,MAXLEN,stdin);
	board[strlen(board)-1]='\0';
	int* alphfreq=(int*)calloc(sizeof(int),27);
	findfreq(board,alphfreq);

	int i,flag=0;
	for(i=0;i<26;i++)
		if(alphfreq[i]==1){
			flag++; break;
		}

	if(!flag && alphfreq[26]) printf("YES\n");
	else {
		if(alphfreq[26]==0){
			i=0;
			if(strlen(board)<=1) {printf("NO\n");return;}
			while(i<strlen(board)){
				if(i==strlen(board)-1 || board[i]!=board[i+1]) {printf("NO\n"); return;}
				while(i<strlen(board) && board[i]==board[i+1]) i++;
				i++;
			}
			printf("YES\n");
		}
		else printf("NO\n");
	}
}

void findfreq(char board[],int* alphafreq){
	int i;
	for(i=0;i<strlen(board);i++){
		if(isalpha(board[i]))
			alphafreq[board[i]-'A']++;
		else if(board[i]=='_')
			alphafreq[26]++;
	}
}
