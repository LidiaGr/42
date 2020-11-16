#!/bin/bash

minikube start --driver=virtualbox
minikube addons enable metallb
minikube addons enable dashboard
eval $(minikube docker-env)

docker build -t nginx:my ./srcs/nginx
docker build -t mysql:my ./srcs/mysql
docker build -t wordpress:my ./srcs/wordpress
docker build -t phpmyadmin:my ./srcs/phpmyadmin
docker build -t ftps:my ./srcs/ftps
docker build -t grafana:my ./srcs/grafana
docker build -t influxdb:my ./srcs/influxdb

kubectl apply -f ./srcs/volumes.yaml
kubectl apply -f ./srcs/metallb.yaml
kubectl apply -f ./srcs/nginx/nginx.yaml
kubectl apply -f ./srcs/mysql/mysql.yaml
kubectl apply -f ./srcs/wordpress/wordpress.yaml
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f ./srcs/ftps/ftps.yaml
kubectl apply -f ./srcs/grafana/grafana.yaml
kubectl apply -f ./srcs/influxdb/influxdb.yaml

minikube dashboard
