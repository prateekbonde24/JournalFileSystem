#include <stdio.h>
#include "read.h"
#include "write.h"
#include "allocate.h"
#include "deallocate.h"
#include "version.h"
#include "action.h"
#include "act.h"
#include <string.h>
#include "new_outcome_record.h"
struct ActionId NEW_ACTION();
int COMMIT(int data_id,struct ActionId c);
int ABORT(int data_id,struct ActionId c);
int my_init(void);
int READ_CURRENT_VALUE(int data_id);
int WRITE_NEW_VALUE( int data_id, char *new_value, struct ActionId caller_id);

int getlocation(int var_id);
int getlocationofid(int var_id,int aid);
int getlocationread(int var_id);
void checkresult(int c);
char read_value[20]="NULL";


int main(){

my_init();
int c1;
int result1,result2;char readval[20];

//Starting new actions
ActionId a1,a2,a3;
a1=NEW_ACTION();
a2=NEW_ACTION();
a3=NEW_ACTION();

//Step 0 write info to some position
result1=WRITE_NEW_VALUE(0,"Good",a1);
//step 1 Abort the write request
c1=ABORT(0,a1);
checkresult(c1);

//step 2 write another info
result2=WRITE_NEW_VALUE(0,"7050",a2);
//step 3 Commit the write request
c1=COMMIT(0,a2);
checkresult(c1);
//Step 4 write info to some position
result1=WRITE_NEW_VALUE(0,"Morning",a3);

//step 5 Abort the write request
c1=ABORT(0,a3);
checkresult(c1);

//Step 6 read from the write location
int n1= READ_CURRENT_VALUE(0);
strcpy(readval,read_value);
printf("Read = %s\n", readval);

return 0;


}












struct ActionId NEW_ACTION(){

ActionId new;
new = NEW_OUTCOME_RECORD();
strcpy(new.state,"PENDING");
printf("NEW ACTION:  Action id - %d, State - %s\n",new.a_id,new.state);

return new;
}

int COMMIT(int data_id,struct ActionId c)
{

	int index=getlocationofid(data_id,c.a_id);
	strcpy(c.state,"COMMITTED");
	v[data_id].id[index]=c;
	printf("COMMITTED: Data - %s, Action id - %d, State - %s\n",v[data_id].value[index],c.a_id,c.state);
	return 0;
}

int ABORT(int data_id,struct ActionId c)
{

	int index=getlocationofid(data_id,c.a_id);
	strcpy(c.state,"ABORTED");
	v[data_id].id[index]=c;
	printf("ABORTED: Data - %s, Action id - %d, State - %s\n",v[data_id].value[index],c.a_id,c.state);
	return 0;
}


int READ_CURRENT_VALUE(int data_id){
	int index;
	
	strcpy(read_value,"NULL");
	index=getlocationread(data_id);
	//printf("read index %d",index);
	while(1)
	{
		if(strcmp(v[data_id].id[index].state,"COMMITTED")==0)
		{
			strcpy(read_value,v[data_id].value[index]);
			printf("READ OP: Data - %s, Actionid - %d , State - %s \n",read_value,v[data_id].id[index].a_id,v[data_id].id[index].state);
			break;
		}
		else{
		index--;
			if(index==-1)
			{
				break;
				strcpy(read_value,"NULL");
				printf("ERROR");				
				}		
		}
	}
	return 0;
}

int WRITE_NEW_VALUE( int data_id, char *new_value, struct ActionId caller_id){
	int val=strcmp(caller_id.state,"PENDING");

	if (val==0){
		int index;
		index=getlocation(data_id);
	//printf("index %d",index);
		strcpy(v[data_id].value[index],new_value);
		v[data_id].id[index]=caller_id;
		printf("WRITE OP: Data - %s, Actionid - %d , State - %s \n",  v[data_id].value[index],v[data_id].id[index].a_id,v[data_id].id[index].state);
	
	}
	else{
	printf("ERR");
	}
	return 0; 

}


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

int my_init(void){
int i,j;
	for(i=0;i<10000;i++){
		for(j=0;j<100;j++){	
	strcpy(v[i].value[j],"NULL");
	v[i].id[j].a_id=-1;
	strcpy(v[i].id[j].state,"NULL");
	
		}
	}
}
