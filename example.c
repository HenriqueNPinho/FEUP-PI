#include <stdio.h>

int main (void) 
{
    int senProx, senMov, secretaria, counterPositive = 0, counterNegative = 0; // secretaria 1 - 5
    int nsec[5] = {0, 0, 0, 0, 0}; //5 secretarias e 3 niveis de alarme
    scanf("%d %d %d", &senProx, &senMov, &secretaria);

    while (1)
    {
        if(senMov == 1 && senProx == 1) 
        {
            counterPositive++;
            counterNegative = 0;
            if(counterPositive == 2) 
            {
                nsec[secretaria - 1]++;
                counterPositive = 0;
                if(nsec[secretaria - 1] == 3) 
                {
                    printf("Movimento detetado na secretária: %d \n", secretaria);
                }
            }
        }

        if(senMov == 0 && senProx == 0) 
        {
            counterNegative++;
            counterPositive = 0;

            if(counterNegative = 2) 
            {
                counterNegative = 0;
                int temp = nsec[secretaria - 1] - 1;
                if(temp < 0) 
                {
                    nsec[secretaria - 1] = 0
                }
                printf("Nenhum movimento detetado na secretária: %d \n", secretaria);
            }
        } 

        if((senMov == 1 && senProx == 0) || (senMov == 0 && senProx == 1)) 
        { //fase de analise
            int num = 0, counterP = 0, counterN = 0;
            counterPositive = 0;
            while (num < 3)
            {
                scanf("%d %d %d", &senProx, &senMov, &secretaria);
                if()

            }
            
        }

        if(senProx == 9 && senMov == 9) break;
        scanf("%d %d %d", &senProx, &senMov, &secretaria);
    }
    
    return 0;
}