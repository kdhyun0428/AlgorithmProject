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
		printf("1.노래예약   2.노래 시작  3.예약 현황   4.예약한 노래 검색\n");
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
	 }// 큐가 가득 차 있다면 rear 은 어떤 상태일까?
	 else{
		  return -1;
	 }
}
void enQueue( QUEUE *q, ELEMENT nu, CHARACTER na ){
	 if(isFull(q)==1){
	 		printf("queue is full\n");	
	 }// 가득 차 있다면 "queue is full"이라고 출력
	 else{
	 		q -> rear++;
//		 	q->buf[q->rear] = data;
		 	q ->name[q->rear] = na;
			q->num [q->rear] =  nu;
	 }// 아니면 rear에 data 삽입
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
	}	// 비어 있다면 "Queue is empty" 출력하고 0 리턴
  else{
		q->front++;
		return q->num[q->front];
	}	// 아니면 front위치의 데이터 리턴
}
void printAll( QUEUE *q ){
	int i;
	for(i = q->front + 1;i<=q->rear;i++){
		printf("%d ",q->name[i]);
		printf("%d ",q->num[i]);
	}
}

void destroyQueue( QUEUE * q ){
	free(q->name);// buf 동적 메모리 해제
	free(q->num);
	free(q);// q 동적 메모리 해제
}
