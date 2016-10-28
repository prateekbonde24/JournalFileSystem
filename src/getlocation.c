#include <stdio.h>
#include "getlocation.h"
#include "version.h"
#include "log.h"
#include <string.h>
#include <stdlib.h>

int getlocation(int var_id){
	int i;
	int count;
	
	for(i=99;i>=0;i--)
	{	
		if(v[var_id].id[i].a_id==-1)
		{	
			count=i;
			
		}
		
	}
//printf("count= %d\n", count);
	return count;

}


int getlocationofid(int var_id,int aid){
	int i;
	int count;
	
	for(i=99;i>=0;i--)
	{	
		if(v[var_id].id[i].a_id==aid)
		{	
			count=i;
			
		}
		
	}
//printf("commit_count= %d", count);
return count;

}

int getlocationread(int var_id){
	int i;
	int count;
	
	for(i=99;i>=0;i--)
	{	
		if(v[var_id].id[i].a_id==-1)
		{	
			count=i;
			
		}
		
	}
//printf("count_read = %d ...", count);
	int n_count;
	n_count=count-1;
	return n_count;

}
void checkresult(int c){
	if(c==0){
	printf("SUCCESS \n");
	}
	else{
	printf("Operation Failed!\n");}
}


char *str_replace(char *str, char *orig, char *rep)
{
  static char buffer[4096];

  char *p;

  if(!(p = strstr(str, orig)))  // Is 'orig' even in 'str'?
    return str;

  strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
  buffer[p-str] = '\0';

  sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));

  return buffer;
}

int my_init(void){
int i,j;

FILE *f = fopen("data/log.txt", "w");
	if (f == NULL)
		{
 		   printf("Error opening file!\n");
 		   exit(1);
	}


FILE *fp = fopen("data/recover.txt", "w");
	if (fp == NULL)
		{
 		   printf("Error opening file!\n");
 		   exit(1);
	}	
	
	fclose(fp);
	for(i=0;i<10000;i++){
		for(j=0;j<100;j++){	
	strcpy(v[i].sector[j].S1,"Empty");
		strcpy(v[i].sector[j].S2,"Empty");
	strcpy(v[i].sector[j].S3,"Empty");
	v[i].id[j].a_id=-1;
	strcpy(v[i].id[j].state,"NULL");
	
		}
	}
	for(i=0;i<1000;i++){
	log_record[i].action_id=-100;	
	strcpy(log_record[i].type,"EMPTY");
	strcpy(log_record[i].undo_action,"EMPTY");
	strcpy(log_record[i].redo_action,"EMPTY");
	
	}
}
