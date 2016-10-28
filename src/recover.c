#include "log.h"
#include "version.h"
#include "recover.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RECOVER(){
	
	LOG_RECORD winners[1000];
	LOG_RECORD log_r;

	int index= getlocationoflog();

	int i;
	int winner_count;
	winner_count=0;
	
	for(i=index;i>=0;i--){
		log_r=log_record[i];
		
		if(strcmp(log_r.type,"OUTCOME")==0)
		{
			winners[winner_count]=log_r;
			winner_count++;
		}
	}

	int j; int compare_result;
	for(j=0;j<=index;j++){
		log_r=log_record[j];
		compare_result=strcmp(log_r.type,"CHANGE");
		int c=ifcommitted(log_r.action_id,winner_count,winners);

		if((compare_result==0)&&(c==1))
		{FILE *f = fopen("data/recover.txt", "a+");
			if (f == NULL)
		{
 		   printf("Error opening file!\n");
 		   exit(1);
	}

	
	fprintf(f,"[ RECOVERY ]:   Perform %s \n \n",log_r.redo_action);
		
	
		fclose(f);
		
			printf("[ RECOVERY ]:   Perform %s \n \n",log_r.redo_action);
		}
	
	}

	return 0;
	}

int ifcommitted(int action_id,int count, LOG_RECORD winners[]){
	
		int i;
		for(i=0;i<=count;i++)
		{
			 if(winners[i].action_id==action_id){
				int j,k;
						for(j=0;j<10000;j++){
							for(k=0;k<100;k++){
								if(v[j].id[k].a_id==action_id){
									
									if(strcmp(v[j].id[k].state,"COMMITTED")==0){return 1; }				
												}
			
										}
									}
			}			
		}
	
		
	return 0;}
