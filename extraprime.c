#include<stdio.h>
#include<math.h>
#define Total 664600
#define LIM 10000000
int v[LIM],j=1;

int prim(int numar)
{
    int divizor=3,stop=1;
    if((numar==1)||(numar==0)) return 0;
    while(divizor<=sqrt(numar)&&(stop==1))
    {
        if(numar%divizor==0) stop=0;
        divizor=divizor+2;
    }
    return stop;
}

int cautare(int nr,int limit)
{
    int st,dr,mij;
    st=1;
    dr=limit;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(nr==v[mij]) return 1;
        else
        {
            if(nr<v[mij]) dr=mij-1;
            else st=mij+1;
        }
    }
    return 0;
}

int extraprime(int numar,int nr_cifre)
{
    int aux,k=1,p=10,stop,prim_1,secund;
    stop=0;
    while((nr_cifre>0)&&(stop==0))
    {
        aux=numar;
        prim_1=(int)(pow(10,k)+0.5);
        secund=(int)(pow(10,k-1)+0.5);
        aux=((numar/prim_1)*secund)+(numar%secund);
        k++;
        nr_cifre--;
        if(cautare(aux,j)==0) stop=1;
    }
    if(stop==0)  return numar;
}


int main()
{
    FILE *input,*output;
    input=fopen("extraprime.in","r");
    output=fopen("extraprime.out","w");
    int a,b,intrari,nr_cifre=0,nr_prim,aux,i,min=10000000,max=0,sol=0,p;
    fscanf(input,"%d",&a);
    fscanf(input,"%d",&b);
    v[j++]=2;
    for(i=3;i<=LIM;i=i+2) v[i]=0;
    for(i=3;i<=LIM;i=i+2)
    {
        if(v[i]==0)
        {
            v[j++]=i;
            for(p=i*2;p<=LIM;p=p+i) v[p]=1;
        }
    }
    if(a%2==0) a++;
    for(i=a; i<=b; i=i+2)
    {
        if(cautare(i,j)==1)
        {
            aux=i;
            while(aux>0)
            {
                nr_cifre++;
                aux=aux/10;
            }
            if(extraprime(i,nr_cifre)==i)
            {
                sol++;
                printf("%d ",i);
                if(i>max) max=i;
                if(i<min) min=i;
            }
        }
        nr_cifre=0;
    }
    fprintf(output,"%d\n",sol);
    fprintf(output,"%d\n",min);
    fprintf(output,"%d",max);
    fclose(input);
    fclose(output);
    return 0;
}
