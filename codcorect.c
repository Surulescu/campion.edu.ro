#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("codcorect.in","r");
    output=fopen("codcorect.out","w");
    int n,i,val,prima,ultima,k,temp,nr,p,aux,r;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&val);
        k=p=1;
        temp=val;
        ultima=val%10;
        while(val>=10)
        {
            k=k+1;
            val=val/10;
            p=p*10;
        }
        prima=val;
        r=prima*p;
        aux=(temp%r)/10;
        if((ultima>prima)&&(k%2!=0))
        {
            nr=ultima*p+aux*10+prima;
            fprintf(output,"%d ",nr);
        }
        else  fprintf(output,"%d ",temp);
    }
    fclose(input);
    fclose(output);
    return 0;
}
