#!/bin/bash

mkdir -p /var/www/html/wp-content/plugins
if [ ! -f "/var/www/html/wp-content/plugins/wordpress-seo/index.php" ]
then
	wget -O /tmp/seo.zip "https://downloads.wordpress.org/plugin/wordpress-seo.20.3.zip" && \
	unzip /tmp/seo.zip -d /var/www/html/wp-content/plugins/ && \
	rm /tmp/seo.zip && \
	chmod 777 /var/www/html/wp-content/plugins/wordpress-seo/
fi

echo "listen = 0.0.0.0:7000" >> /etc/php/7.3/fpm/pool.d/www.conf
chown -R www-data:www-data /var/www/html

php-fpm7.3 -R -F
