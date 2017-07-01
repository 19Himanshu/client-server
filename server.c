/* A simple echo server using TCP */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
itdefine SERVER_TCP_POR‘I‘ 3000 /* well—known port */
#define BUFLEN 256 /* buffer length */
int main(int argc, char **argv)
{
int n, bytes_to_read;
int sd, new_sd, client_len, port;
struct sockaddr_in server, client;
char *bp, buf[BUFLEN];
switch(argc) {
case 1:
pOIt = SERVER_TCP_PORT;
break;
case 2:
port = atoi(argv[l]);
break;
default:
fprintf(stderr, "Usage: %s [port]\n", argv[O]);
exit(l);
}
/* Create a stream socket */
if ((sd I s0cket(AF_1NET, SOCK_STREAM, 0)) I: -1) {
fprintf(stderr, "Can't create a socket\n");
exit(l);
}
/* Bind an address to the socket */
bZer0((Char *)&server, siZeof(struct sockaddr_in));
sezver.sin_family = AF_INET;
server.sin_p0rt = ht0nS(p0rt);
server.sin_addr.s_addr I hton1(INADDR_ANY);
if (bind(sd, (struct sockaddr *)&server,
sizeof(server)) I: -1) {
fprintf(stderr, "Can't bind name to socket\n");
exit(1);
}
/* queue up to 5 connect requests */
listen(sd, 5);
while (1) {
c1ient_len = sizeof(client);
if ((new_sd = accept(sd, (struct sockaddr *)
&c1ient, &client_len)) == -1) {
fprintf(stderr, "Can't accept client\n");
exit(1);
}
bytes_to_read = BUFLEN;
while ((n = read(new_sd, bp, bytes_to_read)) > O) {
hp += n;
bytes_to_read —= n;
l
write(new_sd, buf, BUFLEN);
close(new_sd);
}
close(sd);
return(O);
}