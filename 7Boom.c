#include <stdio.h>
#include <stdint.h>


uint8_t has7(int num)
{
    uint8_t res = 0;
    while(num > 0)
    {
        if(num%10 == 7)
        {
            res = 1;
            break;
        }
        else
        {
            num /=10;
        }
    }
    return res;
}

uint8_t has7Recursive(int num)
{
    if (num == 0)
    {
        return 0;
    }
    if (num % 10 == 7)
    {
        return 1;
    }
    return has7Recursive(num / 10);
}


void sevenBoom(int n) // naiive solution 
{
    uint8_t is7Boom = 0;
    for(int i = 1; i<=n ; i++)
    {
        if((i%7)==0) // case divided by 7
        {
            is7Boom = 1;
        }
        else
        {
            is7Boom = has7(i);
        }
        if(is7Boom == 1)
        {
            printf("Boom! ");
            is7Boom = 0;
        }
        else
        {
            printf("%d, ", i);
        }
    }
    printf("\r\n;");
}








int main(void)
{
    return 0;
}