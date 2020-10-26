#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Paulo Ricardo dos Reis
//Professor, do nada minha 5 começou a dar erro e eu não consegui mais arrumar, se voce na hora da correção puder me dar um feedback do que fiz de errado eu agradeço.

//estrutura
struct Data{
	int dia;
	int mes;
	int ano;
};

struct Comeco{
    int chora;
    int cminuto;
};

struct Fim{
    int fhora;
    int fminuto;
};

typedef struct{
    struct Data dia;
    struct Comeco h_comeco;
    struct Fim h_fim;
    char descricao[30];
    char local[30];
}Evento;


//funções
void le_evento(Evento *p);
void mostra_evento(Evento x);
void ordena_eventos_data(Evento *p, int n);
void ordena_eventos_hora(Evento *p, int n);
int verifica_eventos(Evento *p, int n);
void move_para_fim(Evento *p, int n, int d, int m, int a);
int conta_data(Evento *p, int n, int a, int m, int d);
void move_para_fim_dois(Evento *p, int n, int a, int m, int d, int h);
int verificacao_total(Evento x);


int main(int argc, char *argv[]){

    //variaveis
    int regra = 0;
    int regra_remove = 0;
    int n = 0;
    int i;
    Evento *p = NULL;
    int d, m, a;
    int h, min;
    int cont = 0;
    int outrocontador = 0;
    char str[30];

    do{

        printf("\n-----AGENDA DE EVENTOS-----\n");
        printf("1. Cadrastrar um evendo na agenda;\n");
        printf("2. Mostrar todos os eventos da agenda;\n");
        printf("3. Procurar eventos de um dia;\n");
        printf("4. Procurar por uma descricao;\n");
        printf("5. Remover eventos;\n");
        printf("6. Sair do programa;\n");

        printf("\nDigite um numero para selecionar o comando: ");
        scanf(" %d", &regra);

        if(regra == 1){
            
            n++;
            p = realloc( p, sizeof(Evento) * n);
            
            le_evento(&p[n-1]);

            ordena_eventos_data(p, n);
            
            ordena_eventos_hora(p, n);

            if(n > 1){
                if(verifica_eventos(p, n) == 0){
                    
                    printf("Ja existe um evento nesse horario!!!\n");
                    n--;
                    p = realloc(p, sizeof(Evento) * n);
                
                }
            }

            for(i = 0 ; i < n ; i++){
                if(verificacao_total(p[i]) == 0){
                    
                    printf("DATA OU HORA INVALIDAS!!\n");
                    n--;
                    p = realloc(p, sizeof(Evento) * n);

                }
            }


        }

        if(regra == 2){

            if(n < 1){
                printf("Nao ha eventos cadastrados!!\n");
            }

            for(i = 0 ; i < n ; i++){
                printf("\n----EVENTO %d----\n", i+1);
                mostra_evento(p[i]);
            }

        }

        if(regra == 3){

            printf("\nDigite o dia: ");
            scanf("%d", &d);
            printf("Digite o mes: ");
            scanf("%d", &m);
            printf("Digite o ano: ");
            scanf("%d", &a);


            printf("\n----EVENTO(S) DIA %d/%d/%d----\n\n", d, m, a);
            for(i = 0; i <= (n-1) ; i++){ 
                if( a == p[i].dia.ano){
                    if( m == p[i].dia.mes){
                        if( d == p[i].dia.dia){
                            mostra_evento(p[i]);
                            cont++;
                        }
                    }
                }
            }

            if(cont == 0){
                printf("Nenhum evento encontrado no dia!!!\n");
            }

            cont = 0;
        }

        if(regra == 4){
            
            printf("\nDigite a descricao para ser buscada: ");
            fflush(stdin);
            gets(str);

            printf("\n----EVENTO(S) ENCONTRADOS----\n\n");
            for(i = 0 ; i <= (n-1) ; i++){
                if(strcmp(str, p[i].descricao) == 0){
                    mostra_evento(p[i]);
                    outrocontador++;
                }
            }

            if(outrocontador == 0){
                printf("\nNenhum evento encontrado com essa descricao!!!\n");
            }

            outrocontador = 0;
        }

        if(regra == 5){
            
            printf("Digite 1- Remover todos os eventos de uma data;\n");
            printf("Digite 2- Remover um evento especifico;\n");

            printf("Comando: ");
            scanf("%d", &regra_remove);
            
            if(regra_remove == 1){

                printf("\nDigite o dia: ");
                scanf("%d", &d);
                printf("Digite o mes: ");
                scanf("%d", &m);
                printf("Digite o ano: ");
                scanf("%d", &a);

                move_para_fim(p, n, a, m, d);
                
                int q = conta_data(p, n, a, m, d);

                n = n - q;

                p = realloc(p, sizeof(Evento) * n);

            }

            if(regra_remove == 2){

                printf("\nDigite o dia: ");
                scanf("%d", &d);
                printf("Digite o mes: ");
                scanf("%d", &m);
                printf("Digite o ano: ");
                scanf("%d", &a);
                printf("Digite a hora: ");
                scanf("%d", &h);

                move_para_fim_dois(p, n, a, m, d, h);
 
                n--;

                p = realloc(p, sizeof(Evento) * n);

            }



        }


    }while(regra != 6);

    //liberação de memoria
    free(p);

    return 0;
}

void le_evento(Evento *p){
    
    printf("\n");

    //data
    printf("Digite o dia: ");
	scanf("%d", &p->dia.dia);
    printf("Digite o mes: ");
    scanf("%d", &p->dia.mes);
    printf("Digite o ano: ");
    scanf("%d", &p->dia.ano);
    
    printf("\n");

    //horario começo
    printf("Digite a hora de comeco: ");
    scanf("%d", &p->h_comeco.chora);
    printf("Digite os minutos de comeco: ");
    scanf("%d", &p->h_comeco.cminuto);
    
    //horario fim
    printf("Digite a hora do fim: ");
    scanf("%d", &p->h_fim.fhora);
    printf("Digite os minutos do fim: ");
    scanf("%d", &p->h_fim.fminuto);

    printf("\n");

    //descrição
    printf("Digite uma descricao para o evento: ");
    fflush(stdin);
    gets(p->descricao);

    //local
    printf("Digite o local do evento: ");
    fflush(stdin);
    gets(p->local);

    printf("\n");
}

void mostra_evento(Evento x){
    
    //data
    printf("Data: %2d/%2d/%4d\n", x.dia.dia, x.dia.mes, x.dia.ano);
    
    //horario comeco
    printf("Horario que comeca: %2d:%2d\n", x.h_comeco.chora, x.h_comeco.cminuto);

    //horario fim
    printf("Horario que termina: %2d:%2d\n", x.h_fim.fhora, x.h_fim.fminuto);

    //descricao
    printf("Descricao: %s\n", x.descricao);

    //local
    printf("Local: %s\n\n", x.local);

}

void ordena_eventos_data(Evento *p, int n){

    int i;
    int j;
    Evento aux;

    for(i = 1; i < n ; i++){
        for(j = 0; j < (n-1) ; j++){
            if(p[j].dia.ano >= p[j+1].dia.ano){
                if(p[j].dia.mes >= p[j+1].dia.mes){
                    if(p[j].dia.dia > p[j+1].dia.dia){
                        aux = p[j];
                        p[j] = p[j+1];
                        p[j+1] = aux;
                    }
                }
            }
        }       
    }
        
}

void ordena_eventos_hora(Evento *p, int n){

    int i;
    int j;
    Evento auxiliar;

    for(i = 1; i < n ; i++){
        for(j = 0; j < (n-1) ; j++){
            if(p[j].dia.ano == p[j+1].dia.ano){
                if(p[j].dia.mes == p[j+1].dia.mes){
                    if(p[j].dia.dia == p[j+1].dia.dia){
                        if(p[j].h_comeco.chora >= p[j+1].h_comeco.chora){
                            auxiliar = p[j];
                            p[j] = p[j+1];
                            p[j+1] = auxiliar;
                        }
                    }
                }
            }
        }       
    }
}

int verifica_eventos(Evento *p, int n){

    int i;
    int j;

    for(i = n; i >= 0 ; i--){
        for(j = (n-1); j >= 0; j--){
            if(p[j].dia.ano == p[j-1].dia.ano){
                if(p[j].dia.mes == p[j-1].dia.mes){
                    if(p[j].dia.dia == p[j-1].dia.dia){
                        if(p[j].h_comeco.chora >= p[j-1].h_comeco.chora && p[j].h_comeco.chora <= p[j-1].h_fim.fhora){
                            if(p[j].h_comeco.cminuto >= p[j-1].h_comeco.cminuto){
                                return 0;
                            }
                        }
                    }
                }
            }
        }       
    }

    return 1;
}

void move_para_fim(Evento *p, int n, int a, int m, int d){

    int i, j;
    Evento auxiliar;

    for(j = 0 ; j < n ; j++){
        for(i = 0 ; i < n ; i++){
            if(p[i].dia.ano == a){
                if(p[i].dia.mes == m){
                    if(p[i].dia.dia == d){
                        auxiliar = p[i];
                        p[i] = p[i+1];
                        p[i+1] = auxiliar;
                    }
                }
            }
        }
    }

}

void move_para_fim_dois(Evento *p, int n, int a, int m, int d, int h){

    int i;
    Evento auxiliar;

    for(i = 0 ; i < n ; i++){
        if(p[i].dia.ano == a){
            if(p[i].dia.mes == m){
                if(p[i].dia.dia == d){
                    if(h >= p[i].h_comeco.chora && h <= p[i].h_fim.fhora){
                        auxiliar = p[i];
                        p[i] = p[i+1];
                        p[i+1] = auxiliar;
                    }
                }
            }
        }
    }


}

int conta_data(Evento *p, int n, int a, int m, int d){

    int i;
    int contador = 0;
    
    for(i = 0 ; i <= (n-1) ; i++){
        if(p[i].dia.ano == a){
            if(p[i].dia.mes == m){
                if(p[i].dia.dia == d){
                    contador++;
                }
            }
        }
    }

    return contador;
}

int verificacao_total(Evento x){

    //Verificação hora
    if(x.h_comeco.chora > 24 || x.h_comeco.chora < 0){
        return 0;
    }

    if(x.h_comeco.cminuto > 60 || x.h_comeco.cminuto < 0){
        return 0;
    }

    if(x.h_fim.fhora > 24 || x.h_fim.fhora < 0){
        return 0;
    }

    if(x.h_fim.fminuto > 60 || x.h_fim.fminuto < 0){
        return 0;
    }

    //Verificação datas 

    if(x.dia.mes > 12 || x.dia.mes < 0){
        return 0;
    }

    if(x.dia.mes == 1){
        if(x.dia.dia > 31 || x.dia.dia < 0){
            return 0;
        }
    }

    if(x.dia.mes == 2){
        if(x.dia.dia > 29 || x.dia.dia < 0){
            return 0;
        }
    }

    if(x.dia.mes == 3){
        if(x.dia.dia > 31 || x.dia.dia < 0){
            return 0;
        }
    }

    if(x.dia.mes == 4){
        if(x.dia.dia > 30 || x.dia.dia < 0){
            return 0;
        }
    }

    if(x.dia.mes == 5){
        if(x.dia.dia > 31 || x.dia.dia < 0){
            return 0;
        }
    }

    if(x.dia.mes == 6){
        if(x.dia.dia > 30 || x.dia.dia < 0){
            return 0;
        }
    }

    if(x.dia.mes == 7){
        if(x.dia.dia > 31 || x.dia.dia < 0){
            return 0;
        }
    }

    if(x.dia.mes == 8){
        if(x.dia.dia > 31 || x.dia.dia < 0){
            return 0;
        }
    }

    if(x.dia.mes == 9){
        if(x.dia.dia > 30 || x.dia.dia < 0){
            return 0;
        }
    }

    if(x.dia.mes == 10){
        if(x.dia.dia > 31 || x.dia.dia < 0){
            return 0;
        }
    }

    if(x.dia.mes == 11){
        if(x.dia.dia > 30 || x.dia.dia < 0){
            return 0;
        }
    }

    if(x.dia.mes == 12){
        if(x.dia.dia > 31 || x.dia.dia < 0){
            return 0;
        }
    }

    return 1;
}