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
    if ( !mysql_real_connect(&conexao, "localhost", "userpi3", "pi3_123", "pi3", 0, NULL, 0) ){
        // Se não estabelecer conexão segue aqui!!!
        printf("Conexão com o banco de dados falhou...\n");
        //Teste alteração 2
        mysql_close(&conexao);
        return 0;
    }else{
        int Op;
<<<<<<< HEAD

        //Cabecalho(conexao, resp, linhas, campos);

        int acesso=3;
        CABECALHO_1 (acesso);
        CABECALHO_2 (acesso);
        
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
=======
        if(Cabecalho(conexao, resp, linhas, campos, Op)){

            MenuPrincipal();
            printf("\n--> ");
            scanf("%i", &Op);
            setbuf(stdin,NULL);

            switch(Op){
                case 1:
                    //Cabecalho(conexao, resp, linhas, campos);
                    InserirFuncionario(conexao, resp, linhas, campos);
                break;
                case 2:
                    ExibirFuncionario(conexao, resp, linhas, campos);
                break;
                case 3:
                    LancarHoras(conexao, resp, linhas, campos);
                break;
                case 4:
                    
                break;
                default:
                    printf("Opcao invalida...\n");
                break;
            }
        }else{
            system("exit");
>>>>>>> fb8889817962fd098943aea76bc99bb2e7523343
        }
    }

	return 0;

}