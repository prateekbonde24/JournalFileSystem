#include "action.h"
#include "abort.h"
#include <string.h>
#include "version.h"
#include <stdio.h>
#include <stdlib.h>
#include "log.h"

int ABORT(int data_id,struct ActionId c)
{
	LOG_RECORD* log_r;
	log_r=malloc(sizeof(LOG_RECORD));
	int i;
	int index=getlocationoflog();

	for(i=index;i>=0;i--){

	log_r=&log_record[i];

	if(log_r->action_id==c.a_id){
	
		if(strcmp(log_r->type,"OUTCOME")==0)
			{	
				printf("Can't abort an already completed action \n");
				break;
				}
		else if(strcmp(log_r->type,"CHANGE")==0)
		{
					printf("Perform %s \n",log_r->undo_action);	
						printf("ABORTED: Action id - %d, State - %s\n",c.a_id,c.state);
						strcpy(c.state,"ABORTED");
	v[data_id].id[index]=c;
		LOG(c.a_id,"OUTCOME","NONE","ABORT()");
	LOG(c.a_id,"END","NONE","NONE");
	
			}
		else if(strcmp(log_r->type,"BEGIN")==0)
		{
			break;		
		}
	
	}		
	}
	return 0;

}

