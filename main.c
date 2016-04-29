/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void main()
{

    while(1)
    {
        switch(menu_principal())
        {
        case 1:
            system("cls");
            salvar_medico(dados_medico());
            break;

        case 2:
            system("cls");
            salvar_paciente(dados_paciente());
            break;

        case 3:
            system("cls");
            salvar_consulta(dados_consulta());
            break;

        case 4:
            system("cls");
            consultas_marcadas(menu_listar_consultas_dia());
            break;

        case 5:
            system("cls");
            listar_medicos();
            break;

        case 6:
            system("cls");
            listar_pacientes();
            break;

        case 7:
            exit(0); // 0 executed successfully
            break;

        default:
            system("cls");
            printf("\nOpcao Invalida");
            break;
        }
    }
}
