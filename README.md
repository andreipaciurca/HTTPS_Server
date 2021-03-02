# HTTPS_Server

## OpenSSL pre requirements:
1. sudo apt-get install libssl-dev

## Generate a self-signed cert.pem && key.pem (server side):
2.  openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -days 365 -nodes -subj '/CN=localhost'

## Generate ca-bundle.crt (client side):
3.  openssl x509 -outform pem -in cert.pem -out ca-bundle.crt

## Compile time
4.   g++ -pthread -o server server.cc -lssl -lcrypto
5.   g++ -pthread -o client client.cc -lssl -lcrypto
