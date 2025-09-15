#include <stdio.h>

/*int jogo[9][9];

int verificaLinha(int);
int verificaColuna(int);
int verificaQuadrado(int);
void imprime();
void preenche();

int main(){
    int linha, coluna, i, j, instancias, cont=0;
    char resposta;

    scanf("%d", &instancias);

    do{
        printf("Instancia %d\n", cont+1);
    if(verificaLinha && verificaColuna && verificaQuadrado == 1)
        printf("SIM\n");
    else
    printf("NAO\n");
    cont++;
    }while(cont < instancias);
}
int verificaLinha(jogo){
    int ver1=ver2=ver3=ver4=ver5=ver6=ver7=ver8=ver9=0;
    for(int i=0;i<9;i++){
        if(jogo[i] == 1)ver1++;
        if(jogo[i]== 2)ver2++;
        if(jogo[i]==3)ver3++;
        if(jogo[i]==4)ver4++;
        if(jogo[i]==5)ver5++;
        if(jogo[i]==6)ver6++;
        if(jogo[i]==7)ver7++;
        if(jogo[i]==8)ver8++;
        if(jogo[i]==9)ver9++;
    }
    if(ver1=ver2=ver3=ver4=ver5=ver6=ver7=ver8=ver9=1)return 1;
    else return 0;
}
int verificaColuna(jogo){
    int ver1=ver2=ver3=ver4=ver5=ver6=ver7=ver8=ver9=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
        if(jogo[i][j] == 1)ver1++;
        if(jogo[i][j]== 2)ver2++;
        if(jogo[i][j]==3)ver3++;
        if(jogo[i][j]==4)ver4++;
        if(jogo[i][j]==5)ver5++;
        if(jogo[i][j]==6)ver6++;
        if(jogo[i][j]==7)ver7++;
        if(jogo[i][j]==8)ver8++;
        if(jogo[i][j]==9)ver9++;
    }
}
    if(ver1=ver2=ver3=ver4=ver5=ver6=ver7=ver8=ver9=1)return 1;
    else return 0;
}



void preenche(){
    int i, j;
    for (i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++){
            scanf("%d", &jogo[i][j]);
        }
    }
}*/