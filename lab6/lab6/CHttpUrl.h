#include "CUrlParsingError.h"	

enum class Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	// выполн€ет парсинг строкового представлени€ URL-а, в случае ошибки парсинга
	// выбрасыват исключение CUrlParsingError, содержащее текстовое описание ошибки
	CHttpUrl(string const& url);

	/* инициализирует URL на основе переданных параметров.
		ѕри недопустимости входных параметров выбрасывает исключение
		std::invalid_argument
		≈сли им€ документа не начинаетс€ с символа /, то добавл€ет / к имени документа
	*/
	CHttpUrl(string const& domain, string const& document, Protocol  protocol);

	/* инициализирует URL на основе переданных параметров.
		ѕри недопустимости входных параметров выбрасывает исключение
		std::invalid_argument
		≈сли им€ документа не начинаетс€ с символа /, то добавл€ет / к имени документа
	*/
	CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port);

	// возвращает строковое представление URL-а. ѕорт, €вл€ющийс€ стандартным дл€
	// выбранного протокола (80 дл€ http и 443 дл€ https) в эту строку
	// не должен включатьс€
	//string GetURL()const;

	// возвращает доменное им€
	string GetDomain()const;

	/*
		¬озвращает им€ документа. ѕримеры:
			/
			/index.html
			/images/photo.jpg
	*/
	string GetDocument()const;

	// возвращает тип протокола
	Protocol GetProtocol()const;

	// возвращает номер порта
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
