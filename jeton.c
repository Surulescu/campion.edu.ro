#include<stdio.h>
#define LIMIT 50001
int main()
{
    FILE *input,*output;
    input=fopen("jeton.in","r");
    output=fopen("jeton.out","w");
    int n,m,i,j,min=LIMIT,max=0,temp,k=0,l=0,c,stop;
    int a[LIMIT],b[LIMIT];
    fscanf(input,"%d",&n);
    fscanf(input,"%d",&m);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&temp);
        a[temp]=a[temp]+1;
    }
    for(i=1; i<=m; i++)
    {
        fscanf(input,"%d",&temp);
        b[temp]=b[temp]+1;
    }
    i=1;
    stop=0;
    while((i<LIMIT)&&(stop==0))
    {
        if((a[i]>=1)&&(b[i]>=1)) stop=1;
        i=i+1;
    }
    i=i-1;
    min=i;
    i=LIMIT-1;
    stop=0;
    while((i>=1)&&(stop==0))
    {
        if((a[i]>=1)&&(b[i]>=1)) stop=1;
        i=i-1;
    }
    i=i+1;
    max=i;

    for(i=1;i<min;i++)
    {
        if(a[i]>=1) k=k+a[i];
        if(b[i]>=1) l=l+b[i];
    }

    for(i=max+1;i<LIMIT;i++)
    {
        if(a[i]>=1) k=k+a[i];
        if(b[i]>=1) l=l+b[i];
    }

    if(k==l) c=0;
    if(k>l) c=1;
    if(k<l) c=2;
    fprintf(output,"%d ",min);
    fprintf(output,"%d ",max);
    fprintf(output,"%d",c);
    fclose(input);
    fclose(output);
    return 0;
}
