#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#include "pi3.h"

/*
void ConectaDB(MYSQL conexao){
	mysql_init(&conexao);
	if ( !mysql_real_connect(&conexao, "localhost", "root", "123456*", "pi3", 0, NULL, 0) ){
    	// Se não estabelecer conexão segue aqui!!!
		return;
    }
}
*/

int Cabecalho(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos, int Op){
    system("clear");
    printf("\n\n");
    printf("\t     ******  ######  ######     ##   ########   ####### \n");
    printf("\t     ******  ######  ######     ##   ##        ##      #\n");
    printf("\t     ######  ######             ##   ##       ##        \n");
    printf("\t     ######  ######             ##   ######   ##        \n");
    printf("\t     ######  ######  ######     ##   ##       ##        \n");
    printf("\t     ######  ######  ######     ##   ##       ##    ####\n");
    printf("\t     ######  ######             ##   ##        ##     ##\n");
    printf("\t     ######  ######             ##   ##         #######\n");
    printf("\n\n\t   Seja bem vindo ao DESAFIO DO TERCEIRAO << SISTEMA ESPELHO PONTO >> \nAo aceitar  participar voce vera o sistema desenvolvido pelos alunos como\ndesafio para o Terceiro Período de TADS!");
    printf("\n\n\n\t(1)-Aceito\t   Ou precione qualquer tecla para sair...");
    printf("\n\nOpção ==> ");
    __fpurge(stdin);
    scanf("%i", &Op);
    
    if(Op==1)
        return Op;
 
        return 0;
    
}

void MenuPrincipal(){
    system("clear");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx       SISTEMA      xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx  ESPELHO DE PONTO  xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n\n" );
        
    printf("              Digite as opção abaixo para prosseguir no sistema\n\n\n");
    printf("1 - Cadastrar Funcionario\n");  
    printf("2 - Listar Funcionarios Cadastrados\n");
    printf("3 - Lancar Horas Trabalhadas\n");
    printf("4 - Gerar Espelho Ponto\n");
}

void InserirFuncionario(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos){
    TipoFuncionario funcionario;
    int i, Op, IdCargo, IdFuncionario;
    char nomeFuncionario[100],
         telefoneFuncionario[15],
         enderecoFuncionario[200],
         bairroFuncionario[30],
         cidadeFuncionario[30],
         ufFuncionario[3],
         sql[500],
         dtCargo[12],
         StrIdCargo[10],
         StrIdFuncionario[10];
    
    do{
        system("clear");
        printf("<<< CADASTRO DE FUNCIONARIO >>>\n\n");
        printf("Nome: ");
        fgets(nomeFuncionario,100,stdin);
        nomeFuncionario[strlen(nomeFuncionario)-1] = '\0';
        for(i=0;nomeFuncionario[i];i++)
            nomeFuncionario[i]=toupper(nomeFuncionario[i]);
        strcpy(funcionario.Nome, nomeFuncionario);            

        printf("Telefone: ");
        fgets(telefoneFuncionario,15,stdin);
        telefoneFuncionario[strlen(telefoneFuncionario)-1] = '\0';
        strcpy(funcionario.Telefone, telefoneFuncionario);

        printf("Endereco: ");
        fgets(enderecoFuncionario,200,stdin);
        enderecoFuncionario[strlen(enderecoFuncionario)-1] = '\0';
        for(i=0;enderecoFuncionario[i];i++)
            enderecoFuncionario[i]=toupper(enderecoFuncionario[i]);
        strcpy(funcionario.Endereco, enderecoFuncionario);
                    
        printf("Bairro: ");
        fgets(bairroFuncionario,30,stdin);
        bairroFuncionario[strlen(bairroFuncionario)-1] = '\0';
        for(i=0;bairroFuncionario[i];i++)
            bairroFuncionario[i]=toupper(bairroFuncionario[i]);
        strcpy(funcionario.Bairro, bairroFuncionario);

        printf("Cidade: ");
        fgets(cidadeFuncionario,30,stdin);
        cidadeFuncionario[strlen(cidadeFuncionario)-1] = '\0';
        for(i=0;cidadeFuncionario[i];i++)
            cidadeFuncionario[i]=toupper(cidadeFuncionario[i]);
        strcpy(funcionario.Cidade, cidadeFuncionario);

        printf("UF: ");
        fgets(ufFuncionario,3,stdin);
        for(i=0;ufFuncionario[i];i++)
            ufFuncionario[i]=toupper(ufFuncionario[i]);
        strcpy(funcionario.UF, ufFuncionario);

        strcpy(sql, "INSERT INTO funcionario VALUES(null,'");
        strcat(sql, funcionario.Nome);
        strcat(sql, "','");
        strcat(sql, funcionario.Telefone);
        strcat(sql, "','");
        strcat(sql, funcionario.Endereco);
        strcat(sql, "','");
        strcat(sql, funcionario.Bairro);
        strcat(sql, "','");
        strcat(sql, funcionario.Cidade);
        strcat(sql, "','");
        strcat(sql, funcionario.UF);
        strcat(sql, "');");


    //    printf("QUERY: %s\n", sql);
        system("clear");
/*        printf("<<< DADOS DO FUNCIONARIO >>>\n\n");
        printf("\nNOME FUNCIONARIO: %s\n", funcionario.Nome);
        printf("TELEFONE FUNCIONARIO: %s\n", funcionario.Telefone);
        printf("ENDERECO FUNCIONARIO: %s\n", funcionario.Endereco);
        printf("BAIRRO FUNCIONARIO: %s\n", funcionario.Bairro);
        printf("CIDADE FUNCIONARIO: %s\n", funcionario.Cidade);
        printf("UF FUNCIONARIO: %s\n\n", funcionario.UF);

        printf("\n\nPressione qualquer tecla para continuar...\n");
        getchar();
        setbuf(stdin,NULL);
*/
        mysql_query(&conexao, sql);

        if(mysql_affected_rows(&conexao) != 1){
            printf("\nErro: Nao foi possivel cadastrar o funcionario\n\n");
            printf("\nPressione qualquer tecla para continuar...\n");
            setbuf(stdin,NULL);
            getchar();
        }else{

            strcpy(sql, "SELECT MAX(funcionario.id) FROM funcionario;");
            mysql_query(&conexao, sql);

            resp = mysql_store_result(&conexao);
            linhas=mysql_fetch_row(resp);
            IdFuncionario = atoi(linhas[0]);

            ExibirCargo(conexao, resp, linhas, campos);
            printf("\n\n");
            printf("Digite o Codigo do Cargo para o funcionario que deseja cadastrar: ");
            scanf("%i", &IdCargo);
            setbuf(stdin,NULL);

            printf("\nInforme a data que o usuario iniciou no Cargo (DD-MM-AAAA) -> ");
            fgets(dtCargo,12,stdin);
            dtCargo[strlen(dtCargo)-1] = '\0';

/*
            printf("\n\n");
            printf("ID Funcionario = %d\n", IdFuncionario);
            printf("ID Cargo = %d\n", IdCargo);
            printf("Data Inicio = %s\n", dtCargo);
*/

            sprintf(StrIdFuncionario,"%d",IdFuncionario);
            sprintf(StrIdCargo,"%d",IdCargo);
            
            strcpy(sql, "INSERT INTO ocupa (datainicial, id_tab_funcionario, id_tab_cargo) VALUES('");
            strcat(sql, dtCargo);
            strcat(sql, "','");
            strcat(sql, StrIdFuncionario);
            strcat(sql, "','");
            strcat(sql, StrIdCargo);
            strcat(sql, "');");
            
            mysql_query(&conexao, sql);
            //printf("\nSQL = %s\n", sql);

            if(mysql_affected_rows(&conexao) != 1){
                printf("\nErro: Nao foi possivel cadastrar o funcionario\n\n");
                printf("Pressione qualquer tecla para continuar...\n");
                getchar();
            }else{
                printf("\nFuncionario cadastrado com sucesso!!!\n\n");
                printf("1 - Cadastrar outro funcionario\n");
                printf("2 - Voltar\n");
                scanf("%i", &Op);
                setbuf(stdin,NULL);
            }
        }
    }while(Op=1);

    mysql_close(&conexao);
}


void LancarHoras(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos){
    TipoControleHoras horas;

    int IdFuncionario, 
        IdPeriodo, 
        TipoDia, 
        Data,
        HoraEntrada1,
        HoraSaida1,
        HoraEntrada2,
        HoraSaida2,
        Op;

    char sql[500],
         StrIdFuncionario[10],
         StrIdPeriodo[10],
         StrTipoDia[10],
         StrData[10],
         StrHoraEntrada1[10],
         StrHoraSaida1[10],
         StrHoraEntrada2[10],
         StrHoraSaida2[10];

    do{
        system("clear");

        ExibirPeriodo(conexao, resp, linhas, campos);
        printf("\n\nInforme o Codigo do periodo que deseja lancar horas: ");
        scanf("%i", &IdPeriodo);
        setbuf(stdin,NULL);
        sprintf(StrIdPeriodo,"%d",IdPeriodo);
        strcpy(horas.IdPeriodo, StrIdPeriodo);

        system("clear");
        ExibirFuncionario(conexao, resp, linhas, campos);
        printf("\n\nInforme o Codigo do funcionario que deseja lancar horas: ");
        scanf("%i", &IdFuncionario);
        setbuf(stdin,NULL);
        sprintf(StrIdFuncionario,"%d",IdFuncionario);
        strcpy(horas.IdFuncionario, StrIdFuncionario); 

    /*
        printf("ID Periodo = %s\n", horas.IdPeriodo);
        printf("ID Funcionario = %s\n", horas.IdFuncionario);
    */
        system("clear");
        printf("<<< LANCAMENTO DE HORAS TRABALHADAS >>>\n\n");
        
        printf("Tipos de Dia -->    1 -> Normal      2 -> Horas 50%%      3 -> 100%%      4 -> Falta\n\n");

        printf("Tipo de Dia: ");
        scanf("%i", &TipoDia);
        setbuf(stdin,NULL);
        sprintf(StrTipoDia,"%d",TipoDia);
        strcpy(horas.TipoDia, StrTipoDia);

        printf("Data trabalhada: ");
        fgets(StrData,12,stdin);
        setbuf(stdin,NULL);
        StrData[strlen(StrData)-1] = '\0';
        strcpy(horas.Data, StrData);   
        
        printf("Hora 1ª Entrada: ");
        fgets(StrHoraEntrada1,10,stdin);
        setbuf(stdin,NULL);
        StrHoraEntrada1[strlen(StrHoraEntrada1)-1] = '\0';
        strcpy(horas.HoraEntrada1, StrHoraEntrada1); 

        printf("Hora 1ª Saida: ");
        fgets(StrHoraSaida1,10,stdin);
        setbuf(stdin,NULL);
        StrHoraSaida1[strlen(StrHoraSaida1)-1] = '\0';
        strcpy(horas.HoraSaida1, StrHoraSaida1); 

        printf("Hora 2ª Entrada: ");
        fgets(StrHoraEntrada2,10,stdin);
        setbuf(stdin,NULL);
        StrHoraEntrada2[strlen(StrHoraEntrada2)-1] = '\0';
        strcpy(horas.HoraEntrada2, StrHoraEntrada2); 

        printf("Hora 2ª Saida: ");
        fgets(StrHoraSaida2,10,stdin);
        setbuf(stdin,NULL);
        StrHoraSaida2[strlen(StrHoraSaida2)-1] = '\0';
        strcpy(horas.HoraSaida2, StrHoraSaida2);

        strcpy(sql, "INSERT INTO controlehoras (data1, tipodia, hrsentrada1, hrssaida1, hrsentrada2, hrssaida2, id_tab_periodo, id_tab_funcionario) VALUES('");
        strcat(sql, horas.Data);
        strcat(sql, "','");
        strcat(sql, horas.TipoDia);
        strcat(sql, "','");
        strcat(sql, horas.HoraEntrada1);
        strcat(sql, "','");
        strcat(sql, horas.HoraSaida1);
        strcat(sql, "','");
        strcat(sql, horas.HoraEntrada2);
        strcat(sql, "','");
        strcat(sql, horas.HoraSaida2);
        strcat(sql, "','");
        strcat(sql, horas.IdPeriodo);
        strcat(sql, "','");
        strcat(sql, horas.IdFuncionario);
        strcat(sql, "');");

    /*
        char TipoDia;
        char Data;
        char HoraEntrada1;
        char HoraSaida1;
        char HoraEntrada2;
        char HoraSaida2;
        char Horas100;
        char Horas50;
        char AdcNoturno;    
        char IdFuncionario;
        char IdPeriodo;



            system("clear");
            printf("<<< DADOS DAS HORAS >>>\n\n");
            printf("\nTipo de Dia: %s\n", horas.TipoDia);
            printf("\nData trabalhada: %s\n", horas.Data);
            printf("Hora 1ª Entrada: %s\n", horas.HoraEntrada1);
            printf("Hora 1ª Saida: %s\n", horas.HoraSaida1);
            printf("Hora 2ª Entrada: %s\n", horas.HoraEntrada2);
            printf("Hora 2ª Saida: %s\n", horas.HoraSaida2);
            printf("ID Periodo: %s\n\n", horas.IdPeriodo);
            printf("ID Funcionario: %s\n\n", horas.IdFuncionario);
              
        printf("\nSQL = %s\n", sql);
    */  

        mysql_query(&conexao, sql);
        //printf("\nSQL = %s\n", sql);

        if(mysql_affected_rows(&conexao) != 1){
            printf("\nErro: Nao foi possivel cadastrar as horas\n\n");
            printf("Pressione qualquer tecla para continuar...\n");
            getchar();
        }else{
            printf("Horas cadastradas com sucesso!!!\n\n");
            printf("1 - Cadastrar novas horas\n");
            printf("2 - Voltar\n");
            scanf("%i", &Op);
            setbuf(stdin,NULL);
        }
    }while(Op=1);

}

void CadastrarCartaoPonto(){

}

void GerarEspelho(){

}

void GerarHolerite(){

}

void ExibirFuncionario(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos){
    TipoFuncionario funcionario;
    char sql[500];
    int i;

    strcpy(sql, "SELECT funcionario.id, funcionario.nome, cargo.nome FROM funcionario LEFT JOIN ocupa ON (ocupa.id_tab_funcionario = funcionario.id) LEFT JOIN cargo ON (ocupa.id_tab_cargo = cargo.id);");
    mysql_query(&conexao, sql);

    resp = mysql_store_result(&conexao);

    if(resp){
        system("clear");
        printf("<<< RELACAO DE FUNCIONARIO >>>\n\n");

        printf("CODIGO\t\t\t\tNOME\t\t\t\t\tCARGO\n");
        campos = mysql_fetch_fields(resp);
        /*for (i=0;i<mysql_num_fields(resp);i++) {
            printf("%s",(campos[i]).name);
            if (mysql_num_fields(resp)>1)
                printf("\t\t\t");
            }*/
            printf("\n");

            while ((linhas=mysql_fetch_row(resp)) != NULL)
              {
                 for (i=0;i<mysql_num_fields(resp);i++)
                    if(linhas[i]==NULL)
                        printf("\t\t\t\t");
                    else
                        printf("%s\t\t\t\t",linhas[i]);
                 printf("\n");
              }
    }
   
}

void ExibirCargo(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos){
    char sql[500];
    int i;

    strcpy(sql, "SELECT cargo.id, cargo.nome FROM cargo;");
    mysql_query(&conexao, sql);

    resp = mysql_store_result(&conexao);

    if(resp){
        system("clear");
        printf("<<< RELACAO DE CARGOS >>>\n\n");

        printf("CODIGO\t\t\t\tNOME\n");
        campos = mysql_fetch_fields(resp);
        /*for (i=0;i<mysql_num_fields(resp);i++) {
            printf("%s",(campos[i]).name);
            if (mysql_num_fields(resp)>1)
                printf("\t\t\t");
            }*/
            printf("\n");

            while ((linhas=mysql_fetch_row(resp)) != NULL)
              {
                 for (i=0;i<mysql_num_fields(resp);i++)
                    if(linhas[i]==NULL)
                        printf("\t\t\t\t");
                    else
                        printf("%s\t\t\t\t",linhas[i]);
                 printf("\n");
              }
    }
}

void ExibirEspelho(){

}

void ExibirHolerite(){

}

void ExibirPeriodo(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos){
    int i;
    char sql[500];

    strcpy(sql, "SELECT periodo.id, periodo.datainicial, periodo.datafinal FROM periodo;");
    mysql_query(&conexao, sql);

    resp = mysql_store_result(&conexao);

    if(resp){
        system("clear");
        printf("<<< RELACAO DE PERIODOS CADASTRADOS >>>\n\n");

        printf("CODIGO\t\t\t\tDATA INICIAL\t\t\t\tDATA FINAL \n");
        campos = mysql_fetch_fields(resp);
        /*for (i=0;i<mysql_num_fields(resp);i++) {
            printf("%s",(campos[i]).name);
            if (mysql_num_fields(resp)>1)
                printf("\t\t\t");
            }*/
            printf("\n");

            while ((linhas=mysql_fetch_row(resp)) != NULL)
              {
                 for (i=0;i<mysql_num_fields(resp);i++)
                    if(linhas[i]==NULL)
                        printf("\t\t\t\t");
                    else
                        printf("%s\t\t\t\t",linhas[i]);
                 printf("\n");
              }
    }
}