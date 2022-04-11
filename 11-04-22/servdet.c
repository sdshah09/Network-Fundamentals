#include<netdb.h>
#include<stdio.h>

//todo TO get all the details of all entries availabe in /etc/services
main(){
    char **names;
    int i;
    struct servent *se = NULL;
    while((se = getservent())!=NULL){
        printf("------------\n");
        printf("Official servicde name = %s\n",se->s_name);
        printf("Port no = %d\n",ntohs(se->s_port));
        printf("Protocol = %s\n",se->s_proto);
        names = se->s_aliases;
        for(i=0;names[i]!=NULL;i++){
            printf("----%s----\n",names[i]);
        }
        printf("-------------------\n");
    }
}