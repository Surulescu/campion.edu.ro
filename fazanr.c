#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("fazanr.in","r");
    output=fopen("fazanr.out","w");
    int n,i,val,k,q,l,w=0,t,p;
    fscanf(input,"%d",&n);
    fscanf(input,"%d",&val);
    k=val%10;
    for(i=2;i<=n;i++)
    {
        fscanf(input,"%d",&val);
        p=val;
        while(val>10)
        {
            val=val/10;
        }
        t=val;
        q=p%10;
        if(k!=t) w=w+1;
        k=q;
    }
    fprintf(output,"%d\n",w);
    fclose(input);
    fclose(output);
    return 0;
}
