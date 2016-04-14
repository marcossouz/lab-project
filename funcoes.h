#include "funcoes.c"

int menu_principal();
int menu_listar_consultas_dia();
int auto_cod_med();
Medico* dados_medico();
void salvar_medico(Medico *medico);
void listar_medicos();
int auto_cod_pac();
Paciente* dados_paciente();
void salvar_paciente(Paciente *paciente);
void listar_pacientes();
int auto_cod_con();
Consulta* dados_consulta();
void salvar_consulta(Consulta *consulta);
void listar_consultas(Consulta consulta);
void consultas_marcadas(int dia);
