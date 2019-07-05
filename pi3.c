#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#include "pi3.h"

void ConectaDB(MYSQL conexao){
	mysql_init(&conexao);
	if ( !mysql_real_connect(&conexao, "localhost", "root", "Rjalves2011*", "pi3", 0, NULL, 0) ){
    	// Se não estabelecer conexão segue aqui!!!
		return;
    }
}

void Cabecalho(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos){
    char sql[200];
    int Qtd;
    strcpy(sql, "select * from usuario;");
    mysql_query(&conexao, sql);
    resp = mysql_store_result(&conexao);
    linhas=mysql_fetch_row(resp);
    Qtd = mysql_num_rows(resp);
    printf("%d\n",Qtd);
 /*   
    mysql_free_result(resp);
    Qtd = mysql_num_rows(resp);
*/
}

void MenuPrincipal(conexao, resp, linhas, campos){

}

void InserirFuncionario(conexao, resp, linhas, campos){

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