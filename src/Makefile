driver: driver.o Manager.o Store.o Food.o Orders.o Order.o
	g++ -Wall -g -o driver.exe driver.o Manager.o Store.o Food.o Orders.o Order.o
driver.o: Driver.cpp Manager.h
	g++ -Wall -g -c Driver.cpp
Manager.o: Manager.cpp Manager.h
	g++ -Wall -g -c Manager.cpp
Store.o: Store.cpp Store.h
	g++ -Wall -g -c Store.cpp
Food.o: Food.cpp Food.h
	g++ -Wall -g -c Food.cpp
Orders.o: Orders.cpp Orders.h
	g++ -Wall -g -c Orders.cpp
Order.o: Order.cpp Order.h
	g++ -Wall -g -c Order.cpp

clean:
	rm *.o
	rm driver.exe

run:
	./driver.exe Sample1Store.txt Sample1Orders.txt