#include <stdio.h>
#include <string.h>

 

//���� ���������� ���� �ϱ����� 100�̶� ���ڸ�
//MAX_NUM���� ����, 100�� 200���� �ٲٸ�
//MAX_NUM�� 200�� ��
#define MAX_NUM 100

 

//������� ������ �����ϴ� ����ü
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
     User user[MAX_NUM]; //����� ������ ������ ����ü �迭
     int person = 0; //����� user��

 

     //�޴� ����
     while(1){
		printf("----------------------------------------------------------------------\n");
		printf("1.�뷡 ���� | 2.�뷡 ���� | 3.���� ��Ȳ | 4.������ �뷡 �˻� | 5.������\n");
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
//�뷡��  ������ �����ϴ� �Լ�
void insert(User* ptr, int* num){
     //���������� �� ���� ������
     if (*num < MAX_NUM){
          printf("�뷡 ��ȣ�� �Է��ϼ��� :");
          scanf("%s", ptr[*num].number);
		  printf("�뷡 ������ �Է��ϼ��� :");
          scanf("%s", ptr[*num].name);          
          (*num)++;
          printf("�뷡�� ���� �Ǿ����ϴ� \n\n");
     }
     //�밡 �� ����
     else
          printf("������ ���� á���ϴ� \n\n");
    }
//����� �뷡�� �����ϴ� �Լ� 
int deleted(User* ptr, int* num){
     char name[30];
     int i, j;
     if (*num > 0){
          printf("�뷡 ����: ");
          scanf("%s", name);
          for (i = 0; i < MAX_NUM; i++){
               if (strcmp(name, ptr[i].name) == 0){
                    (*num)--;
                    printf("  ������ ���� �Ǿ����ϴ�\n");     
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
//����� �뷡�� ���ٸ� 
else{
    printf("ã���ô� �뷡�� �����ϴ�. \n");
    return 0;
	}
}
//�뷡��  �˻��ϴ� �Լ�
int search(User* ptr, int* num){
     char name[30];
     int i;
     //����� �����Ͱ� �ִٸ�
     if (*num > 0){
          printf("�˻��� �뷡 ���� : ");
          scanf("%s", name);
         for (i = 0; i < MAX_NUM; i++){
               if (!strcmp(name, ptr[i].name)){
                    printf("\n�뷡 ����  : %s \n", ptr[i].name);
                    printf("�뷡 ��ȣ  : %s \n", ptr[i].number);
                    printf("�˻��� ���� �߽��ϴ�!\n");
                    return 0;
               }
          }
          printf("�˻��� ���� �߽��ϴ�!\n");
          return 0;
     }
     else{
          printf("ã���ô� �뷡�� �����ϴ� \n");
          return 0;
     }
}
//����� ��� �뷡�� ��ȣ�� ����ϴ� �Լ�  
void printAll(User* ptr, int* num){
     int i = 0;
     if (*num > 0){
          for (i = 0; i < *num; i++){
               printf("�뷡 ����  : %s ", ptr[i].name);
               printf("�뷡 ��ȣ  : %s \n", ptr[i].number);
          }
     }
     else
          printf("�����Ͱ� �����ϴ�\n\n");
    }
