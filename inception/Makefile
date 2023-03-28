WP_VOL=/home/dongchoi/data/wordpress
DB_VOL=/home/dongchoi/data/mariadb


up :
	mkdir -p ${WP_VOL}
	mkdir -p ${DB_VOL}
	sudo docker-compose -f ./srcs/docker-compose.yml up --build -d

down :
	sudo docker-compose -f ./srcs/docker-compose.yml down

rm :
	sudo rm -rf ${WP_VOL} ${DB_VOL}

re :
	@$(MAKE) down
	@$(MAKE) rm
	@$(MAKE) up
