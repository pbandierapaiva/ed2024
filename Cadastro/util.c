//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do CSV:
// "Id_SERVIDOR_PORTAL";"NOME";"CPF";"MATRICULA";"DESCRICAO_CARGO";"CLASSE_CARGO";"REFERENCIA_CARGO";
// "PADRAO_CARGO";"NIVEL_CARGO";"SIGLA_FUNCAO";"NIVEL_FUNCAO";"FUNCAO";"CODIGO_ATIVIDADE";"ATIVIDADE";
// "OPCAO_PARCIAL";"COD_UORG_LOTACAO";"UORG_LOTACAO";"COD_ORG_LOTACAO";"ORG_LOTACAO";"COD_ORGSUP_LOTACAO";
// "ORGSUP_LOTACAO";"COD_UORG_EXERCICIO";"UORG_EXERCICIO";"COD_ORG_EXERCICIO";"ORG_EXERCICIO";
// "COD_ORGSUP_EXERCICIO";"ORGSUP_EXERCICIO";"COD_TIPO_VINCULO";"TIPO_VINCULO";"SITUACAO_VINCULO";
// "DATA_INICIO_AFASTAMENTO";"DATA_TERMINO_AFASTAMENTO";"REGIME_JURIDICO";"JORNADA_DE_TRABALHO";
// "DATA_INGRESSO_CARGOFUNCAO";"DATA_NOMEACAO_CARGOFUNCAO";"DATA_INGRESSO_ORGAO";"DOCUMENTO_INGRESSO_SERVICOPUBLICO"
// ;"DATA_DIPLOMA_INGRESSO_SERVICOPUBLICO";"DIPLOMA_INGRESSO_CARGOFUNCAO";"DIPLOMA_INGRESSO_ORGAO"
// ;"DIPLOMA_INGRESSO_SERVICOPUBLICO";"UF_EXERCICIO"


// Função para pegar campo de string de um CSV
void pegaCampo(char *lin, int indice, char *resultado) {
	int i=0;
	char *p, *r;
	
	p = lin;
	while(i<indice) {
		while( *p!=';' && *p != '\0' ) p++;
		if(*p=='\0') {
			printf("ERRO - índice fora de escopo.\n");
			exit(-1);
			}
		i++; p++;
		}
	if(*p=='"') p++;
	r = resultado;	
	while( *p!=';' && *p!='"' && *p!='\0' ){
		*r = *p;
		r++; 
		*r='\0';
		p++;
		}
	return;
}

