
/*
This c++ source file was generated by for Arabica
and is a derived work from the source document.
The source document contained the following notice:


Copyright (c) 2001 World Wide Web Consortium,
(Massachusetts Institute of Technology, Institut National de
Recherche en Informatique et en Automatique, Keio University). All
Rights Reserved. This program is distributed under the W3C's Software
Intellectual Property License. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.
See W3C License http://www.w3.org/Consortium/Legal/ for more details.

*/

#ifndef test_hc_nodechildnodesappendchild
#define test_hc_nodechildnodesappendchild

#include "dom_conf_test.hpp"

/**
 *     The NodeList returned by the "getChildNodes()" method
 *     is live.   Changes on the node's children are immediately
 *     reflected on the nodes returned in the NodeList.
 *     
 *     Create a NodeList of the children of the second employee
 *     and then add a newly created element that was created
 *     by the "createElement()" method(Document Interface) to
 *     the second employee by using the "appendChild()" method.
 *     The length of the NodeList should reflect this new
 *     addition to the child list.   It should return the value 14.
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1451460987">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1451460987</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107</a>
* @see <a href="http://www.w3.org/Bugs/Public/show_bug.cgi?id=246">http://www.w3.org/Bugs/Public/show_bug.cgi?id=246</a>
* @see <a href="http://www.w3.org/Bugs/Public/show_bug.cgi?id=247">http://www.w3.org/Bugs/Public/show_bug.cgi?id=247</a>
*/

template<class string_type, class string_adaptor>
class hc_nodechildnodesappendchild : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     hc_nodechildnodesappendchild(std::string name) : DOMTestCase(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = getContentType();
    preload(contentType, "hc_staff", true);
    }

  typedef typename DOMTestCase<string_type, string_adaptor> baseT;
  using baseT::DOMImplementation;
  using baseT::Document; 
  using baseT::DocumentType;
  using baseT::DocumentFragment; 
  using baseT::Node;
  using baseT::Element;
  using baseT::Attr;
  using baseT::NodeList;
  using baseT::NamedNodeMap;
  using baseT::Entity;
  using baseT::EntityReference;
  using baseT::CharacterData;
  using baseT::CDATASection;
  using baseT::Text;
  using baseT::Comment;
  using baseT::ProcessingInstruction;
  using baseT::Notation;

  typedef typename Arabica::DOM::DOMException DOMException;
  typedef string_type String;
  typedef string_adaptor SA;
  typedef bool boolean;

   /*
    * Runs the test case.
    */
   void runTest()
   {
      Document doc;
      NodeList elementList;
      Node employeeNode;
      NodeList childList;
      Node createdNode;
      Node childNode;
      String childName;
      int childType;
      Node textNode;
      std::vector<string_type> actual;
      
      std::vector<string_type> expected;
      expected.push_back(SA::construct_from_utf8("em"));
      expected.push_back(SA::construct_from_utf8("strong"));
      expected.push_back(SA::construct_from_utf8("code"));
      expected.push_back(SA::construct_from_utf8("sup"));
      expected.push_back(SA::construct_from_utf8("var"));
      expected.push_back(SA::construct_from_utf8("acronym"));
      expected.push_back(SA::construct_from_utf8("br"));
      
      doc = (Document) load("hc_staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("p"));
      employeeNode = elementList.item(1);
      childList = employeeNode.getChildNodes();
      createdNode = doc.createElement(SA::construct_from_utf8("br"));
      employeeNode = employeeNode.appendChild(createdNode);
      for (int indexN65671 = 0; indexN65671 != childList.getLength(); indexN65671++) {
          childNode = (Node) childList.item(indexN65671);
    childName = childNode.getNodeName();
      childType = (int) childNode.getNodeType();
      
      if (equals(1, childType)) {
          actual.push_back(childName);
      } else {
          assertEquals(3, childType);
  }
        
      }
      assertEquals(expected, actual);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/hc_nodechildnodesappendchild";
   }
};

#endif