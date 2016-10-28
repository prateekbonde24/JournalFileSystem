#include "new_action.h"
#include "action.h"
#include "new_outcome_record.h"
#include <string.h>
#include "version.h"
#include <stdio.h>
#include "jsmreadwrite.h"
struct ActionId NEW_ACTION(int data_id){

ActionId new;
new = NEW_OUTCOME_RECORD();
strcpy(new.state,"PENDING");
printf("NEW ACTION:  Action id - %d, State - %s\n",new.a_id,new.state);

	 if(v[data_id].lock==1)
    {
        printf("\n \n Disk Location %d locked. Other threads waiting. \n \n",data_id); t_sleep(5000);
    }
    while(v[data_id].lock==1);
    if(v[data_id].lock==0)
    {
        v[data_id].lock=1;
    }

return new;
}