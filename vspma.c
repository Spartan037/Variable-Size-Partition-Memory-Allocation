#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int allocate(int s, int ram)
{
    ram= ram-s;
    return ram;
}

int terminate(char name[], int s[], char n[100][100], int size, int ram)
{
    for(int i=0; i<size; i++)
    {
        if(strcmp(name, n[i])==0)
        {
            printf("\nProcess terminated successfully!!!\n");
            ram= ram+s[i];
            for(int j=i; j<size; j++)
            {
                s[j]= s[j+1];
                strcpy(n[j], n[j+1]);
            }
            return ram;
            break;
        }
    }
    printf("\nProcess not found!!!");
}

int Defragment(char name[], int s[], char n[100][100], int size, int ram)
{
    ram= ram+s[0];
    for(int j=0; j<size; j++)
    {
        s[j]= s[j+1];
        strcpy(n[j], n[j+1]);
    }
    return ram;
}
int main()
{
	int size, s1, ch, i=0, s[100];
	char n[100][100], name[100];
    printf("Enter the size of RAM: ");
    scanf("%d", &size);
    int ram=size;
    while(ch!=5)
	{
		printf("\nMENU-");
		printf("\n1.Process Arrival");
		printf("\n2.Process Termination");
		printf("\n3.View Memory status");
		printf("\n4.Defragment Memory");
		printf("\n5.Exit");
		printf("\nEnter your choice: ");
    	scanf("%d", &ch);

		switch(ch)
		{
		    case 1:
		        if(ram==0)
                {
                    printf("\nThe ram is full!!!");
                    break;
                }
                else
                {
                    printf("\nEnter process name: ");
    		        scanf("%s", name);
    		        printf("\nEnter process size: ");
    		        scanf("%d", &s1);
    		        if(ram<s1)
                        printf("\nEnough memory not available!!!\n");
                    else
                    {
                        strcpy(n[i], name);
                        s[i]=s1;
                        ram= allocate(s[i], ram);
    		            i++;
                    }
                }
    		    break;
		    case 2:
		        if(ram==size)
                {
                    printf("No processes in ram!!!");
                    break;
                }
                else
                {
                    printf("\nEnter process name to be terminated: ");
		            scanf("%s", name);
		            ram= terminate(name, s, n, i, ram);
		            i--;
		        }
		        break;
		    case 3:
		        printf("Process Name\t Memory");
		        for(int j=0; j<i; j++)
		            printf("\n%s\t\t%d", n[j], s[j]);
		        printf("\n\nRAM available: %d\n", ram);
		        break;
		    case 4:
		        if(i==0)
		        {
		            printf("\nRAM is completely Defragmented!!!\n");
		            break;
		        }
		        else
		        {
    		        ram= Defragment(name, s, n, i, ram);
    		        printf("\nRAM available: %d\n", ram);
    		        i--;
    		    }  
    		    break;
		    case 5:
		        exit(0);
		        break;
		}   
		
	}
}
