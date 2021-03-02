# Usefull instruction for me
## (for) OpenSSL
     sudo apt-get install libssl-dev

     openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -days 365 -nodes -subj '/CN=localhost'

     openssl x509 -outform pem -in cert.pem -out ca-bundle.crt

fyi: (https://stackoverflow.com/questions/10175812/how-to-create-a-self-signed-certificate-with-openssl)

## (for compilation with) g++ (commands):
     g++ -pthread -o server server.cc -lssl -lcrypto
     g++ -pthread -o client client.cc -lssl -lcrypto

fyi: (https://stackoverflow.com/questions/18835219/linking-libssl-and-libcrypto-in-gcc)

## Other useful information:
     curl -k https://localhost:8080/hi
