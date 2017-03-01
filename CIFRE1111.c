<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#define LIM 50000

int main()
{
    FILE *input,*output;
    char c;
    int cifra,v[LIM],x[LIM],i,index=0,contor=1,n,ciclu=2,l;
    input=fopen("cifre.in","r");
    output=fopen("cifre.out","w");
    do
    {
        index++;
        cifra=getc(input);
        v[index]=cifra-48;
    }
    while(cifra!='\n');
    index=index-1;
    fscanf(input,"%d",&n);
    while(n>0)
    {
        ciclu++;
        if(ciclu%2!=0)
        {
            i=1;
            contor=1;
            l=1;
            while(i<=index)
            {
                while((v[i]==v[i+1])&&(i<index))
                {
                    l++;
                    i++;
                }
                if(l<10)
                {
                    x[contor]=l;
                    contor=contor+1;
                }
                else if ((l/10==1) &&(l/100==0))
                {
                    x[contor]=l/10;
                    contor++;
                    x[contor]=l%10;
                    contor++;
                }
                else if(l/100==1)
                {
                    x[contor]=l/100;
                    contor++;
                    x[contor]=l/10%10;
                    contor++;
                    x[contor]=l%10;
                    contor++;
                }
                x[contor]=v[i];
                contor=contor+1;
                i++;
                l=1;
            }
            index=contor-1;
            for(i=1; i<LIM; i++) v[i]=0;
        }
        else
        {
                i=1;
                contor=1;
                l=1;
                while(i<=index)
                {
                    while((x[i]==x[i+1])&&(i<index))
                    {
                        l++;
                        i++;
                    }
                    if(l<10)
                    {
                        v[contor]=l;
                        contor++;
                    }
                    else if ((l/10==1) &&(l/100==0))
                    {
                        v[contor]=l/10;
                        contor++;
                        v[contor]=l%10;
                        contor++;
                    }
                    else if(l/100==1)
                    {
                        v[contor]=l/100;
                        contor++;
                        v[contor]=l/10%10;
                        contor++;
                        v[contor]=l%10;
                        contor++;
                    }
                    v[contor]=x[i];
                    contor++;
                    i++;
                    l=1;
                }
                index=contor-1;
                for(i=1; i<LIM; i++) x[i]=0;
        }
        n=n-1;
    }
    if(ciclu%2!=0)
    {
        for(i=1;i<=index;i++) fprintf(output,"%d",x[i]);
    }
    else
    {
        for(i=1;i<=index;i++) fprintf(output,"%d",v[i]);
    }
    fclose(input);
    fclose(output);
    return 0;
}
=======
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *input,*output;
    char c;
    int cifra,v[50000],i,index=0,q=1,temp=0,p=10,n,nrcf=0,aux,val;
    input=fopen("cifre.in","r");
    output=fopen("cifre.out","w");
    do
    {
        index++;
        cifra=getc(input);
        v[index]=cifra-48;
    }
    while(cifra!='\n');
    fscanf(input,"%d",&n);
    while(n>0)
    {
        q=1;
        temp=0;
        nrcf=0;
        for(i=0; i<index-1; i++)
        {
            if(v[i]==v[i+1]) temp=temp+10;
            else
            {
                temp=temp*100+q*10+v[i+1];
            }
        }
        val=temp;
        aux=temp;
        while(temp>0)
        {
            nrcf=nrcf+1;
            temp=temp/10;
        }
        index=nrcf+1;
        for(i=nrcf;i>0;i--)
        {
            v[i]=aux%10;
            aux=aux/10;
        }
        n=n-1;
    }
    fprintf(output,"%d ",val);
    fclose(input);
    fclose(input);
    return 0;
}
>>>>>>> origin/master
