#include "sector.h"
#include "action.h"
#ifndef ALL_OR_NOTHING_H
#define ALL_OR_NOTHING_H

struct Sector almost_all_or_nothing_put(struct ActionId act,char *data, int data_id);
void all_or_nothing_get(int data_id);
struct Sector all_or_nothing_put(struct ActionId act, char *data, int data_id);
struct Sector check_and_repair(int data_id);



struct Sector faulty_almost_all_or_nothing_put(struct ActionId act,char *data, int data_id);
void faulty_all_or_nothing_get(int data_id);
struct Sector faulty_all_or_nothing_put(struct ActionId act, char *data, int data_id);
struct Sector faulty_check_and_repair(int data_id);
#endif
