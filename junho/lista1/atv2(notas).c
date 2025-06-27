#include <stdio.h>

int main() {
float a,b,c;

while(1) {
    printf("Digite a primeira nota: \n");
    scanf("%f",&a);
    
    printf("Digite a segunda nota: \n");
    scanf("%f",&b);
    
    c=(a+b)/2;
    
    if(c>=0){
        
        if(c>=9) {
            printf("Aluno nota A\n");
        }
        
        else if(c>=7){
            printf("Aluno nota B\n");
        }
        
        else if(c>=5){
            printf("Aluno nota C\n");
        }
        
        else {
            printf("Aluno nota D\n");
        }
        break;
    }
    
    else {
        printf("Nota inválida, tente novamente\n");
    }
}
    return 0;
}
