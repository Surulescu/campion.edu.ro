#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("multimi.in","r");
    output=fopen("multimi.out","w");
    int n,f,i,l,j,k,q=0;
    fscanf(input,"%d",&n);
    fscanf(input,"%d",&f);
    fscanf(input,"%d",&l);
    //printf("%d\n",f);
    //printf("%d\t",l);
    for(i=f; i<=l; i++)
    {
        k=f;
        fscanf(input,"%d",&f);
        fscanf(input,"%d",&l);
        for(j=f; j<=l; j++)
        {
            if(k==j) q=q+1;

        }
    }
    //if(q==1) printf("%c",'multimea vida');
    fclose(input);
    fclose(output);
    return 0;
}
