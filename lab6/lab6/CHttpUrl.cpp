#include "CHttpUrl.h"
#include <iostream>
#include <algorithm>


CHttpUrl::CHttpUrl(string const& url)
{
	auto protocolPos = url.find("://");
	if (protocolPos == string::npos)
	{
		throw CUrlParsingError("Url must has protocol before \"://\".");
	}
	auto protocolString = url.substr(0, protocolPos);
	auto documentPos = url.find('/', protocolPos + 3);
	if (documentPos == string::npos)
	{
		documentPos = url.length();
	}
	else 
	if(documentPos == protocolPos + 3)
	{
		throw CUrlParsingError("Error: symbol / mustn't be after :// ");
	}
	auto domain = url.substr(protocolPos + 3, documentPos - protocolPos - 3);
	auto document = GetCorrectDocument(url, documentPos);
	auto port = (m_protocol == Protocol::HTTP) ? 80 : 443;
	m_domain = domain;
	m_protocol = GetCorrectProtocol(protocolString);;
	m_port = port;
	m_document = document;
}
CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol)
{
	CheckCorrectDomain(domain);
	m_document = (document[0] == '/') ? document : ("/" + document);
	m_domain = domain;
	m_protocol = protocol;
	m_port = protocol == Protocol::HTTP ? 443 : 80;
}

CHttpUrl::CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port)
{
	CheckCorrectDomain(domain);
	m_domain = domain;
	m_document = (document[0] == '/') ? document : ("/" + document);
	if (((port == 80) && (protocol == Protocol::HTTP)) || ((port == 443) && (protocol == Protocol::HTTPS)))
	{
		throw CUrlParsingError("Invalid port for this protocol");
	}
	m_protocol = protocol;
	m_port = port;
}

string CHttpUrl::GetDomain() const
{
	return m_domain;
}

string CHttpUrl::GetDocument() const
{
	return m_document.empty() ? "/" : m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

string CHttpUrl::GetUrl() const
{
	return (GetProtocol() == Protocol::HTTP ? "http" : "https") + string("://")
		+ GetDomain() + GetDocument();
}
Protocol CHttpUrl::GetCorrectProtocol(string& protocolString)
{
	transform(protocolString.begin(), protocolString.end(), protocolString.begin(), tolower);
	if (protocolString == "https")
		return Protocol::HTTPS;
	if (protocolString == "http")
		return Protocol::HTTP;
	throw CUrlParsingError("Uncorrect protocol");
}

string CHttpUrl::GetCorrectDocument(const string& url, unsigned short documentPos)
{
	auto document = url.substr(documentPos);
	document = (document[0] == '/') ? document : ("/" + document);
	if (document[1] == '/')
	{
		throw CUrlParsingError("Mustn't be 2 / after domain");
	}
	return document;
}

void CHttpUrl::CheckCorrectDomain(const string& domain)
{
	if (domain[0] == '/')
	{
		throw CUrlParsingError("Domain couldn't start with /");
	}
}
