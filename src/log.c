#include "log.h"
#include "action.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
struct LOG_RECORD log_record[1000];
int i=0;


void LOG(int action_id,char *type, char *undo_action,char *redo_action){
	

	strcpy(log_record[i].type,type);
	strcpy(log_record[i].undo_action,undo_action);
	strcpy(log_record[i].redo_action,redo_action);
	//printf("%s %s %s  \n",log_record[i].type,log_record[i].undo_action,log_record[i].redo_action);
	log_record[i].action_id=action_id;
	i++;
//	printf("HELLO\n");
	printlog(action_id,type,undo_action,redo_action);
	}


int getlocationoflog(){
	int i;
	int count;

	for(i=0;i<=1000;i++)
	{	
		if(log_record[i].action_id==-100)
		{	
			break;
		
			
		}
		count=i; 
		
	}
	
	return count;
	
}



void printlog(int action_id,char *type, char *undo_action,char *redo_action)
{	
	FILE *f = fopen("data/log.txt", "a+");
	if (f == NULL)
		{
 		   printf("Error opening file!\n");
 		   exit(1);
	}

	
	fprintf(f,"[ LOG ]: Action id- %d  Type- %s  UndoAction- %s  RedoAction- %s \n \n",action_id,type,undo_action,redo_action);
		
	
		fclose(f);
		}
