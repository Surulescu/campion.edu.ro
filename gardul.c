#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("gardul.in","r");
    output=fopen("gardul.out","w");
    int n,p,q,i,rd=0,bl=0,pr=0,total,k,w;
    fscanf(input,"%d",&n);
    fscanf(input,"%d",&p);
    fscanf(input,"%d",&q);
    k=p;
    w=q;
    for(i=1;i<=n;i++)
    {
        if((i%p==0)&&(i%q!=0)) rd++;
        if((i%q==0)&&(i%p!=0)) bl++;
        if((i%p==0)&&(i%q==0)) pr++;
    }
    fprintf(output,"%d\n",n-rd-bl-pr);
    fprintf(output,"%d\n",rd);
    fprintf(output,"%d\n",bl);
    fprintf(output,"%d",pr);
    fclose(input);
    fclose(output);
    return 0;
}
