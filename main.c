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
    if ( !mysql_real_connect(&conexao, "localhost", "root", "123456", "pi3", 0, NULL, 0) ){
        // Se não estabelecer conexão segue aqui!!!
        printf("Conexão com o banco de dados falhou...\n");
        //Teste alteração 2
        mysql_close(&conexao);
        return 0;
    }else{
        
        int Op;

        //Cabecalho(conexao, resp, linhas, campos);

        MenuPrincipal();
        scanf("%i", &Op);
        setbuf(stdin,NULL);

            printf("\n%d\n", Op);

        switch(Op){
            case 1:
                //Cabecalho(conexao, resp, linhas, campos);
                InserirFuncionario(conexao, resp, linhas, campos);

            break;
            case 2:

            break;
            case 3:

            break;
            case 4:

            break;
            default:
                printf("Opcao invalida...\n");
            break;
        }

    }

	return 0;

}