#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("numere12.in","r");
    output=fopen("numere12.out","w");
    int a,b,q,k,c=0,l,m=0,nr=0;
    fscanf(input,"%d",&a);
    fscanf(input,"%d",&b);
    while(b>=a)
    {
        k=b;
        while(k>0)
        {
            c=c+1;
            k=k/10;
        }
        l=b;
        while(b>0)
        {
            q=b%10;
            if(q!=0)
            {
                if(l%q==0)
                {
                    b=b/10;
                    m=m+1;
                }
                else b=0;
            }
            else
            {
                b=b/10;
                m=m+1;
            }
        }
        if(c==m) nr=nr+1;
        c=0;
        m=0;
        b=l-1;
    }
    fprintf(output,"%d",nr);
    fclose(input);
    fclose(output);
    return 0;
}
