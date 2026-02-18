<?xml version="1.0"?>
<xsl:stylesheet version="1.0"
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" indent="yes"/>

<xsl:template match="/">
<html>
<head>
    <title>GoogleTest Report</title>
    <style>
        body { font-family: Arial; }
        table { border-collapse: collapse; width: 80%; }
        th, td { border: 1px solid black; padding: 6px; }
        th { background-color: #f2f2f2; }
        .pass { color: green; }
        .fail { color: red; }
    </style>
</head>
<body>
<h2>GoogleTest Report</h2>

<table>
<tr>
<th>Test Suite</th>
<th>Test Case</th>
<th>Status</th>
<th>Time</th>
</tr>

<xsl:for-each select="testsuites/testsuite/testcase">
<tr>
<td><xsl:value-of select="../@name"/></td>
<td><xsl:value-of select="@name"/></td>
<td>
<xsl:choose>
<xsl:when test="failure">
<span class="fail">FAILED</span>
</xsl:when>
<xsl:otherwise>
<span class="pass">PASSED</span>
</xsl:otherwise>
</xsl:choose>
</td>
<td><xsl:value-of select="@time"/></td>
</tr>
</xsl:for-each>

</table>

</body>
</html>
</xsl:template>

</xsl:stylesheet>
