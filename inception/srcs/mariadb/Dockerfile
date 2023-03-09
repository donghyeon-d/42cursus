FROM debian:oldstable-20230202

# mariadb 설치
RUN apt-get -y update && \
	apt-get -y upgrade && \
	apt-get install -y mariadb-server

# 시간 설정
RUN ln -snf /usr/share/zoneinfo/Asia/Seoul /etc/localtime && echo Asia/Seoul > /etc/timezone
COPY ./init.sh /init.sh
RUN /bin/bash /init.sh

CMD ["mysqld", "--bind-address=0.0.0.0"]


#config 위치 :  /etc/mysql/mariadb.cnf
#data저장위치 :  /var/lib/mspl

# sudo docker run -it -v /home/dongchoi/data/mariadb:/var/lib/mysql -v /home/dongchoi/wordpress:/var/www/html --network my_docker  --expose 3306 --name my_mariadb debian:oldstable-20230202

# echo "env[MARIADB_HOST] = mariadb" >> /etc/php/7.3/fpm/pool.d/www.conf
# echo "env[MARIADB_ADMIN_USER] = root" >> /etc/php/7.3/fpm/pool.d/www.conf
# echo "env[MARIADB_ADMIN_PASSWORD] = 1234" >> /etc/php/7.3/fpm/pool.d/www.conf
# echo "env[MARIADB_DATABASE] = wordpress_db" >> /etc/php/7.3/fpm/pool.d/www.conf

