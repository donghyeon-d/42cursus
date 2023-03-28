#!/bin/bash

mkdir -p /var/www/html/adminer
if [ ! -f "/var/www/html/adminer/index.php" ]
then
	wget -O /var/www/html/adminer/index.php "https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1-mysql-en.php" && \
	chmod 777 /var/www/html/adminer/index.php
fi

echo "listen = 0.0.0.0:8000" >> /etc/php/7.3/fpm/pool.d/www.conf
chown -R www-data:www-data /var/www/html

php-fpm7.3 -R -F
