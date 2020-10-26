#include <stdio.h>
#include <stdlib.h>
void zeravetor(int v[], int n);
void frente(int v[], int n, int j, int x);
void tras(int v[], int n, int j, int x);
void imprime(int v[], int n, int i);

int main(int argc, char *argv[]) {
	
	int vet[200000];
	int n, m;
	int i, j, r, x;
	
	printf("Digite o tamanho do vetor(max 200.000) e o numero de instrucoes(max 200.000):\n");
	scanf("%d %d", &n, &m);
	
	if(n > 200000 || m > 200000){
		printf("Os tamanhos digitados sao maiores que o permitido");
		return 0;
	}

	zeravetor(vet , n);
	
	printf("Selecione primeiro a regra 1 ou 2, e depois digite a posicao e o valor, ou digite 3 e a posicao que deve ser mostrada:\n");
	
	for(i = 0 ; i < m ; i++){
		
		printf("Regra: ");
		scanf("%d", &r);
		printf("\n");
		
		if(r == 3){
			printf("Posicao: ");
			scanf("%d", &j);
			imprime(vet, n, j);
			printf("\n");
		}
		
		if(r == 1){
			printf("Posicao e valor: ");
			scanf("%d %d", &j, &x);
			frente( vet, n, j, x);
			printf("\n");
		}
		
		if(r == 2){
			printf("Posicao e valor: ");
			scanf("%d %d", &j, &x);
			tras(vet, n, j, x);
			printf("\n");
		}
	}

	return 0;
}


void zeravetor(int v[], int n){
	
	int i;
	
	for(i = 0 ; i < n ; i++)
		v[i] = 0;

}

void frente(int vet[], int n, int j, int x){
	
	int i;
	
	for( i = j ; i < n; i++){
		if(x > 0){
		vet[i] += x;
		x--;
		}
	}
	
}

void tras(int vet[], int n, int j, int x){
	
	int i;
	
	for(i = j ; i >= 0 ; i--){
		if(x > 0){
		vet[i] += x;
		x--;
		}
	}
	
}

void imprime(int vet[], int n, int j){
	
	if(j < n){
		printf("Valor alocado na posicao %d: %d\n", j,vet[j]);
	}else{
		printf("O valor digitado e maior que o vetor");
	}
	
}
