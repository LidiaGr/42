# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/23 18:42:26 by ttarsha           #+#    #+#              #
#    Updated: 2020/07/25 16:38:37 by ttarsha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt update \
&&  apt upgrade -y \
&&  apt install -y nginx \
                openssl \
                php-fpm \
                php-mysql \
                php-mbstring \
                mariadb-server \
                wget 

RUN mkdir /var/www/ttarsha /var/www/ttarsha/phpmyadmin /var/www/ttarsha/phpmyadmin/cache \
&&  wget -c https://wordpress.org/latest.tar.gz \
&&  tar -xvf latest.tar.gz -C ./var/www/ttarsha \
&&  wget -c https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.xz \
&&  tar -xvf phpMyAdmin-4.9.5-all-languages.tar.xz --strip-components 1 -C ./var/www/ttarsha/phpmyadmin \
&&  rm -f *.tar* 

RUN mkdir /etc/nginx/ssl \
&&  openssl req -newkey rsa:2048 -x509 -sha256 -nodes -out /etc/nginx/ssl/localhost.crt \
    -keyout /etc/nginx/ssl/localhost.key -subj "/C=RU/ST=Tatarstan/L=Kazan/O=School 21/OU=ttarsha/CN=localhost"

RUN mkdir scripts 
COPY ./srcs/ ./scripts/

EXPOSE 80 443

RUN mv /scripts/localhost /etc/nginx/sites-available \
&&  rm -f /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default \
&&  ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost \
&&  bash /scripts/mysql_db.sh \
&&  mv /scripts/wp-config.php /var/www/ttarsha/wordpress \
&&  mv /scripts/config.inc.php /var/www/ttarsha/phpmyadmin/ 

CMD bash /scripts/server.sh