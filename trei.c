#include<stdio.h>
#define LIM 200001
int v[LIM],prim[3],secund[3];

int main()
{
    FILE *input,*output;
    input=fopen("trei.in","r");
    output=fopen("trei.out","w");
    int n,k,i,j=1,y=1,first_prim,first_secund,p=0,l=0,r,suma_rest=0;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&v[i]);
        r=v[i]%3;
        if(r==1)
        {
            if(j<=2)
            {
                prim[j]=v[i];
                j++;
            }
        }
        else if(r==2)
        {
            if(y<=2)
            {
                secund[y]=v[i];
                y++;
            }
        }
        suma_rest=suma_rest+r;
    }
    r=suma_rest%3;
    if(r==0)
    {
        k=n;
        fprintf(output,"%d",k);
    }
    else
    {
        for(i=1; i<=1; i++)
        {
            first_prim=prim[i];
            first_secund=secund[i];
        }
        for(i=1; i<=2; i++)
        {
            if(prim[i]!=0) p=p+1;
            if(secund[i]!=0) l=l+1;
        }
        if((r==1)&&(p>=1))
        {
            k=n-1;
            fprintf(output,"%d\n",k);
            fprintf(output,"%d ",prim[1]);
        }
        else if((r==2)&&(l>=1))
        {
            k=n-1;
            fprintf(output,"%d\n",k);
            fprintf(output,"%d ",secund[1]);
        }
        else if (p==0)
        {
            k=n-2;
            fprintf(output,"%d\n",k);
            fprintf(output,"%d %d",secund[1],secund[2]);
        }
        else if(l==0)
        {
            k=n-2;
            fprintf(output,"%d\n",k);
            fprintf(output,"%d %d",prim[1],prim[2]);
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}
