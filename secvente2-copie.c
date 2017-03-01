<<<<<<< HEAD
#include<stdio.h>
#define LIM 1000010
int x[LIM];

int main()
{
    FILE *input,*output;
    input=fopen("secvente2.in","r");
    output=fopen("secvente2.out","w");
    int n,i,nr,temp,max=1,aux;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&temp);
        if((x[temp-1]==0)&&(x[temp+1]==0))
        {
            x[temp]=temp;
            nr=1;
        }
        else if((x[temp-1]!=0)&&(x[temp+1]==0))
        {
            x[temp]=x[temp-1];
            x[x[temp]]=temp;
            nr=temp-x[temp]+1;
        }
         else if((x[temp+1]!=0)&&(x[temp-1]==0))
        {
            x[temp]=x[temp+1];
            x[x[temp]]=temp;
            nr=x[temp]-temp+1;
        }
        else if((x[temp-1]!=0)&&(x[temp+1]!=0))
        {
            aux=x[temp-1];
            x[x[temp-1]]=x[temp+1];
            x[x[temp+1]]=aux;
            nr=x[aux]-aux+1;
        }
        if(nr>max) max=nr;
        fprintf(output,"%d\n",max);
    }
    fclose(input);
    fclose(output);
    return 0;
}
=======
#include<stdio.h>
int a[190001];
int b[190001];
int c[1000000];

void ordonare(int numar)
{
    int i,j,min=1000001,max=0;
    for(i=numar; i>=1; i--)
    {
        if(a[i]<min) min=a[i];
        if(a[i]>max) max=a[i];
    }
    for(i=min;i<=max;i++) c[i]=0;
    for(i=numar; i>=1; i--)     c[a[i]]=c[a[i]]+1;
    for(j=min+1; j<=max; j++)   c[j]=c[j-1]+c[j];
    for(i=1;i<=numar;i++)
    {
        b[c[a[i]]]=a[i];
        c[a[i]]=c[a[i]]-1;
    }
}

int numarare(int valoare)
{
    int i,temp=1,m1=1;
    for(i=valoare; i>=2; i--)
    {
        if(b[i]-b[i-1]==1)
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
>>>>>>> origin/master
