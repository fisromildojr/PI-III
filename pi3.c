#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#include "pi3.h"

void Cabecalho(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos){
    int QtdResult; //Para armazenar o resultado da consulta...
    char sql[250]; //Para armazenar a string no comando sql...
	strcpy(sql, "select usuario.id as 'ID', usuario.nome as 'Nome' from usuario;"); //Copiando a string do comando para a variável sql...
    mysql_query(&conexao,sql); //Estabelecendo a conexão e executando a consulta armazenada na variável sql...
    resp = mysql_store_result(&conexao); //Pegando o tipo de retorno do banco de dados e guardando na variável resp
    QtdResult = mysql_num_rows(resp); //Pegando a qtd de registros retornados na consulta e armazenando na Variável QtdResult
    printf("%d\n", QtdResult); //Exibindo na tela a quantidade...
}

void InserirFuncionario(){

}

void CadastrarCartaoPonto(){

}

void GerarEspelho(){

}

void GerarHolerite(){

}

void ExibirFuncionario(){

}

void ExibirEspelho(){

}

void ExibirHolerite(){

}