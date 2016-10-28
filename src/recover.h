#include "log.h"
#ifndef RECOVER_H
#define RECOVER_H

int RECOVER();
int ifcommitted(int action_id,int count, LOG_RECORD winners[]);
#endif
