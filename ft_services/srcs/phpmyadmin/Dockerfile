FROM alpine

COPY	config.inc.php \
		nginx.conf \
		supervisord.conf \
		/

RUN apk update \
&&	apk add php7 \
			php7-fpm \
			php7-opcache \
			php7-gd \
			php7-mysqli \
			php7-zlib \
			php7-curl \
			php7-mbstring \
			php7-json \
			php7-session \
			nginx \
			supervisor \
\
&&	mkdir /etc/supervisor.d \
		  /run/nginx \
		  /var/run/php \
		  /var/www/phpmyadmin \
		  /var/www/phpmyadmin/cache \
&& chmod 777 /var/www/phpmyadmin/cache \
\
&&	wget -c https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-english.tar.xz \
&&	tar -xf /phpMyAdmin-4.9.5-english.tar.xz --strip-components 1 -C /var/www/phpmyadmin \
&&	mv /config.inc.php /var/www/phpmyadmin \
\
&&	rm /etc/nginx/conf.d/default.conf \
&&	mv /nginx.conf /etc/nginx/conf.d/ \
\
&& 	mv /supervisord.conf /etc

EXPOSE 5000

CMD ["usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
