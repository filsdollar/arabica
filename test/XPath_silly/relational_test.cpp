#ifdef _MSC_VER
#pragma warning(disable: 4786 4250 4503 4224 4180)
#endif
#include "../CppUnit/framework/TestCase.h"
#include "../CppUnit/framework/TestSuite.h"
#include "../CppUnit/framework/TestCaller.h"

#include <XPath/XPath.hpp>
#include "../silly_string/silly_string.hpp"
// let's see if this crazy gizmo really works
// and define a default_string_adaptor specialisation
template<> class Arabica::default_string_adaptor<silly_string> : public silly_string_adaptor { };

using namespace Arabica::XPath;

class RelationalTest : public TestCase
{
public:
  RelationalTest(const std::string& name) : TestCase(name)
  {
  } // RelationalTest

  void setUp()
  {
  } // setUp

  void test1()
  {
    XPathExpressionPtr<silly_string> equals1(new impl::EqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1)));
    XPathExpressionPtr<silly_string> equals2(new impl::EqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1)));

    assertEquals(true, equals1->evaluateAsBool(dummy_));
    assertEquals(true, equals2->evaluateAsBool(dummy_));
  } // test1

  void test2()
  {
    XPathExpressionPtr<silly_string> equals1(new impl::EqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(2)));
    XPathExpressionPtr<silly_string> equals2(new impl::EqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(2), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1)));

    assertEquals(false, equals1->evaluateAsBool(dummy_));
    assertEquals(false, equals2->evaluateAsBool(dummy_));
  } // test2

  void test3()
  {
    XPathExpressionPtr<silly_string> equals1(new impl::EqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1)));

    assertEquals(true, equals1->evaluateAsBool(dummy_));
  } // test3

  void test4()
  {
    XPathExpression<silly_string, Arabica::default_string_adaptor<silly_string> >* p1 = new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("charlie");
    XPathExpression<silly_string, Arabica::default_string_adaptor<silly_string> >* p2 = new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("charlie");

    XPathExpressionPtr<silly_string> equals1(new impl::EqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(p1, p2));

    assertEquals(true, equals1->evaluateAsBool(dummy_));
  } // test4

  void test5()
  {
    XPathExpression<silly_string, Arabica::default_string_adaptor<silly_string> >* p1 = new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("trousers");
    XPathExpression<silly_string, Arabica::default_string_adaptor<silly_string> >* p2 = new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("charlie");

    XPathExpressionPtr<silly_string> equals1(new impl::EqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(p1, p2));

    assertEquals(false, equals1->evaluateAsBool(dummy_));
  } // test5

  void test6()
  {
    XPathExpressionPtr<silly_string> equals1(new impl::EqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true)));
    XPathExpressionPtr<silly_string> equals2(new impl::EqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false)));

    assertEquals(true, equals1->evaluateAsBool(dummy_));
    assertEquals(true, equals2->evaluateAsBool(dummy_));
  } // test6

  void test7()
  {
    XPathExpressionPtr<silly_string> equals1(new impl::EqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false)));
    XPathExpressionPtr<silly_string> equals2(new impl::EqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true)));

    assertEquals(false, equals1->evaluateAsBool(dummy_));
    assertEquals(false, equals2->evaluateAsBool(dummy_));
  } // test7

  void testLessThan1()
  {
    XPathExpressionPtr<silly_string> lessThan1(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true)));
    XPathExpressionPtr<silly_string> lessThan2(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false)));
    XPathExpressionPtr<silly_string> lessThan3(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false)));
    XPathExpressionPtr<silly_string> lessThan4(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true)));

    assertEquals(false, lessThan1->evaluateAsBool(dummy_));
    assertEquals(false, lessThan2->evaluateAsBool(dummy_));
    assertEquals(false, lessThan3->evaluateAsBool(dummy_));
    assertEquals(true, lessThan4->evaluateAsBool(dummy_));
  } // testLessThan1

  void testLessThan2()
  {
    XPathExpressionPtr<silly_string> lessThan1(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1.0), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1.0)));
    XPathExpressionPtr<silly_string> lessThan2(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(3.0), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(2.0)));
    XPathExpressionPtr<silly_string> lessThan3(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(2.0), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(3.0)));
    XPathExpressionPtr<silly_string> lessThan4(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(-1), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1)));

    assertEquals(false, lessThan1->evaluateAsBool(dummy_));
    assertEquals(false, lessThan2->evaluateAsBool(dummy_));
    assertEquals(true, lessThan3->evaluateAsBool(dummy_));
    assertEquals(true, lessThan4->evaluateAsBool(dummy_));
  } // testLessThan2

  void testLessThan3()
  {
    XPathExpressionPtr<silly_string> lessThan1(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("1.0"), new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("1.0")));
    XPathExpressionPtr<silly_string> lessThan2(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("3.0"), new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("2.0")));
    XPathExpressionPtr<silly_string> lessThan3(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("2.0"), new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("3.0")));
    XPathExpressionPtr<silly_string> lessThan4(new impl::LessThanOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("-1"), new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("1")));

    assertEquals(false, lessThan1->evaluateAsBool(dummy_));
    assertEquals(false, lessThan2->evaluateAsBool(dummy_));
    assertEquals(true, lessThan3->evaluateAsBool(dummy_));
    assertEquals(true, lessThan4->evaluateAsBool(dummy_));
  } // testLessThan3

  void testLessThanEquals1()
  {
    XPathExpressionPtr<silly_string> lessThanEquals1(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true)));
    XPathExpressionPtr<silly_string> lessThanEquals2(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false)));
    XPathExpressionPtr<silly_string> lessThanEquals3(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false)));
    XPathExpressionPtr<silly_string> lessThanEquals4(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(false), new BoolValue<silly_string, Arabica::default_string_adaptor<silly_string> >(true)));

    assertEquals(true, lessThanEquals1->evaluateAsBool(dummy_));
    assertEquals(true, lessThanEquals2->evaluateAsBool(dummy_));
    assertEquals(false, lessThanEquals3->evaluateAsBool(dummy_));
    assertEquals(true, lessThanEquals4->evaluateAsBool(dummy_));
  } // testLessThanEquals1

  void testLessThanEquals2()
  {
    XPathExpressionPtr<silly_string> lessThanEquals1(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1.0), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1.0)));
    XPathExpressionPtr<silly_string> lessThanEquals2(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(3.0), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(2.0)));
    XPathExpressionPtr<silly_string> lessThanEquals3(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(2.0), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(3.0)));
    XPathExpressionPtr<silly_string> lessThanEquals4(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(-1), new NumericValue<silly_string, Arabica::default_string_adaptor<silly_string> >(1)));

    assertEquals(true, lessThanEquals1->evaluateAsBool(dummy_));
    assertEquals(false, lessThanEquals2->evaluateAsBool(dummy_));
    assertEquals(true, lessThanEquals3->evaluateAsBool(dummy_));
    assertEquals(true, lessThanEquals4->evaluateAsBool(dummy_));
  } // testLessThanEquals2

  void testLessThanEquals3()
  {
    XPathExpressionPtr<silly_string> lessThanEquals1(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("1.0"), new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("1.0")));
    XPathExpressionPtr<silly_string> lessThanEquals2(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("3.0"), new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("2.0")));
    XPathExpressionPtr<silly_string> lessThanEquals3(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("2.0"), new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("3.0")));
    XPathExpressionPtr<silly_string> lessThanEquals4(new impl::LessThanEqualsOperator<silly_string, Arabica::default_string_adaptor<silly_string> >(new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("-1"), new StringValue<silly_string, Arabica::default_string_adaptor<silly_string> >("1")));

    assertEquals(true, lessThanEquals1->evaluateAsBool(dummy_));
    assertEquals(false, lessThanEquals2->evaluateAsBool(dummy_));
    assertEquals(true, lessThanEquals3->evaluateAsBool(dummy_));
    assertEquals(true, lessThanEquals4->evaluateAsBool(dummy_));
  } // testLessThanEquals3

private:
  DOM::Node<silly_string> dummy_;
}; // class RelationalTest

TestSuite* RelationalTest_suite()
{
  TestSuite* tests = new TestSuite;

  tests->addTest(new TestCaller<RelationalTest>("test1", &RelationalTest::test1));
  tests->addTest(new TestCaller<RelationalTest>("test2", &RelationalTest::test2));
  tests->addTest(new TestCaller<RelationalTest>("test3", &RelationalTest::test3));
  tests->addTest(new TestCaller<RelationalTest>("test4", &RelationalTest::test4));
  tests->addTest(new TestCaller<RelationalTest>("test5", &RelationalTest::test5));
  tests->addTest(new TestCaller<RelationalTest>("test6", &RelationalTest::test6));
  tests->addTest(new TestCaller<RelationalTest>("test7", &RelationalTest::test7));

  tests->addTest(new TestCaller<RelationalTest>("testLessThan1", &RelationalTest::testLessThan1));
  tests->addTest(new TestCaller<RelationalTest>("testLessThan2", &RelationalTest::testLessThan2));
  tests->addTest(new TestCaller<RelationalTest>("testLessThan3", &RelationalTest::testLessThan3));

  tests->addTest(new TestCaller<RelationalTest>("testLessThanEquals1", &RelationalTest::testLessThanEquals1));
  tests->addTest(new TestCaller<RelationalTest>("testLessThanEquals2", &RelationalTest::testLessThanEquals2));
  tests->addTest(new TestCaller<RelationalTest>("testLessThanEquals3", &RelationalTest::testLessThanEquals3));

  return tests;
} // RelationalTest_suite