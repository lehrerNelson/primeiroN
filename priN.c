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
	size_t tamanhoNome = strlen(nomeArquivo);

	if (tamanhoNome < 4 || strcmp(nomeArquivo + tamanhoNome - 4, ".txt") != 0)
	{
		if (tamanhoNome + 4 >= sizeof(nomeArquivo))
		{
			printf("Nome do arquivo muito longo.\n");
			return 1;
		}

		strcat(nomeArquivo, ".txt");
	}

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