FROM debian:oldstable

RUN apt-get -y update && \
	apt-get -y upgrade && \
	apt-get install -y php7.3 php7.3-fpm php-cli wget unzip

RUN wget -O /tmp/wp-cli.phar "https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar" && \
	chmod +x /tmp/wp-cli.phar && \
	mv /tmp/wp-cli.phar /usr/local/bin/wp

COPY ./tools/init.sh ./init.sh

ENTRYPOINT ["sh", "./init.sh"]
