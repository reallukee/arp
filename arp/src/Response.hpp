#ifndef ARP_RESPONSE_HPP
#define ARP_RESPONSE_HPP

#include <WiFiS3.h>

#include "Header.hpp"

class Response
{

private:

    unsigned statusCode;
    String statusText;
    String body;

public:

    Response(
        unsigned statusCode,
        String statusText,
        String body
    );

    unsigned getStatusCode();
    String getStatusText();
    String getBody();

};

#endif // !ARP_RESPONSE_HPP
