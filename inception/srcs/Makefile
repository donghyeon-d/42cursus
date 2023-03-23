up :
	mkdir -p /home/dongchoi/data/wordpress
	mkdir -p /home/dongchoi/data/mariadb
	sudo docker-compose up --build -d

down :
	sudo docker-compose down

rm :
	sudo rm -rf /home/dongchoi/data

re :
	@$(MAKE) down
	@$(MAKE) rm
	@$(MAKE) up
