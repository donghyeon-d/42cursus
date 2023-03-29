#!/bin/bash

while :
do
    # FILECOUNT=`ls ${WP_PATH} | wc -l`
    # if [[ "${FILECOUNT}" != "0" ]]; then
    if [ -f "/var/www/html/wp-config.php" ]
    then
		echo "file check done."
        break
    fi
	echo "file waiting..."
    sleep 1
done

# chown -R www-data:www-data /var/www/html
if [ ! -f "/var/www/html/wp-content/plugins/elementor/elementor.php" ]
then
wget -O /tmp/elementor.zip https://downloads.wordpress.org/plugin/elementor.3.11.5.zip
unzip /tmp/elementor.zip -d $WP_PATH/wp-content/plugins
rm /tmp/elementor.zip
fi

echo "listen = 0.0.0.0:7000" >> /etc/php/7.3/fpm/pool.d/www.conf

service php7.3-fpm start
service php7.3-fpm stop

php-fpm7.3 -R -F