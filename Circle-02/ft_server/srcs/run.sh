# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 17:24:31 by suhshin           #+#    #+#              #
#    Updated: 2021/05/11 17:29:37 by suhshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#!/bin/bash

openssl req -newkey rsa:2048 -days 42 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=GON/OU=GONNN/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt

mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/

chmod 600 etc/ssl/certs/localhost.dev.crt

cp /tmp/default /etc/nginx/sites-available/

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
cp /tmp/config.inc.php /var/www/html/phpmyadmin/

service mysql start
mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON *.* TO 'suhshin'@'localhost' IDENTIFIED BY '1234' WITH GRANT OPTION" | mysql -u root --skip-password

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress

cp /tmp/wp-config.php /var/www/html/wordpress

service nginx start
service php7.3-fpm start
service mysql restart

bash
