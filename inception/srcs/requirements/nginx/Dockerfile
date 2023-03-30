FROM debian:oldstable

RUN apt-get -y update && \
	apt-get -y upgrade && \
	apt-get install -y nginx openssl

RUN mkdir -p /etc/ssl/private && \
    mkdir -p /etc/ssl/certs/ && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=dongchoi/CN=dongchoi.42.fr" -keyout /etc/ssl/private/server_pkey.pem -out /etc/ssl/certs/server.crt && \
	chown -R www-data:www-data /var/www/html && \
	chmod -R 775 /var/www/html

ADD ./conf/config.conf /etc/nginx/sites-available/default

ENTRYPOINT ["nginx", "-g", "daemon off;"]