#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("sircifre.in","r");
    output=fopen("sircifre.out","w");
    int n,i,j,v[510],aux[510],stop,k,max,min,indice;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&v[i]);
    }
    k=1;
    if(n==1)
    {
        fprintf(output,"%d ",v[1]);
        fprintf(output,"%d\n",1);
    }
    else
    {
        while(k!=0)
        {
            i=2;
            stop=0;
            indice=0;
            while((i<=n)&&(stop==0))
            {
                if((v[i]-v[i-1]==1)||(v[i]-v[i-1]==-1))
                {
                    stop++;
                    indice=i;
                    k=1;
                }
                else k=0;
                i++;
            }
            n=n-2*stop;
            if(n==0)
            {
                fprintf(output,"%d",-1);
                k=0;
            }
            else if(n!=0)
            {
                if(stop!=0)
                {
                    i=indice-1;
                    for(j=indice+1; j<=n+2; j++)
                    {
                        v[i]=v[j];
                        i++;
                    }
                }
                if(stop==0)
                {
                    max=0;
                    min=v[1];
                    for(i=1; i<=n; i++)
                    {
                        if(v[i]>max) max=v[i];
                        if(v[i]<=min) min=v[i];
                    }
                    for(i=1; i<=n; i++) aux[i]=0;
                    for(i=1; i<=n; i++)
                    {
                        aux[v[i]]++;
                    }
                    for(i=min; i<=max; i++)
                    {
                        if(aux[i]!=0)
                        {
                            fprintf(output,"%d ",i);
                            fprintf(output,"%d\n",aux[i]);
                        }
                    }
                    k=0;
                }
            }
        }
    }
    return 0;
}
