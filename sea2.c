#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("sea2.in","r");
    output=fopen("sea2.out","w");
    int n,i,j,x,y,k,abscisa=0,ordonata=0,q=0;
    int a[200000];
    fscanf(input,"%d",&n);
    for(i=1; i<=n*2; i++)
    {
        fscanf(input,"%d",a[i])
        if(i%2==0)
        {
            if((abscisa>a[i-1])&&(ordonata>a[i]))
            {
                printf("%d\n",-1);
                abscisa=a[i-1];
                ordonata=a[i];
            }
            else if((abscisa<a[i-1])&&(ordonata<a[i]))
            {
                if()
            }
            else
            {
                q=q+1;
                printf("%d\n",q);
            }
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}
