#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("sircifre.in","r");
    output=fopen("sircifre.out","w");
    int n,i,j,v[501],aux[10],stop=1;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++) fscanf(input,"%d",&v[i]);
    for(i=0; i<=9; i++) aux[i]=0;
    while(stop==1)
    {
        stop=0;
        i=1;
        while(i<=n-1)
        {
            if((v[i]+1==v[i+1])||(v[i]==v[i+1]+1))
            {
                stop=1;
                for(j=i+2; j<=n; j++)  v[j-2]=v[j];
                n=n-2;
            }
            i++;
        }
    }
    if(n==0) fprintf(output,"%d",-1);
    else
    {
        for(i=1; i<=n; i++) aux[v[i]]++;
        for(i=0; i<=9; i++)
        {
            if(aux[i]!=0)  fprintf(output,"%d %d\n",i,aux[i]);
        }
    }
    return 0;
}
