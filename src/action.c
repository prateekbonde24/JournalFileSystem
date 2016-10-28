#include "action.h"

#include <string.h>
ActionId act[100];

int in_itt(void){
int i;
act[0].a_id=0;
strcpy(act[0].state,"NULL");
for(i=1;i<100;i++){
act[i].a_id=-1;
strcpy(act[i].state,"NULL");
}
}
