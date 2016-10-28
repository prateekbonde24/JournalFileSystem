#include "ALL_OR_NOTHING.h"
#include "careful.h"
#include <string.h>
#include "log.h"
#include "action.h"
#include "act.h"
#include "sector.h"
#include <stdio.h>
#include "version.h"
#include "readval.h"
#include <stdlib.h>

struct Sector almost_all_or_nothing_put(struct ActionId act,char *data, int data_id){
		int index;
		index=getlocation(data_id);	

	 Sector s;
	char *undoaction="CAREFUL_PUT(sector.S1,NULL);CAREFUL_PUT(sector.S2,NULL);CAREFUL_PUT(sector.S3,NULL);";
	char *redoaction="CAREFUL_PUT(d_t, sector.S1);CAREFUL_PUT(d_t, sector.S2);CAREFUL_PUT(d_t, sector.S3);";
	
	char newredo[900];
		strcpy(newredo,str_replace(redoaction,"d_t",data));
		strcpy(newredo,str_replace(newredo,"d_t",data));
		strcpy(newredo,str_replace(newredo,"d_t",data));


	LOG(act.a_id,"CHANGE",undoaction,newredo); // changes here


	strcpy(s.S1,data);
	strcpy(s.S2,data);
	strcpy(s.S3,data);



return s;
}

void all_or_nothing_get(int data_id){

	int index;	
	index=getlocationread(data_id);
	char data1[50];
	char data2[50];
	char data3[50];
//printf("SECTOR 1 GET %s \n",v[data_id].sector[index].S1);
strcpy(data1,v[data_id].sector[index].S1);
strcpy(data2,v[data_id].sector[index].S2);
strcpy(data3,v[data_id].sector[index].S3);

if(strcmp(data1,data2)==0){
	strcpy(read_value,data1);
		
	}
else{
	strcpy(read_value,data3);	
	printf("Last write was not completed correctly \n \n");	
	}



}

struct Sector all_or_nothing_put(struct ActionId act, char *data,int data_id){
		Sector s_check,s_new;		
		s_check=check_and_repair(data_id);
		int index;	
		index=getlocationread(data_id);
		v[data_id].sector[index]=s_check;

		s_new=almost_all_or_nothing_put(act,data,data_id);
	return s_new;
	}

struct Sector check_and_repair(int data_id)
{	int index;	
	index=getlocationread(data_id);
	char data1[50];
	char data2[50];
	char data3[50];
	Sector s_check;

	

	strcpy(data1,v[data_id].sector[index].S1);
	strcpy(data2,v[data_id].sector[index].S2);
	strcpy(data3,v[data_id].sector[index].S3);
		//printf("CHECK AND REPAIR %s %s %s \n",s_check.S1,s_check.S2,s_check.S3);
	if((strcmp(data1,data2)==0)&&(strcmp(data2,data3)==0))
	{
	//	return;	//no repair
	strcpy(s_check.S1,data1);
	strcpy(s_check.S2,data2);
	strcpy(s_check.S3,data3);
	//printf("CHECK AND REPAIR1 %s %s %s \n",s_check.S1,s_check.S2,s_check.S3);
		}
	else if ((strcmp(data2,data3)!=0)||(strcmp(data1,data3)!=0)){
		strcpy(s_check.S3,data1);
		strcpy(s_check.S1,data1);
		strcpy(s_check.S2,data1);
	//printf("CHECK AND REPAIR2 %s %s %s \n",s_check.S1,s_check.S2,s_check.S3);
	}
	else if ((strcmp(data1,data3)!=0)||(strcmp(data1,data2)!=0)){

		strcpy(s_check.S1,data2);
		strcpy(s_check.S2,data2);
		strcpy(s_check.S3,data2);
		//printf("CHECK AND REPAIR3 %s %s %s \n",s_check.S1,s_check.S2,s_check.S3);
		}

	else{
		strcpy(s_check.S2,data1);
		strcpy(s_check.S3,data1);
		strcpy(s_check.S1,data1);
	}

return s_check;

}

struct Sector faulty_all_or_nothing_put(struct ActionId act, char *data, int data_id){
		Sector s_new;		
		s_new=check_and_repair(data_id);
		s_new=faulty_almost_all_or_nothing_put(act,data,data_id);
	return s_new;

}
struct Sector faulty_almost_all_or_nothing_put(struct ActionId act, char *data, int data_id)
	{
	int index;
		index=getlocation(data_id);	

	 Sector s;
	char *undoaction="CAREFUL_PUT(sector.S1,NULL);CAREFUL_PUT(sector.S2,NULL);CAREFUL_PUT(sector.S3,NULL);";
	char *redoaction="CAREFUL_PUT(d_t, sector.S1);CAREFUL_PUT(d_t, sector.S2);CAREFUL_PUT(d_t, sector.S3);";
	
		char newredo[900];
		strcpy(newredo,str_replace(redoaction,"d_t",data));
		strcpy(newredo,str_replace(newredo,"d_t",data));
		strcpy(newredo,str_replace(newredo,"d_t",data));


	LOG(act.a_id,"CHANGE",undoaction,newredo);

	strcpy(s.S1,data);
	strcpy(s.S2,"ERROR VALUE");
	strcpy(s.S3,data);
	//strcpy(v[0].sector[0].S1,data);
	//printf("SECTOR 1 PUT %s \n",v[data_id].sector[index].S1);
	//printf("SECTOR 2 PUT %s \n",v[data_id].sector[index].S2);
	//printf("SECTOR 3 PUT %s \n",v[data_id].sector[index].S3);


return s;
	}
void faulty_all_or_nothing_get(int data_id){

	int index;	
	index=getlocationread(data_id);
	char data1[50];
	char data2[50];
	char data3[50];
	//printf("SECTOR 1 GET %s \n",v[data_id].sector[index].S1);
	strcpy(data1,v[data_id].sector[index].S1);
	strcpy(data2,v[data_id].sector[index].S2);
	strcpy(data3,v[data_id].sector[index].S3);



	
	}



	















