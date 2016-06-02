#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "usuarios.bin"
#define ARQUIVO2 "categorias.bin"
#define ARQUIVO3 "produtos.bin"
#define ARQUIVO4 "avaliacoes.bin"

// Structs
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

struct Categoria {
	int codigo;
	char nome[50];
	int flag;
};

struct Produto {
	int codigo;
	char titulo[100]; // Texto que fica destacado em um e-comm
	char descricao[256];
	int categoria; // codigo da categoria que esta no arquivo cateorias.bin
	int preco; // valor com 2 casas decimais
	int flag;
};

struct Avaliacao {
	int codigoUsuario;
	int codigoProduto;
	int nota;
};

// Busca usuario (c = pelo codigo)
int busca(char *arquivo, char nome[]) {
	struct Usuario u;
	int i = 0;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Erro ao ler arquivo. \n");
		return;
	}

	fseek(arq, 0, SEEK_SET);
	fread(&u, sizeof(struct Usuario), 1, arq);
	while (!feof(arq)) {
		if (u.flag == 1 && (((strcmp(u.nome, nome) == 0) || (strcmp(u.login, nome) == 0)))) {
			fclose(arq);
			return i;
		}
		else
			i++;

		fread(&u, sizeof(struct Usuario), 1, arq);
	}

	fclose(arq);

	return -1;

}

int buscaC(char *arquivo, int codigo) {
	struct Usuario u;
	int i = 0;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Erro ao ler arquivo. \n");
		return;
	}

	fseek(arq, 0, SEEK_SET);
	fread(&u, sizeof(struct Usuario), 1, arq);
	while (!feof(arq)) {
		if (u.flag == 1 && u.codigo == codigo) {
			fclose(arq);
			return i;
		}
		else
			i++;

		fread(&u, sizeof(struct Usuario), 1, arq);
	}

	fclose(arq);

	return -1;
}

int buscaSenha(char *arquivo, char senha[]) {
	struct Usuario u;
	int i = 0;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Erro ao ler arquivo. \n");
		return;
	}

	fseek(arq, 0, SEEK_SET);
	fread(&u, sizeof(struct Usuario), 1, arq);
	while (!feof(arq)) {
		if (u.flag == 1 && ((strcmp(u.senha, senha) == 0))) {
			fclose(arq);
			return i;
		}
		else
			i++;

		fread(&u, sizeof(struct Usuario), 1, arq);
	}

	fclose(arq);

	return -1;

}

// retorna o codigo do login
int buscaUsuario(char *arquivo, char usuario[]) {
	struct Usuario u;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Erro ao ler arquivo. \n");
		return;
	}

	fseek(arq, 0, SEEK_SET);
	fread(&u, sizeof(struct Usuario), 1, arq);
	while (!feof(arq)) {
		if (u.flag == 1 && ((strcmp(u.login, usuario) == 0))) {
			fclose(arq);
			return u.codigo;
		}

		fread(&u, sizeof(struct Usuario), 1, arq);
	}

	fclose(arq);

}

// Busca categoria (c = pelo codigo)
int busca2(char *arquivo, char nome[]){
	struct Categoria c;
	int i = 0;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Erro ao ler arquivo. \n");
		return;
	}

	fseek(arq, 0, SEEK_SET);
	fread(&c, sizeof(struct Categoria), 1, arq);
	while (!feof(arq)) {
		if (c.flag == 1 && (strcmp(c.nome, nome) == 0)) {
			fclose(arq);
			return i;
		}
		else
			i++;

			fread(&c, sizeof(struct Categoria), 1, arq);
	}

	fclose(arq);

	return -1;

}

int busca2C(char *arquivo, int codigo) {
	struct Categoria c;
	int i = 0;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Erro ao ler arquivo. \n");
		return;
	}

	fseek(arq, 0, SEEK_SET);
	fread(&c, sizeof(struct Categoria), 1, arq);
	while (!feof(arq)) {
		if (c.flag == 1 && c.codigo == codigo) {
			fclose(arq);
			return i;
		}
		else
			i++;

		fread(&c, sizeof(struct Categoria), 1, arq);
	}

	fclose(arq);

	return -1;

}

// Busca produto (c = pelo codigo)
int busca3(char *arquivo, char nome[]) {
	struct Produto p;
	int i = 0;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Erro ao ler arquivo. \n");
		return;
	}

	fseek(arq, 0, SEEK_SET);
	fread(&p, sizeof(struct Produto), 1, arq);
	while (!feof(arq)) {
		if (p.flag == 1 && (strcmp(p.titulo, nome) == 0)) {
			fclose(arq);
			return i;
		}
		else
			i++;

		fread(&p, sizeof(struct Produto), 1, arq);
	}

	fclose(arq);

	return -1;

}

int busca3C(char *arquivo, int codigo) {
	struct Produto p;
	int i = 0;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Erro ao ler arquivo. \n");
		return;
	}

	fseek(arq, 0, SEEK_SET);
	fread(&p, sizeof(struct Produto), 1, arq);
	while (!feof(arq)) {
		if (p.flag == 1 && p.codigo == codigo) {
			fclose(arq);
			return i;
		}
		else
			i++;

		fread(&p, sizeof(struct Produto), 1, arq);
	}

	fclose(arq);

	return -1;

}

// retorna o codigo do titulo
int buscaTitulo(char *arquivo, char titulo[]) {
	struct Produto p;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Erro ao ler arquivo. \n");
		return;
	}

	fseek(arq, 0, SEEK_SET);
	fread(&p, sizeof(struct Produto), 1, arq);
	while (!feof(arq)) {
		if (p.flag == 1 && (strcmp(p.titulo, titulo) == 0)) {
			fclose(arq);
			return p.codigo;
		}

		fread(&p, sizeof(struct Produto), 1, arq);
	}

	fclose(arq);

}

// Usuario (c = pelo codigo)
void inserirUsuario(char *arquivo) {
	system("cls");
	struct Usuario u;

	FILE *arq;
	if (!(arq = fopen(arquivo, "ab"))) {
		printf("Erro ao tentar abrir arquivo. \n");
		return;
	}

	printf("Informe seu nome: \n");
	fflush(stdin);
	fgets(u.nome, sizeof(u.nome), stdin);
	printf("Informe seu codigo: \n");
	fflush(stdin);
	scanf("%d", &u.codigo);
	printf("Informe seu login: \n");
	fflush(stdin);
	fgets(u.login, sizeof(u.login), stdin);
	printf("Informe sua senha: \n");
	fflush(stdin);
	fgets(u.senha, sizeof(u.senha), stdin);
	printf("Informe sua idade: \n");
	fflush(stdin);
	scanf("%d", &u.idade);
	printf("Informe seu sexo: M/F \n");
	fflush(stdin);
	u.sexo = toupper(getchar());
	printf("Informe seu telefone: \n");
	fflush(stdin);
	fgets(u.telefone, sizeof(u.telefone), stdin);
	u.flag = 1;
	system("cls");

	if (fwrite(&u, sizeof(struct Usuario), 1, arq) != 1) {
		printf("Erro ao gravar. \n");
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

void removerUsuario(char *arquivo, char nome[]) {
	struct Usuario u;
	int chave = busca(arquivo, nome);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}

	if (chave == -1) {
		printf("O usuario/Login n existe. \n");
	}
	else {
		fseek(arq, chave*sizeof(struct Usuario), SEEK_SET);
		fread(&u, sizeof(struct Usuario), 1, arq);
		printf("A pessoa de nome/login: %s sera deletada. \n", nome);
		u.flag = 0;
		fseek(arq, chave*sizeof(struct Usuario), SEEK_SET);
		if (fwrite(&u, sizeof(struct Usuario), 1, arq) != 1) {
			printf("Erro ao deletar. \n");
		}
		else
			printf("Deletado com sucesso. \n");

	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}

}

void removerUsuarioC(char *arquivo, int codigo) {
	struct Usuario u;
	int chave = buscaC(arquivo, codigo);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}

	if (chave == -1) {
		printf("O codigo n existe. \n");
	}
	else {
		fseek(arq, chave*sizeof(struct Usuario), SEEK_SET);
		fread(&u, sizeof(struct Usuario), 1, arq);
		printf("A pessoa de codigo: %d sera deletada. \n", u.codigo);
		u.flag = 0;
		fseek(arq, chave*sizeof(struct Usuario), SEEK_SET);
		if (fwrite(&u, sizeof(struct Usuario), 1, arq) != 1) {
			printf("Erro ao deletar. \n");
		}
		else
			printf("Deletado com sucesso. \n");

	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}
}

void alterarUsuario(char *arquivo, char nome[]) {
	struct Usuario u;
	int chave = busca(arquivo, nome);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}
	if (chave == -1) {
		printf("O usuario/login n existe. \n");
	}
	else {
		fseek(arq, chave*sizeof(struct Usuario), SEEK_SET);
		fread(&u, sizeof(struct Usuario), 1, arq);
		system("cls");
		printf("Digite o novo nome para: %s \n", u.nome);
		fflush(stdin);
		fgets(u.nome, sizeof(u.nome), stdin);
		printf("Digite o novo login: \n");
		fflush(stdin);
		fgets(u.login, sizeof(u.login), stdin);
		printf("Digite a nova senha: \n");
		fflush(stdin);
		fgets(u.senha, sizeof(u.senha), stdin);
		printf("Digite a nova idade: \n");
		fflush(stdin);
		scanf("%d", &u.idade);
		printf("Digite seu novo sexo: M/F \n");
		fflush(stdin);
		u.sexo = toupper(getchar());
		printf("Digite seu novo telefone: \n");
		fflush(stdin);
		fgets(u.telefone, sizeof(u.telefone), stdin);
		u.flag = 1;
		fseek(arq, chave*sizeof(struct Usuario), SEEK_SET);
		if (fwrite(&u, sizeof(struct Usuario), 1, arq) != 1) {
			printf("Erro ao alterar. \n");
		}
		else
			printf("Alterado com sucesso. \n");

	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}

}

void alterarUsuarioC(char *arquivo, int codigo) {
	struct Usuario u;
	int chave = buscaC(arquivo, codigo);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}
	if (chave == -1) {
		printf("O codigo n existe. \n");
	}
	else {
		system("cls");
		fseek(arq, chave*sizeof(struct Usuario), SEEK_SET);
		fread(&u, sizeof(struct Usuario), 1, arq);
		printf("Digite o novo nome para: %s \n", u.nome);
		fflush(stdin);
		fgets(u.nome, sizeof(u.nome), stdin);
		printf("Digite o novo login: \n");
		fflush(stdin);
		fgets(u.login, sizeof(u.login), stdin);
		printf("Digite a nova senha: \n");
		fflush(stdin);
		fgets(u.senha, sizeof(u.senha), stdin);
		printf("Digite a nova idade: \n");
		fflush(stdin);
		scanf("%d", &u.idade);
		printf("Digite seu novo sexo: M/F \n");
		fflush(stdin);
		u.sexo = toupper(getchar());
		printf("Digite seu novo telefone: \n");
		fflush(stdin);
		fgets(u.telefone, sizeof(u.telefone), stdin);
		u.flag = 1;
		fseek(arq, chave*sizeof(struct Usuario), SEEK_SET);
		if (fwrite(&u, sizeof(struct Usuario), 1, arq) != 1) {
			printf("Erro ao alterar. \n");
		}
		else
			printf("Alterado com sucesso. \n");

	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}

}

void listarUsuarios(char *arquivo) {
	system("cls");
	struct Usuario u;

	FILE *arq;

	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Nao existem usuarios cadastrados. \n");
		return;
	}

	printf("LISTA \n");
	printf("------------------------- \n");
	fread(&u, sizeof(struct Usuario), 1, arq);
	while (!feof(arq)) {
		if (u.flag == 1) {
			printf("Codigo: %d \n", u.codigo);
			printf("Nome: %s \n", u.nome);
			printf("Login: %s \n", u.login);
			printf("Senha: %s \n", u.senha);
			printf("Idade: %d \n", u.idade);
			printf("Sexo: %c \n", u.sexo);
			printf("Telefone: %s \n", u.telefone);
			printf("------------------------- \n");
		}
		fread(&u, sizeof(struct Usuario), 1, arq);
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

void retornaTituloNota(char *arquivo, int codigo, int nota) {
	struct Produto p;

	FILE *arq3;
	if (!(arq3 = fopen(arquivo, "rb"))) {
		printf("N existem produtos cadastrados. \n");
		return;
	}

	fread(&p, sizeof(struct Produto), 1, arq3);
	while (!feof(arq3)) {
		if (p.codigo == codigo) {
			printf("-------------------- \n");
			printf("O Produto de titulo: %s teve avaliacao de nota: %d \n", p.titulo, nota);
			printf("-------------------- \n");
		}
		fread(&p, sizeof(struct Produto), 1, arq3);
	}

	if (fclose(arq3)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

void consultarAvaliacao(char *arquivo, int codigo) {
	struct Avaliacao a;
	
	FILE *arq2;
	if (!(arq2 = fopen(arquivo, "rb"))) {
		printf("N existem avaliacoes. \n");
		return;
	}

	fread(&a, sizeof(struct Avaliacao), 1, arq2);
	while (!feof(arq2)) {
		if (a.codigoUsuario == codigo) {
			retornaTituloNota(ARQUIVO3, a.codigoProduto, a.nota);
		}
		fread(&a, sizeof(struct Avaliacao), 1, arq2);
	}
	if (fclose(arq2)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}
}

void consultarUsuario(char *arquivo, char nome[]) {
	system("cls");
	struct Usuario u;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("N existem usuarios cadastrados. \n");
		return;
	}

	fread(&u, sizeof(struct Usuario), 1, arq);
	while (!feof(arq)) {
		if (u.flag == 1 && ((strcmp(u.nome, nome) == 0) || (strcmp(u.login, nome) == 0) || (strcmp(u.telefone, nome) == 0))) {
			printf("Codigo: %d \n", u.codigo);
			printf("Nome: %s \n", u.nome);
			printf("Login: %s \n", u.login);
			printf("Senha: %s \n", u.senha);
			printf("Idade: %d \n", u.idade);
			printf("Sexo: %c \n", u.sexo);
			printf("Telefone: %s \n", u.telefone);
			consultarAvaliacao(ARQUIVO4, u.codigo);
		}
		fread(&u, sizeof(struct Usuario), 1, arq);
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

// Categoria (c = pelo codigo)
void inserirCategoria(char *arquivo) {
	system("cls");
	struct Categoria c;

	FILE *arq;
	if (!(arq = fopen(arquivo, "ab"))) {
		printf("Erro ao tentar abrir arquivo. \n");
		return;
	}

	printf("Informe o codigo da categoria: \n");
	fflush(stdin);
	scanf("%d", &c.codigo);
	printf("Informe o nome da categoria: \n");
	fflush(stdin);
	fgets(c.nome, sizeof(c.nome), stdin);
	c.flag = 1;

	if (fwrite(&c, sizeof(struct Categoria), 1, arq) != 1) {
		printf("Erro ao gravar. \n");
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

void removerCategoria(char *arquivo, char nome[]) {
	struct Categoria c;
	int chave = busca2(arquivo, nome);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}

	if (chave == -1) {
		printf("O nome n existe. \n");
	}
	else {
		fseek(arq, chave*sizeof(struct Categoria), SEEK_SET);
		fread(&c, sizeof(struct Categoria), 1, arq);
		printf("A categoria de nome: %s sera deletada. \n", nome);
		c.flag = 0;
		fseek(arq, chave*sizeof(struct Categoria), SEEK_SET);
		if (fwrite(&c, sizeof(struct Categoria), 1, arq) != 1) {
			printf("Erro ao deletar. \n");
		}
		else
			printf("Deletado com sucesso. \n");

	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}

}

void removerCategoriaC(char *arquivo, int codigo) {
	struct Categoria c;
	int chave = busca2C(arquivo, codigo);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}

	if (chave == -1) {
		printf("O codigo n existe. \n");
	}
	else {
		fseek(arq, sizeof(struct Categoria), SEEK_SET);
		fread(&c, sizeof(struct Categoria), 1, arq);
		printf("A categoria de codigo: %d sera deletada. \n", c.codigo);
		c.flag = 0;
		fseek(arq, sizeof(struct Categoria), SEEK_SET);
		if (fwrite(&c, sizeof(struct Usuario), 1, arq) != 1) {
			printf("Erro ao deletar. \n");
		}
		else
			printf("Deletado com sucesso. \n");

	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}

}

void alterarCategoria(char *arquivo, char nome[]) {
	struct Categoria c;
	int chave = busca2(arquivo, nome);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}

	if (chave == -1) {
		printf("A categoria n existe. \n");
	}
	else {
		fseek(arq, chave*sizeof(struct Categoria), SEEK_SET);
		fread(&c, sizeof(struct Categoria), 1, arq);
		system("cls");
		printf("Digite o novo nome para: %s \n", c.nome);
		fflush(stdin);
		fgets(c.nome, sizeof(c.nome), stdin);
		c.flag = 1;
		fseek(arq, chave*sizeof(struct Categoria), SEEK_SET);
		if (fwrite(&c, sizeof(struct Categoria), 1, arq) != 1) {
			printf("Erro ao alterar. \n");
		}
		else
			printf("Alterado com sucesso. \n");

	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}

}

void alterarCategoriaC(char *arquivo, int codigo) {
	struct Categoria c;
	int chave = busca2C(arquivo, codigo);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}
	if (chave == -1) {
		printf("O codigo n existe. \n");
	}
	else {
		system("cls");
		fseek(arq, chave*sizeof(struct Categoria), SEEK_SET);
		fread(&c, sizeof(struct Categoria), 1, arq);
		printf("Digite o novo nome para: %s \n", c.nome);
		fflush(stdin);
		fgets(c.nome, sizeof(c.nome), stdin);
		c.flag = 1;
		fseek(arq, chave*sizeof(struct Categoria), SEEK_SET);
		if (fwrite(&c, sizeof(struct Categoria), 1, arq) != 1) {
			printf("Erro ao alterar. \n");
		}
		else
			printf("Alterado com sucesso. \n");
	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}

}

void listarCategorias(char *arquivo) {
	system("cls");
	struct Categoria c;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Nao existem categorias cadastradas. \n");
		return;
	}

	printf("LISTA \n");
	printf("------------------------- \n");
	fread(&c, sizeof(struct Categoria), 1, arq);
	while (!feof(arq)) {
		if (c.flag == 1) {
			printf("Codigo: %d \n", c.codigo);
			printf("Nome: %s \n", c.nome);
			printf("------------------------- \n");
		}
		fread(&c, sizeof(struct Categoria), 1, arq);
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

void consultarCategoria(char *arquivo, char nome[]) {
	system("cls");
	struct Categoria c;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("N existem categorias cadastradas. \n");
		return;
	}

	fread(&c, sizeof(struct Categoria), 1, arq);
	while (!feof(arq)) {
		if (c.flag == 1 && ((strcmp(c.nome, nome) == 0))) {
			printf("Codigo: %d \n", c.codigo);
			printf("Nome: %s \n", c.nome);
		}
		fread(&c, sizeof(struct Categoria), 1, arq);
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

void consultarCategoriaC(char *arquivo, int codigo) {
	system("cls");
	struct Categoria c;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("N existem categorias cadastradas. \n");
		return;
	}

	fread(&c, sizeof(struct Categoria), 1, arq);
	while (!feof(arq)) {
		if (c.flag == 1 && c.codigo == codigo) {
			printf("Codigo: %d \n", c.codigo);
			printf("Nome: %s \n", c.nome);
		}
		fread(&c, sizeof(struct Categoria), 1, arq);
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

// Produto (c = pelo codigo)
void inserirProduto(char *arquivo) {
	system("cls");
	struct Produto p;

	FILE *arq;
	if (!(arq = fopen(arquivo, "ab"))) {
		printf("Erro ao tentar abrir arquivo. \n");
		return;
	}

	printf("Informe o codigo do produto: \n");
	fflush(stdin);
	scanf("%d", &p.codigo);
	printf("Informe o titulo do produto: \n");
	fflush(stdin);
	fgets(p.titulo, sizeof(p.titulo), stdin);
	printf("Informe a descricao do produto: \n");
	fflush(stdin);
	fgets(p.descricao, sizeof(p.descricao), stdin);
	do {
		listarCategorias(ARQUIVO2);
		printf("Informe a categoria do produto pelo codigo: \n");
		printf("Digite: \n");
		fflush(stdin);
		scanf("%d", &p.categoria);
	} while (busca2C(ARQUIVO2, p.categoria) == -1);
	printf("Digite o preco do produto: \n");
	fflush(stdin);
	scanf("%d", &p.preco);
	p.flag = 1;

	if (fwrite(&p, sizeof(struct Produto), 1, arq) != 1) {
		printf("Erro ao gravar. \n");
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

void removerProduto(char *arquivo, char nome[]) {
	struct Produto p;

	int chave = busca3(arquivo, nome);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}

	if (chave == -1) {
		printf("N existe produto com esse titulo. \n");
	}
	else {
		fseek(arq, chave*sizeof(struct Produto), SEEK_SET);
		fread(&p, sizeof(struct Produto), 1, arq);
		printf("O produto com o titulo de: %s sera deletado. \n", nome);
		p.flag = 0;
		fseek(arq, chave*sizeof(struct Produto), SEEK_SET);
		if (fwrite(&p, sizeof(struct Produto), 1, arq) != 1) {
			printf("Erro ao deletar. \n");
		}
		else
			printf("Deletado com sucesso. \n");

	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}

}

void removerProdutoC(char *arquivo, int codigo) {
	struct Produto p;
	int chave = busca3C(arquivo, codigo);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}

	if (chave == -1) {
		printf("O codigo n existe. \n");
	}
	else {
		fseek(arq, sizeof(struct Produto), SEEK_SET);
		fread(&p, sizeof(struct Produto), 1, arq);
		printf("O produto de codigo: %d sera deletada. \n", codigo);
		p.flag = 0;
		fseek(arq, sizeof(struct Produto), SEEK_SET);
		if (fwrite(&p, sizeof(struct Produto), 1, arq) != 1) {
			printf("Erro ao deletar. \n");
		}
		else
			printf("Deletado com sucesso. \n");

	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}

}

void alterarProduto(char *arquivo, char nome[]) {
	struct Produto p;
	int chave = busca3(arquivo, nome);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}

	if (chave == -1) {
		printf("O Produto n existe. \n");
	}
	else {
		fseek(arq, chave*sizeof(struct Produto), SEEK_SET);
		fread(&p, sizeof(struct Produto), 1, arq);
		system("cls");
		printf("Digite o novo titulo para: %s \n", p.titulo);
		fflush(stdin);
		fgets(p.titulo, sizeof(p.titulo), stdin);
		printf("Digite uma nova descricao: \n");
		fflush(stdin);
		fgets(p.descricao, sizeof(p.descricao), stdin);
		do {
			listarCategorias(ARQUIVO2);
			printf("Digite uma nova categoria: \n");
			printf("Digite: \n");
			fflush(stdin);
			scanf("%d", &p.categoria);
		} while (busca2C(ARQUIVO2, p.categoria) == -1);
		printf("Digite um novo preco: \n");
		scanf("%d", &p.preco);
		p.flag = 1;
		fseek(arq, chave*sizeof(struct Produto), SEEK_SET);
		if (fwrite(&p, sizeof(struct Produto), 1, arq) != 1) {
			printf("Erro ao alterar. \n");
		}
		else
			printf("Alterado com sucesso. \n");

	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}


}

void alterarProdutoC(char *arquivo, int codigo) {
	struct Produto p;
	int chave = busca3C(arquivo, codigo);

	FILE *arq;
	if (!(arq = fopen(arquivo, "r+b"))) {
		printf("Erro ao abrir arquivo. \n");
		return;
	}
	if (chave == -1) {
		printf("O codigo n existe. \n");
	}
	else {
		system("cls");
		fseek(arq, chave*sizeof(struct Produto), SEEK_SET);
		fread(&p, sizeof(struct Produto), 1, arq);
		printf("Digite um novo titulo para: %s \n", p.titulo);
		fflush(stdin);
		fgets(p.titulo, sizeof(p.titulo), stdin);
		printf("Digite uma nova descricao: \n");
		fflush(stdin);
		fgets(p.descricao, sizeof(p.descricao), stdin);
		do {
			listarCategorias(ARQUIVO2);
			printf("Digite a nova categoria: \n");
			printf("Digite: \n");
			fflush(stdin);
			scanf("%d", &p.categoria);
		} while (busca2C(ARQUIVO2, p.categoria) == -1);
		printf("Digite o novo preco: \n");
		fflush(stdin);
		scanf("%d", &p.preco);
		p.flag = 1;
		fseek(arq, chave*sizeof(struct Produto), SEEK_SET);
		if (fwrite(&p, sizeof(struct Produto), 1, arq) != 1) {
			printf("Erro ao alterar. \n");
		}
		else
			printf("Alterado com sucesso. \n");
	}

	if (fclose(arq)) {
		printf("Erro ao fechar arquivo. \n");
	}

}

// **falta ordenar a lista** 
void listarProdutos(char *arquivo) { 
	system("cls");
	struct Produto p;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("Nao existem produtos cadastrados. \n");
		return;
	}

	printf("LISTA \n");
	printf("------------------------- \n");
	fread(&p, sizeof(struct Produto), 1, arq);
	while (!feof(arq)) {
		if (p.flag == 1) {
			printf("Codigo: %d \n", p.codigo);
			printf("Titulo: %s \n", p.titulo);
			printf("Descricao: %s \n", p.descricao);
			printf("Categoria: %d \n", p.categoria);
			printf("Preco: %d \n", p.preco);
			printf("------------------------- \n");
		}
		fread(&p, sizeof(struct Produto), 1, arq);
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}



} 

void consultarProduto(char *arquivo, char nome[]) {
	system("cls");
	struct Produto p;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("N existem produtos cadastrados. \n");
		return;
	}

	fread(&p, sizeof(struct Produto), 1, arq);
	while (!feof(arq)) {
		if (p.flag == 1 && ((strcmp(p.titulo, nome) == 0) || (strcmp(p.descricao, nome) == 0))) {
			printf("Codigo: %d \n", p.codigo);
			printf("Titulo: %s \n", p.titulo);
			printf("Descricao: %s \n", p.descricao);
			printf("Categoria: %d \n", p.categoria);
			printf("Preco: %d \n", p.preco);
		}
		fread(&p, sizeof(struct Produto), 1, arq);
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

void consultarProdutoC(char *arquivo, int codigo) {
	system("cls");
	struct Produto p;

	FILE *arq;
	if (!(arq = fopen(arquivo, "rb"))) {
		printf("N existem produtos cadastrados. \n");
		return;
	}

	fread(&p, sizeof(struct Produto), 1, arq);
	while (!feof(arq)) {
		if (p.flag == 1 && p.categoria == codigo) {
			printf("Codigo: %d \n", p.codigo);
			printf("Titulo: %s \n", p.titulo);
			printf("Descricao: %s \n", p.descricao);
			printf("Categoria: %d \n", p.categoria);
			printf("Preco: %d \n", p.preco);
		}
		fread(&p, sizeof(struct Produto), 1, arq);
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

// Avaliacao
// **falta perguntar se o usuario quer avaliar mais vezes**
void inserirAvaliacao(char *arquivo) {
	system("cls");
	struct Avaliacao a;
	int op;
	char titulo[100];
	char user[15];
	char pass[15];

	FILE *arq;
	if (!(arq = fopen(arquivo, "ab"))) {
		printf("Erro ao tentar abrir arquivo. \n");
		return;
	}

	do {
		printf("Digite seu Login: \n");
		fflush(stdin);
		fgets(user, sizeof(user), stdin);
	} while (busca(ARQUIVO, user) == -1);
	a.codigoUsuario = buscaUsuario(ARQUIVO, user);

	do {
		printf("Digite sua senha: \n");
		fflush(stdin);
		fgets(pass, sizeof(pass), stdin);
	} while (buscaSenha(ARQUIVO, pass) == -1);

	do {
		printf("Vc deseja avaliar pelo: \n 1 - Codigo. \n 2 - Titulo. \n");
		fflush(stdin);
		scanf("%d", &op);
	} while (op < 1 || op > 2);

	if (op == 1) {
		do {
			listarProdutos(ARQUIVO3);
			printf("Informe o Codigo do produto que deseja avaliar: \n");
			printf("Digite: \n");
			fflush(stdin);
			scanf("%d", &a.codigoProduto);
		} while (busca3C(ARQUIVO3, a.codigoProduto) == -1);

		do {
			printf("Digite sua nota para o produto: \n");
			printf("1 - * \n 2 - ** \n 3 - *** \n 4 - **** \n 5 - ***** \n");
			fflush(stdin);
			scanf("%d", &a.nota);
		} while (a.nota < 1 || a.nota > 5);

	}

	else {
		do {
			printf("Informe o Titulo do produto que deseja avaliar: \n");
			listarProdutos(ARQUIVO3);
			printf("Digite: \n");
			fflush(stdin);
			fgets(titulo, sizeof(titulo), stdin);
		} while (busca3(ARQUIVO3, titulo) == -1);
		a.codigoProduto = buscaTitulo(ARQUIVO3, titulo);

		do {
			printf("Digite sua nota para o produto: \n");
			printf("1 - * \n 2 - ** \n 3 - *** \n 4 - **** \n 5 - ***** \n");
			fflush(stdin);
			scanf("%d", &a.nota);
		} while (a.nota < 1 || a.nota > 5);

	}

	if (fwrite(&a, sizeof(struct Avaliacao), 1, arq) != 1) {
		printf("Erro ao gravar. \n");
	}

	if (fclose(arq)) {
		printf("Erro ao tentar fechar arquivo. \n");
	}

}

// Main
int main() {

	char nome[50], login[15], tel[17];
	int op, remov, codigo;

	do {
		printf("MENU \n");
		printf("1 - Inserir Usuario. \n");
		printf("2 - Remover Usuario. \n");
		printf("3 - Listar Usuarios. \n");
		printf("4 - Altera Usuario. \n");
		printf("5 - Consultar Usuario. \n");
		printf("-------------------------- \n");
		printf("6 - Inserir Categoria. \n");
		printf("7 - Remover Categoria. \n");
		printf("8 - Listar Categorias. \n");
		printf("9 - Altera Categoria. \n");
		printf("10 - Consultar Categoria. \n");
		printf("-------------------------- \n");
		printf("11 - Inserir Produto. \n");
		printf("12 - Remover Produto. \n");
		printf("13 - Listar Produtos. \n");
		printf("14 - Alterar Produto. \n");
		printf("15 - Consultar Produto. \n");
		printf("-------------------------- \n");
		printf("16 - Avaliar Produto. \n");
		printf("-------------------------- \n");
		printf("0 - Sair. \n");
		scanf("%d", &op);
		switch (op) {
			// Usuario
		case 1:
			inserirUsuario(ARQUIVO);
			break;

		case 2:
			system("cls");
			do {
				printf("Vc deseja remover pelo:\n 1 - Codigo. \n 2 - Nome. \n 3 - Login. \n");
				scanf("%d", &remov);
			} while (remov < 1 || remov > 3);

			if (remov == 1) {
				printf("Informe o CODIGO para remover: \n");
				fflush(stdin);
				scanf("%d", &codigo);
				removerUsuarioC(ARQUIVO, codigo);
			}
			else if (remov == 2) {
				printf("Informe o NOME para remover: \n");
				fflush(stdin);
				fgets(nome, sizeof(nome), stdin);
				removerUsuario(ARQUIVO, nome);
			}
			else {
				printf("Informe o LOGIN para remover: \n");
				fflush(stdin);
				fgets(login, sizeof(login), stdin);
				removerUsuario(ARQUIVO, login);
			}
			break;

		case 3:
			listarUsuarios(ARQUIVO);
			break;

		case 4:
			system("cls");
			do {
				printf("Vc deseja alterar pelo: \n 1 - Codigo. \n 2 - Nome. \n 3 - Login. \n");
				scanf("%d", &remov);
			} while (remov < 1 || remov > 3);

			if (remov == 1) {
				printf("Informe o CODIGO para alterar: \n");
				fflush(stdin);
				scanf("%d", &codigo);
				alterarUsuarioC(ARQUIVO, codigo);
			}
			else if (remov == 2) {
				printf("Informe o NOME para alterar: \n");
				fflush(stdin);
				fgets(nome, sizeof(nome), stdin);
				alterarUsuario(ARQUIVO, nome);
			}
			else {
				printf("Informe o LOGIN para alterar: \n");
				fflush(stdin);
				fgets(login, sizeof(login), stdin);
				alterarUsuario(ARQUIVO, login);
			}
			break;

		case 5:
			system("cls");
			do {
				printf("Vc deseja consultar pelo: \n 1 - Telefone. \n 2 - Nome. \n 3 - Login. \n");
				scanf("%d", &remov);
			} while (remov < 1 || remov > 3);

			if (remov == 1) {
				printf("Informe o TELEFONE pata consultar: \n");
				fflush(stdin);
				fgets(tel, sizeof(tel), stdin);
				consultarUsuario(ARQUIVO, tel);
			}
			else if (remov == 2) {
				printf("Informe o NOME para consultar: \n");
				fflush(stdin);
				fgets(nome, sizeof(nome), stdin);
				consultarUsuario(ARQUIVO, nome);
			}
			else {
				printf("Informe o LOGIN para consultar: \n");
				fflush(stdin);
				fgets(login, sizeof(login), stdin);
				consultarUsuario(ARQUIVO, login);
			}
			break;

			// Categoria
		case 6:
			inserirCategoria(ARQUIVO2);
			break;

		case 7:
			system("cls");
			do {
				printf("Vc deseja remover pelo:\n 1 - Codigo. \n 2 - Nome. \n");
				scanf("%d", &remov);
			} while (remov < 1 || remov > 2);

			if (remov == 1) {
				printf("Informe o CODIGO para remover: \n");
				fflush(stdin);
				scanf("%d", &codigo);
				removerCategoriaC(ARQUIVO2, codigo);
			}
			else {
				printf("Informe o NOME para remover: \n");
				fflush(stdin);
				fgets(nome, sizeof(nome), stdin);
				removerCategoria(ARQUIVO2, nome);
			}
			break;

		case 8:
			listarCategorias(ARQUIVO2);
			break;

		case 9:
			system("cls");
			do {
				printf("Vc deseja alterar pelo: \n 1 - Codigo. \n 2 - Nome. \n");
				scanf("%d", &remov);
			} while (remov < 1 || remov > 2);

			if (remov == 1) {
				printf("Informe o CODIGO para alterar: \n");
				fflush(stdin);
				scanf("%d", &codigo);
				alterarCategoriaC(ARQUIVO2, codigo);
			}
			else {
				printf("Informe o NOME para alterar: \n");
				fflush(stdin);
				fgets(nome, sizeof(nome), stdin);
				alterarCategoria(ARQUIVO2, nome);
			}
			break;

		case 10:
			system("cls");
			do {
				printf("Vc deseja consultar pelo: \n 1 - Codigo. \n 2 - Nome. \n");
				scanf("%d", &remov);
			} while (remov < 1 || remov > 2);

			if (remov == 1) {
				printf("Informe o CODIGO pata consultar: \n");
				fflush(stdin);
				scanf("%d", &codigo);
				consultarCategoriaC(ARQUIVO2, codigo);
			}
			else  {
				printf("Informe o NOME para consultar: \n");
				fflush(stdin);
				fgets(nome, sizeof(nome), stdin);
				consultarCategoria(ARQUIVO2, nome);
			}
			break;

			// Produto
		case 11:
			inserirProduto(ARQUIVO3);
			break;

		case 12:
			system("cls");
			do {
				printf("Vc deseja remover pelo:\n 1 - Codigo. \n 2 - Titulo. \n");
				scanf("%d", &remov);
			} while (remov < 1 || remov > 2);

			if (remov == 1) {
				printf("Informe o CODIGO para remover: \n");
				fflush(stdin);
				scanf("%d", &codigo);
				removerProdutoC(ARQUIVO3, codigo);
			}
			else {
				printf("Informe o TITULO para remover: \n");
				fflush(stdin);
				fgets(nome, sizeof(nome), stdin);
				removerProduto(ARQUIVO3, nome);
			}
			break;

		case 13:
			listarProdutos(ARQUIVO3);
			break;

		case 14:
			system("cls");
			do {
				printf("Vc deseja alterar pelo: \n 1 - Codigo. \n 2 - Titulo. \n");
				scanf("%d", &remov);
			} while (remov < 1 || remov > 2);

			if (remov == 1) {
				printf("Informe o CODIGO para alterar: \n");
				fflush(stdin);
				scanf("%d", &codigo);
				alterarProdutoC(ARQUIVO3, codigo);
			}
			else {
				printf("Informe o TITULO para alterar: \n");
				fflush(stdin);
				fgets(nome, sizeof(nome), stdin);
				alterarProduto(ARQUIVO3, nome);
			}
			break;

		case 15:
			system("cls");
			do {
				printf("Vc deseja consultar pela: \n 1 - Categoria. \n 2 - Titulo. \n 3 - Descricao. \n");
				scanf("%d", &remov);
			} while (remov < 1 || remov > 3);

			if (remov == 1) {
				printf("Informe a CATEGORIA pata consultar: \n");
				fflush(stdin);
				scanf("%d", &codigo);
				consultarProdutoC(ARQUIVO3, codigo);
			}
			else  {
				printf("Informe o TITULO/DESCRICAO para consultar: \n");
				fflush(stdin);
				fgets(nome, sizeof(nome), stdin);
				consultarProduto(ARQUIVO3, nome);
			}
			break;

		case 16:
			inserirAvaliacao(ARQUIVO4);
			break;

		default:
			if (op != 0) {
				printf("Opcao invalida. \n");
				system("cls");
			}
		}
	} while (op != 0);

	return 0;
}
