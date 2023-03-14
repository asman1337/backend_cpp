//
// Created by asman on 12-03-2023.
//

#ifndef CODINGVEDA_BACKEND_CPP_BASESMTPHELPER_H
#define CODINGVEDA_BACKEND_CPP_BASESMTPHELPER_H

#include <cstdlib>
#include <iostream>
#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Net/MailMessage.h>
#include <string>

#include "../../utils/LibConstants.h"

using namespace Poco::Net;

class BaseSMTPHelper {
public:
    static auto sendEmail(const std::string &name, const std::string &email, const std::string &subject, const std::string &message);
};


#endif //CODINGVEDA_BACKEND_CPP_BASESMTPHELPER_H
