#include<stdio.h>
#define LIM 200001
int v[LIM],prim[3],secund[3];

int main()
{
    FILE *input,*output;
    input=fopen("trei.in","r");
    output=fopen("trei.out","w");
    int n,k,i,prim_1=0,prim_2=0,secund_1=0,secund_2=0,first_prim,first_secund,p=0,l=0,r,suma_rest=0;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&v[i]);
        r=v[i]%3;
        if(r==1)
        {
            prim_1=secund_1;
            secund_1=v[i];
        }
        else if(r==2)
        {
            prim_2=secund_2;
            secund_2=v[i];
        }
        suma_rest=suma_rest+r;
    }
    r=suma_rest%3;
    //printf("%d ",prim_1);
    //printf("%d\n",secund_1);
    //printf("%d ",prim_2);
    //printf("%d ",secund_2);
    if(r==0)
    {
        k=n;
        fprintf(output,"%d",k);
    }
    else
    {
            first_prim=prim_1;
            first_secund=prim_2;
        if(prim_1!=0) p=p+1;
        if(secund_1!=0) p=p+1;
        if(prim_2!=0) l=l+1;
        if(secund_2!=0) l=l+1;
        if(p!=2)
        {
            k=n-2;
            fprintf(output,"%d\n",k);
            fprintf(output,"%d ",prim_2);
            fprintf(output,"%d ",secund_2);
        }
        else if(l!=2)
        {
            k=n-2;
            fprintf(output,"%d\n",k);
            fprintf(output,"%d ",prim_1);
            fprintf(output,"%d ",secund_1);
        }
        else if(r==1)
        {
            k=n-1;
            fprintf(output,"%d\n",k);
            fprintf(output,"%d\n",first_prim);
        }
        else if(r==2)
        {
            k=n-1;
            fprintf(output,"%d\n",k);
            fprintf(output,"%d\n",first_secund);
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}
