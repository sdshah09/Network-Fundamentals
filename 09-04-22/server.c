#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>


void handleclient(int confd){
    int n;
    char buf[200];
    n=read(confd,buf,200);
    buf[n]='\0';
    printf("data rec'd from client = %s\n",buf);
    printf("requested handled by server ^%d\n",getpid());
    exit(0);
}
int main(){
    int listfd,connfd,retval;
    socklen_t clilen;
    struct sockaddr_in cliaddr,servaddr;

    listfd = socket(AF_INET,SOCK_STREAM,0);
    if(listfd<0){
        perror("sock:");
        exit(1);
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
   // servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_addr.s_addr= htonl(INADDR_ANY);
    servaddr.sin_port = htons(8000);

    retval = bind(listfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    if(retval<0){
        perror("bind:");
        exit(2);
    }
    listen(listfd,5);
    while(1){
        pid_t p;
        clilen = sizeof(cliaddr);
        connfd = accept(listfd,(struct sockaddr *)&cliaddr,&clilen);
        printf("Clien conneected\n");
        p=fork();
        if(p==0){

        close(listfd);
        handleclient(connfd);
        }
        close(connfd);
    }
}

