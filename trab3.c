#include <stdio.h>
#include <stdlib.h>
int verifica_repetidos(int **v, int n, int tam);
int *uniao(int **p_conjuntos, int n,int *p_quantidades, int q1, int q2);
int *interseccao(int **p_conjuntos, int n, int *p_quantidades, int q1, int q2);
int *diferenca(int **p_conjuntos, int n, int *p_quantidades, int q1, int q2);
int *busca_valor(int **p_conjuntos, int n, int *p_quantidades, int chave);
int busca(int *v, int n, int chave);
int busca2( int *v, int n, int chave );
int verifica_conjunto(int n, int c1, int c2);

int main(int argc, char *argv[]){

    int n = 0;
    int regra = 0;
    int *p_quantidades = NULL;
    int **p_conjuntos = NULL;
    int i;
    int j;
    int q1 = 0, q2 = 0;
    int chave = 0;

    //MENU
    {
    printf("--------MENU--------\n");
    printf("1. Criar um novo conjunto;\n");
    printf("2. Fazer a uniao entre dois conjuntos (Requer ao menos 2 conjuntos criados);\n");
    printf("3. Fazer a interseccao entre dois conjuntos (Requer ao menos 2 conjuntos criados);\n");
    printf("4. Fazer a diferenca entre dois conjuntos (Requer ao menos 2 conjuntos criados);\n");
    printf("5. Informe um valor para localizar onde ele esta (Requer ao menos 1 conjunto criado);\n");
    printf("6. Mostrar um conjunto na tela (Requer ao menos 1 conjunto criado);\n");
    printf("7. Mostrar todos os conjuntos (Requer ao menos 1 conjunto criado);\n");
    printf("8. Sair do programa.\n");
    }

    //OPERAÇÕES
    do{
        printf("Digite um numero para selecionar o comando: ");
        scanf("%d", &regra);

        if(regra == 1){

            n++;
            p_quantidades = realloc(p_quantidades, sizeof(int)* n);
            p_conjuntos = realloc(p_conjuntos, sizeof(int*) * n);

            printf("Digite o tamanho do conjunto: ");
            scanf(" %d", &p_quantidades[n-1]);
            p_conjuntos[n-1] = malloc(sizeof(int) * p_quantidades[n-1]);
            
            printf("Digite o conjunto:\n");
            for(i = 0 ; i < p_quantidades[n-1]; i++){
                scanf(" %d", &p_conjuntos[n-1][i]);
            }

            if(verifica_repetidos(p_conjuntos, n, p_quantidades[n-1]) != 0){
                printf("O conjunto nao pode ter valores repetidos!\n");
                free(p_conjuntos[n-1]);
                n--;
            }

        }

        if(regra == 2){

            n++;

            printf("Digite o primeiro conjunto para fazer a uniao:");
            scanf(" %d", &q1);
            printf("Digite o segundo conjunto para fazer a uniao:");
            scanf(" %d", &q2);

            if(verifica_conjunto(n, q1, q2) == 0){
                printf("Um ou mais dos conjuntos digitados nao existe!\n");
                n--;
            }else{

            p_quantidades = realloc(p_quantidades, sizeof(int)* n);
            p_conjuntos = realloc(p_conjuntos, sizeof(int*) * n);
            
            uniao(p_conjuntos, n, p_quantidades, q1, q2);

            printf("Uniao:");
            for(i = 0 ; i < p_quantidades[n-1] ; i++){
                printf(" %d", p_conjuntos[n-1][i]);
            }
            printf("\n");
            
            }
        }

        if(regra == 3){

            n++;
            p_quantidades = realloc(p_quantidades, sizeof(int)* n);
            p_conjuntos = realloc(p_conjuntos, sizeof(int*) * n);

            printf("Digite o primeiro conjunto para fazer a interseccao:");
            scanf(" %d", &q1);
            printf("Digite o segundo conjunto para fazer a interseccao:");
            scanf(" %d", &q2);

            if(verifica_conjunto(n, q1, q2) == 0){
                printf("Um ou mais dos conjuntos digitados nao existe!\n");
                n--;
            }else{

            p_quantidades = realloc(p_quantidades, sizeof(int)* n);
            p_conjuntos = realloc(p_conjuntos, sizeof(int*) * n);

            interseccao(p_conjuntos, n, p_quantidades, q1, q2);
            
            printf("interseccao:");
            for(i = 0 ; i < p_quantidades[n-1] ; i++){
                printf(" %d", p_conjuntos[n-1][i]);
            }
            printf("\n");
            
            }
        }
        
        if(regra == 4){

            n++;

            printf("Digite o primeiro conjunto para fazer a diferenca:");
            scanf(" %d", &q1);
            printf("Digite o segundo conjunto para fazer a diferenca:");
            scanf(" %d", &q2);

            if(verifica_conjunto(n, q1, q2) <= 0){
                printf("Um ou mais dos conjuntos digitados nao existe!\n");
                n--;
            }else{

            p_quantidades = realloc(p_quantidades, sizeof(int)* n);
            p_conjuntos = realloc(p_conjuntos, sizeof(int*) * n);

            diferenca(p_conjuntos, n, p_quantidades, q1, q2);

            printf("Diferenca:");
            if(p_quantidades[n-1] <= 0){
                printf("Conjunto vazio");
            }else{
                for(i = 0 ; i < p_quantidades[n-1] ; i++){
                    printf(" %d", p_conjuntos[n-1][i]);
                }
            }
            printf("\n");

            }
        }

        if(regra == 5){
            
            printf("Digite um valor para procurar nos conjuntos:");
            scanf(" %d", &chave);

            int *vetcontador = busca_valor(p_conjuntos, n, p_quantidades, chave);

            if(vetcontador[0] == -1 ){
                printf("O valor nao foi encontrado em nenhum conjunto!\n");
            }else{

            printf("O valor foi encontrado nos conjuntos:");
            for(i = 0 ; vetcontador[i] != -1 ; i++){
                printf(" %d", vetcontador[i]);
            }
            printf("\n");
            }

            free(vetcontador);
        }

        if(regra == 6){
            printf("Digite o numero de um conjunto para ser mostrado na tela: ");
            scanf(" %d", &chave);

            if(chave > n){
                printf("O conjunto nao existe\n");
            }else{

            printf("Conjunto %d:", chave);
            for(i = 0 ; i < p_quantidades[chave-1] ; i++){
                printf(" %d", p_conjuntos[chave-1][i]);
            }
            printf("\n");

            }
        }
    
        if(regra == 7){
            
            if(n < 1){
                printf("Nao ha nenhum conjunto!\n");
            }else{

            for(i = 0 ; i < n ; i++){
                printf("Conjunto %d:", i+1);
                for(j = 0 ; j < p_quantidades[i] ; j++){
                    printf(" %d", p_conjuntos[i][j]);
                }
                printf("\n");
            }

            }
        }
    
    }while(regra != 8);

    //LIBERAÇÃO DE MEMORIA

    for(i = 0 ; i < n ; i++){
        free(p_quantidades + 1);
    }

    for(i = 0 ; i < n ; i++){
       free(p_conjuntos + 1);
    }

    return 0;
}

int verifica_repetidos(int **v, int n, int tam){

    int i;
    int j;
    int c;

    for(i = 0 ; i < tam ; i++){
        for(j = i+1 ; j < tam ; j++){
            if(v[n-1][i] == v[n-1][j]){
                c++;
            }
        }
    }

    return c;
}

int *uniao(int **p_conjuntos, int n,int *p_quantidades, int q1, int q2){

    p_conjuntos[n-1] = malloc(sizeof(int)*p_quantidades[q1-1]);
    int tam = p_quantidades[q1-1];
    int i;
    
    for(i = 0; i < p_quantidades[q1-1]; i++){
		p_conjuntos[n-1][i] = p_conjuntos[q1-1][i];
    }

    for(i = 0 ; i < p_quantidades[q2-1]; i++){
        if(busca(p_conjuntos[n-1], p_quantidades[q1-1], p_conjuntos[q2-1][i]) == -1){
            (tam)++;
            p_conjuntos[n-1] = realloc(p_conjuntos[n-1], sizeof(int) * tam);
            p_conjuntos[n-1][tam-1] = p_conjuntos[q2-1][i];
        }
    }

    p_quantidades[n-1] = tam;

    return p_conjuntos[n-1];
}

int *interseccao(int **p_conjuntos, int n, int *p_quantidades, int q1, int q2){

    p_conjuntos[n-1] = NULL;
    int i, j;
    int tam = 0;

    for(i = 0 ; i < p_quantidades[q1-1] ; i++){
        for(j = 0 ; j < p_quantidades[q2-1] ; j++){
            if(p_conjuntos[q1-1][i] == p_conjuntos[q2-1][j]){
                (tam)++;
                p_conjuntos[n-1] = realloc(p_conjuntos[n-1], sizeof(int)*tam);
                p_conjuntos[n-1][tam-1] = p_conjuntos[q2-1][j];
            }
        }
    }

    p_quantidades[n-1] = tam;

    return p_conjuntos[n-1];
}

int *diferenca(int **p_conjuntos, int n, int *p_quantidades, int q1, int q2){

    p_conjuntos[n-1] = NULL;
    int j;
    int p = 0;


        for(j = 0 ; j < p_quantidades[q2-1] ; j++){
            if(busca2(p_conjuntos[q2-1], p_quantidades[q2-1], p_conjuntos[q1-1][j]) == 1){
                p++;
                p_conjuntos[n-1] = realloc(p_conjuntos[n-1], sizeof(int)*p);
                p_conjuntos[n-1][p-1] = p_conjuntos[q1-1][j];
            }
        }
    

    p_quantidades[n-1] = p;

    return p_conjuntos[n-1];
}

int *busca_valor(int **p_conjuntos, int n, int *p_quantidades, int chave){

    int i;
    int j;
    int k = 1;
    int *vet = malloc(sizeof(int));

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < p_quantidades[i]; j++){
            if(chave == p_conjuntos[i][j]){
                vet[k-1] = i+1;
                k++;
                vet = realloc(vet, sizeof(int) * k);
            }
        }
    }

    vet[k-1] = -1;

    return vet;
}

int busca2( int *v, int n, int chave ){
	int i;
	
    for(i = 0 ; i < n ; i++ ){
		if( chave == v[i] ){
			return 0;
        }
    }

	return 1;
}

int busca( int *v, int n, int chave ){
	int i;
	
    for( i = 0 ; i < n ; i++ )
		if( v[i] == chave )
			return i;
	
	return -1;
}

int verifica_conjunto(int n, int c1, int c2){

    if(c1 >= n || c2 >= n){
        return 0;
    }

    return 1;
}