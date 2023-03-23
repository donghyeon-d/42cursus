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
	#sendmail
	#vim

# wp-cli 설치
RUN wget -O /tmp/wp-cli.phar "https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar" && \
	chmod +x /tmp/wp-cli.phar && \
	mv /tmp/wp-cli.phar /usr/local/bin/wp

COPY ./www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY ./init.sh ./init.sh

#WORKDIR /var/www/html

# RUN /bin/bash /init.sh

# ENTRYPOINT [ "bash", "/init.sh" ]
CMD [ "sh", "./init.sh" ]
# CMD ["service", "php7.3-fpm", "start"]



# FROM debian:oldstable-20230202

# RUN apt-get update && \
# 	apt-get install -y wget tar
# RUN wget -O /tmp/wordpress.tar.gz "http://wordpress.org/latest.tar.gz" && \
# 	mkdir -p /var/www/html && \
# 	tar -xvzf /tmp/wordpress.tar.gz && \
	
# 	-C /var/www/html


# RUN apt-get install -y php-fpm
# ADD ./config.conf /etc/php/7.4/fpm/pool.d/myphp.conf
# # RUN echo "listen = 9000" >> /etc/php/7.4/fpm/pool.d/www.conf

# RUN apt-get install -y mariadb-client

# # 시간 설정
# RUN ln -snf /usr/share/zoneinfo/Asia/Seoul /etc/localtime && echo Asia/Seoul > /etc/timezone

# #/var/www/html/wordpress




# sudo docker run -it -v /home/dongchoi/data/wordpress:/var/www/html --network my_docker --name my_wordpress --expose 9000 debian:oldstable-20230202