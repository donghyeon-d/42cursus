#!/bin/bash 


# wordpress 설치
wget -O /tmp/wordpress.tar.gz "https://wordpress.org/latest.tar.gz"
tar -xvzf /tmp/wordpress.tar.gz -C /tmp
mkdir -p /var/www/html
mv /tmp/wordpress/* /var/www/html/
chown -R www-data:www-data /var/www/html 
chmod -R 775 /var/www/html
rm -r /tmp/wordpress /tmp/wordpress.tar.gz

# wp-cli 설치
wget -O /tmp/wp-cli.phar "https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar"
chmod +x /tmp/wp-cli.phar
mv /tmp/wp-cli.phar /usr/local/bin/wp

# config 생성
wp config create --dbname="wordpress_db" --dbuser="dongchoi" --dbpass="123123" --dbhost="mariadb" --path="/var/www/html" --dbcharset="utf8" --allow-root

echo "listen = 0.0.0.0:9000" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_HOST] = mariadb" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_ADMIN_USER] = dongchoi" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_ADMIN_PASSWORD] = 123123" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_DATABASE] = wordpress_db" >> /etc/php/7.3/fpm/pool.d/www.conf
touch /var/log/fpm-php.www.log
chown -R www-data:www-data /var/log/fpm-php.www.log
chmod -R 775 /var/log/fpm-php.www.log
touch /var/log/fpm-php.access.log
chown -R www-data:www-data /var/log/fpm-php.access.log
chmod -R 775 /var/log/fpm-php.access.log
echo "access.log = /var/log/php7.3-fpm.access.log" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "php_flag[display_errors] = on" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "php_admin_value[error_log] = /var/log/php7.3-fpm.error.log" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "php_admin_flag[log_errors] = on" >> /etc/php/7.3/fpm/pool.d/www.conf

service php7.3-fpm restart

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

