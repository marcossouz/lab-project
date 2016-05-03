/* funcoes.c*/

#include <stdio.h>
#include <string.h>
#include "funcoes.h"

int menu_principal() //menu principal
{
    system("cls");

    int opcao;

    do
    {
        printf("\tMENU PRINCIPAL\n");
        printf("\n1  Cadastrar Medico.\n");
        printf("2  Cadastrar Paciente.\n");
        printf("3  Cadastrar Consulta.\n");
        printf("4  Buscar consulta.\n");
        printf("5  Listar Medicos.\n");
        printf("6  Listar Pacientes.\n");
        printf("7  sair.\n\n--> ");

    scanf("%d", &opcao);
    if(opcao < 1 || opcao > 7)
    {
        printf("Digite uma opcao valida!...\n");
        system("pause");

    }
    system("cls");
    fflush(stdin);

    }while(opcao < 1 || opcao > 7);
    return opcao;
}

int menu_listar_consultas_dia() //menu principal
{
    system("cls");
    int dia;

    printf("\tMENU LISTAR CONSULTA\n");
    printf("\nDigite o dia da semana(int): ");
    scanf("%d", &dia);
    if(dia < 2 || dia > 6)
    {
        system("cls");
        printf("\nSo atendemos de segunda a sexta!\n");
        printf("\nDigite o dia da semana(int): ");
        scanf("%d", &dia);
    }
    fflush(stdin);

    return dia;
}

/*
    //Essa funcao não foi necessária
struct dia{
    int Consulta[4];
    int quant_consultas;
};*/


struct medico{
    int cod_med;
    long long int tel;
    char nome[50];
    char end[70];
};

struct paciente{
    int cod_pac;
    long long int tel;
    char nome[50];
    char end[70];
};

typedef struct consulta{
    int cod_con;
    int dia_con;
    int cod_med, cod_pac;
    int hora_con;
};

//------------------------------------- medicos --------------------------------------------
int auto_cod_med()
{
    int cont = 0;

    Medico aux;

    FILE *arquivo;
    char nome_arquivo[] = "medicos.txt";

    arquivo = fopen(nome_arquivo, "r");

    while(arquivo != NULL && !feof(arquivo))
    {

            fscanf(arquivo," %d", &aux.cod_med);
            fgetc(arquivo);
            fgets(aux.nome, 50, arquivo);
            fscanf(arquivo,"%lld", &aux.tel);
            fgetc(arquivo);
            fgets(aux.end, 70, arquivo);

        cont++;
        if(cont > 50)
        {
            printf("ERRO_FATAL\n[modulo auto_cod_med]\n");
            exit(-1);
        }
    }
    if (cont > 0)
        return aux.cod_med+1;
    else
        return 1;

    fclose(arquivo);
}


Medico* dados_medico()
{
    Medico *medico = (Medico*)malloc(sizeof(Medico));

    medico->cod_med = auto_cod_med();
    fflush(stdin);
    printf("Nome: ");
    fgets(medico->nome, 50, stdin);
    printf("Telefone: ");
    scanf("%lld", &medico->tel);
    fflush(stdin);
    printf("Endereco: ");
    fgets(medico->end, 70, stdin);

    printf("\n\nDADOS SALVOS: \nCOD_MED:   %d\nNome:   %sTelefone:  %lld\nEndereco:   %s\n\n", medico->cod_med,
           medico->nome, medico->tel, medico->end);

    return medico;
}

void salvar_medico(Medico *medico){
    FILE *arquivo;
    char nome_arquivo[] = "medicos.txt";

    arquivo = fopen(nome_arquivo, "a+");

    medico->nome[strlen(medico->nome)-1] = '\0';
    medico->end[strlen(medico->end)-1] = '\0';
    fprintf(arquivo, "%d\n%s\n%lld\n%s\n\n", medico->cod_med, medico->nome, medico->tel, medico->end);

    free(medico);
    fclose(arquivo);
    system("pause");
}

void listar_medicos()
{
    Medico aux;
    FILE *arquivo;
    char nome_arquivo[] = "medicos.txt";

    arquivo = fopen(nome_arquivo, "r");

    while(arquivo != NULL && !feof(arquivo))
    {

        fscanf(arquivo," %d", &aux.cod_med);
        fgetc(arquivo);
        fgets(aux.nome, 50, arquivo);
        fscanf(arquivo,"%lld", &aux.tel);
        fgetc(arquivo);
        fgets(aux.end, 70, arquivo);

        if(!feof(arquivo))
        {
            printf("\nCOD_MED: %d", aux.cod_med);
            printf("\nNome: %s", aux.nome);
            printf("Telefone: %lld", aux.tel);
            printf("\nEndereco: %s", aux.end);
            printf("\n");
        }
    }

    fclose(arquivo);
    system("pause");
}

//------------------------------ pacientes ------------------------

int auto_cod_pac()
{
    int cont = 0;

    Paciente aux;

    FILE *arquivo;
    char nome_arquivo[] = "pacientes.txt";

    arquivo = fopen(nome_arquivo, "r");

    while(arquivo != NULL && !feof(arquivo))
    {
        fscanf(arquivo, " %d", &aux.cod_pac);
        fgetc(arquivo);
        fgets(aux.nome, 50, arquivo);
        fscanf(arquivo, "%lld", &aux.tel);
        fgetc(arquivo);
        fgets(aux.end, 70, arquivo);

        cont++;
    }
    if (cont > 0)
        return aux.cod_pac+1;
    else
        return 1;

    fclose(arquivo);
}

Paciente* dados_paciente()
{
    Paciente *paciente = (Paciente*)malloc(sizeof(Paciente));

    paciente->cod_pac = auto_cod_pac();
    fflush(stdin);
    printf("Nome: ");
    fgets(paciente->nome, 50, stdin);
    printf("Telefone: ");
    scanf("%lld", &paciente->tel);
    fflush(stdin);
    printf("Endereco: ");
    fgets(paciente->end, 70, stdin);

    printf("\n\nDADOS SALVOS: \nCOD_PAC:   %d\nNome:   %sTelefone:  %lld\nEndereco:   %s\n", paciente->cod_pac,
           paciente->nome, paciente->tel, paciente->end);

    return paciente;
}

void salvar_paciente(Paciente *paciente){
    FILE *arquivo;
    char nome_arquivo[] = "pacientes.txt";

    arquivo = fopen(nome_arquivo, "a+");

    paciente->nome[strlen(paciente->nome)-1] = '\0';
    paciente->end[strlen(paciente->end)-1] = '\0';

    fprintf(arquivo, "%d\n%s\n%lld\n%s\n\n", paciente->cod_pac, paciente->nome, paciente->tel, paciente->end);

    free(paciente);
    fclose(arquivo);
    system("pause");
}

void listar_pacientes()
{
    Paciente aux;
    FILE *arquivo;
    char nome_arquivo[] = "pacientes.txt";

    arquivo = fopen(nome_arquivo, "r");

    while(arquivo != NULL && !feof(arquivo))
    {
        fscanf(arquivo, " %d", &aux.cod_pac);
        fgetc(arquivo);
        fgets(aux.nome, 50, arquivo);
        fscanf(arquivo, "%lld", &aux.tel);
        fgetc(arquivo);
        fgets(aux.end, 70, arquivo);

        if(!feof(arquivo))
        {
            printf("\nCOD_PAC: %d", aux.cod_pac);
            printf("\nNome: %s", aux.nome);
            printf("Telefone: %lld", aux.tel);
            printf("\nEndereco: %s", aux.end);
            printf("\n");
        }
    }

    fclose(arquivo);
    system("pause");
}

//-----------------------  consultas  ----------------------------
int auto_cod_con()
{
    int cont = 0;

    Consulta aux;

    FILE *arquivo;
    char nome_arquivo[] = "consultas.txt";

    arquivo = fopen(nome_arquivo, "r");

    while((fscanf(arquivo,"%d\t%d\t%d\t%d\t%d\n", &aux.cod_con, &aux.cod_med, &aux.cod_pac,
                  &aux.dia_con, &aux.hora_con)) != EOF)
    {
        cont++;
    }
    if (cont > 0)
        return aux.cod_con+1;
    else
        return 1;

    fclose(arquivo);
}


Consulta* dados_consulta()
{
    Consulta *consulta = (Consulta*)malloc(sizeof(Consulta));

    consulta->cod_con = auto_cod_con();
    printf("Codigo do medico: ");
    scanf("%d", &consulta->cod_med);
    printf("Codigo do paciente: ");
    scanf("%d", &consulta->cod_pac);
    printf("\nDia da consulta\n2_Segunda\n3_Terca\n4_Quarta\n5_Quinta\n6_Sexta\n\n------> ");
    scanf("%d", &consulta->dia_con);
    while(consulta->dia_con < 2 || consulta->dia_con > 6)
    {
        system("cls");
        printf("\nSo atendemos de segunda a sexta!\n");
        printf("\nDia da consulta\n2_Segunda\n3_Terca\n4_Quarta\n5_Quinta\n6_Sexta\n\n------> ");
        scanf("%d", &consulta->dia_con);
    }
    printf("Hora da consulta(hhmm): ");
    scanf("%d", &consulta->hora_con);

    int hora = consulta->hora_con/100;
    int min = consulta->hora_con%100;
    if(min >= 10)
    {
    printf("\n\nDADOS SALVOS: \nCOD_CON:   %d\nCOD_MED:   %d\nCOD_PAC:  %d\nDIA_CON:   %d\nHORA:   %d:%d\n", consulta->cod_con,
           consulta->cod_med, consulta->cod_pac, consulta->dia_con, hora,min);
    }
    else
    {
    printf("\n\nDADOS SALVOS: \nCOD_CON:   %d\nCOD_MED:   %d\nCOD_PAC:  %d\nDIA_CON:   %d\nHORA:   %d:0%d\n", consulta->cod_con,
           consulta->cod_med, consulta->cod_pac, consulta->dia_con, hora,min);
    }
    return consulta;
}

void salvar_consulta(Consulta *consulta){
    FILE *arquivo;
    char nome_arquivo[] = "consultas.txt";

    arquivo = fopen(nome_arquivo, "a+");

    fprintf(arquivo, "%d\t%d\t%d\t%d\t%d\n", consulta->cod_con,
           consulta->cod_med, consulta->cod_pac, consulta->dia_con, consulta->hora_con);

    free(consulta);
    fclose(arquivo);
    system("pause");
}


void listar_consultas(Consulta consulta)
{
    Paciente aux_pac;
    Medico aux_med;
    int teste = 0;

    FILE *arquivo;

    arquivo = fopen("medicos.txt", "r");

    //-----------------CONSULTA
    printf("\nCOD_CONSULTA: %d", consulta.cod_con);
    printf("\nCOD_MEDICO: %d", consulta.cod_med);

    //-----------------MÉDICO

    while(arquivo != NULL && !feof(arquivo))
    {
        fscanf(arquivo, " %d", &aux_med.cod_med);
        fgetc(arquivo);
        fgets(aux_med.nome, 50, arquivo);
        fscanf(arquivo, "%lld", &aux_med.tel);
        fgetc(arquivo);
        fgets(aux_med.end, 70, arquivo);

        /*verificando se existe esse codigo de medico no sistema*/
        if(consulta.cod_med == aux_med.cod_med)
        {
            teste = 1;
            break;
        }
    }

    if(teste == 1)
    {
        printf("\nMEDICO: %s", aux_med.nome);
    }
    else
    {
        printf("\nMedico Nao encontrado");
    }

    teste = 0;
    fclose(arquivo);

    printf("\nCOD_PACIENTE: %d", consulta.cod_pac);

    //-----------------PACIENTE

    arquivo = fopen("pacientes.txt", "r");

    while(arquivo != NULL && !feof(arquivo))
    {
        fscanf(arquivo, " %d", &aux_pac.cod_pac);
        fgetc(arquivo);
        fgets(aux_pac.nome, 50, arquivo);
        fscanf(arquivo, "%lld", &aux_pac.tel);
        fgetc(arquivo);
        fgets(aux_pac.end, 70, arquivo);

        if(consulta.cod_pac == aux_pac.cod_pac)
        {
            teste = 1;
            break;
        }
    }

    if(teste == 1)
    {
        printf("\nPACIENTE: %s", aux_pac.nome);
    }
    else
    {
        printf("\nPaciente Nao encontrado\n");
    }

    teste = 0;
    fclose(arquivo);

    switch(consulta.dia_con)
    {
    case 2:
        printf("DIA_CONSULTA: Segunda-feira");
        break;
    case 3:
        printf("DIA_CONSULTA: Terca-feira");
        break;
    case 4:
        printf("DIA_CONSULTA: Quarta-feira");
        break;
    case 5:
        printf("DIA_CONSULTA: Quinta-feira");
        break;
    case 6:
        printf("DIA_CONSULTA: Sexta-feira");
        break;
    default:
        printf("So atendemos de Segunda a sexta!\n!");
    }




    int hora = consulta.hora_con/100;
    int min = consulta.hora_con%100;

    if(min >= 10)
        printf("\nHORA_CONSULTA: %d:%d\n\n", hora, min);
    else
        printf("\nHORA_CONSULTA: %d:0%d\n\n", hora, min);

printf("\n--------------------------------\n");
}

void consultas_marcadas(int dia)
{
    Consulta aux_con;

    FILE *arquivo;

    char nome_arquivo[] = "consultas.txt";

    arquivo = fopen(nome_arquivo, "r");

    while(arquivo != NULL && !feof(arquivo))
    {
       fscanf(arquivo,"%d\t%d\t%d\t%d\t%d\n", &aux_con.cod_con,
           &aux_con.cod_med, &aux_con.cod_pac, &aux_con.dia_con, &aux_con.hora_con);

        if(aux_con.dia_con == dia)
            listar_consultas(aux_con);
    }

    system("pause");
    fclose(arquivo);
}
