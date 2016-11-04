#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("cadouri.in","r");
    output=fopen("cadouri.out","w");
    int n,f,b,i,c,k=0,q=0;
    fscanf(input,"%d",&f);
    fscanf(input,"%d",&b);
    fscanf(input,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(input,"%d",&c);
        if(c%2==0) k=k+1;
        else q=q+1;
    }
    if(k-f>=0) k=0;
    else k=f-k;
    if(q-b>=0) q=0;
    else q=b-q;
    fprintf(output,"%d\n",k);
    fprintf(output,"%d",q);
    fclose(input);
    fclose(output);
    return 0;
}
