#!/bin/bash 

# wordpress 설치
# wget -O /tmp/wordpress.tar.gz "https://wordpress.org/latest.tar.gz"
# tar -xvzf /tmp/wordpress.tar.gz -C /tmp
# mkdir -p /var/www/html
# mv /tmp/wordpress/* /var/www/html/
# chown -R www-data:www-data /var/www/html 
# chmod -R 775 /var/www/html
# rm -r /tmp/wordpress /tmp/wordpress.tar.gz

# config 생성

# if [ ! -f "/var/www/html/wp-config.php" ]; then
wp --allow-root core download --locale=ko_KR --path=/var/www/html --force
wp --allow-root config create --dbname="$MARIADB_DATABASE" --dbuser="$MARIADB_USER_NAME" --dbpass="$MARIADB_USER_PW" --dbhost="$MARIADB_HOST" --path="/var/www/html" --dbcharset="utf8"
wp core install --path=/var/www/html --url="$WP_URL" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL" --allow-root --skip-email
wp --allow-root --path=/var/www/html user create "$WP_ADMIN_USER" "$WP_ADMIN_EMAIL" --user_pass="$WP_ADMIN_PASSWORD" --role=administrator || echo "User($WP_ADMIN_USER) already exists." 
wp user create --path=/var/www/html "$WP_USER" "$WP_EMAIL" --user_pass="$WP_PASSWORD" --role=editor  --allow-root || echo "User($WP_USER) already exists."

# echo "access.log = /var/log/php7.3-fpm.access.log;" >> /var/www/html/wp-config.php
# echo "php_flag[display_errors] = on;" >> /var/www/html/wp-config.php
# echo "php_admin_value[error_log] = /var/log/php7.3-fpm.error.log;" >> /var/www/html/wp-config.php
# echo "php_admin_flag[log_errors] = on;" >> /var/www/html/wp-config.php
# fi

if [ ! -f "/var/log/php7.3-fpm.error.log" ]; then
touch /var/log/php7.3-fpm.error.log
chown -R www-data:www-data /var/log/php7.3-fpm.error.log
chmod -R 775 /var/log/php7.3-fpm.error.log
touch /var/log/php7.3-fpm.access.log
chown -R www-data:www-data /var/log/php7.3-fpm.access.log
chmod -R 775 /var/log/fpm-php.access.log
fi

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

