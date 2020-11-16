FROM alpine

COPY	wp-config.php \
		nginx.conf \
		supervisord.conf \
		/

RUN apk update \
&&	apk add php7 \
		php7-cli \
		php7-curl \
		php7-fpm \
		php7-cgi \
		php7-json \
		php7-mysqli \
		php7-mbstring \
		mysql \
		mysql-client \
		nginx \
		supervisor \
\
&&  wget -c https://wordpress.org/latest.tar.gz \
&&  tar -xf latest.tar.gz -C /var/www \
&&  mv /wp-config.php /var/www/wordpress/ \
\
&&	mkdir /etc/supervisor.d \
		  /run/nginx \
		  /var/run/php \
\
&&	rm /etc/nginx/conf.d/default.conf \
&&	mv /nginx.conf /etc/nginx/conf.d/ \
\
&& 	mv /supervisord.conf /etc

EXPOSE 5050

CMD ["usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
