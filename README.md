# client-server
Transferring files between client and server

Requirements:
-------------------
1. CMake 2.8.12 or newer

Build:
-------------------
1. Clone the client and server software
	```
	git clone https://github.com/19Himanshu/client-server.git
	cd client-server/
	```

2. Configure the system with CMake and build source code
	```
	mkdir build/
	cd build
	cmake ../src
	make
	```

If the ```build``` directory already exists, you are better off to erase it and re-do the cmake procedure above or to just make another directory, say ```build_my``` and work from there (i.e. the executables will be created within that directory)

Run:
-------------------

### Command-Line Stuff ###

Can run the client and server executable in any number of ways.  From the `client-server/` directory
	```
	./build/clisrv/cli
	```
and

	```
	./build/clisrv/srv
	```

	
