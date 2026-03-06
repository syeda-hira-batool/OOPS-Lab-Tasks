#include <iostream>
#include <string>
using namespace std;

class Message
{
private:
    string text;

public:
    void modify(string t)
    {
        text = t;
    }

    string toString() const
    {
        return text;
    }
};

class SMS : public Message
{
private:
    string num;

public:
    void modifyNum(string n)
    {
        num = n;
    }

    string getNum()
    {
        return num;
    }

    string toString() const
    {
        return "Contact No: " + num + " Message: " + Message::toString();
    }
};

class Email : public Message
{
private:
    string sender;
    string receiver;
    string subject;

public:
    void modifySender(string s)
    {
        sender = s;
    }

    void modifyReceiver(string r)
    {
        receiver = r;
    }

    void modifySubject(string su)
    {
        subject = su;
    }

    string toString() const
    {
        return "Sender: " + sender + " Receiver: " + receiver + " Subject: " + subject + " Message: " + Message::toString();
    }
};

bool ContainsKeyword(const Message &messageObject, const string &keyword)
{

    string text = messageObject.toString();

    int i, j;

    for (i = 0; i < text.length(); i++)
    {

        for (j = 0; j < keyword.length(); j++)
        {

            if (text[i + j] != keyword[j])
            {
                break;
            }
        }

        if (j == keyword.length())
        {
            return true;
        }
    }

    return false;
}

string encodeMessage(string message)
{

    for (int i = 0; message[i] != '\0'; i++)
    {

        if (message[i] == 'Z')
            message[i] = 'A';

        else if (message[i] == 'z')
            message[i] = 'a';

        else if ((message[i] >= 'A' && message[i] <= 'Y') ||
                 (message[i] >= 'a' && message[i] <= 'y'))
            message[i] = message[i] + 1;
    }

    return message;
}

int main()
{

    SMS s1;
    s1.modifyNum("67676767");
    s1.modify("Hi i am a sun");

    Email e1;
    e1.modifySender("batool@gmail.com");
    e1.modifyReceiver("tehreem@gmail.com");
    e1.modifySubject("TT party");
    e1.modify("invitation to party");

    cout << "SMS Information:" << endl;
    cout << s1.toString() << endl;

    cout << "Email Information:" << endl;
    cout << e1.toString() << endl;

    cout << "\nKeyword Search: " << endl;
    if (ContainsKeyword(s1, "Ali"))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    string msg = "This is Java";

    cout << "\nOriginal Message: " << msg << endl;
    cout << "Encoded Message: " << encodeMessage(msg) << endl;

    return 0;
}