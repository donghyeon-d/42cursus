#!/bin/bash 

if [ ! -f "/var/www/html/wp-config.php" ]; then
# wordpress 설치
wget -O /tmp/wordpress.tar.gz "https://wordpress.org/latest.tar.gz"
tar -xvzf /tmp/wordpress.tar.gz -C /tmp
mkdir -p /var/www/html
mv /tmp/wordpress/* /var/www/html/
chown -R www-data:www-data /var/www/html 
chmod -R 775 /var/www/html
rm -r /tmp/wordpress /tmp/wordpress.tar.gz

# config 생성
wp config create --dbname="wordpress_db" --dbuser="dongchoi" --dbpass="123123" --dbhost="mariadb" --path="/var/www/html" --dbcharset="utf8" --allow-root
fi

# log file 
touch /var/log/fpm-php.www.log
chown -R www-data:www-data /var/log/fpm-php.www.log
chmod -R 775 /var/log/fpm-php.www.log
touch /var/log/fpm-php.access.log
chown -R www-data:www-data /var/log/fpm-php.access.log
chmod -R 775 /var/log/fpm-php.access.log

service php7.3-fpm start
service php7.3-fpm stop
php-fpm7.3 -F -R

#echo "env[MARIADB_HOST] = \$MARIADB_HOST" >> /etc/php/7.4/fpm/pool.d/www.conf
#echo "env[MARIADB_ADMIN_USER] = \$MARIADB_ADMIN_USER" >> /etc/php/7.4/fpm/pool.d/www.conf
#echo "env[MARIADB_ADMIN_PASSWORD] = \$MARIADB_ADMIN_PASSWORD" >> /etc/php/7.4/fpm/pool.d/www.conf
#echo "env[MARIADB_DATABASE] = \$MARIADB_DATABASE" >> /etc/php/7.4/fpm/pool.d/www.conf
#echo "listen = 0.0.0.0:9000" >> /etc/php/7.3/fpm/pool.d/www.conf

# chown -R :www-data /var/www/wordpress
#한국어판
#wp core download --path=/var/www/html --locale=ko_KR --allow-root
#config 만들기
#wp config create --dbname='wordpress_db' --dbuser='dongchoi' --dbpass='123123' --dbhost='mariadb' --dbcharset="utf8" --path="/var/www/html" --allow-root --force

# wp config create --dbname=$MARIADB_DATABASE --dbuser=$MARIADB_USER --dbpass=$MARIADB_PASSWORD --dbhost=$MARIADB_HOST --dbcharset="utf8" --allow-root  --extra-php <<PHP
# define( 'WP_REDIS_HOST', '$REDIS_HOST' );
# define( 'WP_REDIS_PORT', '$REDIS_PORT' );
# define( 'WP_REDIS_TIMEOUT', '$REDIS_TIMEOUT' );
# define( 'WP_REDIS_READ_TIMEOUT', '$REDIS_READ_TIMEOUT' );
# define( 'WP_REDIS_DATABASE', '$REDIS_DATABASE' );
# define( 'WP_CACHE', '$REDIS_CACHE' );
# PHP

