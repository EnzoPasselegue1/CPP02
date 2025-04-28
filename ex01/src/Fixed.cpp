#include "Fixed.hpp"

Fixed::Fixed() {
    _fixed_point_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int value) {
    std::cout << "int constructor called" << std::endl;
    _fixed_point_value = value << _fractional_bits; // Décalage à gauche pour partie fractionnaire
}

Fixed::Fixed(const float value) {
    std::cout << "float constructor called" << std::endl;
    _fixed_point_value = static_cast<int>(roundf(value * (1 << _fractional_bits)));
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixed_point_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixed_point_value;
}

void Fixed::setRawBits(int const raw) {
    _fixed_point_value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixed_point_value) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const {
    return _fixed_point_value >> _fractional_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}