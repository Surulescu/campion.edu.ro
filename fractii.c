#include<stdio.h>

int divizor_comun(int numarator,int numitor)
{
    while(numarator!=numitor)
    {
        if(numarator>numitor) numarator=numarator-numitor;
        else numitor=numitor-numarator;
    }
    return numarator;
}

int main()
{
    FILE *input,*output;
    input=fopen("fractii.in","r");
    output=fopen("fractii.out","w");
    int n,i,k,q;
    int a[1000];
    fscanf(input,"%d",&n);
    k=n;
    q=n+1;
    for(i=1;i<=n;i++)
    {
        a[i]=k*2;
        k=k-1;
        if(divizor_comun(a[i],q)==1)
        {
            fprintf(output,"%d ",a[i]);
            fprintf(output,"%d\n",q);
        }
        else
        {
            fprintf(output,"%d ",a[i]/divizor_comun(a[i],q));
            fprintf(output,"%d\n",q/divizor_comun(a[i],q));
        }

    }
    fclose(input);
    fclose(output);
    return 0;
}
