#!/bin/bash

while :
do
    # FILECOUNT=`ls ${WP_PATH} | wc -l`
    # if [ "${FILECOUNT}" != "0" ]
	if [ -f "/var/www/html/wp-config.php" ]
	then
		echo "file check done." && \
        break
    fi
	echo "file waiting..."
    sleep 2
done

mkdir -p /var/www/html/adminer
if [ ! -f "/var/www/html/adminer/index.php" ]
then
	wget -O /var/www/html/adminer/index.php "https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1-mysql-en.php" && \
	chmod 777 /var/www/html/adminer/index.php
fi

echo "listen = 0.0.0.0:8000" >> /etc/php/7.3/fpm/pool.d/www.conf
chown -R www-data:www-data /var/www/html

service php7.3-fpm start
service php7.3-fpm stop

php-fpm7.3 -R -F