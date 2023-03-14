//
// Created by asman on 12-03-2023.
//

#include "BaseSMTPHelper.h"

auto BaseSMTPHelper::sendEmail(const std::string &name, const std::string &email, const std::string &subject, const std::string &message) {
    try {
        MailMessage msg;
        msg.addRecipient(MailRecipient(MailRecipient::PRIMARY_RECIPIENT,email, name));
        msg.setSender(LibConstants::SMTP::smtpSender);
        msg.setSubject(subject);
        msg.setContent(message);

        SMTPClientSession smtp(LibConstants::SMTP::smtpHost, LibConstants::SMTP::smtpPort);
        smtp.login(SMTPClientSession::AUTH_LOGIN, LibConstants::SMTP::smtpUser, LibConstants::SMTP::smtpPass);
        smtp.sendMessage (msg);
        smtp.close();
    } catch (std::exception &e) {
        std::cerr << "Failed to send mail: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}