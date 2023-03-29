#!/bin/bash

if [ ! -f "$WP_PATH/wp-config.php" ]; then
wp --allow-root core download --locale=ko_KR --path=$WP_PATH
chown -R www-data:www-data /var/www/html
wp --allow-root config create --dbname="$MARIADB_DATABASE" --dbuser="$MARIADB_USER_NAME" --dbpass="$MARIADB_USER_PW" --dbhost="$MARIADB_HOST" --path="$WP_PATH" --dbcharset="utf8"
wp --allow-root core install --path=$WP_PATH --url="$WP_URL" --title="$WP_TITLE" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL"
wp --allow-root --path=$WP_PATH user create "$WP_ADMIN_USER" "$WP_ADMIN_EMAIL" --user_pass="$WP_ADMIN_PASSWORD" --role=administrator || echo "User($WP_ADMIN_USER) already exists." 
wp user create --path=$WP_PATH "$WP_USER" "$WP_EMAIL" --user_pass="$WP_PASSWORD" --role=editor  --allow-root || echo "User($WP_USER) already exists."
fi

wp config set WP_REDIS_HOST $WP_REDIS_HOST --allow-root --path=$WP_PATH
wp config set WP_REDIS_PORT $WP_REDIS_PORT --allow-root --path=$WP_PATH
wp config set WP_REDIS_SCHEME tcp --allow-root --path=$WP_PATH
wp config set WP_REDIS_PASSWORD $WP_REDIS_PASSWORD --allow-root --path=$WP_PATH

wp plugin update --all --allow-root --path=$WP_PATH
wp plugin install redis-cache --activate --allow-root --path=$WP_PATH
wp cache flush --allow-root --path=$WP_PATH
wp redis enable --allow-root --path=$WP_PATH

service php7.3-fpm start
service php7.3-fpm stop

php-fpm7.3 -F -R
