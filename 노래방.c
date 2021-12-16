#include <stdio.h>
#include <stdlib.h>
typedef int ELEMENT ;
typedef char CHARACTER ;
typedef struct song{
	int Snum;
	char Sname[20];
}Song;
typedef struct queue{
//	ELEMENT * buf;
	ELEMENT * num;
	CHARACTER * name;
	QUEUE * link;
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
//	ELEMENT data;
	q = createQueue( 2 );
	Song* song = (Song *)malloc(sizeof(song));
 
	int num; 
	while(1){
		printf("--------------------------------------------------------------------\n");
		printf("1.노래예약   2.노래 시작  3.예약 현황   4.예약한 노래 검색  5.끝내기\n");
		printf("--------------------------------------------------------------------\n");
		scanf("%d",&num);
		switch(num){
			case 1:
				printf("노래 번호를 입력하세요 :");
				scanf("%d",&(song->Snum));
				printf("\n노래 제목을 입력하세요 :");
				scanf("%s",(song->Sname));
//				gets(song->Sname);
				enQueue(q,song->Snum,song->Sname);
				if(isEmpty(q)>=1){
					printf("%s이(가) 예약이 되었습니다.\n",song->Sname);
				}
				
			 	break;
			case 2: 
				return 0;
				break;
			case 3:
				printAll(q);
				break;
			case 4:
				return 0;
				break;
			case 5:
				return 0;
				break;
		}
	}
//	printAll(q);

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
	 }	
	 else{
		  return -1;
	 }
}
void enQueue( QUEUE *q, ELEMENT nu, CHARACTER na ){
	 if(isFull(q)==1){
	 		printf("예약이 가득찼습니다.\n");	
	 }
	 else{
	 		q -> rear++;
//		 	q->buf[q->rear] = data;
		 	q ->name[q->rear] = na;
			q->num [q->rear] =  nu;
	 }
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
	}
  else{
		q->front++;
		return q->num[q->front];
	}
}
void printAll( QUEUE *q ){
	int i;
	for(i = q->front + 1;i<= q->rear;i++){
		printf("%s",q->name[i]);
	}
}

void destroyQueue( QUEUE * q ){
	free(q->name);
	free(q->num);
	free(q);
}
