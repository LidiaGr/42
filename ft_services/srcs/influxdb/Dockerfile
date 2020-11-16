FROM alpine

RUN apk update \
&&  apk add ca-certificates \
	        supervisor \
\
&&     wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub \
&&     wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.32-r0/glibc-2.32-r0.apk \
&&     apk add glibc-2.32-r0.apk \
\
&&	wget https://dl.influxdata.com/influxdb/releases/influxdb-1.8.2-static_linux_amd64.tar.gz \
&&	mkdir /var/lib/influxdb \
&&	tar xfz influxdb-1.8.2-static_linux_amd64.tar.gz \
&&	mv /influxdb-1.8.2-1 /etc/influxdb \
\
&&	wget https://dl.influxdata.com/telegraf/releases/telegraf-1.15.3_linux_amd64.tar.gz \
&&	tar xf telegraf-1.15.3_linux_amd64.tar.gz \
&&	cp -r /telegraf-1.15.3/* / \
&&	./usr/bin/telegraf	-sample-config \
						--input-filter docker \
						--output-filter influxdb > /etc/telegraf/telegraf.conf 

COPY supervisord.conf /etc/

VOLUME /var/lib/influxdb

EXPOSE 8086
CMD ["usr/bin/supervisord", "-c", "/etc/supervisord.conf"]
