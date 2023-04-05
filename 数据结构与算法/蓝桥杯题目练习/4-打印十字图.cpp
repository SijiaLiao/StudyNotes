#include <stdio.h>  

int go(int i, int j, int n) 
{      
    //上下对称
    if (i > n * 2 + 3)         
        i = n * 4 + 6 - i;
    //左右对称
    if (j > n * 2 + 3)         
        j = n * 4 + 6 - j;
    //前两行时显示的为 '.'      
    if (i <= 2 && j <= 2) return 0; 
    //每一奇数行连续的三个$     
    if (i % 2 == 1 && j >= i - 2) return 1;
    //每一个奇数列中奇异点     
    if (j % 2 == 1 && j != i - 1) return 1;     
    return 0; 
}

int main() 
{      
    int n;      
    scanf("%d", &n);           
    int i, j;      
    for (i = 1; i <= n*4+5; i++)     
    {          
        for (j = 1; j <= n*4+5; j++)         
        {              
            if (go(i, j, n))                 
            printf("$");             
            else                  
            printf(".");         
        }          
        printf("\n");     
    }           
    return 0; 
} 
