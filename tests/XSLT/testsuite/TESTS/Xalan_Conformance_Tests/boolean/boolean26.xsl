<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

  <!-- FileName: boolean26 -->
  <!-- Document: http://www.w3.org/TR/xpath -->
  <!-- DocVersion: 19991116 -->
  <!-- Section: 3.4 -->
  <!-- Purpose: Test of boolean "or" operator with two false values -->

<xsl:template match="doc">
  <out>
    <xsl:value-of select="false() or false()"/>
  </out>
</xsl:template>

</xsl:stylesheet>
