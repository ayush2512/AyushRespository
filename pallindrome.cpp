#include<stdio.h>
#include<string.h>
int check(char* A)
{
	int len = strlen(A);
    int i=0;
    int count=0;
    while(A[i]!='\0')
    {
        if((A[i]>=97 && A[i]<=122) || (A[i]>=48 && A[i]<=57))
        {
            A[count]=A[i];
            count++;
        }
        i++;
    }
    i=0;
    A[count]='\0';
    printf("%s\n",A);
    while(A[i]!='\0')
    {
        if(A[i]!=A[count-i-1])
            return 0;
        i++;
    }
    return 1;
}
int main()
{
	int ret;
	char A[] = "race a car";
	ret = check(A);
	printf("%d\n",ret);
	return 0;
}