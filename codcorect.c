#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("codcorect.in","r");
    output=fopen("codcorect.out","w");
    int n,i,val,prima,ultima,k=1,temp,nr,p=1,aux,r;
    fscanf(input,"%d",&n);
    if((n>0)&&(n<=20))
    {
        for(i=1; i<=n; i++)
        {
            fscanf(input,"%d",&val);
            if((val>10)&&(val<999999999))
            {
                temp=val;
                ultima=val%10;
                while(val>10)
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
                k=1;
                p=1;
            }
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}
