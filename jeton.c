#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("jeton.in","r");
    output=fopen("jeton.out","w");
    int n,m,i,j,min=50000,max=0,k=0,q,l=0,h,c;
    int a[28000],b[28000];
    fscanf(input,"%d",&n);
    fscanf(input,"%d",&m);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&a[i]);
    }
    for(i=1; i<=m; i++)
    {
        fscanf(input,"%d",&b[i]);
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                if(a[i]>max) max=a[i];
                if(a[i]<min) min=a[i];
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        if((a[i]>=min)&&(a[i]<=max)) k=k+1;
    }
    q=n-k;
    for(i=1; i<=m; i++)
    {
        if((b[i]>=min)&&(b[i]<=max)) l=l+1;
    }
    h=m-l;
    if(q==h) c=0;
    else if(q>h) c=1;
    else if(q<h) c=2;
    fprintf(output,"%d ",min);
    fprintf(output,"%d ",max);
    fprintf(output,"%d",c);
    fclose(input);
    fclose(output);
    return 0;
}
