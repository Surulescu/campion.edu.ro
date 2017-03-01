#include<stdio.h>
#include<math.h>
int v[1010];

int main()
{
    FILE *input,*output;
    input=fopen("test2.in","r");
    output=fopen("test2.out","w");
    int n,k,i,nr_cifre,aux,p,l,m;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&v[i]);
        aux=v[i];
        nr_cifre=0;
        while(aux>0)
        {
            nr_cifre++;
            aux=aux/10;
        }
        if(nr_cifre>=i)
        {
            p=(int)(pow(10,i)+0.5);
            l=(int)(pow(10,i-1)+0.5);
            v[i]=(v[i]/p)*l+(v[i]%l);
            fprintf(output,"%d ",v[i]);
        }
        else if(nr_cifre<i)
        {
            k=i%nr_cifre;
            if(k==0)
            {
                m=(int)(pow(10,nr_cifre-1)+0.5);
                v[i]=v[i]%m;
                fprintf(output,"%d ",v[i]);
            }
            else
            {
                p=(int)(pow(10,k)+0.5);
                l=(int)(pow(10,k-1)+0.5);
                v[i]=(v[i]/p)*l+(v[i]%l);
                fprintf(output,"%d ",v[i]);
            }
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}
