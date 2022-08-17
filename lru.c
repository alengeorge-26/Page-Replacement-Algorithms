#include<stdio.h>

struct frame
{
    int PN;
    int T;
    int F;
}F[10];

int P[50],A,f;

void lru(int);
int isFound(int,int);
void increment(int); 
int oldest(int);

int main()
{
    int i,j,k,n;

    printf("\nEnter the number of refernce string : ");
    scanf("%d",&n);

    printf("\nEnter the number of frames : ");
    scanf("%d",&f);

    printf("\nEnter the refernce string : ");
    for(i=0;i<n;i++)
        scanf("%d",&P[i]);

    lru(n);
}

void lru(int n)
{
    int i,j,k=0,count=0,pf=0;

    printf("\n\nLRU REPLACEMENT\n");
    printf("------------------\n");
    for(i=0;i<n;i++)
    {
        if(isFound(P[i],count))
        {
            increment(count);
            F[A].T=1;
            printf("\n%d -> \n",P[i]);
            continue;
        }

        else
        {
            if(count<f)
            {
                F[k].PN=P[i]; 
                k++;
                count++;
            }

            else
            {
                j=oldest(count);
                F[j].PN=P[i];
                F[j].T=0;
            }
            pf++;
            increment(count);
        }

        printf("\n");
        printf("%d -> ",P[i]);
        for(int x=0;x<count;x++)
            printf("%d ",F[x].PN);
        printf("\n");
    }

    printf("\nPage Faults : %d\n",pf);
}

int isFound(int p,int count)
{
    for(int i=0;i<count;i++)
    {
        if(F[i].PN == p)
        {
            A=i;
            return 1;
        }
    }
    return 0;
}

void increment(int count)
{
    for(int i=0;i<count;i++)
        F[i].T=F[i].T + 1;
}

int oldest(int count)
{
    int old=0;

    for(int i=0;i<count;i++)
    {
        if(F[old].T < F[i].T)
            old=i;
    }
    return old;
}



