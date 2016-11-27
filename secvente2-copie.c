#include<stdio.h>
int a[190001];

int ordonare(int numar)
{
    int i,aux,stop=0;
    while(stop==0)
    {
        stop=1;
        for(i=numar;i>=2;i--)
        {
            if(a[i]<a[i-1])
            {
                aux=a[i-1];
                a[i-1]=a[i];
                a[i]=aux;
                stop=0;
            }
        }
    }
    return;
}

int numarare(int valoare)
{
    int i,temp=1,m1=1,r;
    for(i=1;i<=valoare-1;i++)
    {
        if(a[i]-a[i+1]==-1) m1=m1+1;
        else
        {
            if(m1>temp)
            {
                temp=m1;
                m1=1;
            }
        }
    }
    if(temp==1) r=m1;
    else r=temp;
    return r;
}

int main()
{
    FILE *input,*output;
    input=fopen("secvente2.in","r");
    output=fopen("secvente2.out","w");
    int n,i,k,q=1;
    fscanf(input,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(input,"%d",&a[i]);
    }
    fprintf(output,"%d\n",1);
    for(i=2;i<=n;i++)
    {
        ordonare(i);
        fprintf(output,"%d\n",numarare(i+1));
    }
    fclose(input);
    fclose(output);
    return 0;
}
