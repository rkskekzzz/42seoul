# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 17:16:08 by suhshin           #+#    #+#              #
#    Updated: 2021/05/11 17:17:08 by suhshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:buster

LABEL	maintainer="suhshin <suhshin@student.42seoul.kr>"

RUN		apt-get -y update && apt-get -y install \
		nginx \
		php7.3-fpm \
		mariadb-server \
		php-mysql \
		vim \
		openssl \
		wget

COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp

CMD		sh run.sh
