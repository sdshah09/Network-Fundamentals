#include <netdb.h>
#include <stdio.h>
#include<limits.h>
#include<unistd.h>
#include <netinet/in.h>
//!local host program
int main(int argc,char *argv[])
{
   char hostname[HOST_NAME_MAX+1];

   hostname[HOST_NAME_MAX]=0;
   if(gethostname(hostname,HOST_NAME_MAX)==0)
    puts(hostname);
   else 
        perror("gethostname");
    return 0;
}