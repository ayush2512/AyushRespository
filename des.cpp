#include <bits/stdc++.h>
void left_shift(int *a)
{
        int i,tmp=a[0];
        for(i=0;i<27;i++)
                a[i]=a[i+1];
        a[27]=tmp;
}
int main()
{
        int i,j;
        int p[64]={0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1,1,0};
        int key[64]={1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,1,1,0,0,1,1,0,1,1,0,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1};
        //parity drop
        int parity_drop[8][7]={{57,49,41,33,25,17,9},
                               {1,58,50,42,34,26,18},
                               {10,2,59,51,43,35,27},
                               {19,11,3,60,52,44,36},
                               {63,55,47,39,31,23,15},
                               {7,62,54,46,38,30,22},
                               {14,6,61,53,45,37,29},
                               {21,13,5,28,20,12,4}};
        int key_comp[8][6]={{14,17,11,24,1,5},
                          {3,28,15,6,21,10},
                          {23,19,12,4,26,8},
                          {16,7,27,20,13,2},
                          {41,52,31,37,47,55},
                          {30,40,51,45,33,48},
                          {44,49,39,56,34,53},
                          {46,42,50,36,29,32}};
        int key_parity[56];
        int z=0;
        for(i=0;i<8;i++)
        {
                for(j=0;j<7;j++)
                key_parity[z++]=key[parity_drop[i][j]-1];
        }
//      for(i=0;i<56;i++)
//      printf("%d",key_parity[i]);
        int k1[28],k2[28];
        for(i=0;i<56;i++)
        {
                if(i<28)
                        k1[i]=key_parity[i];
                else
                        k2[i-28]=key_parity[i];
        }
        int round=1,shift;
        while(round<=16)
        {
                printf("key for round %d:\n",round);
                if(round==1 || round==2 || round==9 ||round==16)
                        shift=1;
                else
                        shift=2;
                while(shift--)
                {
                        left_shift(k1);
                        left_shift(k2);
                }
                for(i=0;i<8;i++)
                {
                        for(j=0;j<6;j++)
                        {
                                if(key_comp[i][j]<=28)
                                        printf("%d",k1[key_comp[i][j]-1]);
                                else
                                        printf("%d",k2[key_comp[i][j]-29]);
                        }
                }
                printf("\n");
                round++;
        }
return 0;
}
     