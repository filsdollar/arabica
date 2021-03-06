#ifndef test_nodeappendchilddocfragment
#define test_nodeappendchilddocfragment


/*
This C++ source file was generated for Arabica
from the source document contained in the W3C
DOM Conformance Test Suite.
The source document contained the following notice:


Copyright (c) 2001-2004 World Wide Web Consortium,
(Massachusetts Institute of Technology, Institut National de
Recherche en Informatique et en Automatique, Keio University). All
Rights Reserved. This program is distributed under the W3C's Software
Intellectual Property License. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.
See W3C License http://www.w3.org/Consortium/Legal/ for more details.

*/
/**
 *     Create and populate a new DocumentFragment object and
 *     append it to the second employee.   After the 
 *     "appendChild(newChild)" method is invoked retrieve the
 *     new nodes at the end of the list, they should be the
 *     two Element nodes from the DocumentFragment.
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-184E7107</a>
*/

template<class string_type, class string_adaptor>
class nodeappendchilddocfragment : public DOMTestCase<string_type, string_adaptor> 
{
    typedef DOMTestCase<string_type, string_adaptor> baseT;
   public: 
     nodeappendchilddocfragment(std::string name) : baseT(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = baseT::getContentType();
    baseT::preload(contentType, "staff", true);
    }

  typedef typename Arabica::DOM::DOMImplementation<string_type, string_adaptor>  DOMImplementation;
  typedef typename Arabica::DOM::Document<string_type, string_adaptor> Document; 
  typedef typename Arabica::DOM::DocumentType<string_type, string_adaptor> DocumentType;
  typedef typename Arabica::DOM::DocumentFragment<string_type, string_adaptor> DocumentFragment; 
  typedef typename Arabica::DOM::Node<string_type, string_adaptor> Node;
  typedef typename Arabica::DOM::Element<string_type, string_adaptor> Element;
  typedef typename Arabica::DOM::Attr<string_type, string_adaptor> Attr;
  typedef typename Arabica::DOM::NodeList<string_type, string_adaptor> NodeList;
  typedef typename Arabica::DOM::NamedNodeMap<string_type, string_adaptor> NamedNodeMap;
  typedef typename Arabica::DOM::Entity<string_type, string_adaptor> Entity;
  typedef typename Arabica::DOM::EntityReference<string_type, string_adaptor> EntityReference;
  typedef typename Arabica::DOM::CharacterData<string_type, string_adaptor> CharacterData;
  typedef typename Arabica::DOM::CDATASection<string_type, string_adaptor> CDATASection;
  typedef typename Arabica::DOM::Text<string_type, string_adaptor> Text;
  typedef typename Arabica::DOM::Comment<string_type, string_adaptor> Comment;
  typedef typename Arabica::DOM::ProcessingInstruction<string_type, string_adaptor> ProcessingInstruction;
  typedef typename Arabica::DOM::Notation<string_type, string_adaptor> Notation;

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
      DocumentFragment newdocFragment;
      Node newChild1;
      Node newChild2;
      Node child;
      String childName;
      std::vector<string_type> result;
      
      int nodeType;
      Node appendedChild;
      std::vector<string_type> expected;
      expected.push_back(SA::construct_from_utf8("employeeId"));
      expected.push_back(SA::construct_from_utf8("name"));
      expected.push_back(SA::construct_from_utf8("position"));
      expected.push_back(SA::construct_from_utf8("salary"));
      expected.push_back(SA::construct_from_utf8("gender"));
      expected.push_back(SA::construct_from_utf8("address"));
      expected.push_back(SA::construct_from_utf8("newChild1"));
      expected.push_back(SA::construct_from_utf8("newChild2"));
      
      doc = (Document) baseT::load("staff", true);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("employee"));
      employeeNode = elementList.item(1);
      childList = employeeNode.getChildNodes();
      newdocFragment = doc.createDocumentFragment();
      newChild1 = doc.createElement(SA::construct_from_utf8("newChild1"));
      newChild2 = doc.createElement(SA::construct_from_utf8("newChild2"));
      appendedChild = newdocFragment.appendChild(newChild1);
      appendedChild = newdocFragment.appendChild(newChild2);
      appendedChild = employeeNode.appendChild(newdocFragment);
      for (unsigned int indexN65695 = 0; indexN65695 != childList.getLength(); indexN65695++) {
          child = (Node) childList.item(indexN65695);
    nodeType = (int) child.getNodeType();
      
      if (baseT::equals(1, nodeType)) {
          childName = child.getNodeName();
      result.push_back(childName);
      }
      }
      baseT::assertEquals(expected, result, __LINE__, __FILE__);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/nodeappendchilddocfragment";
   }
};

#endif
