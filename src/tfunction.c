#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "read.h"
#include "write.h"
#include "allocate.h"
#include "deallocate.h"
#include "version.h"
#include "action.h"
#include "act.h"
#include <string.h>
#include "new_outcome_record.h"
#include "new_action.h"
#include "jsmreadwrite.h"
#include "readval.h"
#include "ALL_OR_NOTHING.h"
#include "log.h"
#include "recover.h"
#include "sector.h"
#include "tfunction.h"
#include "args.h"
#include "getlocation.h"
#include <time.h>
#include <signal.h>
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var = PTHREAD_COND_INITIALIZER;
void *tfunction(void *arg)
{

		 ARGS *a =(ARGS*)arg;
		 char *data;
		 int thread=a->thread;
		 int data_id=a->data_id;
		 data=a->data;

		 //TEST CASE1

		 ActionId a1=NEW_ACTION(data_id);

		 printf("Thread %d  id- %d data_id %d \n",thread,a1.a_id,data_id);
		 int result1,c1;

	
		   pthread_mutex_lock( &mutex1 );
	
		 result1=FAULTY_WRITE_NEW_VALUE(data_id,data,a1);	 
		 c1=ABORT(data_id,a1);
		 
		
		
			 pthread_mutex_unlock( &mutex1 );
					
	

		printf("Thread %d action %d complete \n",thread,a1.a_id);
    	v[data_id].lock=0;


}






/*
//TEST CASE 2

void *tfunction(void *arg)
{

		 ARGS *a =(ARGS*)arg;
		 char *data;
		 int thread=a->thread;
		 int data_id=a->data_id;
		 data=a->data;

		 ActionId a1=NEW_ACTION(data_id);

		 printf("Thread %d  id- %d data_id %d \n",thread,a1.a_id,data_id);
		 int result1,c1;

	
		   pthread_mutex_lock( &mutex1 );
	
		 result1=WRITE_NEW_VALUE(data_id,data,a1);	 
		 c1=COMMIT(data_id,a1);
		 
		
		
			 pthread_mutex_unlock( &mutex1 );
					
	

		printf("Thread %d action %d complete \n",thread,a1.a_id);
    	v[data_id].lock=0;


}


//TEST CASE 3

void *tfunction(void *arg)
{

		 ARGS *a =(ARGS*)arg;
		 char *data;
		 int thread=a->thread;
		 int data_id=a->data_id;
		 data=a->data;

		 ActionId a1=NEW_ACTION(data_id);		//Create new action

		 printf("Thread %d  id- %d data_id %d \n",thread,a1.a_id,data_id);
		 int result1,c1;

	
		   pthread_mutex_lock( &mutex1 );
	
		 result1=WRITE_NEW_VALUE(data_id,data,a1);	 // WRITE To the disk
		 c1=COMMIT(data_id,a1);					// COMMIT
		 result1= READ_CURRENT_VALUE(data_id); // Read the data from disk
			 pthread_mutex_unlock( &mutex1 );
					
	

		printf("Thread %d action %d complete \n",thread,a1.a_id);
    	v[data_id].lock=0;


}








//TEST CASE 4


pthread_cond_t  condition_var = PTHREAD_COND_INITIALIZER;
void *tfunction(void *arg)
{

		 ARGS *a =(ARGS*)arg;
		 char *data;
		 int thread=a->thread;
		 int data_id=a->data_id;
		 data=a->data;

		 ActionId a1=NEW_ACTION(data_id);

		 printf("Thread %d  id- %d data_id %d \n",thread,a1.a_id,data_id);
		 int result1,c1;

	
		   pthread_mutex_lock( &mutex1 );
	
		 result1=WRITE_NEW_VALUE(data_id,data,a1); // write value	 
		 c1=COMMIT(data_id,a1);		// Commit	
		  c1 = ABORT(data_id,a1);	// Abort already committed action
		
			 pthread_mutex_unlock( &mutex1 );
					
	

		printf("Thread %d action %d complete \n",thread,a1.a_id);
    	v[data_id].lock=0;


}

void *tfunction1(void *arg)
{

		 ARGS *a =(ARGS*)arg;
		 char *data;
		 int thread=a->thread;
		 int data_id=a->data_id;
		 data=a->data;

		 ActionId a1=NEW_ACTION(data_id);

		 printf("Thread %d  id- %d data_id %d \n",thread,a1.a_id,data_id);
		 int result1,c1;

	
		   pthread_mutex_lock( &mutex1 );
	
		 result1=WRITE_NEW_VALUE(data_id,data,a1);	  // write new value
		 c1 = ABORT(data_id,a1);				// Abort action
		 		
			 pthread_mutex_unlock( &mutex1 );
					
	

		printf("Thread %d action %d complete \n",thread,a1.a_id);
    	v[data_id].lock=0;


}








//TEST CASE 5

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var = PTHREAD_COND_INITIALIZER;
void *tfunction(void *arg)
{

		 ARGS *a =(ARGS*)arg;
		 char *data;
		 int thread=a->thread;
		 int data_id=a->data_id;
		 data=a->data;

		 ActionId a1=NEW_ACTION(data_id);

		 printf("Thread %d  id- %d data_id %d \n",thread,a1.a_id,data_id);
		 int result1,c1;

	
		   pthread_mutex_lock( &mutex1 );
	
		 result1=FAULTY_WRITE_NEW_VALUE(data_id,data,a1); // Faulty Write	 
		 c1=COMMIT(data_id,a1);				// Commit it
		 int r;
		 r=READ_CURRENT_VALUE(data_id); 		// Read from disk
		
			 pthread_mutex_unlock( &mutex1 );
					
	

		printf("Thread %d action %d complete \n",thread,a1.a_id);
    	v[data_id].lock=0;


}

*/