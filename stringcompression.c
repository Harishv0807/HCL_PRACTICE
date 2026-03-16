#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int count;

    printf("Enter string: ");
    scanf("%s",str);

    int len = strlen(str);

    for(int i=0;i<len;i++)
    {
        count=1;

        while(str[i]==str[i+1])
        {
            count++;
            i++;
        }

        printf("%c%d",str[i],count);
    }

    return 0;
}