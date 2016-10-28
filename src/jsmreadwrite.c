#include "version.h"
#include "action.h"
#include "jsmreadwrite.h"
#include "getlocation.h"
#include "ALL_OR_NOTHING.h"
#include "readval.h"
#include "log.h"
#include <stdio.h>
#include <string.h>
#include "sector.h"
#include <time.h>


int READ_CURRENT_VALUE(int data_id){
	int index;
	char read_data[50];
	strcpy(read_value,"NULL");

	index=getlocationread(data_id);
	
	while(1)
	{
		if(strcmp(v[data_id].id[index].state,"COMMITTED")==0)
		{
				
			all_or_nothing_get(data_id);
			//printf("read  %s",read_value);
			//strcpy(read_value,v[data_id].value[index]);
			//printf("SECTOR 1 GET %s \n",v[data_id].sector[index].S1);
			//printf("SECTOR 2 GET %s \n",v[data_id].sector[index].S2);
			//printf("SECTOR 3 GET %s \n",v[data_id].sector[index].S3);
			printf("READ OP: Data - %s, Actionid - %d , State - %s \n \n",read_value,v[data_id].id[index].a_id,v[data_id].id[index].state);

		
			break;
		}
		else{
		index--;
			if(index==-1)
			{
				break;
				//strcpy(read_value,"NULL");
				printf("ERROR");				
				}		
		}
	}
	return 0;
}

int WRITE_NEW_VALUE( int data_id, char *new_value, struct ActionId caller_id){

	int val=strcmp(caller_id.state,"PENDING");
	Sector new;
	if (val==0){
		int index;
		index=getlocation(data_id);
	

		v[data_id].id[index]=caller_id;

			 new=all_or_nothing_put(caller_id, new_value, data_id);
		
		v[data_id].sector[index]=new;
		

		
		//strcpy(v[data_id].value[index],new_value); // allornothing put
		
		printf("WRITE OP: Data - %s, Actionid - %d , State - %s \n \n", v[data_id].sector[index].S1,v[data_id].id[index].a_id,v[data_id].id[index].state);
	printf("SECTOR 1 PUT %s \n",v[data_id].sector[index].S1);
	printf("SECTOR 2 PUT %s \n",v[data_id].sector[index].S2);
	printf("SECTOR 3 PUT %s \n",v[data_id].sector[index].S3);
	}
	else{
	printf("ERR");
	}
	return 0; 

}

int FAULTY_READ_CURRENT_VALUE(int data_id){
	int index;
	char read_data[50];
	strcpy(read_value,"NULL");

	index=getlocationread(data_id);
	//printf("readcurr index %d",index);
		//printf("read index %d",index);
	while(1)
	{
		if(strcmp(v[data_id].id[index].state,"COMMITTED")==0)
		{
				
			all_or_nothing_get(data_id);
			//printf("read  %s",read_value);
			//strcpy(read_value,v[data_id].value[index]);
			printf("READ OP: Data - %s, Actionid - %d , State - %s \n",read_value,v[data_id].id[index].a_id,v[data_id].id[index].state);
			break;
		}
		else{
		index--;
			if(index==-1)
			{
				break;
				//strcpy(read_value,"NULL");
				printf("ERROR");				
				}		
		}
	}
	return 0;
}

int FAULTY_WRITE_NEW_VALUE( int data_id, char *new_value, struct ActionId caller_id){
	//printf("index");
	int val=strcmp(caller_id.state,"PENDING");
	Sector new;
	if (val==0){
		int index;
		index=getlocation(data_id);
	//printf("index %d",index);
		v[data_id].id[index]=caller_id;

			 new=faulty_all_or_nothing_put(caller_id, new_value, data_id);
		
		v[data_id].sector[index]=new;
		

		
		//strcpy(v[data_id].value[index],new_value); // allornothing put
		
		printf("WRITE OP: Data - %s, Actionid - %d , State - %s \n", v[data_id].sector[index].S1,v[data_id].id[index].a_id,v[data_id].id[index].state);
	printf("SECTOR 1 PUT %s \n",v[data_id].sector[index].S1);
	printf("SECTOR 2 PUT %s \n",v[data_id].sector[index].S2);
	printf("SECTOR 3 PUT %s \n",v[data_id].sector[index].S3);
	}
	else{
	printf("ERR");
	}
	return 0; 

}




int t_sleep(unsigned long milisec)
{
	    printf("WAITING FOR %lu  milisecs \n",milisec );
    struct timespec req={0};
    time_t sec=(int)(milisec/1000);
    milisec=milisec-(sec*1000);
    req.tv_sec=sec;
    req.tv_nsec=milisec*1000000L;

    while(nanosleep(&req,&req)==-1)
         continue;
    return 1;
}