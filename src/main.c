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


pthread_mutex_t mutex12 = PTHREAD_MUTEX_INITIALIZER;
//extern pthread_mutex_t lock,lock1;
int main(){

my_init();
int c1;
int result1,result2;


pthread_t t[6];

ARGS* args;
   args= malloc(20*sizeof(ARGS));

// TEST CASE 1
(*args).thread=1;// thread number
(*args).data_id=0;  // disk location
(*args).data="Hey123123";  // data

    pthread_create(&t[1],NULL,tfunction,(void*)args);
args=args+1;
(*args).thread=2;// thread number
(*args).data_id=1;// disk location
(*args).data="bye"; // data

    pthread_create(&t[2],NULL,tfunction,(void*)args); 
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);



return 0;


}


/*


// TEST CASE 1
(*args).thread=1;// thread number
(*args).data_id=0;  // disk location
(*args).data="Hey123123";  // data

    pthread_create(&t[1],NULL,tfunction,(void*)args);
args=args+1;
(*args).thread=2;// thread number
(*args).data_id=1;// disk location
(*args).data="bye"; // data

    pthread_create(&t[2],NULL,tfunction,(void*)args); 
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);



// TEST CASE 2
(*args).thread=1;// thread number
(*args).data_id=0;  // disk location
(*args).data="Hey123123";  // data

    pthread_create(&t[1],NULL,tfunction,(void*)args);
args=args+1;
(*args).thread=2;// thread number
(*args).data_id=1;// disk location
(*args).data="bye"; // data

    pthread_create(&t[2],NULL,tfunction,(void*)args); 

args=args+1;
(*args).thread=3; // thread number
(*args).data_id=0;  // disk location
(*args).data="data 3";  // data

    pthread_create(&t[3],NULL,tfunction,(void*)args);


     args=args+1;
(*args).thread=4; // thread number
(*args).data_id=1;  // disk location
(*args).data="FOUR";  // data

    pthread_create(&t[4],NULL,tfunction,(void*)args);

 pthread_join(t[1], NULL);
     pthread_join(t[2], NULL);
      
     pthread_join(t[3], NULL);
     pthread_join(t[4], NULL);
 



// TEST CASE 3
(*args).thread=1;// thread number
(*args).data_id=0;  // disk location
(*args).data="testcase3";  // data

    pthread_create(&t[1],NULL,tfunction,(void*)args);
args=args+1;
(*args).thread=2;// thread number
(*args).data_id=1;// disk location
(*args).data="data3"; // data

    pthread_create(&t[2],NULL,tfunction,(void*)args); 

args=args+1;
(*args).thread=3; // thread number
(*args).data_id=0;  // disk location
(*args).data="AdvOS";  // data

    pthread_create(&t[3],NULL,tfunction,(void*)args);
     pthread_join(t[1], NULL);
     pthread_join(t[2], NULL);
     pthread_join(t[3], NULL);
int rec;
    rec=RECOVER(); 

    
// TEST CASE 4
(*args).thread=1;// thread number
(*args).data_id=0;  // disk location
(*args).data="testcase4";  // data

    pthread_create(&t[1],NULL,tfunction,(void*)args);
args=args+1;
(*args).thread=2;// thread number
(*args).data_id=1;// disk location
(*args).data="data4"; // data

    pthread_create(&t[2],NULL,tfunction1,(void*)args); 




     pthread_join(t[1], NULL);
     pthread_join(t[2], NULL);



// TEST CASE 5
(*args).thread=1;// thread number
(*args).data_id=0;  // disk location
(*args).data="testcase5";  // data

    pthread_create(&t[1],NULL,tfunction,(void*)args);
args=args+1;
(*args).thread=2;// thread number
(*args).data_id=0;// disk location
(*args).data="data5"; // data

    pthread_create(&t[2],NULL,tfunction,(void*)args); 

     pthread_join(t[1], NULL);
     pthread_join(t[2], NULL);

*/