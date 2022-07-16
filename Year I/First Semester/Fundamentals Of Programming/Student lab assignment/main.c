#include <stdio.h>
#include <string.h>

void printDecimals(int unsigned,int signed);

int convertToBase10Unsigned(char c[])
{
    int b = 1;
    int result_unsigned = 0;
    int len = strlen(c)-1;
    for(int i=len;i>=0;i--)
    {
        if(c[i]>='A'&&c[i]<='F')
            result_unsigned += (((c[i]-'A')+10)*b);

        else
            result_unsigned += (c[i]-'0')*b;

        b*=16;
    }

    return result_unsigned;
}

int convertToBase10Signed(char c[],int result_unsigned)
{
    if(c[0]>='8')
    {
        int len = strlen(c);
        int power=1,inc=0;
        while(inc<4*len)
            power*=2,inc++;
        return (-1)*(power-result_unsigned);
    }
    return result_unsigned;
}

    
int main(){ 
    int v_unsigned[100],v_signed[100], n=0;
    char c[100];
    do{
        printf("Insert Hexa:\n");
        scanf("%s", c);
        v_unsigned[n] = convertToBase10Unsigned(c);
        v_signed[n] = convertToBase10Signed(c,v_unsigned[n]);
        n++;
    }while (c[0]!='0');

    for(int i=0;i<n;i++)
    {
    	printDecimals(v_unsigned[i],v_signed[i]);
    }

    return 0;
}