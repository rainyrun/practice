all: client server server_s

client server server_s: wrap.o

client: client.o
	gcc $^ -o $@

server: server.o
	gcc $^ -o $@

server_s: server_s.o
	gcc $^ -o $@

client.o server.o server_s.o: wrap.h

clean:
	@echo "cleaning project..."
	-rm *.o client server server_s
	@echo "clean completed"

.PHONY: clean
