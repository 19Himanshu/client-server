# client-server

Transferring files between client and server
#Build:
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

# Command line instrcutions
Once you get to the directory where you have the files. 
To compile the server code "gcc serv.c -o serv" and run using "./serv"
To compile the client code "gcc cli.c -o cli" and run using "./cli"
