#!/bin/bash

if [ ! -f "/var/www/html/wp-content/plugins/elementor/elementor.php" ]
then
wp plugin update --all --allow-root --path=$WP_PATH
wp plugin install elementor --activate --allow-root --path=$WP_PATH
wp elementor enable --allow-root --path=$WP_PATH
fi

echo "listen = 0.0.0.0:7000" >> /etc/php/7.3/fpm/pool.d/www.conf
chown -R www-data:www-data /var/www/html


php-fpm7.3 -R -F
