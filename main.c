#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

#include "pi3.h"

int main(int argc, char const *argv[]){
	//Início do desenvolvimento do projeto!!!
	//Conexão com o DB...
	MYSQL conexao;
    MYSQL_RES *resp;
    MYSQL_ROW linhas;
    MYSQL_FIELD *campos;

    mysql_init(&conexao);

    if ( !mysql_real_connect(&conexao, "localhost", "root", "123456*", "pi3", 0, NULL, 0) ){
    	// Se não estabelecer conexão segue aqui!!!
		printf("\nFalha na conexão com o Banco de Dados...\n");
    }else{
    	// Se estabelecer conexão, segue o programa...
    	Cabecalho(conexao, resp, linhas, campos); //Chamando a função Cabecalho passando os parametros de conexão...










	}

	return 0;

}