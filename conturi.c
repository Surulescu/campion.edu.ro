#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("conturi.in","r");
    output=fopen("conturi.out","w");
    int n,x,i,val,q,k,z,temp=0,j,max=0;
    fscanf(input,"%d",&n);
    fscanf(input,"%d",&x);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&val);
        q=val/100000;
        k=((val/10000)%10);
        z=val%10000;
        if (q==x)
        {
            if(k==1)
            {
                if(z>max) max=z;
            }
        }

    }
    fprintf(output,"%d",max);
    fclose(input);
    fclose(output);
    return 0;
}
