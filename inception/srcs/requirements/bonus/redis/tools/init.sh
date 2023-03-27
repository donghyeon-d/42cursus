#!/bin/bash

echo "bind 0.0.0.0 ::" >> /etc/redis/redis.conf

redis-server --daemonize no