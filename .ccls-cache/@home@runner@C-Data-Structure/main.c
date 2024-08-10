#include <string.h>
#include <stdio.h>
# define size 100

char *name[size];
char *number[size];
int n = 0;

void add();
void find();
void status();
void removes();

int main() {
  char command[size];

  while(1){
    printf("$ ");
    scanf("%s", command);
  // strcmp 두문자열이 동일한 경우 0을 반환한다 
    if(strcmp(command, "add") ==0) 
      add();
    else if (strcmp(command, "find") == 0) 
      find();
    else if (strcmp(command, "status") == 0) 
      status();
    else if (strcmp(command, "remove") == 0) 
      removes();
    //else if (strcmp(command, "exit") == 0)
    //  break;
    
  }
  return 0;
}

void add() {
  char buf1[size], buf2[size];
  scanf("%s", buf1);
  scanf("%s", buf2);
  // strdup 배열을 만들고 매개변수로 받은 하나의 문자열을 거기에 복사하여 반환한다 add 함수가 종료되도 소멸하지 않는다
  name[n] = strdup(buf1);
  number[n] = strdup(buf2);
  n++;

  printf("add success : %s",buf1);
}

void find() {
    char buf1[size];
    scanf("%s", buf1);
    for(int i = 0 ; i < n ; i++)
      {
        if(strcmp(buf1, name[i]) ==0) {
          printf("%s \n",number[i]);
          break;
        }
      }
}

void status() {
  for(int i = 0 ; i < n ; i++) {
    printf("%s : %s \n", name[i], number[i]);
  }
}

void removes() {
  char buf1[size];
  scanf("%s", buf1);

  for(int i = 0 ; i < n ; i++) {
      if(strcmp(buf1,name[i]) ==0) {
        name[i] = name[n-1];
        number[i] = number[n-1];
        n--;
        return;
      }
  }
  printf("can't find : %s \n", buf1);
}

// 전역변수 data section  메모리 영역에 위치
// 지역변수 stack 메모리 영역에 위치
// 동적 메모리 할당 heap 메모리 영역에 위치 명시적으로 free() 함수를 호출해야 반환됨 