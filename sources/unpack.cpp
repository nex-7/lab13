#include <iostream>
#include <pugixml.hpp>

using namespace std;
using namespace pugi;

struct Email
{
   string nickname;
   string server;
};

struct Person
{
   string first_name;
   string last_name;
   Email email;
   size_t age;
   string phone;
};

void LoadFile(Person &dt, string file)
{
   xml_document doc;
   
   doc.load_file(file.c_str());

   xml_node person = doc.child("person");
   
   cout << "[Pesron]" << endl;
   cout << "First name: " << person.child("first_name").child_value() << endl;
   cout << "Last name: " << person.child("last_name").child_value() << endl;
   cout << "Email: " << person.child("email").child_value() << endl;
   cout << "Age (optional): " << person.child("age").child_value() << endl;
   cout << "Phone (optional): " << person.child("phone").child_value() << endl;
}

int main(int argc, char* argv[])
{
   string file = argv[1];
   Person person;
   LoadFile(person, file);
   return 0;
}
