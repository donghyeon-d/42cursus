FROM debian:oldstable-20230202

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get -y install \
	php7.3 \
	php7.3-fpm \
	php-cli \
	wget \
	mariadb-client \
	curl \
	php-mysql \
	php-mbstring \
	php-xml 

RUN wget -O /tmp/wp-cli.phar "https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar" && \
	chmod +x /tmp/wp-cli.phar && \
	mv /tmp/wp-cli.phar /usr/local/bin/wp

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY ./tools/website /var/www/html/home/
# COPY ./tools/index.html /var/www/html/index.html
COPY ./tools/init.sh ./init.sh

ENTRYPOINT [ "sh", "./init.sh" ]

# sudo docker run -it -v /home/dongchoi/data/wordpress:/var/www/html --network my_docker --name my_wordpress --expose 9000 debian:oldstable-20230202