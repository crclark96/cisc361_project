CC = g++
OBJS = system.o job.o process.o
TESTS = system_test intake_test

default: intake.o

test: $(TESTS)

system_test: system_test.o $(OBJS)
	$(CC) $^ -o $@
	./$@

intake_test: intake.o $(OBJS)
	$(CC) $^ -o $@
	./$@ test.txt

%.o: %.cc %.h
	$(CC) -c $<

clean:
	rm *.o
