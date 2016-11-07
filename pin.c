#include<stdio.h>
#include<math.h>

int prim(int numar)
{
    int divizor=2,oprire=1;
    while(divizor<=sqrt(numar)&&(oprire==1))
    {
        if(numar%divizor==0) oprire=0;
        divizor++;
    }
    return oprire;
}

int main(void)
{
    FILE *input,*output;
    input=fopen("pin.in","r");
    output=fopen("pin.out","w");
    int k,p,i,q,temp,m=0,n=9999;
    fscanf(input,"%d",&k);
    fscanf(input,"%d",&p);
    while(n>1000)
    {
        if(prim(n)==1)
        {
            temp=n;
            while(temp>0)
            {
                q=temp%10;
                if((k!=q)&&(p!=q)) m=m+1;
                temp=temp/10;
            }
            if(m==4)
            {
                fprintf(output,"%d",n);
                n=1000;
            }
            m=0;
        }
        n=n-1;
    }
    fclose(input);
    fclose(output);
    return 0;
}
