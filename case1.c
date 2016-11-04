#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("case1.in","r");
    output=fopen("case1.out","w");
    int n,a,b,c,d,i,val,r1=0,r2=0,r3=0,k=0,z=0,y=0;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&val);
        a=val/1000;
        b=((val/100)%10);
        c=((val/10)%10);
        d=val%10;
        if(a==1) r1=r1+1;
        else if(a==2) r2=r2+1;
             else r3=r3+1;
        k=k+b;
        z=z+c;
        y=y+d;
    }
    fprintf(output,"%d\n",r1);
    fprintf(output,"%d\n",r2);
    fprintf(output,"%d\n",r3);
    fprintf(output,"%d\n",k);
    fprintf(output,"%d\n",z);
    fprintf(output,"%d",y);
    fclose(input);
    fclose(output);
    return 0;
}
