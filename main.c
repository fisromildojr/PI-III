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
        int Op, Opc;
        if(Cabecalho(conexao, resp, linhas, campos)){
            do{
                Op=MenuPrincipal();

                switch(Op){
                    case 1:
                        InserirFuncionario(conexao, resp, linhas, campos);
                    break;
                    case 2:
                        ExibirFuncionario(conexao, resp, linhas, campos);
                        printf("\n1 - Voltar\n");
                        scanf("%i", &Opc);
                        setbuf(stdin,NULL);                          
                    break;
                    case 3:
                        LancarHoras(conexao, resp, linhas, campos);
                    break;
                    case 4:
                        
                    break;
                    case 5:
                        return 0;
                    break;
                    default:
                        printf("Opcao invalida...\n");
                    break;
                }
            
            }while(1);

        }else{
            system("exit");
        }
    }

	return 0;

}