
#include "new_outcome_record.h"
#include "action.h"
#include <string.h>
#include "log.h"
int aid=0;

struct ActionId NEW_OUTCOME_RECORD(){
	
	ActionId new;
	new.a_id=aid;
	aid++;
	strcpy(new.state,"PENDING");
	LOG(new.a_id,"BEGIN","NONE","NONE");
	return new;

}

