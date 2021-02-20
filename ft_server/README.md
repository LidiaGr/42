# FT_SERVER
Basics of system and network administration. The aim is to install a complete web server, using a deployment technology named Docker.

# Objectives

- Network & system administration
- Docker

# Usage
# To create image: 
        docker build -t ft_server .

(-t == image name)

# To run a container:
        docker run -p 80:80 -p 443:443 --name ttarsha -it -d ft_server
 
(--name == container name
-it == suspend a container (no automatic close)
-d == run in background)

# To see running containers:
        docker ps 

(-a == see all containers
-g == see only containers id) 

# To stop a container:
        docker stop ttarsha

# To start previously stopped container:
        docker start ttarsha

# To go inside a container (VM):
        docker exec -it ttarsha /bin/bash

# To delete a container:
        docker rm ttarsha

docker rm $(docker ps -aq) == delete all containers

# To delete an image:
        docker rmi ft_server

docker rmi $(docker images -aq) == delete all images
