
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

#define PORT 4000
#define IPADDR "127.0.0.1"
#define BUFF_SIZE 1024

int main(int argc, char** argv) {
	static char   buff[BUFF_SIZE];
	if (argc < 2) {
		fprintf(stderr, "인자가 너무 적습니다\n");
		exit(1);
	}
	printf("argv : %s\n", argv[1]);
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
	addr.sin_port        = htons(PORT);         // 사용할 port 번호는 4000
	addr.sin_addr.s_addr = inet_addr(IPADDR);   // network byte order 32bit IPv4 주소

	// 소켓 연결
	if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		printf("Can not connect\n");
		return -1;
	}
	printf("client socket fd : %d\n", sockfd);
	write(sockfd, argv[1], strlen(argv[1]) + 1);
	read(sockfd, &buff, BUFF_SIZE);
	printf("client : %s\n", buff);
	shutdown(sockfd, SHUT_RDWR);
	sleep(2);
	close(sockfd);
	while (1);
	return 0;
}
