/**@project   Automação de uma clínica médica
 * 
 * @abstract  trabalho produzido por
 * 							Marcos Antonio Santos de Souza
 *							Jean
 * 							Sergio
 *
 * 							Instituto de Computação - UFAL
 *							COMP202A - Laboratório de programação
 *
 * @documented by Marcos Souza
 * @date   april 29, 2016
*/


/** @struct Dia 
 * 	
 * @abstract         Verificar se está sendo usada
 */
typedef struct dia Dia;


/** @struct Medico - Dados de medicos cadastrados
 * 	
 * @abstract      Armazena temporariamente os dados dos medicos
 *                no sistema ate que eles sejam escritos no arquivo
 * 
 * @field int cod_med - inteiro que armazena o codigo do medico, gerado automaticamente
 * @field long long int tel - inteiro longo que armazena o nomero de telefone do medico
 * @field char nome[] - string que armazena o nome do medico
 * @field char end[] - string que armazena o endereço do medico
*/
typedef struct medico Medico;


/** @struct Paciente - Dados de pacientes cadastrados
 * 	
 * @abstract        Armazena temporariamente os dados dos pacientes
 *                  no sistema ate que eles sejam escritos no arquivo
 * 
 * @field int cod_pac - inteiro que armazena o codigo do paciente, gerado automaticamente
 * @field long long int tel - inteiro longo que armazena o nomero de telefone do paciente
 * @field char nome[] - string que armazena o nome do paciente
 * @field char end[] - string que armazena o endereço do paciente
*/
typedef struct paciente Paciente;


/** @struct Consulta - Dados das consultas cadastrados
 * 	
 *  @abstract       Armazena temporariamente os dados das consultas
 * 		            no sistema ate que eles sejam escritos no arquivo
 * 
 *	@field int cod_con - inteiro que armazena o codigo da consulta, gerado automaticamente
 *  @field int dia_con - inteiro que armazena o dia da consulta, solicitado ao usuario
 *  @field int cod_med - inteiro que armazena o codigo do medico, solicitado ao usuario
 *	@field int cod_pac - inteiro que armazena o codigo do paciente, solicitado ao usuario
 *  @field int hora_con - inteiro que armazena a hora da consulta @format hhmm
 */
typedef struct consulta Consulta;

/** @function menu_principal() - função que imprime o menu.
 *
 * @abstract        função que escreve na tela a solicitação de qual função deve ser chamada
 *                  pelo usuario.       
 *
 * @param void - sem parametros.
 *
 * @return int opcao - retorna um numero de 1 a 7 com a opcao escolhida pelo usuario para
 * 					   que seja usada no switch.
 */
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
