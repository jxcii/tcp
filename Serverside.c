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
    write(connfd, buff, sizeof(buff));
    if(strncmp(buff, "exit", 4)==0){
      printf("Server exit...\n");
      break;
    }
  }
}
int main(){
  int sockfd, connfd, len;
  struct sockaddr_in servaddr, cli;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(socketfd==-1){
    printf("socket creation failed...\n");
    exit(0);
  } else printf("Socket successfully created");
  bzero(&servaddr, sizeof(servaddr));
  //IP, Port 
  servaaddr.sin_family = AF_INET;
  servaaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaaddr.sin_port = htons(PORT);
  if(bind(sockfd, (SA*)&servaaddr, sizeof(servaaddr))!=0){
    printf("socket bind failed\n");
    exit(0);
  } else printf("socket successfully binded\n");
  if(listen(sockfd, 5)!=0){
    printf("socket listen failed...\n");
    exit(0);
  } else prinf("socket successfully listened\n");
  len = sizeof(cli);
  connfd = accept(sockfd, (SA*)&cli, &len);
  if(connfd<0){
    printf("server accept failed\n");
    exit(0);
  }else print("server accept the client...\n");
  func(sockfd);
  close(sockfd);
}
