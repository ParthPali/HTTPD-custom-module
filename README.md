# HTTPD-custom-module

Follow the steps to download HTTPD

## Create a Module that prints out "GCI 2019"

## Use `apxs -i -a -c mod_gci_psquare.c` to configure the application

This creates four different files of the c module that are used to connect your module to the server.

Make sure the .so file is in the modules folder

In the httpd.conf file, add the following lines:


`LoadModule gci_module modules/mod_gci_psquare.so`

`<Location "/psquare">`
`    SetHandler gci_handler`
`</Location>`

## Running the server

In the terminal type the command ` myApache-GCI/bin/apachectl -k start`

Navigat to http//:localhost.com
