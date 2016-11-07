#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("cifra1.in","r");
    output=fopen("cifra1.out","w");
    int n,m,k=0,q,i,j,temp;
    fscanf(input,"%d",&n);
    fscanf(input,"%d",&m);
    temp=n;
    while(n>0)
    {
        q=n%10;
        k=q+k;
        n=n/10;
    }
    if(k>m)
    {
        for(i=k; i>=0; i--)
        {
            q=temp%10;
            for(j=k; j>=k-q; j--)
            {
                if(m==j)
                {
                    fprintf(output,"%d",q);
                    j=k-q-1;
                    i=-1;
                }
            }
            temp=temp/10;
            k=k-q;
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}
