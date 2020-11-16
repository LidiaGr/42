FROM alpine

RUN apk update \
&&	apk add openrc \
			openssh \
			openssl \
			nginx \
			supervisor \
\
&& mkdir -p	/run/nginx \
			/var/run/sshd \
&& chown -R nginx:www-data /var/lib/nginx \
\
&& adduser -D admin \
&& echo "admin:admin" | chpasswd \
&& ssh-keygen -A \
\
&& openssl req \
			-out	/etc/ssl/certs/localhost.crt \
			-keyout /etc/ssl/certs/localhost.key \
			-newkey rsa:2048 \
			-sha256 \
			-nodes \
			-x509 \
			-subj '/C=RU/L=Kazan/O=School 21/CN=ttarsha'

COPY nginx.conf /etc/nginx/nginx.conf
COPY supervisord.conf /etc/supervisord.conf

EXPOSE 80 443 22

CMD ["usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
