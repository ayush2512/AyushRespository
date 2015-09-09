#include<stdio.h>
#include<string.h>
void reverse(char *begin, char *end)
{
    char temp;
    while(begin<end)
    {
        temp=*begin;
        *begin++ = *end;
        *end-- = temp;
    }
}
void reverseWords(char* A) {
    char *temp1=NULL,*rev=NULL;
    int i=0,count=0;
    //printf("%s\n",A);
    while(*A)
    {
        if(*A!=' ')
        {
            *rev=*A;
            rev++;
        }
        else if(*A == ' ' && *A != ' ')
        {
            *rev=*A;
            rev++;
        }
        A++;
    }
    *rev='\0';
    //printf("%s\n",rev);
    char *temp2 = A;
    while(*temp2)
    {
        if((temp1 == NULL) && (*temp2 !=' '))
            temp1=temp2;
        if(temp1 && *(temp2+1)==' ' || *(temp2+1)=='\0')
        {
            reverse(temp1,temp2);
            temp1=NULL;
        }
        temp2++;
    }
    reverse(A,temp2-1);
}
int main()
{
    char str[] = "the sky is blue";
    reverseWords(str);
    return 0;
}