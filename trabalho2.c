// Alunos Paulo Ricardo e Matheus Duarte

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int sao_anagramas(char str1[], char str2[]);
int conta_ocorrencias(char str1[], char str2[]);
float string_para_float(char str[]);

//funções auxiliares
void conta_letras(char str[], int *tam);
void ate_virgula(char str1[], int *tam);
void depois_virgula(char str1[], int *tam2);
int eh_digito(char c);
int tamanho(char str[]);

int main(int argc, char *argv[]){

    char str1[200], str2[200];
    int p, r;
    float n;

    printf("Digite qual programa voce quer ( 1-verificar se sao anagramas, 2-contar ocorrencias e 3-converter string para float): ");
    scanf(" %d", &p);

    if(p == 1){
       
        printf("Digite uma palavra: ");
        scanf(" %s", str1);
        printf("Digite outra palavra: ");
        scanf(" %s", str2);
        
        if(sao_anagramas(str1, str2)){
            printf("Sao anagramas");
        }else{
            printf("Nao sao anagramas");
        }  
        
    }

    if(p == 2){
        
        printf("Digite uma palavra: ");
        scanf(" %[^\n]s", str1);
        setbuf(stdin, NULL);
        printf("Digite outra palavra: ");
        scanf(" %[^\n]s", str2);
        setbuf(stdin, NULL);

        r = tamanho(str2);

        printf("%d", conta_ocorrencias(str1, str2)/r );

    }

    if(p == 3){

        printf("Digite um numero: ");
        scanf(" %s", str1);

        n = string_para_float(str1);

        if(string_para_float(str1) == 0){
            printf("Numero mal formado!\n");
        }else{
            printf("Numero convertido: %f", n);
        }
        
    }

    return 0;
}

int sao_anagramas(char str1[], char str2[]){

    int tam1 = 0;
    int tam2 = 0;
    int i, j, aux;
    
    conta_letras(str1, &tam1);
    conta_letras(str2, &tam2);

    if(tam1 == tam2){
      
        //ordena string1
        for(i = 0 ; i < tam1 ; i++){
            for(j = i+1 ; j < tam1 ; j++){
                if(str1[i] > str1[j]){
                    aux = str1[i];
				    str1[i] = str1[j];
				    str1[j] = aux;
                }
            }
        }
        //ordena string2
        for(i = 0 ; i < tam1 ; i++){
            for(j = i+1 ; j < tam1 ; j++){
                if(str2[i] > str2[j]){
                    aux = str2[i];
				    str2[i] = str2[j];
				    str2[j] = aux;
                }
            }
        }
        //compara as duas strings
        for(i = 0 ; i < tam1 ; i++){
            if(str1[i] != str2[i]){
                return 0;
            }
        }

        return 1;
    }

    return 0;
}

int conta_ocorrencias(char str1[], char str2[]){

    int i;
	int j;
    int cont = 0;

    for(i = 0 ; str1[i] != '\0'; i++){
        if(str1[i] == str2[0]){
            for(j = 0 ; str2[j] != '\0' ; j++){
                if(str2[j] != str1[i+j]){
                	return 0;
                }else{
                	cont++;
				}
        	}
    	}
	}

    return cont;
}

float string_para_float(char str[]){
	
	int i;
	float n=0;
	int tam = 0;
	int tam2 = 0;
	int pot1 = 1;
	float pot2 = 1;
	
	ate_virgula(str, &tam);
	depois_virgula(str, &tam2);

	for(i = tam-1 ; i >= 0 ; i--){
		if(eh_digito(str[i])){
        int d = str[i] - 48;
		n += d * pot1;
		pot1 *= 10;
        }else{
            return 0;
        }
	}
	
	for(i = tam+1 ; str[i] != '\0' ; i++){
		if(eh_digito(str[i])){
        int d = str[i] - 48;
        pot2 /= 10;
		n += d * pot2;
        }else{
            return 0;
        }
	}
	
	return n;
}

//funções auxiliares

void conta_letras(char str[], int *tam){

    int i;

    for(i = 0 ; str[i] != '\0' ; i++){
        (*tam)++;
    }
    
}

void ate_virgula(char str1[], int *tam){
	
	int i;
	
	for(i = 0 ; str1[i] != ',' ;i++){
		(*tam)++;
	}
	
}

void depois_virgula(char str1[], int *tam2){
	
	int i, j;
	
	for(i = 0 ; str1[i] != ',' ;i++);
	for(j = i+1 ; str1[j] != '\0' ; j++){
		(*tam2)++;
	}
	
}

int eh_digito( char c ){
	return c >= '0' && c <= '9';
}

int tamanho(char str[]){
	
	int k;
	
	for(k=0 ; str[k] != '\0' ; k++)
		;
		
	return k;
}