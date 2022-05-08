#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h> // open function
#include <unistd.h> // close function
#include <strings.h>
#include <arpa/inet.h>

#define PORT 9000
#define IPADDR "127.0.0.1"

char buffer[BUFSIZ] = "hello, world";
char rBuffer[BUFSIZ];

int main() {
	int c_socket, s_socket;
	struct sockaddr_in s_addr, c_addr;
	int len;

	char *temp;
	int length;

	int n, i;

	s_socket = socket(PF_INET, SOCK_STREAM, 0);
	memset(&s_addr, 0, sizeof(s_addr));

	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(PORT);

	if (bind(s_socket, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1) {
		printf("Can not bind\n");
		close(s_socket);
		return -1;
	}

	if (listen(s_socket, 5) == -1) {
		printf("listen Fail\n");
		return -1;
	}

	while (1) {
		len = sizeof(c_addr);
		c_socket = accept(s_socket, (struct sockaddr *)&c_addr, &len);

		int flag = fcntl(c_socket, F_GETFL, 0);
        fcntl(c_socket, F_SETFL, flag | O_NONBLOCK);

		length = 0;
		temp = rBuffer;
		while((n = read(c_socket, temp, 1)) > 0) {
			if(*temp == '\r') continue;
			if(*temp == '\n') break;
			if(*temp == '\0') break;

			if (length == BUFSIZ) break;
			temp++;
			length++;
		}

		rBuffer[length] = '\0';
		write(c_socket, rBuffer, strlen(rBuffer));
		close(c_socket);
		printf(" routine running \n");
	}
	close(s_socket);
}
