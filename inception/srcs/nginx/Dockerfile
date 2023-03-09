FROM debian:oldstable-20230202

RUN apt-get -y update && \
	apt-get -y upgrade && \
	apt-get install -y nginx openssl

RUN mkdir -p /etc/ssl/private && \
    mkdir -p /etc/ssl/certs/ && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=dongchoi/CN=dongchoi.42.fr" -keyout /etc/ssl/private/server_pkey.pem -out /etc/ssl/certs/server.crt && \
	chown -R www-data:www-data /var/www/html && \
	chmod -R 775 /var/www/html
# RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/server_pkey.pem -out /etc/ssl/certs/server.crt
# 시간 설정

# ADD ./config.conf /etc/nginx/conf.d/nginx.conf
ADD ./config.conf /etc/nginx/sites-available/default
# RUN ln -s /etc/nginx/sites-available/mynginx.conf /etc/nginx/sites-enable/mynginx.conf
# RUN	mkdir -p /etc/nginx/sites-enable/ && \
# 	mkdir -p /etc/nginx/sites-available/ && \
# 	rm -f /etc/nginx/sites-enable/* && \
# 	ln -s /etc/nginx/sites-available/mynginx.conf /etc/nginx/sites-enable/mynginx.conf

#RUN ln -snf /usr/share/zoneinfo/Asia/Seoul /etc/localtime && echo Asia/Seoul > /etc/timezone

CMD ["nginx", "-g", "daemon off;"]

#docker build -t nginx .


# sudo docker run -it -v /home/dongchoi/data/wordpress:/var/www/html --network my_docker --name my_nginx -p 8080:8080 debian:oldstable-20230202