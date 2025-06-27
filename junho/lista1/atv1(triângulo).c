#include <stdio.h>

int main() {
int a,b,c;
    printf("Digite o valor de 'A': \n");
    scanf("%d",&a);
    printf("Digite o valor de 'B': \n");
    scanf("%d",&b);
    printf("Digite o valor de 'C': \n");
    scanf("%d",&c);

    if(a==b && b==c) {
    printf("Seu triangulo é um triângulo Equilétero! \n");
    
    }
    else if(a==b || b==c || a==c){
        printf("Seu triangulo é um triângulo Isóceles! \n");
    }
    
    else {
        printf("Seu triangulo é um triângulo Escaleno! \n");
    }
    
    return 0;
}
