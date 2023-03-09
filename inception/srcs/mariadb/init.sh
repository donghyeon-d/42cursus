#!/bin/bash

service mysql start

mysql << end
UPDATE mysql.user SET Password=PASSWORD('123123') WHERE User='root' AND Host='mariadb';
CREATE DATABASE IF NOT EXISTS wordpress_db;
CREATE USER 'dongchoi'@'%' IDENTIFIED BY '123123';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'dongchoi'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
end

touch /var/log/mariadb.error.log /var/log/mariadb.general.log
# chown -R www-data:www-data /var/log/mariadb.error.log
# chown -R www-data:www-data /var/log/mariadb.general.log
chmod -R 775 /var/log/mariadb.error.log
chmod -R 775 /var/log/mariadb.general.log
echo "log-error = /var/log/mariadb.error.log" >> /etc/mysql/conf.d/mysql.cnf
echo "general_log=on" >> /etc/mysql/conf.d/mysql.cnf
echo "general_log_file=/var/log/mariadb.general.log" >> /etc/mysql/conf.d/mysql.cnf


#service mysql stop

# #UPDATE mysql.user SET Password=PASSWORD('123123') WHERE User='root' AND Host='127.0.0.1';
# mysql << end
# CREATE DATABASE wordpress_db;
# CREATE USER 'dongchoi'@'%' IDENTIFIED BY '123123';
# GRANT ALL ON wordpress_db.* TO 'dongchoi'@'%';
# FLUSH PRIVILEGES;
# end

#mysql << end
# UPDATE mysql.user SET Password=PASSWORD('$MARIADB_ADMIN_PASSWORD') WHERE User='$MARIADB_ADMIN_USER' AND Host='$MARIADB_DATABASE_HOST';
# CREATE DATABASE $MARIADB_DATABASE;
# CREATE USER '$MARIADB_ID'@'%' IDENTIFIED BY '$MARIADB_PW';
# GRANT ALL ON $MARIADB_DATABASE.* TO '$MARIADB_ID'@'%';
# FLUSH PRIVILEGES;
#end;
