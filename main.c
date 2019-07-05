#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#include "pi3.h"

int main(int argc, char const *argv[]){
	//Início do desenvolvimento do projeto!!!
	//Conexão com o D  
	MYSQL conexao;
    MYSQL_RES *resp;
    MYSQL_ROW linhas;
    MYSQL_FIELD *campos;

    mysql_init(&conexao);
    if ( !mysql_real_connect(&conexao, "localhost", "root", "Rjalves2011*", "teste1", 0, NULL, 0) ){
        // Se não estabelecer conexão segue aqui!!!
        printf("Conexão com o banco de dados falhou...\n");
        return 0;
    }else{
        //Inclusão do Cabeçalho
        Cabecalho(conexao, resp, linhas, campos);

        //Inclusão do menu
        MenuPrincipal(conexao, resp, linhas, campos);






    }

	return 0;

}