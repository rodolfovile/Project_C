#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "usuarios.bin"


struct Usuario {
  int codigo;
  char nome[50];
  char login[15];
  char senha[15];
  int idade;
  char sexo;
  char telefone[17];
  int flag;
};

void inserirUsuario (char *arquivo) {
  system("cls");
  struct Usuario user;

  FILE *arq;
  if (!(arq = fopen(arquivo, "ab"))) { /*a+b adiciona o arquivo de forma binaria*/
    printf("Erro ao tentar abrir arquivo\n");
    return;
  }
  printf("Digite o nome do Usuario:  \n");
  fflush(stdin);
  fgets(user.nome,sizeof(user.nome), stdin);

  printf("Digite o codigo do Usuario:  \n");
  fflush(stdin);
  scanf("%d",&user.codigo);

  printf("informe o login do usuario:  \n");
  fflush(stdin);
  fgets(user.login,sizeof(user.login), stdin);

  printf("Digite a senha para seu usario\n");
  fflush(stdin);
  fgets(user.senha,sizeof(user.senha), stdin);

  printf("informe sua idade\n");
  fflush(stdin);
  scanf("%d",&user.idade);

  printf("informe seu sexo");
  fflush(stdin);
  user.sexo = toupper(getchar());

  printf("informe seu telefone\n");
  fflush(stdin);
  fgets(user.telefone,sizeof(user.telefone), stdin);

  user.flag = 1;

  system("cls");

  if (fwrite(&user, sizeof(struct Usuario), 1, arq) != 1) {
    printf("Erro ao gravar arquivo\n");
  }

  if (fclose(arq)) {
    printf("Erro ao tentar fechar arquivo\n");
  }
  
}/*end void void*/
