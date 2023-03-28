#!/bin/bash

chown -R www-data:www-data /var/www/html
echo "bind 0.0.0.0 ::" >> /etc/redis/redis.conf
echo "requirepass $WP_REDIS_PASSWORD" >> /etc/redis/redis.conf

redis-server /etc/redis/redis.conf --daemonize no --protected-mode no
