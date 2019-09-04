#include <stdio.h>
#include <string.h>

struct FCFS
{
    char pid[5];
    int wt;
    int bt;
    int tat;
    int ct;
};

int lim,i,j;

void sortAll(struct FCFS[]);
void makeChart(struct FCFS);

void calcWtTat(struct FCFS[]);

void main()
{

    struct FCFS fcfs[10];

    char str[5];

    printf("Enter the no. of processes:");
    scanf("%d",&lim);

    for(i=0; i<lim; i++)
    {


        printf("Enter the Burst time of p[%d]:",i);
        scanf("%d",&fcfs[i].bt);

        sprintf(str, "p%d", i);
        strcpy(fcfs[i].pid,str);

//printf("\n%s\n",str);

    }
    sortAll(fcfs);
}

void sortAll(struct FCFS fc[10])
{

    int tempAt,tempBt;
    char pid[5];

    for(i=0; i<lim; i++)
    {
        for(j=0; j<lim; j++)
        {

            if(fc[i].bt<fc[j].bt)
            {
                tempBt=fc[j].bt;
                strcpy(pid,fc[j].pid);

                fc[j].bt=fc[i].bt;
                strcpy(fc[j].pid,fc[i].pid);

                fc[i].bt=tempBt;
                strcpy(fc[i].pid,pid);

            }
        }
    }
    calcWtTat(fc);

}

void calcWtTat(struct FCFS fc[10])
{
    int totalWt=0,totalTat=0;

    fc[0].wt=0;
    fc[0].tat=0+fc[0].bt;
    fc[0].ct=0+fc[0].bt;
    totalTat+=fc[0].tat;
    totalWt+=fc[0].wt;

    if(lim>1)
        for(i=1; i<lim; i++)
        {
            fc[i].wt=fc[i-1].bt+fc[i-1].wt;
            fc[i].tat=fc[i].wt+fc[i].bt;
            fc[i].ct=fc[i-1].ct+fc[i].bt;
            /*fc[i].ct=fc[i-1].ct+fc[i].bt;
            fc[i].tat=fc[i].ct-fc[i].at;
            fc[i].wt=fc[i].tat - fc[i].bt;*/
            totalTat+=fc[i].tat;
            totalWt+=fc[i].wt;
        }

    for(i=0; i<lim; i++)
    {
        //printf("pid:%s,\tat:%d,\tbt:%d,\twt:%d\ttat:%d\tct:%d\n",fc[i].pid,fc[i].at,fc[i].bt,fc[i].wt,fc[i].tat,fc[i].ct);
        printf("|\t%s\t",fc[i].pid);
    }
    printf("|\n");
    printf("0\t\t");
    for(i=0; i<lim; i++)
    {
        //printf("pid:%s,\tat:%d,\tbt:%d,\twt:%d\ttat:%d\tct:%d\n",fc[i].pid,fc[i].at,fc[i].bt,fc[i].wt,fc[i].tat,fc[i].ct);
        printf("%d\t\t",fc[i].ct);
    }
    printf("\n");

    printf("Average WaitingTime:%d,Average TAT:%d",totalWt/lim,totalTat/lim);
    getch();
}

















