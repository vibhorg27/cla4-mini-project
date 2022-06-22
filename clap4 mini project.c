#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void fordelay(int j)
{
	int i,k;
	for(i = 0 ; i < j ; i++)
	{
		k=i;
	}
}

struct emp
{
	char name[40];
	int age,number,id;
	float bs;
};


int main()
{
	FILE *fp, *ft;

	struct emp e;
	char empname[40];
	long int recsize = sizeof(e);

	fp = fopen("EMP.DAT","rb+");
	if (fp == NULL)
	{
    	fp = fopen("EMP.DAT","wb+");
    	if(fp == NULL)
    	{
    	    printf("Connot open file");
    	    exit(1);
    	}
	}

	int anothera, anotherd, anotherm, choice;
	int i;

	main:
		system("cls");
		system("color E0");
		printf("\n\n\n\t\t\t\tWelcome to Employe Management System");
		fordelay(100000000);
        printf("\n\n\n\t\t\t1. Add Record\n");
        fordelay(100000000);
        printf("\n\n\n\t\t\t2. List Records\n");
        fordelay(100000000);
        printf("\n\n\n\t\t\t3. Modify Records\n");
        fordelay(100000000);
        printf("\n\n\n\t\t\t4. Delete Records\n");
        fordelay(100000000);
        printf("\n\n\n\t\t\t5. Exit\n");
        fordelay(100000000);
        fordelay(100000000);
        printf("\n\n\n\t\t\tYour Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        	case 1:
        		add:
        		system("cls");
				printf("\n\n\n\t\t\tEnter name : ");
				scanf("%s",e.name);
				printf("\n\n\n\t\t\tEnter age : ");
				scanf("%d", &e.age);
                printf("\n\n\n\t\t\tEnter ID : ");
				scanf("%d", &e.id);
				printf("\n\n\n\t\t\tEnter contact number : ");
				scanf("%d", &e.number);
				printf("\n\n\n\t\t\tEnter basic salary : ");
				scanf("%f", &e.bs);
				fwrite(&e,recsize,1,fp);
				system("cls");
				printf("\n\n\n\t\t\tPress 0 to add another record : ");
				scanf("%d", &anothera);
				if (anothera == 0)
				{
					goto add;
				}
				else
                {
                    goto wanna;
                }
			case 2:
            	system("cls");
            	rewind(fp);
            	while(fread(&e,recsize,1,fp) == 1)
            	{
                	printf("\n\n\n\t\t\t%s\t\t%d\t\t%d\t\t%d\t\t%.2f",e.name,e.age,e.id,e.number,e.bs);
            	}
            	getchar();
            	break;
        	case 3:
        		modify:
            	system("cls");
            	printf("\n\n\n\t\t\tEnter the employee name to modify : ");
                scanf("%s", &empname);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.name,empname) == 0)
                    {
                       	printf("\n\n\n\t\t\tEnter new name : ");
                        scanf("%s",&e.name);
                       	printf("\n\n\n\t\t\tEnter new age  : ");
                        scanf("%d",&e.age);
                        printf("\n\n\n\t\t\tEnter New ID : ");
				        scanf("%d", &e.id);
				        printf("\n\n\n\t\t\tEnter New contact number : ");
				        scanf("%d", &e.number);
                       	printf("\n\n\n\t\t\tEnter new bs   : ");
                        scanf("%f",&e.bs);
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                }
                printf("\n\n\n\t\t\tPress 0 to Modify another record : ");
                scanf("%d", &anotherm);
                if (anotherm == 0)
                {
                	goto modify;
				}
				else
                {
                    goto wanna;
                }
        	case 4:
        		deletee:
            	system("cls");
            	printf("\n\n\n\t\t\tEnter name of employee to delete : ");
                scanf("%s",&empname);
                ft = fopen("Temp.dat","wb");
                rewind(fp);
               	while(fread(&e,recsize,1,fp) == 1)
                {
                	if(strcmp(e.name,empname) != 0)
                	{
                	    fwrite(&e,recsize,1,ft);
                	}
                }
                fclose(fp);
                fclose(ft);
                remove("EMP.DAT");
               	rename("Temp.dat","EMP.DAT");
                fp = fopen("EMP.DAT", "rb+");
                system("cls");
                printf("\n\t\t\tPress 0 to Delete another record : ");
				scanf("%d", &anotherd);
				if (anotherd == 0)
				{
					goto deletee;
				}
				else
                {
                    goto wanna;
                }
        	case 5:
            	system("cls");
	        	printf("\n\n\n\t\t\tProject made by SIDDHANT ");
	        	printf("\n\n\n\t\t\tExiting");
	       		for(i = 1 ; i <= 15 ; i++)
            	{
            		fordelay(15000000);
					printf("....");
            	}
            	printf("\n\n");
		    	exit(0);
        	default:
        	    printf("\a");
        		printf("\n\n\n\t\t\tInvalid choice!!");
        		goto main;
		}
        wanna:
            system("cls");
        	printf("\n\n\n\t\t\t1. Goto main menu");
        	printf("\n\n\n\t\t\t2. Exit");
        	printf("\n\n\n\t\t\tEnter your choice : ");
        	scanf("%d", &choice);
        	if (choice == 1)
        	{
        		goto main;
			}
			else if (choice == 2)
			{
				system("cls");
	        	printf("\n\n\n\t\t\tProject made by SIDDHANT ");
	        	printf("\n\n\n\t\t\tExiting");
	       		for(i = 1 ; i <= 15 ; i++)
            	{
            		fordelay(15000000);
					printf("....");
            	}
		    	exit(0);
			}
			else
			{
			    printf("\a");
				printf("\n\n\n\t\t\tInvalid choice");
				goto wanna;
			}
}