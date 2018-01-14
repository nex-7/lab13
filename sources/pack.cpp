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

void SaveFile(Person &dt, string file)
{
   xml_document doc;
   
   xml_node person = doc.append_child("person");
   
   cout << "Enter data to fields of the Person structure.\nFirst name: ";
   cin >> dt.first_name;
   xml_node first_name = person.append_child("first_name");
   first_name.append_child(node_pcdata).set_value(dt.first_name.c_str());
   
   cout << "Last name: ";
   cin >> dt.last_name;
   xml_node last_name = person.append_child("last_name");
   last_name.append_child(node_pcdata).set_value(dt.last_name.c_str());
   
   cout << "Email: ";
   cin >> dt.email.nickname;
   xml_node email = person.append_child("email");
   email.append_child(node_pcdata).set_value(dt.email.nickname.c_str());

   cout << "Age (optional): ";
   cin >> dt.age;
   string to_age;
   to_age = to_string(dt.age);
   xml_node age = person.append_child("age");
   age.append_child(node_pcdata).set_value(to_age.c_str());

   cout << "Phone (optional): ";
   cin.ignore();
   getline(cin, dt.phone);
   xml_node phone = person.append_child("phone");
   phone.append_child(node_pcdata).set_value(dt.phone.c_str());

   doc.save_file(file.c_str());
}

int main(int argc, char* argv[])
{
   string file = argv[1];
   Person person;
   SaveFile(person, file);
   return 0;
}
