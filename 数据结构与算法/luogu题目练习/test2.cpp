#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mul(char *a,char *b)
{
    int alen,blen,len,i,j,cf;
    int *s;
    alen=strlen(a);
    blen=strlen(b);
    cf=0;   //进位标识
    s=(int*)malloc(sizeof(int)*(alen+blen));
    for(i=0; i<(alen+blen); i++)
    {
        s[i]=0;
    }
    for(i=alen-1; i>=0; i--)
    {
        for(j=blen-1; j>=0; j--)
        {
            s[(alen-1-i)+(blen-1-j)]=(a[i]-'0')*(b[j]-'0')+s[(alen-1-i)+(blen-1-j)];
        }
    }
    for(i=0; i<=(alen+blen-1); i++)
    {
        s[i]=s[i]+cf;
        if(s[i]>=10)
        {
            cf=s[i]/10;
            s[i]=s[i]%10;
        }
        else
        {
            s[i]=s[i];
            cf=0;
        }
    }
    len=0;   //高位可以不输出的0尽量不输出
    for(i=alen+blen-1;i>=0;i++)
    {
        if(s[i]==0)
        {
            len++;
        }
        else
        {
            break;
        }
    }
 
    len=alen+blen-1-len;
    for(i=len; i>=0; i--)
    {
        printf("%d",s[i]);
    }
    printf("\n");
}
int main()
{
    char n[101],m[101];
    while((scanf("%s %s",n,m))!=EOF)
    {
        mul(n,m);
    }
    return 0;
}
