#include<stdio.h>
int a[200000];

int atac_inainte(int absc, int ordn, int numar)
{
    int i=0, distrugem=0;
    while((i<=numar)&&(distrugem==0))
    {
        i++;
        if(i%2==0)
        {
            if((a[i-1]>absc)&&(a[i]>ordn))
            {
                distrugem=1;
            }
        }
    }
    if (distrugem==1) return 1;
    else return 0;
}

int atac_revers(int absc,int ordn,int numar)
{
    int i,h=0;
    for(i=1; i<=numar; i++)
    {
        if(i%2==0)
        {
            if((a[i-1]!=0)&&(a[i]!=0))
            {
                if((a[i-1]<absc)&&(a[i]<ordn))
                {
                    a[i-1]=a[i]=0;
                }
                else h=h+1;
            }
        }
    }
    return h;
}

int main()
{
    FILE *input,*output;
    input=fopen("sea2.in","r");
    output=fopen("sea2.out","w");
    int n,i,j,abscisa,ordonata,v_ramase;
    fscanf(input,"%d",&n);
    for(i=1; i<=n*2; i++)
    {
        fscanf(input,"%d",&a[i]);
    }
    abscisa=a[1];
    ordonata=a[2];
    fprintf(output,"%d\n",1);
    for(i=4; i<=n*2; i++)
    {
        if(i%2==0)
        {
            if(atac_inainte(a[i-1],a[i],i)==1)
            {
                fprintf(output,"-1\n");
                a[i-1]=a[i]=0;
            }
            else
            {
                v_ramase=atac_revers(a[i-1],a[i],i);
                fprintf(output,"%d\n",v_ramase);
            }
        }
        abscisa=a[i-1];
        ordonata=a[i];

    }
    fclose(input);
    fclose(output);
    return 0;
}
