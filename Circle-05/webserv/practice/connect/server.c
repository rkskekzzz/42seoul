
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

#include <sys/time.h>

#define BUFF_SIZE 1024

int main() {
	static char		buff[BUFF_SIZE];
	static int		sockets;
	// 소켓 생성
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		fprintf(stderr, "socket 생성 실패\n", errno);
		exit(errno);
	}

	// 소켓 주소정보 지정을 위한 구조체 초기화
	struct sockaddr_in addr;

	memset(&addr, 0, sizeof(addr));

	addr.sin_family      = AF_INET;             // IPv4 인터넷 프로토롤
	addr.sin_port        = htons(4000);         // 사용할 port 번호는 4000
	addr.sin_addr.s_addr = htonl(INADDR_ANY);   // network byte order 32bit IPv4 주소


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
			// fprintf(stderr, "2 : %s(%d)\n", strerror(errno), errno);
		} else {
			sockets = c_sockfd;
			printf("original fd : %d(%d)\n", sockfd, addr.sin_addr.s_addr);
			printf("new socket fd : %d(%u)\n", c_sockfd, ntohl(c_addr.sin_addr.s_addr));
			read(c_sockfd, &buff, BUFF_SIZE);
			printf("server : %s\n", buff);
			write(c_sockfd, buff, strlen(buff) + 1);
			// close(c_sockfd);
		}
		if (recv(sockets, &buff, BUFF_SIZE, MSG_DONTWAIT) == 0) {
			close(sockets);
		}
	}
	return 0;
}
