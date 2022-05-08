
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h> // open function
#include <unistd.h> // close function
#include <strings.h>
#include <arpa/inet.h>

#define PORT 9000
#define IPADDR "10.19.238.159"

char buffer[BUFSIZ];

int main() {
	int c_socket;
	struct sockaddr_in c_addr;
	int len;

	char rcvBuffer[BUFSIZ];

	int n;

	c_socket = socket(PF_INET, SOCK_STREAM, 0);
	memset(&c_addr, 0, sizeof(c_addr));

	c_addr.sin_addr.s_addr = inet_addr(IPADDR);
	c_addr.sin_family = AF_INET;
	c_addr.sin_port = htons(PORT);

	if (connect(c_socket, (struct sockaddr *)&c_addr, sizeof(c_addr)) == -1) {
		printf("Can not connect\n");
		close(c_socket);
		return -1;
	}

	scanf("%s", buffer);
	buffer[strlen(buffer)] = '\0';
	write(c_socket, buffer, strlen(buffer) + 1);

	if ((n = read(c_socket, rcvBuffer, sizeof(rcvBuffer))) < 0) {
		return -1;
	}

	rcvBuffer[n] = '\0';
	printf("received Data : %s\n", rcvBuffer);

	close(c_socket);
}
