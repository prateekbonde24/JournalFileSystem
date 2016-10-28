#include "action.h"
#ifndef LOG_H
#define LOG_H

typedef struct LOG_RECORD{
//ActionId action_id;
int action_id;
char type[50];
char undo_action[900];
char redo_action[900];
}LOG_RECORD;


extern struct LOG_RECORD log_record[1000];

void LOG(int action_id,char *type, char *undo_action,char *redo_action);

void printlog(int action_id,char *type, char *undo_action,char *redo_action);
int getlocationoflog();


#endif
