#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

typedef struct TipoFuncionario{
	char Nome[100];
	float Descontos;
	char Telefone[15];// tel
	char Endereco[200];
	char Bairro[30];
	char Cidade[30];
	char UF[3];
} TipoFuncionario;

typedef struct TipoControleHoras{
	char TipoDia[2];
	char Data[12];
	char HoraEntrada1[10];
	char HoraSaida1[10];
	char HoraEntrada2[10];
	char HoraSaida2[10];
	char Horas100[10];
	char Horas50[10];
	char AdcNoturno[10];	
	char IdFuncionario[10];
	char IdPeriodo[10];
} TipoControleHoras;

void ConectaDB(MYSQL conexao);

int Cabecalho(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos, int Op);

void MenuPrincipal();

void InserirFuncionario(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos);

void LancarHoras(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos);

void CadastrarCartaoPonto();

void GerarEspelho();

void GerarHolerite();

void ExibirFuncionario(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos);

void ExibirCargo(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos);

void ExibirEspelho();

void ExibirHolerite();

void ExibirPeriodo(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos);