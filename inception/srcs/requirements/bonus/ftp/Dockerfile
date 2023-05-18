FROM debian:oldstable

RUN apt-get -y update && \
	apt-get -y upgrade && \
	apt-get install -y vsftpd

COPY ./config/vsftpd.conf /etc/vsftpd.conf
COPY ./tools/init.sh ./init.sh

ENTRYPOINT ["sh", "./init.sh"]
