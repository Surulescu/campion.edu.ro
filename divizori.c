#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("divizori.in","r");
    output=fopen("divizori.out","w");
    int m,k,N=0,intrare=1,aux,rest=0,oprire=0,temporar,repetari;
    fscanf(input,"%d",&m);
    fscanf(input,"%d",&k);
    repetari=m-k-1;
    temporar=repetari;
    N=m*m;
    while(intrare==1)
    {
        aux=k;
        repetari=temporar;
        while(repetari>0)
        {
            aux=aux+1;
            rest=N%aux;
            if(rest==k)
            {
                oprire=oprire+1;
                repetari--;
            }
            else
            {
                repetari=0;
                oprire=0;
            }
        }
        if(oprire==temporar)
        {
            intrare=0;
            fprintf(output,"%d",N);
        }
        N=m+N;
    }
    return 0;
}
