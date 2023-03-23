#!/bin/bash


# mysql << end

echo "CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;
CREATE USER '$MARIADB_USER_NAME'@'%' IDENTIFIED BY '$MARIADB_USER_PW';
GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$MARIADB_USER_NAME'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;" > $MARIADB_DATABASE.sql;
service mysql start && mysql < $MARIADB_DATABASE.sql;
rm $MARIADB_DATABASE.sql;

# end

# if [ ! -f "/var/log/mariadb.error.log" ]; then
# touch /var/log/mariadb.error.log /var/log/mariadb.general.log
# chown -R www-data:www-data /var/log/mariadb.error.log
# chown -R www-data:www-data /var/log/mariadb.general.log
# chmod -R 775 /var/log/mariadb.error.log
# chmod -R 775 /var/log/mariadb.general.log
# echo "log-error = /var/log/mariadb.error.log" >> /etc/mysql/conf.d/mysql.cnf
# echo "general_log=on" >> /etc/mysql/conf.d/mysql.cnf
# echo "general_log_file=/var/log/mariadb.general.log" >> /etc/mysql/conf.d/mysql.cnf
# # wp config create --dbname="wordpress_db" --dbuser="dongchoi" --dbpass="123123" --dbhost="mariadb" --path="/var/www/html" --dbcharset="utf8" --allow-root
# fi

service mysql stop

# exec "$@"

mysqld
# --bind-address=0.0.0.0