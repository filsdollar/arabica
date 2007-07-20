#ifndef ARABICA_XSLT_CALL_TEMPLATE_HANDLER_HPP
#define ARABICA_XSLT_CALL_TEMPLATE_HANDLER_HPP

#include "../xslt_call_template.hpp"
#include "xslt_with_param_handler.hpp"

namespace Arabica
{
namespace XSLT
{

class CallTemplateHandler : public SAX::DefaultHandler
{
public:
  CallTemplateHandler(CompilationContext& context) :
    context_(context),
    callTemplate_(0)
  {
  } // CallTemplateHandler

  virtual void startElement(const std::string& namespaceURI,
                            const std::string& localName,
                            const std::string& qName,
                            const SAX::Attributes& atts)
  {
    if(callTemplate_ == 0)
    {
      const std::string& name = atts.getValue("name");
      if(name == "")
        throw SAX::SAXException("xsl:call-template must have a name attribute.");
      if(atts.getLength() > 1)
        throw SAX::SAXException("xsl:call-template may only have a name attribute.");

      callTemplate_ = new CallTemplate(name);
      return;
    } // if(callTemplate_ == 0)

    if((namespaceURI == StylesheetConstant::NamespaceURI()) && (localName == "with-param"))
    {
      context_.push(0,
                    new WithParamHandler(context_, *callTemplate_),
                    namespaceURI, 
                    qName, 
                    localName, 
                    atts);
       return;
    } // if(localName == "with-param")
  
    throw SAX::SAXException("xsl:apply-templates can only contain xsl:sort and xsl:with-param elements.");
  } // startElement

  virtual void endElement(const std::string& namespaceURI,
                          const std::string& localName,
                          const std::string& qName)
  {
    context_.parentContainer().add_item(callTemplate_);
    context_.pop();
  } // endElement

  virtual void characters(const std::string& ch)
  {
  } // characters

private:
  CompilationContext& context_;
  CallTemplate* callTemplate_;
}; // class CallTemplateHandler

} // namespace XSLT
} // namespace Arabica

#endif // ARABICA_XSLT_CALL_TEMPLATE_HANDLER_HPP
