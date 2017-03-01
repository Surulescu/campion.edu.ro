#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("donald.in","r");
    output=fopen("donald.out","w");
    int n,i,j,l,x[303],y[303],max=0,a,b,c,k=0;
    fscanf(input,"%d",&n);
    for(i=1; i<=n*2; i++)
    {
        fscanf(input,"%d",&x[i]);
        fscanf(input,"%d",&y[i]);
    }
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            a=y[j]-y[i];
            b=x[i]-x[j];
            c=y[i]*(x[j]-x[i])-x[i]*(y[j]-y[i]);
            for(l=1; l<=n; l++)
            {
                if(x[l]*a+y[l]*b+c==0) k=k+1;
            }
            if(k>max) max=k;
            k=0;
        }
    }
    fprintf(output,"%d",max);
    fclose(input);
    fclose(output);
    return 0;
}
