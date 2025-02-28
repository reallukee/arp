#ifndef ARP_REQUEST_HPP
#define ARP_REQUEST_HPP

#include <WiFiS3.h>

#include "Header.hpp"

class Request
{

private:

    String method;
    String path;
    String protocol;

    Header* headers;

    String body;

public:

    Request(
        String method,
        String path,
        String protocol,
        Header* headers,
        String body
    );

    Request(String request);

    String getMethod();
    String getPath();
    String getProtocol();

    Header* getHeaders();

    String getBody();

};

#endif // !ARP_REQUEST_HPP
