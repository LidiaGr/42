FROM alpine

COPY init.sh vsftpd.conf /

RUN apk update \
&&	apk add openrc \
			openssl \
			vsftpd \
\
&& adduser -D admin \
&& echo 'admin:admin' | chpasswd \
\
&& openssl req \
			-out	/etc/ssl/certs/ftps.crt \
			-keyout /etc/ssl/certs/ftps.key \
			-newkey rsa:2048 \
			-sha256 \
			-nodes \
			-x509 \
			-subj '/C=RU/L=Kazan/O=School 21/CN=ttarsha' \
\
&& mkdir /home/usr \
&& chmod +x /init.sh

VOLUME /home/usr

EXPOSE 21 21021
ENTRYPOINT /init.sh
