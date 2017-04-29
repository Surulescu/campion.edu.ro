#include<stdio.h>

int cmmmc(int a,int b)
{
    int i,aux,stop,p,m;
    aux=a*(a+1);
    a=a+2;
    for(i=a;i<b;i++)
    {
        stop=0;
        m=aux;
        p=2;
        while(stop==0)
        {
            if(aux%i==0) stop=1;
            else
            {
                aux=m*p;
                p++;
            }
        }
    }
    return aux;
}


int main()
{
    FILE *input,*output;
    input=fopen("divizori.in","r");
    output=fopen("divizori.out","w");
    int m,k,N=0,x=0,nr_cautat,oprire=1;
    fscanf(input,"%d",&m);
    fscanf(input,"%d",&k);
    k++;
    nr_cautat=cmmmc(k,m);
    while(oprire==1)
    {
        x++;
        N=x*nr_cautat+(k-1);
        //printf("%d\n",N%m);
        //printf("%d\n",N);
        if(N%m==0)
        {
            oprire=0;
            fprintf(output,"%d",N);
        }
    }
    return 0;
}
