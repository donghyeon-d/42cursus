FROM debian:oldstable

RUN apt-get -y update && \
	apt-get -y upgrade && \
	apt-get install -y redis

COPY ./tools/init.sh ./init.sh

ENTRYPOINT ["sh", "./init.sh"]
