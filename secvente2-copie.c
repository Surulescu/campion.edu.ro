#include<stdio.h>
#define LIM 1000010
int x[LIM];

int main()
{
    FILE *input,*output;
    input=fopen("secvente2.in","r");
    output=fopen("secvente2.out","w");
    int n,i,nr,temp,max=1,aux;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&temp);
        if((x[temp-1]==0)&&(x[temp+1]==0))
        {
            x[temp]=temp;
            nr=1;
        }
        else if((x[temp-1]!=0)&&(x[temp+1]==0))
        {
            x[temp]=x[temp-1];
            x[x[temp]]=temp;
            nr=temp-x[temp]+1;
        }
         else if((x[temp+1]!=0)&&(x[temp-1]==0))
        {
            x[temp]=x[temp+1];
            x[x[temp]]=temp;
            nr=x[temp]-temp+1;
        }
        else if((x[temp-1]!=0)&&(x[temp+1]!=0))
        {
            aux=x[temp-1];
            x[x[temp-1]]=x[temp+1];
            x[x[temp+1]]=aux;
            nr=x[aux]-aux+1;
        }
        if(nr>max) max=nr;
        fprintf(output,"%d\n",max);
    }
    fclose(input);
    fclose(output);
    return 0;
}
