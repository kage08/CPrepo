#include <string.h>
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10000

student* new_student(int id){
	student* news = (student*)malloc(sizeof(student));
	news->id=id;
	news->next=NULL;
	return news;
}

queue* new_queue(){
	queue* newq=(queue*)malloc(sizeof(queue));
	newq->front=NULL;
	newq->rear=NULL;
	newq->size=0;
	return newq;
}

int is_empty(queue* qu){
	return qu->size==0;
}

int get_size(queue* qu){return qu->size;}

int top(queue* qu){
	if(!is_empty(qu))
		return qu->front->id;
	else return -1;
}
int bottom(queue* qu){
	if(!is_empty(qu))
		return qu->rear->id;
	else return -1;
}

student* dequeue(queue* qu){
	if(is_empty(qu)) return NULL;
	student* temp=qu->front;
	qu->front=qu->front->next;
	qu->size--;
	return temp;
}

void enqueue(queue* qu,student* st){
	if(is_empty(qu)){
		qu->rear=qu->front=st;
		qu->size++;
		return;
	}
	qu->rear->next=st;
	qu->rear=st;
	qu->size++;
	if(is_empty(qu)) qu->front=st;	
}

void merge_queues(queue* main, queue* sub){
	int start=top(main);int i=0;
	while(!is_empty(sub) && top(main) == top(sub)){
		enqueue(main,dequeue(main));
		dequeue(sub);
		i++;
	}
	while(top(main)!=start){
		enqueue(main,dequeue(main));
		
	}
	if(!is_empty(sub)){
		main->rear->next=sub->front;
		main->rear=sub->rear;
		main->size+=sub->size;
	}
}


void input_queue(queue* qu,char* input){

	char* num;
	enqueue(qu,new_student(atoi(strtok(input," "))));
	while((num=strtok(NULL," ")))
		enqueue(qu,new_student(atoi(num)));

	
}

void print_queue(queue* qu){
	int sz=qu->size;
	int i;
	for(i=0;i<sz;i++){
		printf("%d ",top(qu));
		enqueue(qu,dequeue(qu));
	}
}

int main(void){
	int N;
	int *subsize;
	scanf("%d",&N);
	subsize=(int*)malloc(sizeof(int)*N-1);
	while(getchar()!='\n');
	char* inputs=(char*)malloc(sizeof(char)*MAXSIZE);
	fgets(inputs,MAXSIZE-1,stdin);
	queue* main_q=new_queue();
	input_queue(main_q,inputs);
	queue** qarr=(queue**)malloc(sizeof(queue*)*(N-1));

	int i;
	for(i=0;i<N-1;i++){
		qarr[i]=new_queue();
		fgets(inputs,MAXSIZE-1,stdin);
		input_queue(qarr[i],inputs);
		subsize[i]=size_subqueue(main_q,qarr[i]);

	}
	sort_queue_order(subsize,qarr,N-1);
	for(i=0;i<N-1;i++)
		merge_queues(main_q,qarr[i]);

	print_queue(main_q);
	putchar('\n');
	return 0;


}

int size_subqueue(queue* main, queue* sub){
	int mtop=top(main),stop=top(sub),sz=0;
	while(top(main)==top(sub) && sz<=sub->size){
		sz++;
		enqueue(main,dequeue(main));
		enqueue(sub,dequeue(sub));
	}
	while(top(main)!=mtop){
		enqueue(main,dequeue(main));
	}
	while(top(sub)!=stop){
		enqueue(sub,dequeue(sub));
	}
	return sub->size-sz;

}

void sort_queue_order(int* subsize,queue** qarr, int n){
	int i,sz; queue* qt;
	for(i=1;i<n;i++){
		sz=subsize[i]; qt=qarr[i];
		int j=i;
		while(j>0 && subsize[j-1]>subsize[j]){
			qarr[j]=qarr[j-1];
			subsize[j]=subsize[j-1];
			j--;
		}
		subsize[j]=sz; qarr[j]=qt;
	}
}
