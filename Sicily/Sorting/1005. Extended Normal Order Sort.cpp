#include <stdio.h>
#include <string.h>
#include <ctype.h>
//#include 

#define N 1006

int main()
{
    int i, j, k, kk, jj, p;
    int t, len2, len1, flag, m, num1, num2, maxlen;
    int mark1[N], mark2[N];
    char ch1[N], ch2[N];
    //freopen("in.txt", "r", stdin);

    scanf("%d", &t);
    getchar();
    for(i=1; i<=t; i++)
    {
        scanf("%s", ch1);
        scanf("%s", ch2);
        len1 = strlen(ch1);
        len2 = strlen(ch2);

        memset(mark1, 0, sizeof(mark1));
        memset(mark2, 0, sizeof(mark2));

        //去掉那些没用的字符跟0

        for(j=0; j<=len1; j++)
        {
            if((j == 0 || !isdigit(ch1[j-1])) && ch1[j] == '+' && isdigit(ch1[j+1]))
                ch1[j] = '0';
            if((j == 0 || !isdigit(ch1[j-1])) && ch1[j] == '-' && isdigit(ch1[j+1]))
            {
                mark1[j] = 1;
                ch1[j] = '0';
            }
            if((j == 0 || !isdigit(ch1[j-1])) && ch1[j] == '0')
            {
                while(ch1[j] == '0')
                {
                    for(k=j+1; k<=len1; k++)
                    {
                        ch1[k-1] = ch1[k];
                    }
                }
            }
        }
        for(j=0; j<=len2; j++)
        {
            if((j == 0 || !isdigit(ch2[j-1])) && ch2[j] == '+' && isdigit(ch2[j+1]))
                ch2[j] = '0';
            if((j == 0 || !isdigit(ch2[j-1])) && ch2[j] == '-' && isdigit(ch2[j+1]))
            {
                mark2[j] = 1;
                ch2[j] = '0';            
            }
            if((j == 0 || !isdigit(ch2[j-1])) && ch2[j] == '0')
            {
                while(ch2[j] == '0')
                {
                    for(k=j+1; k<=len2; k++)
                    {
                        ch2[k-1] = ch2[k];
                    }
                }
            }
        }
        for(j=0; j<=len1; j++)
        {
            ch1[j] = toupper(ch1[j]);

        }

        for(j=0; j<=len2; j++)
        {
            ch2[j] = toupper(ch2[j]);
            
        }
        flag = 0;
        if(strcmp(ch1, ch2) != 0)
        {
            len1 = strlen(ch1);
            len2 = strlen(ch2);
            for(j=0; j<=len1; j++)
            {
                if(!isdigit(ch1[j])) //处理一般字符

                {
                    if(ch1[j] > ch2[j])
                    {
                        flag = 1;
                        break;
                    }
                    if(ch1[j] < ch2[j])
                    {
                        flag = -1;
                        break;
                    }
                }
                else
                {
                    k = j;
                    num1 = 0;
                    m = 1;
                    while(isdigit(ch1[k])) //处理数字

                    {
                        num1 = num1 * m + ch1[k] - '0';
                        m = 10;
                        k++;
                    }
                    if(mark1[j])
                    {
                        num1 *= -1;
                    }
                    j = k;
                    k = j;
                    num2 = 0;
                    m = 1;
                    while(isdigit(ch2[k]))
                    {
                        num2 = num2 * m + ch2[k] - '0';
                        m = 10;
                        k++;
                    }
                    if(mark2[j])
                    {
                        num2 *= -1;
                    }
                    if(num1 > num2)
                    {
                        flag = 1;
                        break;
                    }
                    if(num1 < num2)
                    {
                        flag = -1;
                        break;
                    }
                }
            }
        }
        printf("%d %d", i, flag);

        printf("\n");
    }
//    getch();

    return 0;
}