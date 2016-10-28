#include "action.h"
#include "commit.h"
#include <string.h>
#include "version.h"
#include <stdio.h>
#include "log.h"
int COMMIT(int data_id,struct ActionId c)
{
	LOG(c.a_id,"OUTCOME","","COMMIT()");
	int index=getlocationofid(data_id,c.a_id);
	strcpy(c.state,"COMMITTED");
	v[data_id].id[index]=c;
	printf("COMMITTED: Data - %s, Action id - %d, State - %s\n",v[data_id].sector[index].S1,c.a_id,c.state);
	return 0;
}

