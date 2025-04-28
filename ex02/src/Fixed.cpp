#include "Fixed.hpp"

Fixed::Fixed() {
    _fixed_point_value = 0;
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed::Fixed(const int value) {
    _fixed_point_value = value << _fractional_bits; // Décalage à gauche pour partie fractionnaire
}

Fixed::Fixed(const float value) {
    _fixed_point_value = static_cast<int>(roundf(value * (1 << _fractional_bits)));
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_fixed_point_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
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

bool Fixed::operator>(const Fixed& other) const{
    return this->_fixed_point_value > other._fixed_point_value;
}
bool Fixed::operator<(const Fixed& other) const{
    return this->_fixed_point_value < other._fixed_point_value;
}
bool Fixed::operator>=(const Fixed& other) const{
    return this->_fixed_point_value >= other._fixed_point_value;
}
bool Fixed::operator<=(const Fixed& other) const{
    return this->_fixed_point_value <= other._fixed_point_value;
}
bool Fixed::operator==(const Fixed& other) const{
    return this->_fixed_point_value == other._fixed_point_value;
}
bool Fixed::operator!=(const Fixed& other) const{
    return this->_fixed_point_value != other._fixed_point_value;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(toFloat() / other.toFloat());
}


Fixed& Fixed::operator++() {
    _fixed_point_value++;
    return *this;
}
Fixed& Fixed::operator--() {
    _fixed_point_value--;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _fixed_point_value++;
    return temp;
}
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _fixed_point_value--;
    return temp;
}

Fixed&  Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}
const Fixed&  Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
Fixed&  Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}
const Fixed&  Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}