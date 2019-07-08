#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>


void  CABECALHO_1(); //cabecalho

void  CABECALHO_2(); //cabecalho

typedef struct TipoFuncionario{
	char Nome[100];
	float Descontos;
	char Telefone[15];// tel
	char Endereco[200];
	char Bairro[30];
	char Cidade[30];
	char UF[3];
} TipoFuncionario;

void ConectaDB(MYSQL conexao);

void Cabecalho(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos);

void MenuPrincipal();

void InserirFuncionario(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos);

void CadastrarCartaoPonto();

void GerarEspelho();

void GerarHolerite();

void ExibirFuncionario();

void ExibirEspelho();

void ExibirHolerite();