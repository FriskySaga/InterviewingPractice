/**
 * C++14
 */

#include <cerrno>
#include <cstdio>
#include <cstring>
#include <iostream>

#include <rapidxml/rapidxml_print.hpp>
#include <rapidxml/rapidxml_utils.hpp>

int main()
{
  // Open 'Original.xml' to read from
  rapidxml::file<> xmlFile("Original.xml");
  rapidxml::xml_document<> doc;
  doc.parse<0>(xmlFile.data());

  // Get to <metadata> tag
  //                                       <root>        <metadata>    ???
  rapidxml::xml_node<>* metadataNode = doc.first_node()->first_node()->first_node();
  
  // Always correctly prints: 'Trying to change this'
  std::cout << "Before: " << metadataNode->value() << std::endl;

  // Modify the contents within <metadata>
  const std::string newMetadataValue = "Did the changing";
  metadataNode->value(newMetadataValue.c_str());

  // Always correctly prints: 'Did the changing'
  std::cout << "After: " << metadataNode->value() << std::endl;

  // Save output to 'New.xml'
  std::ofstream newXmlFile("New.xml");
  newXmlFile << doc;
  newXmlFile.close();
  doc.clear();

  return 0;
}

