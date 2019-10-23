#include <stdio.h>
#include <string.h>

struct Process
{

    int bt;
    int prio;
    char pid[10];
    int tat;
    int ct;
    int wt;
};

void printAll(struct Process[]);

int lim, i, j;
int totalTat = 0, totalWt = 0;
double avgTat, avgWt;

void main()
{

    struct Process pr[20];

    char pid[5];

    struct Process tempPr;

    printf("\nEnter the no. of processes:");
    scanf("%d", &lim);
    for (i = 0; i < lim; i++)
    {

        printf("\nEnter the burst time of p[%d]:", i);
        scanf("%d", &pr[i].bt);

        printf("\nEnter the priority of p[%d]", i);
        scanf("%d", &pr[i].prio);

        sprintf(pr[i].pid, "p%d", i);
    }

    for (i = 0; i < lim; i++)
    {
        for (j = 0; j < lim; j++)
        {

            if (pr[i].prio < pr[j].prio)
            {

                tempPr = pr[j];
                pr[j] = pr[i];
                pr[i] = tempPr;
            }
        }
    }

    pr[0].ct = pr[0].bt;
    pr[0].tat = pr[0].ct;
    //pr[0].wt=pr[0].tat-pr[0].bt;
    pr[0].wt = 0;
    totalTat += pr[0].tat;
    totalWt += pr[0].wt;

    if (lim > 0)
        for (i = 1; i < lim; i++)
        {
            pr[i].ct = pr[i - 1].ct + pr[i].bt;
            pr[i].tat = pr[i].ct;
            pr[i].wt = pr[i - 1].wt + pr[i].bt;

            totalTat += pr[i].tat;
            totalWt += pr[i].wt;
        }

    avgTat = (double)totalTat / lim;
    avgWt = (double)totalWt / lim;

    printf("Average Waiting time:%f\nAverage TAT:%f\n", avgWt, avgTat);

    printf("|\t");
    for (i = 0; i < lim; i++)
    {
        printf("%s\t|\t", pr[i].pid);
    }
    printf("\n0\t");
    for (i = 0; i < lim; i++)
    {
        printf("\t%d\t", pr[i].ct);
    }
    printf("\n");
}

void printAll(struct Process pr[20])
{
    for (i = 0; i < lim; i++)
        printf("\n%s-prio-%d-bt-%d-ct-%d\n", pr[i].pid, pr[i].prio, pr[i].bt, pr[i].ct);
}
