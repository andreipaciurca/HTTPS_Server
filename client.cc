#define CPPHTTPLIB_OPENSSL_SUPPORT
#define CA_CERT_FILE "ca-bundle.crt"

#include <iostream>
#include "httplib.h"

int main(void) {
  #ifdef CPPHTTPLIB_OPENSSL_SUPPORT
    httplib::SSLClient cli("localhost", 8080);
    cli.set_ca_cert_path(CA_CERT_FILE);
    cli.enable_server_certificate_verification(true);
  #else
    httplib::Client cli("localhost", 8080);
  #endif

    if (auto res = cli.Get("/hi")) {
      std::cout << res->status << std::endl;
      std::cout << res->get_header_value("Content-Type") << std::endl;
      std::cout << res->body << std::endl;
    }
    else {
      std::cout << "error code: " << res.error() << std::endl;

  #ifdef CPPHTTPLIB_OPENSSL_SUPPORT
      auto result = cli.get_openssl_verify_result();
      if (result) {
        std::cout << "verify error: " << X509_verify_cert_error_string(result) << std::endl;
      }
  #endif
    }

    return 0;
}