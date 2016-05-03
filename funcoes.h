/**@project   Automação de uma clínica médica
 *
 * @abstract  trabalho produzido por
 * 							Marcos Antonio Santos de Souza
 *							Jean Carlos Alves dos Santos
 * 							Sergio Augusto Teixeira Amorim
 *
 * 							Instituto de Computação - UFAL
 *							COMP202A - Laboratório de programação
 *
 * @documented by Marcos Souza
 * @date   april 29, 2016
*/

/* Não foi necessaria
typedef struct dia Dia;*/


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


/** @function menu_principal() - Imprime o menu principal.
 *
 * @abstract        Escreve na tela a solicitação de qual função deve ser chamada
 *                  pelo usuario.
 *
 * @param void - sem parametros.
 *
 * @return int opcao - retorna um numero de 1 a 7 com a opcao escolhida pelo usuario para
 * 					   que seja usada no switch.
 */
int menu_principal();


/** @function menu_listar_consultas_dia() - Imprime o menu para listar busca de consultas.
 *
 * @abstract        Escreve na tela a solicitação de qual dia que as consultas devem ser buscadas
 *                  pelo usuario.
 *
 * @param void - sem parametros.
 *
 * @return int dia - Retorna o dia desejado do resultado da busca de consultas.
 */
int menu_listar_consultas_dia();


/** @function auto_cod_med() - Gera codigo sequencial de medico.
 *
 * @abstract        Atribui a cada novo medico cadastrado no sistema um codigo
 *                  unico.
 *
 * @param void - sem parametros.
 *
 * @return int - Retorna o codigo do medico cadastrado.
 */
int auto_cod_med();


/** @function dados_medico() - Solicitação dos dados cadastrais do medico.
 *
 * @abstract        Solicita os dados necessários para cadastro de novo medico
 *                  No sistema.
 *
 * @param void - sem parametros.
 *
 * @return struct - Retorna a estrutura medico com os dados preenchidos.
 */
Medico* dados_medico();


/** @function salvar_medico() - Escreve os dados do novo medico no arquivo.
 *
 * @abstract        Recebe a struct medico preenchida com os dados do novo medico
 *                  e acrecenta esses dados no arquivo correspondente (medicos.txt).
 *
 * @param Medico *medico - Dados do medico que acabou de ser cadastrado no sistema.
 *
 * @return void - sem retorno.
 */
void salvar_medico(Medico *medico);


/** @function listar_medicos() - Listagem dos medicos cadastrados.
 *
 * @abstract                    Imprime os dados de todos os medicos cadastrados no sistema
 *                              Ate o momento.
 *
 * @param void - sem parametros.
 *
 * @return void - sem retorno.
 */
void listar_medicos();


/** @function auto_cod_pac() - Gera codigo sequencial de pacientes.
 *
 * @abstract        Atribui a cada novo paciente cadastrado no sistema um codigo
 *                  unico.
 *
 * @param void - sem parametros.
 *
 * @return int - Retorna o codigo do paciente cadastrado.
 */
int auto_cod_pac();


/** @function dados_paciente() - Solicitação dos dados cadastrais do paciente.
 *
 * @abstract        Solicita os dados necessários para cadastro de novo paciente
 *                  No sistema.
 *
 * @param void - sem parametros.
 *
 * @return struct - Retorna a estrutura paciente com os dados preenchidos.
 */
Paciente* dados_paciente();


/** @function salvar_paciente() - Escreve os dados do novo paciente no arquivo.
 *
 * @abstract        Recebe a struct paciente preenchida com os dados do novo paciente
 *                  e acrecenta esses dados no arquivo correspondente (pacientes.txt).
 *
 * @param Paciente *paciente - Dados do paciente que acabou cadastrado no sistema.
 *
 * @return void - sem retorno.
 */
void salvar_paciente(Paciente *paciente);


/** @function listar_pacientes() - Listagem dos pacientes cadastrados.
 *
 * @abstract                    Imprime os dados de todos os pacientes cadastrados no sistema
 *                              Ate o momento.
 *
 * @param void - sem parametros.
 *
 * @return void - sem retorno.
 */
void listar_pacientes();


/** @function auto_cod_con() - Gera codigo sequencial de consulta.
 *
 * @abstract        Atribui a cada nova consulta cadastrado no sistema um codigo
 *                  unico.
 *
 * @param void - sem parametros.
 *
 * @return int - Retorna o codigo da consulta cadastrado.
 */
int auto_cod_con();


/** @function dados_consulta() - Solicitação dos dados da consulta realizada.
 *
 * @abstract        Solicita os dados necessários para cadastrar a consulta realizada
 *                  No sistema.
 *
 * @param void - sem parametros.
 *
 * @return struct - Retorna a estrutura consulta com os dados preenchidos.
 */
Consulta* dados_consulta();


/** @function salvar_consulta() - Escreve os dados da consulta realizada no arquivo.
 *
 * @abstract        Recebe a struct consulta preenchida com os dados da consulta realizada
 *                  e acrecenta esses dados no arquivo correspondente (consultas.txt).
 *
 * @param Consulta *consulta - Dados da consulta que acabaram de ser preenchidos pelo usuario.
 *
 * @return void - sem retorno.
 */
void salvar_consulta(Consulta *consulta);


/** @function listar_consultas() - Listagem dos dados da consulta solicitada.
 *
 * @abstract                    Imprime os dados consulta solicitada por outra função
 *                              No caso (consultas_marcadas()) que filtra quais devem ser
 *                              Os dados a serem imprimidos de acordo com o filtro definido
 *                              Que no caso foi o dia da consulta.
 *
 * @param Consulta consulta - Recebe um consulta que satisfaz o filtro pelo dia de realização.
 *
 * @return void - sem retorno.
 */
void listar_consultas(Consulta consulta);


/** @function consultas_marcadas() - Filtro de busca de consultas.
 *
 * @abstract                    Define quais consultas devem ser imprimidas, respeitando a restrição
 *                              De que somente deve-se imprimir as consultas do dia recebido na entrada.
 *
 * @param int dia - Recebe o dia que define as buscas das consultas.
 *
 * @return void - sem retorno.
 */
void consultas_marcadas(int dia);
