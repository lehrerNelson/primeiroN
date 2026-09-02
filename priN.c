#include <stdio.h>
#include <string.h>

int main(void)
{
	char nomeArquivo[100];

	printf("Digite o nome do arquivo: ");
	if (fgets(nomeArquivo, sizeof(nomeArquivo), stdin) == NULL)
	{
		return 1;
	}

	nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';
	FILE *arquivo = fopen(nomeArquivo, "w");

	if (arquivo == NULL)
	{
		perror("Nao foi possivel abrir o arquivo");
		return 1;
	}

	fclose(arquivo);
	return 0;
}
//https://github.com/lehrerNelson/primeiroN.git