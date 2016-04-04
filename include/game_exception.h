#ifndef FUR_BLAST_EXCEPTION_H
#define FUR_BLAST_EXCEPTION_H

#include <exception>
#include <string>

class SDLException : public std::exception {
public:
    SDLException(const char *msg) : error_msg(msg) { }

    virtual const char *what() const throw() {
        return this->error_msg.c_str();
    }

private:
    std::string error_msg;
};

#endif //FUR_BLAST_EXCEPTION_H
