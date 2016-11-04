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
        if(p==q)
        {
            pr=pr+1;
            rd=rd+1;
            bl=bl+1;
            p=(rd+1)*k;
            q=q+w;
        }else if(i==p)
        {
            rd=rd+1;
            p=(rd+1)*k;
        }else if(i==q)
        {
            bl=bl+1;
            q=q+w;
        }
    }
    rd=rd-pr;
    bl=bl-pr;
    total=n-rd-bl-pr;
    fprintf(output,"%d\n",total);
    fprintf(output,"%d\n",rd);
    fprintf(output,"%d\n",bl);
    fprintf(output,"%d",pr);
    fclose(input);
    fclose(output);
    return 0;
}
