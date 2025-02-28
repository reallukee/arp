#ifndef ARP_HEADER_HPP
#define ARP_HEADER_HPP

#include <WiFiS3.h>

class Header
{

private:

    String key;
    String value;

public:

    Header(
        String key,
        String value
    );

    Header(String header);

    String getKey();
    void setKey(String value);
    String getValue();
    void setValue(String value);

};

#endif // !ARP_HEADER_HPP
