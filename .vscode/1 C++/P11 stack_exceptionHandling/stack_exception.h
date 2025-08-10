#ifndef STACK_EXCEPTION_H
#define STACK_EXCEPTION_H

#include <stdexcept>

/**
 * Exception-Klasse für leeren Stack
 * Erbt von std::runtime_error für sinnvolle Einordnung in Exception-Hierarchie
 */
class empty_stack_exception : public std::runtime_error
{
public:
    // Konstruktor nimmt Fehlermeldung entgegen
    explicit empty_stack_exception(const std::string &message)
        : std::runtime_error(message) {}
};

#endif