FROM alpine

COPY init.sh wordpress.sql /

RUN apk update \
&&	apk add openrc \
			mysql \
			mysql-client \
\
&&	chmod +x /init.sh

COPY my.cnf /etc/mysql/

VOLUME /var/lib/mysql

EXPOSE 3306
ENTRYPOINT /init.sh
