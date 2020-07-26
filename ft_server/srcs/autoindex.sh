#! /bin/bash

localhost='/etc/nginx/sites-available/localhost'
on='autoindex on'
off='autoindex off'

if [ "$1" == "on" ]
then 
    sed -i "s/$off/$on/g" "$localhost"
else
    sed -i "s/$on/$off/g" "$localhost"
fi

nginx -s reload
