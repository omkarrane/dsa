#include<stdio.h>
#include<string.h>

int isBinary(char *str);

int main()
{
  int t;
  scanf("%d\n", &t);
  while(t--)
  {
    char str[10005];
    scanf("%s", str);
    if (isBinary(str))
    {
      printf("1\n");
    }
    else
    {
      printf("0\n");
    }
  }
  return 0;
}

//Return 1 if true, else return 0 if not true
int isBinary(char *str)
{
    //Code here
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        if (str[i] != '0' && str[i] != '1')
            return 0;
    return 1;
}