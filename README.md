# client-server
Transferring files between client and server.  Converted to C++ (only a couple of lines needed changing to start) and merged with CMake-based build system. As tersely implied below the source files are in the `src` directory.  You create a directory where you want to build your executable (e.g. make a directory called `build`) and hopefully the remainder is clear.

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

Can run the client and server executable in any number of ways.  From the `client-server/` directory `./build/clisrv/cli` and `./build/clisrv/srv`


