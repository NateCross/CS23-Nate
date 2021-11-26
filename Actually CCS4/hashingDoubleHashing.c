#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define S 5
#define K 7
#define LH 10
#define INCR 7
#define FLUSH while (getchar() != '\n')

typedef struct
{
	char personId[S]; // key
	char personName[30];
}PERSON;

typedef struct
{
	PERSON person;
	char status;
}TABLE;

void init_Table(TABLE []);
int convertString_Option3(char []);
bool insert_Data(TABLE [], PERSON ) ;
int double_Hashing(int,int);
int hash_Truncation(int);
PERSON input_Data(void);
void input_Search_Key(char []);
bool search_Data(TABLE [], int *, char [],PERSON *,int);
void display_Data(PERSON);
void delete_Data(TABLE [],char []);
void display_All_Data(TABLE []);

int main(void)
{
	int choice, key, index;
	bool found,full;
	char chrKey[S];
	PERSON per;
	TABLE T[LH];
	
	init_Table(T);
	do{
		system("cls");
		printf("\t1] Add new data\n");
		printf("\t2] Search a data\n");
		printf("\t3] Delete a data\n");
		printf("\t4] List all data\n");
		printf("\t5] Exit\n\n");
		printf("\tChoice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	per = input_Data();
					full = insert_Data(T,per);
					if(full)
					{
						printf("\n\n\tData cannot be added anymore, table is full...");
						getch();
					}
					break;
			case 2: input_Search_Key(chrKey);
					key = convertString_Option3(chrKey);
                    printf("key: %d\n", key);
					index = hash_Truncation(key);
					found = search_Data(T,&index, chrKey, &per,key);
					if(found)
						display_Data(per);
					else
						{
							printf("\n\n\tError: Data not found...");
							getch();
						}
					break;
			case 3: input_Search_Key(chrKey);
					delete_Data(T, chrKey);
					break;
			case 4: display_All_Data(T);
					break;
			case 5: printf("\n\n\tThis program will close in 5 seconds...");
					sleep(5);
					break;
			default:printf("\n\tInvalid choice...\n\tTry again...");
					sleep(2);
		}
	}while (choice != 5);
}

PERSON input_Data(void)
{
	PERSON p;
	
	FLUSH;
	printf("\n\n\tIdentification: ");
	gets(p.personId);
	printf("\n\tName: ");
	gets(p.personName);
	return p;
}

void input_Search_Key(char chrKey[])
{
	FLUSH;
	printf("\n\n\tInput search value: ");
	gets(chrKey);
	return;
}

void init_Table(TABLE T[])
{
	int j;
	
	for(j = 0; j < LH;j++)
	{
		memset(T[j].person.personId,'\0',S);
		memset(T[j].person.personName,'\0',30);
		T[j].status = 'e';
	}
		
	return;
}

int convertString_Option3(char chrKey[])
{
	int L, key = 0, i;
	
	L = strlen(chrKey);
	
	for(i = 0;i < L; i++)
	{
		key = key + (chrKey[L - i - 1] * pow(K,i));
	}
	return key;
}

int hash_Truncation(int key)
{
	int index;
	
	index = key % 10; // extract the last  digit (single digit index)
	return index;
}

int double_Hashing(int index, int key)
{
	int increment;
	
	increment = 1 + (key % INCR);
	index = (index + increment) % LH;
	return index;
}

bool insert_Data(TABLE T[], PERSON per)
{
	int index, key, P;
	bool full = false;
	key = convertString_Option3(per.personId);
	index = hash_Truncation(key); // original index of the data
	
	P = index;
	while(!full)
	{
		if((T[P].status == 'e') || (T[P].status == 'd')) // step #2
		{
			T[P].person = per;
			T[P].status = 'o'; // change the status from 'e' to 'o' - occupied
			break;
		}
		else
		{
			P = double_Hashing(P,key); // step #3
			if (P == index)
				full = true;
		}
	} // while(!full)
	
	return full;
}
// the parameter index was previously passed by value. however, the delete function needs to do searchig also. so, instead
// of declaring another function for that purpose, the original search will be re-used and for it to work,
// the parameter index is instead passed with reference for it to return the actual index for the delete function
bool search_Data(TABLE T[], int *index, char chrKey[],PERSON *per, int key)
{
	int P = *index, comp;
	bool found = false;
	
	while(!found)
	{
		if((T[P].status == 'o') || (T[P].status == 'd')) 
		{
			comp = strcmp(T[P].person.personId,chrKey);
			if(comp == 0)
			{
				if (T[P].status == 'o')
				{
					*per = T[P].person;
					*index = P;
					found = true;
				}
				else
				 break;	// if the status is 'd' and comp = 0, there is no need to copy the data. it is assumed to be not found
			}
			else
			{
				// if comp != 0, there is a chance that the data exist except that it is stored in another index
				// because of collission. So, we need to look for it in another index in the table
				P = double_Hashing(P, key); 
				if (P == *index) // when this is true then the data does not exist
					break;
			}
		}
		else
		{
			// this means that the status is'e'. the data is obviously not in the table; the data was not inserted at all
			break; // we will stop the seqrch
		}
	}
	return found;
}
void display_Data(PERSON p)
{
	system("cls");
	printf("\n\n\tIdentification: %s",p.personId);
	printf("\n\tName: %s",p.personName);
	getch();
	return;
}

void delete_Data(TABLE T[],char chrKey[])
{
	int index, key;
	char ans;
	bool found;
	PERSON per;
	key = convertString_Option3(chrKey);
	index = hash_Truncation(key);
	found = search_Data(T,&index, chrKey, &per,key);
	if(found)
	{
		display_Data(per); // display the data for visual validation by the user
		printf("\n\n\tDo you want to proceed deleting the data (Y/N)?");
		scanf(" %c",&ans);
		if(toupper(ans) == 'Y')
			T[index].status = 'd';
	}
	else
	{
		printf("\n\n\tError: Data not found...");
		getch();
	}
	return;
}

void display_All_Data(TABLE T[])
{
	int j;
	
	system("cls");
	printf("\n\n\tindex\tIdentification\tName\tStatus");
	for(j = 0; j < LH; j++)
		printf("\n\t%d\t%s\t\t%s\t%c",j,T[j].person.personId,T[j].person.personName,T[j].status);
	getch();
	return;
}
