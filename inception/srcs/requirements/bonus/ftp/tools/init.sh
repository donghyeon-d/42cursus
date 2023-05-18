#!/bin/bash

chown -R www-data:www-data /var/www/html
echo "local_root=$FTP_PATH" >> /etc/vsftpd.conf

exec vsftpd /etc/vsftpd.conf