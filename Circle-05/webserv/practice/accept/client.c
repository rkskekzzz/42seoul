
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define PORT 4000
#define IPADDR "127.0.0.1"

int main() {
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));

	addr.sin_family      = AF_INET;             // IPv4 인터넷 프로토롤
	addr.sin_port        = htons(PORT);         // 사용할 port 번호는 4000
	addr.sin_addr.s_addr = inet_addr(IPADDR);   // network byte order 32bit IPv4 주소

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		printf("Can not connect\n");
		return -1;
	}

	while (1)
		;
	return 0;
}
