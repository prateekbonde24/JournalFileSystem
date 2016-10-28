JFS: action.o dec.o read.o main.o jsmreadwrite.o new_action.o new_outcome_record.o deallocate.o allocate.o write.o getlocation.o commit.o abort.o careful.o  ALL_OR_NOTHING.o log.o readval.o recover.o tfunction.o 
	gcc -lpthread -o JFS action.o dec.o read.o main.o jsmreadwrite.o new_action.o new_outcome_record.o deallocate.o allocate.o write.o getlocation.o commit.o abort.o careful.o  ALL_OR_NOTHING.o log.o readval.o recover.o tfunction.o

action.o: action.c action.h act.h
	gcc -c action.c

dec.o: dec.c version.h
	gcc -c dec.c
read.o: read.c read.h version.h act.h
	gcc -c read.c
write.o: write.c write.h version.h act.h
	gcc -c write.c
allocate.o: allocate.c allocate.h version.h act.h
	gcc -c allocate.c
deallocate.o: deallocate.c deallocate.h version.h act.h
	gcc -c deallocate.c


jsmreadwrite.o: jsmreadwrite.c jsmreadwrite.h version.h action.h getlocation.h ALL_OR_NOTHING.h log.h sector.h
	gcc -c jsmreadwrite.c

getlocation.o: getlocation.c getlocation.h version.h action.h
	gcc -c getlocation.c
new_outcome_record.o: new_outcome_record.c new_outcome_record.h action.h log.h act.h 
	gcc -c new_outcome_record.c
commit.o: commit.c version.h action.h commit.h log.h
	gcc -c commit.c

abort.o: abort.c version.h action.h abort.h log.h
	gcc -c abort.c

new_action.o: new_action.c action.h new_action.h new_outcome_record.h act.h getlocation.h jsmreadwrite.h  version.h
	gcc -c new_action.c

careful.o: careful.c careful.h
	gcc -c careful.c

recover.o: recover.c log.h recover.h version.h
	gcc -c recover.c

log.o: log.c log.h action.h
	gcc -c log.c

ALL_OR_NOTHING.o: ALL_OR_NOTHING.c ALL_OR_NOTHING.h careful.h sector.h action.h log.h version.h
	gcc -c ALL_OR_NOTHING.c 

tfunction.o: tfunction.c read.h version.h action.h act.h new_outcome_record.h write.h allocate.h deallocate.h getlocation.h commit.h new_action.h jsmreadwrite.h readval.h ALL_OR_NOTHING.h log.h recover.h tfunction.h args.h
	gcc -c tfunction.c -lpthread

main.o: main.c read.h version.h action.h act.h new_outcome_record.h write.h allocate.h deallocate.h getlocation.h commit.h new_action.h jsmreadwrite.h readval.h ALL_OR_NOTHING.h log.h recover.h tfunction.h args.h 
	gcc -c main.c -lpthread

readval.o: readval.c
	gcc -c readval.c




clean :
	rm JFS action.o dec.o read.o main.o jsmreadwrite.o new_action.o new_outcome_record.o deallocate.o allocate.o write.o getlocation.o commit.o abort.o careful.o ALL_OR_NOTHING.o log.o readval.o recover.o tfunction.o
