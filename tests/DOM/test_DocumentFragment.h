#ifndef test_DocumentFragment_H
#define test_DocumentFragment_H

#include "../CppUnit/framework/TestCase.h"
#include "../CppUnit/framework/TestSuite.h"
#include "../CppUnit/framework/TestCaller.h"

#include <DOM/Simple/DOMImplementation.h>

template<class string_type, class string_adaptor>
class DocumentFragmentTest : public TestCase 
{
  DOM::DOMImplementation<string_type> factory;
  typedef string_adaptor SA;

  public: 
    DocumentFragmentTest(std::string name) :
        TestCase(name) 
    {
    } // DocumentFragmentTest
    
    void setUp() 
    {
      factory = SimpleDOM::DOMImplementation<string_type, string_adaptor>::getDOMImplementation();
    } // setUp

    void test1() 
    {
      DOM::DocumentFragment<string_type> d;
      DOM::Node<string_type> n;
      assert(d == 0);
      assert(n == 0);
      assert(n == d);
    } // test1

    void test2()
    {
      DOM::Document<string_type> d = factory.createDocument(SA::construct_from_utf8(""), SA::construct_from_utf8(""), 0);
      DOM::DocumentFragment<string_type> frag = d.createDocumentFragment();

      frag.appendChild(d.createElement(SA::construct_from_utf8("child")));
      frag.appendChild(d.createElement(SA::construct_from_utf8("child2")));
      frag.appendChild(d.createElement(SA::construct_from_utf8("child3")));

      assert(frag.getChildNodes().getLength() == 3);
    } // test2

    void test3()
    {
      DOM::Document<string_type> d = factory.createDocument(SA::construct_from_utf8(""), SA::construct_from_utf8(""), 0);
      DOM::DocumentFragment<string_type> frag = d.createDocumentFragment();
      frag.appendChild(d.createElement(SA::construct_from_utf8("child")));
      frag.appendChild(d.createElement(SA::construct_from_utf8("child2")));
      frag.appendChild(d.createElement(SA::construct_from_utf8("child3")));

      DOM::Element<string_type> elem = d.createElement(SA::construct_from_utf8("root"));
      elem.appendChild(frag);
      assert(elem.getChildNodes().getLength() == 3);
      assert(elem.getFirstChild().getNodeName() == SA::construct_from_utf8("child"));
      assert(elem.getLastChild().getNodeName() == SA::construct_from_utf8("child3"));
      assert(frag.getChildNodes().getLength() == 0);
    } // test3

    void test4()
    {
      DOM::Document<string_type> d = factory.createDocument(SA::construct_from_utf8(""), SA::construct_from_utf8(""), 0);
      DOM::DocumentFragment<string_type> frag = d.createDocumentFragment();
      frag.appendChild(d.createElement(SA::construct_from_utf8("child")));
      frag.appendChild(d.createElement(SA::construct_from_utf8("child2")));
      frag.appendChild(d.createElement(SA::construct_from_utf8("child3")));

      DOM::Element<string_type> elem = d.createElement(SA::construct_from_utf8("root"));
      elem.appendChild(d.createElement(SA::construct_from_utf8("t")));
      assert(elem.getChildNodes().getLength() == 1);

      elem.replaceChild(frag, elem.getFirstChild());
      assert(elem.getChildNodes().getLength() == 3);
      assert(elem.getFirstChild().getNodeName() == SA::construct_from_utf8("child"));
      assert(elem.getLastChild().getNodeName() == SA::construct_from_utf8("child3"));
      assert(frag.getChildNodes().getLength() == 0);
    } // test4

    void test5()
    {
      DOM::Document<string_type> d = factory.createDocument(SA::construct_from_utf8(""), SA::construct_from_utf8(""), 0);
      DOM::DocumentFragment<string_type> frag = d.createDocumentFragment();
      frag.appendChild(d.createElement(SA::construct_from_utf8("child")));
      frag.appendChild(d.createElement(SA::construct_from_utf8("child2")));
      frag.appendChild(d.createElement(SA::construct_from_utf8("child3")));

      DOM::Element<string_type> elem = d.createElement(SA::construct_from_utf8("root"));
      elem.appendChild(d.createElement(SA::construct_from_utf8("t")));
      assert(elem.getChildNodes().getLength() == 1);

      elem.insertBefore(frag, elem.getFirstChild());
      assert(elem.getChildNodes().getLength() == 4);
      assert(elem.getFirstChild().getNodeName() == SA::construct_from_utf8("child"));
      assert(elem.getLastChild().getNodeName() == SA::construct_from_utf8("t"));
      assert(frag.getChildNodes().getLength() == 0);
    } // test5
};

template<class string_type, class string_adaptor>
TestSuite* DocumentFragmentTest_suite() 
{
  TestSuite *suiteOfTests = new TestSuite;
  suiteOfTests->addTest(new TestCaller<DocumentFragmentTest<string_type, string_adaptor> >("test1", &DocumentFragmentTest<string_type, string_adaptor>::test1));
  suiteOfTests->addTest(new TestCaller<DocumentFragmentTest<string_type, string_adaptor> >("test2", &DocumentFragmentTest<string_type, string_adaptor>::test2));
  suiteOfTests->addTest(new TestCaller<DocumentFragmentTest<string_type, string_adaptor> >("test3", &DocumentFragmentTest<string_type, string_adaptor>::test3));
  suiteOfTests->addTest(new TestCaller<DocumentFragmentTest<string_type, string_adaptor> >("test4", &DocumentFragmentTest<string_type, string_adaptor>::test4));
  suiteOfTests->addTest(new TestCaller<DocumentFragmentTest<string_type, string_adaptor> >("test5", &DocumentFragmentTest<string_type, string_adaptor>::test5));
  return suiteOfTests;
} // DocumentFragmentTest_suite

#endif
