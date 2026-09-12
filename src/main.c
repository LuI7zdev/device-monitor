#include <stdio.h>
#include <sys/utsname.h>

int main(void)
{

    struct utsname buf;
    uname(&buf);

    printf("========== MONITOR DO SISTEMA  ============\n");

    printf("SISTEMA: %s\n", buf.sysname);
    printf("DISTRIBUIÇÃO: %s\n", buf.nodename);
    printf("RELEASE: %s\n", buf.release);
    printf("VERSÃO: %s\n", buf.version);
    printf("ARQUITETURA: %s\n", buf.machine);

    FILE *arquivo;
    char nome[50];
    long valor;
    char unidade[10];

    long memoria_total = 0;
    long memoria_disponivel = 0;

    arquivo = fopen("/proc/meminfo", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao acessar informações de memória.\n");
        return 1;
    }

    while (fscanf(arquivo, "%49s %ld %9s", nome, &valor, unidade) == 3)
    {

        if (strcmp(nome, "MemTotal:") == 0)
        {
            memoria_total = valor;
        }

        if (strcmp(nome, "MemAvailable:") == 0)
        {
            memoria_disponivel = valor;
        }
    }

    fclose(arquivo);

    double total_gb = memoria_total / 1024.0 / 1024.0;
    double disponivel_gb = memoria_disponivel / 1024.0 / 1024.0;
    double usada_gb = total_gb - disponivel_gb;

    printf("\nMemoria RAM\n");
    printf("Total: %.2f GB\n", total_gb);
    printf("Usada: %.2f GB\n", usada_gb);
    printf("Disponivel: %.2f GB\n", disponivel_gb);

    printf("=======================================\n");
}
