#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("sircifre.in","r");
    output=fopen("sircifre.out","w");
    int n,i,j=0,v[510],a[510],aux[510],stop=0,k,end;
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
            //printf("%d\n",j);
        }
        n=n-2*stop;
        printf("%d\n",stop);
        //for(i=1;i<=n;i++) printf("%d ",a[i]);
        printf("\n");
        if(n==0)
        {
            fprintf(output,"%d",-1);
            k=0;
        }
        else
        {
            if(stop==0)
            {
                for(i=1; i<=n; i++) aux[i]=0;
                //for(i=1; i<=n; i++) printf("%d ",aux[i]);
                for(i=1; i<=n; i++)
                {
                    aux[a[i]]++;
                }
                //for(i=1; i<=n; i++) printf("%d ",aux[i]);
                for(i=1; i<=n; i++)
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
                //for(i=1;i<=n;i++) printf("%d ",v[i]);
                k=1;
                stop=0;
                j=0;
            }
        }
    }
    return 0;
}
