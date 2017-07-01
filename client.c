/* A simple TCP client */
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#inc1ude <sys/s0cket.h>
#include <netinet/in.h>
#define SERVER_TCP_PORT 3000
#define BUFLEN 256 /* buffer length */
int main(int argc, char **argv)
{
int n, bytes_t0_read;
int sd, port;
struct hostent *hp;
struct sockaddr_in server;
char *l'iost, *bp, rbuf[BUFLEN], sbuf[BUFLEN1;
switch(argc) {
case 2:
host = argvlll;
port = SERVER_TCP_PORT;
break;
case 3:
host = argvllli
port = atoi(argv[2]);
break;
default:
fprintf(stderr, "Usage: %s host[port]\n", argv[O]);
exitll);
}
/* Create a stream socket */
if ((sd = socket(AF_INET, SOCK_STREAM, OH == -1) {
fprintf(stderr, "Can't create a socket\n");
exit(1);
}
bzer0((char *)&server, sizeoflstruct sockaddr_in));
server.sin_family = AF_INET;
server.sin_port = htons(port);
if ((hp = gethostbynamelhostll == NULL) {
fprintf(stderr, "Can't get server's address\n");
exit(1);
}
bcopy(hp—>h_addr, (char *)&server.sin_addr,
hp—>_length);
/* Connecting to the server */
if (connect(sd, (struct sockaddr *)&server,
sizeof(server)) == -1) {
fprintf(stderr, "Can't connect\n");
exit(l);
}
printf("C0nnected: server's address is %s\n“,
hp—>_name);
printf("Transmit:\n");
gets(sbuf); /* get user's text */
write(sd, sbuf, BUFLEN); /* send it out */
printf("Receive:\n");
bp = rbuf;
bytes_to_read I BUFLEN;
while ((n = read (sd, bp, bytes_to_read)) > O) {
bp +1 n;
bytes_to_read —= n;
}
printf("%s\n", rbuf);
close(sd);
return(O);
}