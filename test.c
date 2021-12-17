#include <stdio.h>
#include <string.h>

 

//추후 유지보수를 편히 하기위해 100이란 숫자를
//MAX_NUM으로 설정, 100을 200으로 바꾸면
//MAX_NUM은 200이 됨
#define MAX_NUM 100

 

//사용자의 정보를 저장하는 구조체
typedef struct{
 char name[30];
 char number[30];
}User;

 

void insert(User* ptr, int* num);
int deleted(User* ptr, int* num);
int search(User* ptr, int* num);
void printAll(User* ptr, int* num);

 

int main(void){
     int input;
     User user[MAX_NUM]; //사용자 정보를 저장할 구조체 배열
     int person = 0; //저장된 user수

 

     //메뉴 선택
     while(1){
		printf("----------------------------------------------------------------------\n");
		printf("1.노래 예약 | 2.노래 삭제 | 3.예약 현황 | 4.예약한 노래 검색 | 5.끝내기\n");
		printf("-----------------------------------------------------------------------\n");

          scanf("%d", &input);

 

          if (input == 1){
               insert(user, &person);
          }
          else if (input == 2){
               deleted(user, &person);
          }
          else if (input == 4){
               search(user, &person);
          }
          else if (input == 3){
               printAll(user, &person);
          }
          else if (input == 5){
               return 0;
          }
          else
               printf("\nerror! ReTry! \n\n");
         }

     return 0;
}
//노래의  정보를 삽입하는 함수
void insert(User* ptr, int* num){
     //유저정보가 꽉 차지 않으면
     if (*num < MAX_NUM){
          printf("노래 번호를 입력하세요 :");
          scanf("%s", ptr[*num].number);
		  printf("노래 제목을 입력하세요 :");
          scanf("%s", ptr[*num].name);          
          (*num)++;
          printf("노래가 예약 되었습니다 \n\n");
     }
     //노가 꽉 차면
     else
          printf("예약이 가득 찼습니다 \n\n");
    }
//예약된 노래를 삭제하는 함수 
int deleted(User* ptr, int* num){
     char name[30];
     int i, j;
     if (*num > 0){
          printf("노래 제목: ");
          scanf("%s", name);
          for (i = 0; i < MAX_NUM; i++){
               if (strcmp(name, ptr[i].name) == 0){
                    (*num)--;
                    printf("  예약이 삭제 되었습니다\n");     
                    if (i != MAX_NUM - 1){
                         for (j = i; j < MAX_NUM; j++){
                              strcpy(ptr[j].name, ptr[j + 1].name);
                              strcpy(ptr[j].number, ptr[j + 1].number);
                         }
                     *ptr[MAX_NUM - 1].name = NULL;
                     *ptr[MAX_NUM - 1].number = NULL;
                }
                else{
                     *ptr[MAX_NUM - 1].name = NULL;
                     *ptr[MAX_NUM - 1].number = NULL;
                }
                return 0;
               }
          }
          printf("Not Found \n\n");
          return 0;
}
//저장된 노래가 없다면 
else{
    printf("찾으시는 노래가 없습니다. \n");
    return 0;
	}
}
//노래를  검색하는 함수
int search(User* ptr, int* num){
     char name[30];
     int i;
     //저장된 데이터가 있다면
     if (*num > 0){
          printf("검색할 노래 제목 : ");
          scanf("%s", name);
         for (i = 0; i < MAX_NUM; i++){
               if (!strcmp(name, ptr[i].name)){
                    printf("\n노래 제목  : %s \n", ptr[i].name);
                    printf("노래 번호  : %s \n", ptr[i].number);
                    printf("검색에 성공 했습니다!\n");
                    return 0;
               }
          }
          printf("검색에 실패 했습니다!\n");
          return 0;
     }
     else{
          printf("찾으시는 노래가 없습니다 \n");
          return 0;
     }
}
//저장된 모든 노래와 번호를 출력하는 함수  
void printAll(User* ptr, int* num){
     int i = 0;
     if (*num > 0){
          for (i = 0; i < *num; i++){
               printf("노래 제목  : %s ", ptr[i].name);
               printf("노래 번호  : %s \n", ptr[i].number);
          }
     }
     else
          printf("데이터가 없습니다\n\n");
    }
