#include<stdio.h>
#include<math.h>

int prim(int numar)
{
    int divizor=2,stop=1;
    while(divizor<=sqrt(numar)&&(stop==1))
    {
        if(numar%divizor==0) stop=0;
        divizor++;
    }
    return stop;
}

int extraprime(int numar,int nr_cifre)
{
    int divizor,stop,prim,secund,init,k,l,val,x;
    init=numar;
    k=0;
    l=1;
    val=0;
    x=nr_cifre;
    prim=(int)(pow(10,nr_cifre-k)+0.5);
    secund=(int)(pow(10,nr_cifre-l)+0.5);
    init=((numar/prim)*secund)+(numar%secund);
    while(x-1>0)
    {
        if(init!=1)
        {
            divizor=2;
            stop=1;
            while((divizor<sqrt(init))&&(stop==1))
            {
                if(init%divizor==0) stop=0;
                divizor++;
            }
            if(stop==1)
            {
                val=val+1;
                k++;
                l++;
                prim=(int)(pow(10,nr_cifre-k)+0.5);
                secund=(int)(pow(10,nr_cifre-l)+0.5);
                init=((numar/prim)*secund)+(numar%secund);
                //printf("%d\n",init);
            }
        }
        x--;
    }
    return val;
}


int main()
{
    FILE *input,*output;
    input=fopen("extraprime.in","r");
    output=fopen("extraprime.out","w");
    int a,b,intrari,nr_cifre=0,nr_prim,aux,i,sol;
    fscanf(input,"%d",&a);
    fscanf(input,"%d",&b);
    for(i=a; i<=b; i++)
    {
        if(prim(i)==1)
        {
            //printf("%d\n",i);
            aux=i;
            while(aux>0)
            {
                nr_cifre++;
                aux=aux/10;
            }
            intrari=nr_cifre;
            sol=(extraprime(i,nr_cifre));
            if(sol==nr_cifre) fprintf(output,"%d\n",i);
        }
        nr_cifre=0;
    }
    fclose(input);
    fclose(output);
    return 0;
}
