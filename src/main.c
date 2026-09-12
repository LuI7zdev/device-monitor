#include <stdio.h>
#include <sys/utsname.h>

int main(void) {

    struct utsname buf;
    uname(&buf);

    printf("========== MONITOR DO SISTEMA  ============\n");


    printf("SISTEMA: %s\n", buf.sysname);
    printf("DISTRIBUIÇÃO: %s\n", buf.nodename);
    printf("RELEASE: %s\n", buf.release);
    printf("VERSÃO: %s\n", buf.version);
    printf("ARQUITETURA: %s\n", buf.machine);

    printf("=======================================\n");
 
    
}