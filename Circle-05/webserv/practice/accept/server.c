
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h> // open function
#include <unistd.h> // close function
#include <errno.h>

int main() {
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));

	addr.sin_family      = AF_INET;             // IPv4 인터넷 프로토롤
	addr.sin_port        = htons(4000);         // 사용할 port 번호는 4000
	addr.sin_addr.s_addr = htonl(INADDR_ANY);   // network byte order 32bit IPv4 주소

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
		printf("bind() error!!\n");
		exit(1);
	}

	if (listen(sockfd, 5) == -1) {
		printf("listen Fail\n");
		return -1;
	}

	int flag = fcntl(sockfd, F_GETFL, 0);
	fcntl(sockfd, F_SETFL, flag | O_NONBLOCK);

	struct sockaddr_in c_addr;
	socklen_t c_addr_len = sizeof(c_addr);
	printf("EAGAIN : %d\n", EAGAIN);
	while (1) {
		int c_sockfd = accept(sockfd, (struct sockaddr *)&c_addr, &c_addr_len);
		if (c_sockfd == -1) {
			fprintf(stderr, "2 : %s(%d)\n",strerror(errno), errno);
		} else {
			printf("original fd : %d(%d)\n", sockfd, addr.sin_addr.s_addr);
			printf("new socket fd : %d(%u)\n", c_sockfd, ntohl(c_addr.sin_addr.s_addr));
			break ;
		}
	}
	return 0;
}
