#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("sircifre.in","r");
    output=fopen("sircifre.out","w");
    int n,i,j=0,v[510],a[510],aux[510],stop=0,k,max,min;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&v[i]);
    }
    for(i=1; i<=n; i++) a[i]=0;
    k=1;
    while(k!=0)
    {
        for(i=1; i<=n; i++)
        {
            if(n-i==0)
            {
                j++;
                a[j]=v[i];
            }
            else
            {
                if((v[i+1]-v[i]==1)||(v[i+1]-v[i]==-1))
                {
                    j=i-1;
                    i++;
                    stop++;
                }
                else
                {
                    j++;
                    a[j]=v[i];
                }
            }
        }
        n=n-2*stop;
        if(n==0)
        {
            fprintf(output,"%d",-1);
            k=0;
        }
        else
        {
            if(stop==0)
            {
                max=0;min=v[1];
                for(i=1;i<=n;i++)
                {
                    if(v[i]>max) max=v[i];
                    if(v[i]<=min) min=v[i];
                }
                for(i=min; i<=max; i++) aux[i]=0;
                for(i=1; i<=n; i++)
                {
                    aux[a[i]]++;
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
            else
            {
                for(i=1; i<=n; i++)
                {
                    v[i]=a[i];
                }
                k=1;
                stop=0;
                j=0;
            }
        }
    }
    return 0;
}
