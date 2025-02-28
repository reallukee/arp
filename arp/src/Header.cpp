#include "Header.hpp"

Header::Header(
    String key,
    String value
)
{
    this->key = key;
    this->value = value;
}

Header::Header(String header)
{
    return;
}

String Header::getKey()
{
    return this->key;
}

void Header::setKey(String value)
{
    this->key = value;
}

String Header::getValue()
{
    return this->value;
}

void Header::setValue(String value)
{
    this->value = value;
}
