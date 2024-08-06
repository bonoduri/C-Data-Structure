#include <string.h>
#include <stdio.h>
#define buffer_size 100

int main() {
  /*
  char *words[100];
  char buffer[buffer_size];
  int n = 0; // number of strings
  while(n < 4 && scanf("%s", buffer) != EOF)
  {
      words[n] = strdup(buffer);
      n++;
  }
  for(int i = 0 ; i < n ; i++)
    {
      printf("%s \n",words[i]);
    }

  */
  // 프로그램을 실행하면 화면에 프롬프트($)와 한칸의 공백문자를 출력하고 사용자의 입력을 기다린다 
  // 문장과 문장의 길이를 출력한다 
  char buffer[50];
  
  while(1) {
    // 방법1
    //printf("$ ");
    //scanf("%s" , buffer); // %s 로 입력 받는 경우 공백문자를 기준으로 잘라 하나의 단어만 저장된다 
    //printf("%s:%d \n", buffer, strlen(buffer));
    // 방법2
    //printf("$ ");
    //gets(buffer); // 줄바꿈 문자가 나올때까지 입력받아 저장한다
    //printf("%s:%d \n", buffer, strlen(buffer));

    // 방법3
    //printf("$ ");
    //fgets(buffer, 50, stdin); // 줄바꿈 문자까지 저장된다 
    //buffer[strlen(buffer) - 1] = '\0';
    //printf("%s:%d \n", buffer, strlen(buffer));
    // 방법4
    int k;
    printf("$ ");
    k = read_line(buffer,50);
    printf("%s:%d \n", buffer,k);
  }
}

int read_line (char str[] , int limit) {
  int ch, i = 0;

  while((ch = getchar()) != '\n') {
    if (i < limit) {
      str[i++] = ch;
    }
  }

  str[i] = '\0';
  return i;
}