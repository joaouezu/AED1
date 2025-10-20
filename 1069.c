#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int n;
    if(scanf("%d", &n) != 1)
        return 0;
    getchar();
    char string[1001];
    while (n-- > 0) {
    if (fgets(string, sizeof(string), stdin) == NULL)
        break;
        int verificar = 0, diamantes = 0, i;
        for (i = 0; string[i] != '\0'; i++) {
            if (string[i] == '<')
                verificar++;
            else 
                if(string[i] == '>') {
                    if (verificar > 0) {
                        diamantes++;
                        verificar--;
                    
                }
            }
        }
        printf("%d\n", diamantes);
    }
    return 0;
}

    
