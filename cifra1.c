#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("cifra1.in","r");
    output=fopen("cifra1.out","w");
    int n,m,k=0,q,i,j,temp,l,r,z;
    int a[100];
    fscanf(input,"%d",&n);
    fscanf(input,"%d",&m);
    temp=n;
    while(n>0)
    {
        q=n%10;
        k=k+q;
        n=n/10;
    }
    l=k-m+1;
    q=0;
    r=1;
    z=0;
    while(temp>0)
    {
        q=temp%10;
        z=z+q;
        for(i=r;i<=z;i++)
        {
            a[i]=q;
            if(i==l) fprintf(output,"%d",a[i]);
        }
        r=z+1;
        temp=temp/10;
    }
    fclose(input);
    fclose(output);
    return 0;
}
