#!/bin/bash 

if [ ! -f "/var/www/html/wp-config.php" ]; then
wp --allow-root core download --locale=ko_KR --path=/var/www/html --force
wp --allow-root config create --dbname="$MARIADB_DATABASE" --dbuser="$MARIADB_USER_NAME" --dbpass="$MARIADB_USER_PW" --dbhost="$MARIADB_HOST" --path="/var/www/html" --dbcharset="utf8"
wp core install --path=/var/www/html --url="$WP_URL" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL" --allow-root --skip-email
wp --allow-root --path=/var/www/html user create "$WP_ADMIN_USER" "$WP_ADMIN_EMAIL" --user_pass="$WP_ADMIN_PASSWORD" --role=administrator || echo "User($WP_ADMIN_USER) already exists." 
wp user create --path=/var/www/html "$WP_USER" "$WP_EMAIL" --user_pass="$WP_PASSWORD" --role=editor  --allow-root || echo "User($WP_USER) already exists."
fi

service php7.3-fpm start
service php7.3-fpm stop

php-fpm7.3 -F -R
