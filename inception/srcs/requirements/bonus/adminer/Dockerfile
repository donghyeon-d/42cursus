FROM debian:oldstable

RUN apt-get -y update && \
	apt-get -y upgrade && \
	apt-get install -y php7.3 php7.3-fpm php-cli wget


COPY ./tools/init.sh ./init.sh


ENTRYPOINT ["sh", "./init.sh"]
