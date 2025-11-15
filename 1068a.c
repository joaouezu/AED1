#include <stdio.h>
#include <string.h>
int main(void){
    char expressao[1001];
    int verificador, i, j;

    
    while(fgets(expressao, 1000, stdin) != NULL){
        verificador = 0;
        for(j = 0; j < strlen(expressao); j++){
            if(expressao[j] == '(')
                verificador++;
                // Se vetor tem um '(' contamos como um push e incrementamos o verificador
            else{
                if(expressao[j] == ')'){
                    verificador--;
                    if(verificador < 0)
                        break;
                    // Se vetor contem '(' e ')' fazemos um pop e decrescemos o verificador
                }
            }
        }
        if(verificador == 0)
            printf("correct\n");
        else
            printf("incorrect\n");
        expressao[0] = '\0';
        // Se verificador esta zerado quer dizer que todos os parenteses estao com seus pares corretos
    }   

    return 0;
}
