#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("sea2.in","r");
    output=fopen("sea2.out","w");
    int n,i,j;
    int a[100];
    int b[100];
    fscanf(input,"%d",&n);
    for(i=1; i<=n*2; i++)
    {
        fscanf(input,"%d",&a[i]);
        //printf("%d ",a[i]);
        if(i%2==0)
        {
            for(j=1; j<=i; j++)
            {
                fscanf(input,"%d",&a[i]);
                printf("%d ",a[i]);
            }
        }
    }
    return 0;
}
