#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 50

typedef struct Cadastro{
    int matricula, idade, registro;
    char nome[50], sexo[10];
    float notas[max][4];
}Cadastro;

Cadastro alunos[max];

int adicionar();
int analisar(int m);
float verificar_media(float n1, float n2, float n3);
void pesquisar();
void exibir();
void aprovados();
void reprovados();
void salvar_carregar();
void salvar();
void carregar();
int space();

int main(){

    int op;
    do{
        system("cls");
        printf("UNIVERSIDADE - BANCO DE DADOS\n\n");
        printf("[1] Adicionar\n\n");
        printf("[2] Pesquisar\n\n");
        printf("[3] Exibir\n\n");
        printf("[4] Salvar/Carregar\n\n");
        printf("[0] Sair\n\n");
        printf("Op%c%co: ", 135, 198);
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch(op){
            case 1:
                adicionar();
            break;
            case 2:
                pesquisar();
            break;
            case 3:
                exibir();
            break;
            case 4:
                salvar_carregar();
            break;
        }
    }while(op != 0);

    return 0;
}

int adicionar(){
    int matricula, idade;
    char nome[50], sexo[10];
    float notas[4];
    if (space() == 0){
        printf("\nDesculpe, o sistema esta lotado\n\n");
        system("pause");
        return 1;
    }
    setbuf(stdin, NULL);
    system("cls");
    printf("UNIVERSIDADE - BANCO DE DADOS\n\n");
    printf("ADICIONAR USU%cRIO\n\n", 181);
    printf("Matr%ccula: ", 161);
    scanf("%d", &matricula);
    if(analisar(matricula)){
        printf("\nEsta matr%ccula j%c esta cadastrada\n\n", 161, 160);
    }
    else{
        setbuf(stdin, NULL);
        printf("\nNome: ");
        gets(nome);
        setbuf(stdin, NULL);
        printf("\nIdade: ");
        scanf("%d", &idade);
        printf("\nSexo: ");
        scanf("%s", sexo);
        printf("\nAV1: ");
        scanf("%f", &notas[0]);
        printf("\nAV2: ");
        scanf("%f", &notas[1]);
        printf("\nAV3: ");
        scanf("%f", &notas[2]);
        notas[3] = verificar_media(notas[0], notas[1], notas[2]);
        printf("\nM%cdia Final: %.1f\n\n", 130, notas[3]);
        setbuf(stdin, NULL);
        for (int i = 0; i < max; i++)
        {
            if (alunos[i].registro == 0){
                alunos[i].matricula = matricula;
                strcpy(alunos[i].nome, nome);
                alunos[i].idade = idade;
                strcpy(alunos[i].sexo, sexo);
                for (int j = 0; j < 4; j++){
                    alunos[i].notas[i][j] = notas [j];
                }
                alunos[i].registro = 1;
                break;
            }
        }
    }
    system("pause");
    return 0;
}

void pesquisar(){
    int j=0, matricula;
    char op;
    system("cls");
    setbuf(stdin, NULL);
    printf("UNIVERSIDADE - BANCO DE DADOS\n\n");
    printf("PESQUISAR USU%cRIO\n\n", 181);
    printf("Matr%ccula para Pesquisa: ", 161);
    scanf("%d", &matricula);
    setbuf(stdin, NULL);
    if (analisar(matricula)){
        for (int i = 0; i < max; ++i)
        {
            if (matricula == alunos[i].matricula)
            {
                printf("\nMatr%ccula: %d\n", 161, alunos[i].matricula);
                printf("Nome: %s\n", alunos[i].nome);
                printf("Idade: %d\n", alunos[i].idade);
                printf("Sexo: %s\n", alunos[i].sexo);
                printf("AV1: %.1f\n", alunos[i].notas[i][j]);
                printf("AV2: %.1f\n", alunos[i].notas[i][j+1]);
                printf("AV3: %.1f\n", alunos[i].notas[i][j+2]);
                printf("M%cdia Final: %.1f\n\n", 130, alunos[i].notas[i][j+3]);
            }
        }
        system("pause");
    }
    else{
	    setbuf(stdin, NULL);
	    printf("\nEsta matr%ccula n%co esta cadastrada\nVoc%c deseja adicionar esta matr%ccula no sistema? [S/N] >>", 161, 198, 136, 161);
	    scanf("%c", &op);
	    setbuf(stdin, NULL);
	    if (toupper(op) == 'S'){
	        adicionar();
	    }
	}
}

int analisar(int m){
    for (int i = 0; i < max; i++){
        if (m == alunos[i].matricula){
            return 1;
        }
    }
    return 0;
}

void exibir(){
    int op;
    do{
        system("cls");
        setbuf(stdin, NULL);
        printf("UNIVERSIDADE - BANCO DE DADOS\n\n");
        printf("EXIBIR USU%cRIOS\n\n", 181);
        printf("[1] Aprovados\n\n");
        printf("[2] Reprovados\n\n");
        printf("[3] Todos\n\n");
        printf("[0] Voltar\n\n");
        printf("Op%c%co: ", 135, 198);
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch (op){
            case 1:
                aprovados();
            break;
            case 2:
                reprovados();
            break;
            case 3:
                system("cls");
                printf("TODOS OS ALUNOS\n\n");
                for (int i = 0; i < max; i++){
                    int j=0;
                    if (alunos[i].registro == 1){
                        printf("Matr%ccula: %d\n", 161, alunos[i].matricula);
                        printf("Nome: %s\n", alunos[i].nome);
                        printf("Idade: %d\n", alunos[i].idade);
                        printf("Sexo: %s\n", alunos[i].sexo);
                        printf("AV1: %.1f\n", alunos[i].notas[i][j]);
                        printf("AV2: %.1f\n", alunos[i].notas[i][j+1]);
                        printf("AV3: %.1f\n", alunos[i].notas[i][j+2]);
                        printf("M%cdia Final: %.1f\n", 130, alunos[i].notas[i][j+3]);
                        printf("\n========================\n\n");
                    }
                }
                system("pause");
            break;
        }
    }while(op != 0);
    system("pause");
}

void aprovados(){
    int op;
    do{
        system("cls");
        setbuf(stdin, NULL);
        printf("UNIVERSIDADE - BANCO DE DADOS\n\n");
        printf("USU%cRIOS APROVADOS\n\n", 181);
        printf("[1] M%cdia >=7\n\n", 130);
        printf("[2] M%cdia >=9\n\n", 130);
        printf("[0] Voltar\n\n");
        printf("Op%c%co: ", 135, 198);
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch (op){
            case 1:
            system("cls");
            printf("USU%cRIOS COM M%cDIA >= 7\n\n", 181, 144);
            for (int i = 0; i < max; i++){
                if (alunos[i].registro == 1){
                    float media;
                    int j=0;
                    media = alunos[i].notas[i][3];
                    if (media >= 7){
                        printf("Matr%ccula: %d\n", 161, alunos[i].matricula);
                        printf("Nome: %s\n", alunos[i].nome);
                        printf("Idade: %d\n", alunos[i].idade);
                        printf("Sexo: %s\n", alunos[i].sexo);
                        printf("AV1: %.1f\n", alunos[i].notas[i][j]);
                        printf("AV2: %.1f\n", alunos[i].notas[i][j+1]);
                        printf("AV3: %.1f\n", alunos[i].notas[i][j+2]);
                        printf("M%cdia Final: %.1f\n", 130, alunos[i].notas[i][j+3]);
                        printf("\n========================\n\n");
                    }
                }
            }
            system("pause");
            break;
            case 2:
            system("cls");
            printf("USU%cRIOS COM M%cDIA >= 9\n\n", 181, 144);
            for (int i = 0; i < max; i++){
                if (alunos[i].registro == 1){
                    int j=0;
                    float media;
                    media = alunos[i].notas[i][3];
                    if (media >= 9){
                        printf("Matr%ccula: %d\n", 161, alunos[i].matricula);
                        printf("Nome: %s\n", alunos[i].nome);
                        printf("Idade: %d\n", alunos[i].idade);
                        printf("Sexo: %s\n", alunos[i].sexo);
                        printf("AV1: %.1f\n", alunos[i].notas[i][j]);
                        printf("AV2: %.1f\n", alunos[i].notas[i][j+1]);
                        printf("AV3: %.1f\n", alunos[i].notas[i][j+2]);
                        printf("M%cdia Final: %.1f\n", 130, alunos[i].notas[i][j+3]);
                        printf("\n========================\n\n");
                    }
                }
            }
            system("pause");
            break;
        }
    }while(op != 0);
    system("pause");
}

void reprovados(){
    int j=0, op;
    do{
        system("cls");
        setbuf(stdin, NULL);
        printf("UNIVERSIDADE - BANCO DE DADOS\n\n");
        printf("USU%cRIOS REPROVADOS\n\n", 181);
        printf("[1] M%cdia <7\n\n", 130);
        printf("[2] M%cdia <5\n\n", 130);
        printf("[0] Voltar\n\n");
        printf("Op%c%co: ", 135, 198);
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch (op){
            case 1:
            system("cls");
            printf("USU%cRIOS COM M%cDIA < 7\n\n", 181, 144);
            for (int i = 0; i < max; i++){
                if (alunos[i].registro == 1){
                    int j=0;
                    float media;
                    media = alunos[i].notas[i][3];
                    if (media < 7){
                        printf("Matr%ccula: %d\n", 161, alunos[i].matricula);
                        printf("Nome: %s\n", alunos[i].nome);
                        printf("Idade: %d\n", alunos[i].idade);
                        printf("Sexo: %s\n", alunos[i].sexo);
                        printf("AV1: %.1f\n", alunos[i].notas[i][j]);
                        printf("AV2: %.1f\n", alunos[i].notas[i][j+1]);
                        printf("AV3: %.1f\n", alunos[i].notas[i][j+2]);
                        printf("M%cdia Final: %.1f\n", 130, alunos[i].notas[i][j+3]);
                        printf("\n========================\n\n");
                    }
                }
            }
            system("pause");
            break;
            case 2:
            j=0;
            system("cls");
            printf("USU%cRIOS COM M%cDIA < 5\n\n", 181, 144);
            for (int i = 0; i < max; i++){
                if (alunos[i].registro == 1){
                    int j=0;
                    float media;
                    media = alunos[i].notas[i][3];
                    if (media < 5){
                        printf("Matr%ccula: %d\n", 161, alunos[i].matricula);
                        printf("Nome: %s\n", alunos[i].nome);
                        printf("Idade: %d\n", alunos[i].idade);
                        printf("Sexo: %s\n", alunos[i].sexo);
                        printf("AV1: %.1f\n", alunos[i].notas[i][j]);
                        printf("AV2: %.1f\n", alunos[i].notas[i][j+1]);
                        printf("AV3: %.1f\n", alunos[i].notas[i][j+2]);
                        printf("M%cdia Final: %.1f\n", 130, alunos[i].notas[i][j+3]);
                        printf("\n========================\n\n");
                    }
                }
            }
            system("pause");
            break;
        }
    }while(op != 0);
    system("pause");
}

void salvar_carregar(){
    int op;
    do{
        system("cls");
        setbuf(stdin, NULL);
        printf("UNIVERSIDADE - BANCO DE DADOS\n\n");
        printf("SALVAR/CARREGAR ARQUIVO\n\n");
        printf("[1] Salvar\n\n");
        printf("[2] Carregar\n\n");
        printf("[0] Voltar\n\n");
        printf("Op%c%co: ", 135, 198);
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch (op){
            case 1:
                salvar();
            break;
            case 2:
                carregar();
            break;
        }
    }while(op != 0);
    system("pause");
}

void salvar(){
    FILE *arq;
    char nome_arq[50];
    int j;
    system("cls");
    setbuf(stdin, NULL);
    printf("SALVAR ARQUIVO\n\n");
    setbuf(stdin, NULL);
    printf("Nome do arquivo: ");
    gets(nome_arq);
    setbuf(stdin, NULL);
    strcat(nome_arq,".txt");
    arq = fopen(nome_arq,"w");
        for (int i = 0; i < max; ++i){
            if (alunos[i].registro == 1){
                j=0;
                fprintf(arq, "Matrícula: %d\n", alunos[i].matricula);
                fprintf(arq, "Nome: %s\n", alunos[i].nome);
                fprintf(arq, "Idade: %d\n", alunos[i].idade);
                fprintf(arq, "Sexo: %s\n", alunos[i].sexo);
                fprintf(arq, "AV1: %.1f\n", alunos[i].notas[i][j]);
                fprintf(arq, "AV2: %.1f\n", alunos[i].notas[i][j+1]);
                fprintf(arq, "Av3: %.1f\n", alunos[i].notas[i][j+2]);
                fprintf(arq, "Média Final: %.1f\n\n", alunos[i].notas[i][j+3]);
                fprintf(arq, "========================================\n\n");
            }

        }
    fclose(arq);
    printf("\nArquivo salvo com sucesso!\n\n");
    system("pause");
}

void carregar(){
    FILE *arq;
    char nome_arq[50], n1[50];
    int j;
    for (int i = 0; i < max; ++i){
        alunos[i].registro = 0;}

    system("cls");
    setbuf(stdin, NULL);
    printf("CARREGAR ARQUIVO\n\n");
    printf("Nome do arquivo: ");
    gets(nome_arq);
    setbuf(stdin, NULL);
    strcat(nome_arq,".txt");
    arq = fopen(nome_arq,"r");
    if(arq == NULL)
        printf("\nArquivo n%co encontrado\n\n", 198);
    else{
        for (int i = 0; i < max; i++){
            j=0;
            while(!feof(arq)){
                fseek(arq,11,1); fscanf(arq,"%d\n", &alunos[i].matricula);
                fseek(arq,6,1); fgets(alunos[i].nome, 50, arq); alunos[i].nome[strlen(alunos[i].nome) - 1] = '\0';
                fseek(arq,7,1); fscanf(arq,"%d\n", &alunos[i].idade);
                fseek(arq,6,1); fscanf(arq,"%s\n", alunos[i].sexo);
                fseek(arq,5,1); fscanf(arq,"%f\n", &alunos[i].notas[i][j]);
                fseek(arq,5,1); fscanf(arq,"%f\n", &alunos[i].notas[i][j+1]);
                fseek(arq,5,1); fscanf(arq,"%f\n", &alunos[i].notas[i][j+2]);
                fseek(arq,13,1); fscanf(arq,"%f\n\n", &alunos[i].notas[i][j+3]);
                fseek(arq,0,1); fscanf(arq,"%s\n\n", n1);
                alunos[i].registro = 1;
                break;
            }
        }

        printf("\nArquivo carregado com sucesso!\n\n");
    }
    fclose(arq);
    system("pause");
}

float verificar_media(float n1, float n2, float n3){
    float media;
    if (n1 >= n2 && n2 >= n3){
        media = (n1 + n2)/2;
        return media;
    }

    else if (n1 >= n3 && n3 >= n2){
        media = (n1 + n3)/2;
        return media;
    }

    else if (n2 >= n1 && n1 >= n3){
        media = (n2 + n1)/2;
        return media;
    }

    else if (n2 >= n3 && n3 >= n1){
        media = (n2 + n3)/2;
        return media;
    }

    else if (n3 >= n1 && n1 >= n2){
        media = (n3 + n1)/2;
        return media;
    }

    else if (n3 >= n2 && n2 >= n1){
        media = (n3 + n2)/2;
        return media;
    }
    return 0;
}

int space(){
    for (int i = 0; i < max; ++i){
        if (alunos[i].registro == 0){
            return 1;
        }
    }
    return 0;
}
