#!/bin/bash

echo "CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;
CREATE USER '$MARIADB_USER_NAME'@'%' IDENTIFIED BY '$MARIADB_USER_PW';
GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$MARIADB_USER_NAME'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;" > $MARIADB_DATABASE.sql;
service mysql start && mysql < $MARIADB_DATABASE.sql;
rm $MARIADB_DATABASE.sql;

service mysql stop

mysqld --bind-address=0.0.0.0