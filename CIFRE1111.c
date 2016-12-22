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
