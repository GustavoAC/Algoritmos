
#ifndef _MMESSENGER_H_
#define _MMESSENGER_H_

#include <iostream>
#include <string>
#include <vector>

class Message {

    private:
        // HEADER
        std::vector< std::string > msFields;

    public:
        enum HeaderField {
            SENDER = 0,    // (FROM) Email of the sender of the message.
            SUBJECT,       // The message's subject or description of the topic of the message.
            DATE,          // Date & Time the message was received.
            RECIPIENT,     // (TO) Email of the recipient of the message.
            REPLYTO,       // Email that will become the recipiente of any reply to the message.
            ATTACHMENTS,   // Flag indicating the existance of any files attached to the message.
            BODY,          // The actual content of the message.
            N_FIELDS };    // Just to keep track of the number of fields.

    public:

        Message( std::string _sender = "", std::string _subject = "", std::string _date = "",
                 std::string _recipient = "", std::string _replyto = "",
                 std::string _attachments = "", std::string _body = "" )
        {
            msFields.push_back( _sender );
            msFields.push_back( _subject );
            msFields.push_back( _date );
            msFields.push_back( _recipient );
            msFields.push_back( _replyto );
            msFields.push_back( _attachments );
            msFields.push_back( _body );
        }

        std::string getHeaderComponent( HeaderField _field ) const{
            return msFields[ _field ];
        }

        std::vector< std::string > getHeader( void ) const{
            return msFields;
        }

        void setSender( const std::string& _h )     { msFields[ HeaderField::SENDER      ] = _h; };
        void setSubject( const std::string& _h )    { msFields[ HeaderField::SUBJECT     ] = _h; };
        void setDateTime( const std::string& _h )   { msFields[ HeaderField::DATE        ] = _h; };
        void setRecipient( const std::string& _h )  { msFields[ HeaderField::RECIPIENT   ] = _h; };
        void setReplyTo( const std::string& _h )    { msFields[ HeaderField::REPLYTO     ] = _h; };
        void setAttachment( bool _h )               { msFields[ HeaderField::ATTACHMENTS ] = _h; };


        inline friend std::ostream &operator<< (std::ostream& _os, const Message & _Obj)
        {
            _os << "{\n"
                << "  From: ["          <<  _Obj.msFields[ HeaderField::SENDER ]     << "]\n"
                << "  Subject: ["       <<  _Obj.msFields[ HeaderField::SUBJECT ]    << "]\n"
                << "  Date: ["          <<  _Obj.msFields[ HeaderField::DATE ]       << "]\n"
                << "  To: ["            <<  _Obj.msFields[ HeaderField::RECIPIENT ]  << "]\n"
                << "  Reply: ["         <<  _Obj.msFields[ HeaderField::REPLYTO ]    << "]\n"
                << "  Attachments: ["   <<  _Obj.msFields[ HeaderField::ATTACHMENTS ]<< "]\n"
                << "  Body:\n "         <<  _Obj.msFields[ HeaderField::BODY ]       << "\n}";

            return _os;
        }
};

struct MySorter{
private:
    Message::HeaderField typeComparator;

public:

    MySorter( Message::HeaderField _a ) : typeComparator(_a)
    {}

    bool operator() ( const std::unique_ptr< Message > & _m1, const std::unique_ptr< Message > & _m2 ){
        return _m1->getHeaderComponent( typeComparator ) < _m2->getHeaderComponent( typeComparator );
    }

};

#endif
