#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

#include "pi3.h"
//  teste romildo eltera novamente

int ConectaDB(){
	MYSQL conexao;
    MYSQL_RES *resp;
    MYSQL_ROW linhas;
    MYSQL_FIELD *campos;

    mysql_init(&conexao);

    if ( !mysql_real_connect(&conexao, "localhost", "pi3", "as", "pi3", 0, NULL, 0) ){
    	return 0; //Se falhar retorna 0
    }

    return 1; //Se funcionar retorna 1
}

void Cabecalho(){
	
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