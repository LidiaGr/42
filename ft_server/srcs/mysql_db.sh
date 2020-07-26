#! /bin/bash

service mysql start

mysql -e "CREATE DATABASE wordpress_db;"
mysql -e "CREATE USER 'admin'@'localhost' IDENTIFIED BY '123';"
mysql -e "GRANT ALL PRIVILEGES ON wordpress_db.* TO 'admin'@'localhost' IDENTIFIED BY '123';"
mysql -e "FLUSH PRIVILEGES;"