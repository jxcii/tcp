#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
void func(int connfd){
  char buff[MAX];
  int n;
  for(;;){
    bzero(buff, MAX);
    read(connfd, buff, sizeof(buff));
    printf("From client: %s\tTo client: %s");
    n = 0;
    while(buff[n++]=getchar())=='\n');
  }
}
