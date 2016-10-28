#include "action.h"

#ifndef JSMREADWRITE_H
#define JSMREADWRITE_H


int READ_CURRENT_VALUE(int data_id);
int WRITE_NEW_VALUE( int data_id, char *new_value, struct ActionId caller_id);

int FAULTY_READ_CURRENT_VALUE(int data_id);
int FAULTY_WRITE_NEW_VALUE( int data_id, char *new_value, struct ActionId caller_id);
int t_sleep ( unsigned long milisec);
#endif
