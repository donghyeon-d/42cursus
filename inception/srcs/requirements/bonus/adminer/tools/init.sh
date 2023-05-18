#!/bin/bash

while :
do
    # FILECOUNT=`ls ${WP_PATH} | wc -l`
    # if [ "${FILECOUNT}" != "0" ]
	if [ -f "$WP_PATH/wp-config.php" ]
	then
		echo "file check done." && \
        break
    fi
	echo "file waiting..."
    sleep 2
done

mkdir -p $WP_PATH/adminer
if [ ! -f "$WP_PATH/adminer/index.php" ]
then
	wget -O $WP_PATH/adminer/index.php "https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1-mysql-en.php" && \
	chmod 777 $WP_PATH/adminer/index.php
fi

echo "listen = 0.0.0.0:8000" >> /etc/php/7.3/fpm/pool.d/www.conf
chown -R www-data:www-data /var/www/html

service php7.3-fpm start
service php7.3-fpm stop

exec php-fpm7.3 -R -F