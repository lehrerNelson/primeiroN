#include <stdio.h>

int main(void)
{
	FILE *arquivo = fopen("arquivo.txt", "w");

	if (arquivo == NULL)
	{
		perror("Nao foi possivel abrir o arquivo");
		return 1;
	}

	fclose(arquivo);
	return 0;
}
//https://github.com/lehrerNelson/primeiroN.git