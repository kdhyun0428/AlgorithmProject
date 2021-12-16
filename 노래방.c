#include <stdio.h>
#include <stdlib.h>
typedef int ELEMENT ;
typedef char CHARACTER ;
typedef struct song{
	int Snum;
	char Sname;
}Song;
typedef struct queue{
//	ELEMENT * buf;
	ELEMENT * num;
	CHARACTER * name;
	int front;
	int rear;
	int size;
}QUEUE;
QUEUE * createQueue( int n );
int isFull( QUEUE *q );
void enQueue( QUEUE *q, ELEMENT num,CHARACTER name );
int isEmpty( QUEUE *q );
ELEMENT deQueue( QUEUE *q );
void destroyQueue( QUEUE * q );
void printAll( QUEUE *q );
int main() {
	QUEUE *q;
	ELEMENT data;
	q = createQueue( 8 );
	Song* song = (Song *)malloc(sizeof(song));
//	scanf("%d",&(a->Snum));
//	printf("%d",a->Snum);
	int num; 
	while(1){
		printf("----------------------------------------------------------\n");
		printf("1.�뷡����   2.�뷡 ����  3.���� ��Ȳ   4.������ �뷡 �˻�\n");
		printf("----------------------------------------------------------\n");
		scanf("%d",&num);
		switch(num){
			case 1:
				scanf("%d",&(song->Snum));
				scanf("%d",&(song->Sname));
				enQueue(q,song->Snum,song->Sname);
			 	break;
			default:
				return 0;
		}
	}
	

	return 0;
}
QUEUE * createQueue( int n ){
	QUEUE *temp = (QUEUE *) malloc( sizeof(QUEUE) );
	temp -> size =  n;
	temp -> rear =  -1;
	temp -> front = -1;
//	temp -> buf =   (ELEMENT *) malloc(sizeof(ELEMENT)* n);
	temp -> name = (CHARACTER *) malloc(sizeof(CHARACTER)*n);
	temp -> num = (ELEMENT *) malloc(sizeof(ELEMENT)*n);
	return temp;
}
int isFull( QUEUE *q ){
	 if(q->rear >= q->size-1){
	  	return 1;	
	 }// ť�� ���� �� �ִٸ� rear �� � �����ϱ�?
	 else{
		  return -1;
	 }
}
void enQueue( QUEUE *q, ELEMENT nu, CHARACTER na ){
	 if(isFull(q)==1){
	 		printf("queue is full\n");	
	 }// ���� �� �ִٸ� "queue is full"�̶�� ���
	 else{
	 		q -> rear++;
//		 	q->buf[q->rear] = data;
		 	q ->name[q->rear] = na;
			q->num [q->rear] =  nu;
	 }// �ƴϸ� rear�� data ����
}
int isEmpty( QUEUE *q ){
	if(q->rear == q->front){
		return 1;
	}
	else{
		return -1;
	}
}
ELEMENT deQueue( QUEUE *q ){
	if(isEmpty(q)==1){
		printf("Queue is empty\n");
		return 0;
	}	// ��� �ִٸ� "Queue is empty" ����ϰ� 0 ����
  else{
		q->front++;
		return q->num[q->front];
	}	// �ƴϸ� front��ġ�� ������ ����
}
void printAll( QUEUE *q ){
	int i;
	for(i = q->front + 1;i<=q->rear;i++){
		printf("%d ",q->name[i]);
		printf("%d ",q->num[i]);
	}
}

void destroyQueue( QUEUE * q ){
	free(q->name);// buf ���� �޸� ����
	free(q->num);
	free(q);// q ���� �޸� ����
}
