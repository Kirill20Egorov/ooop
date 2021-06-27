#include <iostream>
#include "CHttpUrl.h"

int main()
{
	string currUrl;
	while (cin >> currUrl)
	{
		try
		{
			auto url = CHttpUrl(currUrl);
			//cout << "Url: " << url.GetURL() << endl;
			cout << "Domain: " << url.GetDomain() << std::endl;
			cout << "Protocol: " << (url.GetProtocol() == Protocol::HTTP ? "http" : "https") << endl;
			cout << "Document: " << url.GetDocument() << std::endl;
			cout << "Port: " << url.GetPort() << std::endl;
	    }
		catch(CUrlParsingError &e)
		{
			cout << e.what() << endl;
		}
	}
}