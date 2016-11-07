#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("rachete.in","r");
    output=fopen("rachete.out","w");
    int n,i,k=0,l=0,m=0;
    int a[60000];
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&a[i]);
        if(a[i]==1)   k=k+1;
        else if(a[i]==2)    l=l+1;
        else if(a[i]==3)    m=m+1;
    }
    for(i=1;i<=k;i++)
    {
        fprintf(output,"%d ",1);
    }
     for(i=1;i<=l;i++)
    {
        fprintf(output,"%d ",2);
    }
     for(i=1;i<=m;i++)
    {
        fprintf(output,"%d ",3);
    }
    fclose(input);
    fclose(output);
    return 0;
}
