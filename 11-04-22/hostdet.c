#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>

main()
{
    struct hostent *he = NULL;
    char dotaddr[20];
    he = gethostbyname("196.12.100.100");
    inet_ntop(AF_INET, he->h_addr, dotaddr, 20);
    printf("Address in dd notation=%s\n", dotaddr);
}