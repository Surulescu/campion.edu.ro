#include<stdio.h>

int main()
{
    FILE *input,*output;
    input=fopen("comori.in","r");
    output=fopen("comori.out","w");
    int n,d,p,i,absc=0,coor=0;
    fscanf(input,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(input,"%d",&d);
        fscanf(input,"%d",&p);
        if(d==1)
        {
            coor=coor+p;
        }
        else if(d==2)
        {
            absc=absc+p;
            coor=coor+p;
        }
        else if(d==3)
        {
            absc=absc+p;
        }
        else if(d==4)
        {
            absc=absc+p;
            coor=coor-p;
        }
        else if(d==5)
        {
            coor=coor-p;
        }
        else if(d==6)
        {
            absc=absc-p;
            coor=coor-p;
        }
        else if(d==7)
        {
            absc=absc-p;
        }
        else if(d==8)
        {
            absc=absc-p;
            coor=coor+p;
        }
    }
    fprintf(output,"%d\t",absc);
    fprintf(output,"%d",coor);
    fclose(input);
    fclose(output);
    return 0;
}
