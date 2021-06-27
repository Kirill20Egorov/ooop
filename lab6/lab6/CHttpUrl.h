#include "CUrlParsingError.h"	

enum class Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	// ��������� ������� ���������� ������������� URL-�, � ������ ������ ��������
	// ���������� ���������� CUrlParsingError, ���������� ��������� �������� ������
	CHttpUrl(string const& url);

	/* �������������� URL �� ������ ���������� ����������.
		��� �������������� ������� ���������� ����������� ����������
		std::invalid_argument
		���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
	*/
	CHttpUrl(string const& domain, string const& document, Protocol  protocol);

	/* �������������� URL �� ������ ���������� ����������.
		��� �������������� ������� ���������� ����������� ����������
		std::invalid_argument
		���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
	*/
	CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port);

	// ���������� ��������� ������������� URL-�. ����, ���������� ����������� ���
	// ���������� ��������� (80 ��� http � 443 ��� https) � ��� ������
	// �� ������ ����������
	//string GetURL()const;

	// ���������� �������� ���
	string GetDomain()const;

	/*
		���������� ��� ���������. �������:
			/
			/index.html
			/images/photo.jpg
	*/
	string GetDocument()const;

	// ���������� ��� ���������
	Protocol GetProtocol()const;

	// ���������� ����� �����
	unsigned short GetPort()const;
	string PortToString(Protocol& protocol) const;
	string GetUrl() const;
private:
	string m_url;
	string m_domain;
	string m_document;
	Protocol m_protocol;
	unsigned short m_port;
	Protocol GetCorrectProtocol(string& protocol);
	string GetCorrectDocument(const string& url, unsigned short documentPos);
	void CheckCorrectDomain(const string& domain);
};
