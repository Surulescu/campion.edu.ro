#include<stdio.h>
int a[190001];
int c[1000000];
int b[1000000];

void ordonare(int numar)
{
    int i,j,min=1000001,max=0;
    for(i=numar; i>=1; i--)
    {
        if(a[i]<min) min=a[i];
        if(a[i]>max) max=a[i];
    }
    for(j=min; j<=max; j++) c[j]=0;
    for(i=numar; i>=1; i--)
    {
        for(j=min; j<=max; j++)
        {
            if(a[i]==j) c[j]=1;
        }
    }
    for(j=min; j<=max; j++)
    {
        if(c[j]==1)  b[j]=j;
    }
    for(j=min; j<=max; j++) printf("%d ",b[j]);
    printf("\n");
}

int numarare(int valoare)
{
    int i,temp=1,m1=1;
    for(i=valoare; i>=2; i--)
    {
        //printf("%d ",a[i]);
        //printf("%d\n",a[i-1]);
        if(a[i]-a[i-1]==1)
        {
            m1=m1+1;
            if(m1>temp) temp=m1;
        }
        else
        {
            m1=1;
        }
    }
    return temp;
}

int main()
{
    FILE *input,*output;
    input=fopen("secvente2.in","r");
    output=fopen("secvente2.out","w");
    int n,i;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++) fscanf(input,"%d",&a[i]);
    fprintf(output,"%d\n",1);
    for(i=2; i<=n; i++)
    {
        ordonare(i);
        fprintf(output,"%d\n",numarare(i));
    }
    fclose(input);
    fclose(output);
    return 0;
}
