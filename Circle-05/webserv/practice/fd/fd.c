
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	struct sockaddr_in addr;
	struct sockaddr_in bf_addr;
	struct sockaddr_in af_addr;
	memset(&addr, 0, sizeof(addr));

	addr.sin_family      = AF_INET;             // IPv4 인터넷 프로토롤
	addr.sin_port        = htons(4000);         // 사용할 port 번호는 4000
	addr.sin_addr.s_addr = htonl(INADDR_ANY);   // network byte order 32bit IPv4 주소

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
		printf("bind() error!!");
		exit(1);
	}

	socklen_t bf_len = sizeof(bf_addr);
	getsockname(sockfd, (struct sockaddr *)&bf_addr, &bf_len);
	printf("bf host : %d\n", ntohs(bf_addr.sin_port));

	memset(&addr, 0, sizeof(addr));

	socklen_t af_len = sizeof(af_addr);
	getsockname(sockfd, (struct sockaddr *)&af_addr, &af_len);
	printf("af host : %d\n", ntohs(af_addr.sin_port));

	int val;
	socklen_t len = sizeof(val);
	if (getsockopt(sockfd, IPPROTO_TCP, SO_ACCEPTCONN, &val, &len) == -1)
		printf("sockfd %d is not a socket\n", sockfd);
	else if (val)
		printf("sockfd %d is a listening socket\n", sockfd);
	else
		printf("sockfd %d is a non-listening socket\n", sockfd);

	return 0;
}
