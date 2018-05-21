CC = g++
CFLAGS = -std=c++98 -g
OBJS = system.o job.o process.o
TESTS = system_test intake_test banker_test validate

default: intake

test: $(TESTS)

intake: intake.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

validate: intake
	./$^ test1.in
	./$^ test2.in
	./$^ sample.in
	./validate.py

system_test: system_test.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	./$@

intake_test: intake.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	./$@ test.txt

banker_test: banker_test.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	./$@

%.o: %.cc %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o D*.json $(TESTS) intake
