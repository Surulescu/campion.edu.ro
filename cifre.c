#include<stdio.h>
#include<math.h>

int numarare(int valoare)
{
    int nr=0;
    while(valoare>0)
    {
        nr=nr+1;
        valoare=valoare/10;
    }
    return nr;
}

int main()
{
    FILE *input,*output;
    input=fopen("cifre.in","r");
    output=fopen("cifre.out","w");
    int n,val,i,p,q,aux,nr_cf,prima,next_cf,nr_cf_init,temp;
    fscanf(input,"%d",&val);
    fscanf(input,"%d",&n);
    for(i=2;i<=n;i++)
    {
        //printf("%d ",n);
        //printf("%d ",val);
        nr_cf=numarare(val);
        //printf("%d ",nr_cf);
        nr_cf_init=nr_cf;
        //printf("%d ",nr_cf_init);
        p=10;
        temp=0;
        q=1;
        while(val>0)
        {
            prima=val/(int)(pow(10,nr_cf-1));
            printf("%d ",prima);
            val=val%((int) pow(10,nr_cf-1));
            //printf("%d ",val);
            nr_cf=nr_cf-1;
            next_cf=val/(int)(pow(10,nr_cf-1));
            printf("%d\n",next_cf);
            if(prima==next_cf) q=q+1;
            else
            {
                temp=temp*p+q*10+prima;
                p=p*10;
            }
            if(q==nr_cf_init)
            {
                temp=q*10+prima;
                val=0;
            }
        }
        //printf("%d ",temp);
        val=temp;
    }
    return 0;
}
