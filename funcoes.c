#include <stdio.h>
#include <string.h>

int menu_principal() //menu principal
{
    system("cls");
    int opcao;

    printf("\tMENU PRINCIPAL\n");
    printf("\n1  Cadastrar Medico.\n");
    printf("2  Cadastrar Paciente.\n");
    printf("3  Cadastrar Consulta.\n");
    printf("4  Buscar consulta.\n");
    printf("5  Listar Medicos.\n");
    printf("6  Listar Pacientes.\n");
    printf("7  sair.\n\n--> ");

    scanf("%d", &opcao);
    fflush(stdin);

    return opcao;
}

int menu_listar_consultas_dia() //menu principal
{
    system("cls");
    int dia;

    printf("\tMENU LISTAR CONSULTA\n");
    printf("\nDigite o dia da semana:\n\n--> ");

    scanf("%d", &dia);
    fflush(stdin);

    return dia;
}

typedef struct dia{
    int Consulta[4];
    int quant_consultas;
} Dia;


typedef struct medico{
    int cod_med;
    char tel[10];
    char nome[50];
    char end[70];
} Medico;

typedef struct paciente{
    int cod_pac;
    char tel[10];
    char nome[50];
    char end[70];
} Paciente;

typedef struct consulta{
    int cod_con;
    int dia_con;
    int cod_med, cod_pac;
    int hora_con;
} Consulta;

//---------------------------------------------------------------------------------
int auto_cod_med()
{
    int cont = 0;

    Medico aux;

    FILE *arquivo;
    char nome_arquivo[] = "medicos.txt";

    arquivo = fopen(nome_arquivo, "r");

    while((fscanf(arquivo,"%d\t%s\t%s\t%s\n", &aux.cod_med, aux.nome, aux.tel, aux.end)) != EOF)
    {
        cont++;
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
    printf("Nome:\n");
    fgets(medico->nome, 50, stdin);
    printf("Telefone:\n");
    fgets(medico->tel, 10, stdin);
    printf("Endereço:\n");
    fgets(medico->end, 70, stdin);

    printf("\n\nDADOS SALVOS: \nCOD_MED:   %d\nNome:   %s\nTelefone:  %s\nEndereco:   %s\n\n", medico->cod_med,
           medico->nome, medico->tel, medico->end);

    return medico;
}

void salvar_medico(Medico *medico){
    FILE *arquivo;
    char nome_arquivo[] = "medicos.txt";

    arquivo = fopen(nome_arquivo, "a+");

    medico->nome[strlen(medico->nome)-1] = '\0';
    medico->tel[strlen(medico->tel)-1] = '\0';
    medico->end[strlen(medico->end)-1] = '\0';

    fprintf(arquivo, "%d\t%s\t%s\t%s\n", medico->cod_med, medico->nome, medico->tel, medico->end);

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

    while((fscanf(arquivo,"%d\t%s\t%s\t%s\n", &aux.cod_med, aux.nome, aux.tel, aux.end)) != EOF)
    {
        printf("\n\tCOD_MED: %d", aux.cod_med);
        printf("\nNome: %s", aux.nome);
        printf("\nTelefone: %s", aux.tel);
        printf("\nEndereco: %s", aux.end);
        printf("\n\n");
    }

    fclose(arquivo);
    system("pause");
}

//----------------------------------------------------

int auto_cod_pac()
{
    int cont = 0;

    Paciente aux;

    FILE *arquivo;
    char nome_arquivo[] = "pacientes.txt";

    arquivo = fopen(nome_arquivo, "r");

    while((fscanf(arquivo,"%d\t%s\t%s\t%s\n", &aux.cod_pac, aux.nome, aux.tel, aux.end)) != EOF)
    {
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
    printf("Nome:\n");
    fgets(paciente->nome, 50, stdin);
    printf("Telefone:\n");
    fgets(paciente->tel, 10, stdin);
    printf("Endereço:\n");
    fgets(paciente->end, 70, stdin);

    printf("\n\nDADOS SALVOS: \nCOD_PAC:   %d\nNome:   %s\nTelefone:  %s\nEndereco:   %s\n\n", paciente->cod_pac,
           paciente->nome, paciente->tel, paciente->end);

    return paciente;
}

void salvar_paciente(Paciente *paciente){
    FILE *arquivo;
    char nome_arquivo[] = "pacientes.txt";

    arquivo = fopen(nome_arquivo, "a+");

    paciente->nome[strlen(paciente->nome)-1] = '\0';
    paciente->tel[strlen(paciente->tel)-1] = '\0';
    paciente->end[strlen(paciente->end)-1] = '\0';

    fprintf(arquivo, "%d\t%s\t%s\t%s\n", paciente->cod_pac, paciente->nome, paciente->tel, paciente->end);

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

    while((fscanf(arquivo,"%d\t%s\t%s\t%s\n", &aux.cod_pac, aux.nome, aux.tel, aux.end)) != EOF)
    {
        printf("\n\tCOD_MED: %d", aux.cod_pac);
        printf("\nNome: %s", aux.nome);
        printf("\nTelefone: %s", aux.tel);
        printf("\nEndereco: %s", aux.end);
        printf("\n\n");
    }

    fclose(arquivo);
    system("pause");
}

//---------------------------------------------------
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
    printf("Código do médico:\n");
    scanf("%d", &consulta->cod_med);
    printf("Código do paciente:\n");
    scanf("%d", &consulta->cod_pac);
    printf("Dia da consulta:\n");
    scanf("%d", &consulta->dia_con);
    printf("Hora da consulta:\n");
    scanf("%d", &consulta->hora_con);

    printf("\n\nDADOS SALVOS: \nCOD_CON:   %d\nCOD_MED:   %d\nCOD_PAC:  %d\nDIA_CON:   %d\nHORA:   %d\n", consulta->cod_con,
           consulta->cod_med, consulta->cod_pac, consulta->dia_con, consulta->hora_con);

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
    printf("\n\t\tCOD_CONSULTA: %d", consulta.cod_con);
    printf("\nCOD_MEDICO: %d", consulta.cod_med);

    //-----------------MÉDICO

    while((fscanf(arquivo,"%d\t%s\t%s\t%s\n", &aux_med.cod_med, aux_med.nome, aux_med.tel, aux_med.end)) != EOF)
    {
        if(consulta.cod_med == aux_med.cod_med)
        {
            teste = 1;
            break;
        }
    }

    if(teste == 1)
    {
        printf("\nNome Medico : %s", aux_med.nome);
    }
    else
    {
        printf("\nNome Medico : Nao encontrado");
    }

    teste = 0;
    fclose(arquivo);

    printf("\nCOD_PACIENTE: %d", consulta.cod_pac);

    //-----------------PACIENTE

    arquivo = fopen("pacientes.txt", "r");

    while((fscanf(arquivo,"%d\t%s\t%s\t%s\n", &aux_pac.cod_pac, aux_pac.nome, aux_pac.tel, aux_pac.end)) != EOF)
    {
        if(consulta.cod_pac == aux_pac.cod_pac)
        {
            teste = 1;
            break;
        }
    }

    if(teste == 1)
    {
        printf("\nNome Paciente : %s", aux_pac.nome);
    }
    else
    {
        printf("\nNome Paciente : Nao encontrado");
    }

    teste = 0;
    fclose(arquivo);

    printf("\nDIA_CONSULTA: %d", consulta.dia_con);
    printf("\nHORA_CONSULTA: %d\n\n", consulta.hora_con);
}

void consultas_marcadas(int dia)
{
    Consulta aux_con;

    FILE *arquivo;

    char nome_arquivo[] = "consultas.txt";

    arquivo = fopen(nome_arquivo, "r");

    while((fscanf(arquivo,"%d\t%d\t%d\t%d\t%d\n", &aux_con.cod_con,
           &aux_con.cod_med, &aux_con.cod_pac, &aux_con.dia_con, &aux_con.hora_con)) != EOF)
    {
        if(aux_con.dia_con == dia)
            listar_consultas(aux_con);
    }

    system("pause");
    fclose(arquivo);
}
