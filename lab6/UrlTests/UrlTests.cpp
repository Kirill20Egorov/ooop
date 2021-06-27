#define CATCH_CONFIG_MAIN
#include "../lab6/CHttpUrl.h"
#include "../lab6/CUrlParsingError.h"
#include "../../catch2/catch.hpp"
#include <iostream>

SCENARIO("Some test without document")
{
	CHttpUrl vk = CHttpUrl("https://vk.com/");
	REQUIRE(vk.GetDocument() == "/");
	REQUIRE(vk.GetPort() == 443);
	REQUIRE(vk.GetProtocol() == Protocol::HTTPS);
	REQUIRE(vk.GetDomain() == "vk.com");	
	REQUIRE(vk.GetUrl() == "https://vk.com/");
	CHttpUrl git = CHttpUrl("git", "page25", Protocol::HTTP, 25);
	REQUIRE(git.GetDocument() == "/page25");
	REQUIRE(git.GetPort() == 25);
	REQUIRE(git.GetProtocol() == Protocol::HTTP);
	REQUIRE(git.GetDomain() == "git");
	REQUIRE(git.GetUrl() == "http://git/page25");
}

SCENARIO("Some test with document")
{
	CHttpUrl vk = CHttpUrl("https://vk.com/id222");
	REQUIRE(vk.GetDocument() == "/id222");
	REQUIRE(vk.GetPort() == 443);
	REQUIRE(vk.GetProtocol() == Protocol::HTTPS);
	REQUIRE(vk.GetDomain() == "vk.com");
	REQUIRE(vk.GetUrl() == "https://vk.com/id222");
}

SCENARIO("Some expections")
{
	WHEN("with double // after domain")
	{
		REQUIRE_THROWS(CHttpUrl("https://vk.com//id222"));
	}
	WHEN("With extra / after ://")
	{
		REQUIRE_THROWS(CHttpUrl("https:///vk.com//id222"));
	}
	WHEN("Uncorrect protocol")
	{
		REQUIRE_THROWS(CHttpUrl("htt:///vk.com//id222"));
		REQUIRE_THROWS_AS(CHttpUrl("htt:///vk.com//id222"), CUrlParsingError);
	}
	WHEN("Uncorrect sumbols after protocol")
	{
		REQUIRE_THROWS(CHttpUrl("http:://vk.com//id222"));
	}
	
	
}

SCENARIO("Some correct tests")
{
	CHttpUrl vk = CHttpUrl("vk.com", "id333", Protocol::HTTP, 443);
	REQUIRE(vk.GetDocument() == "/id333");
	REQUIRE(vk.GetPort() == 443);
	REQUIRE(vk.GetProtocol() == Protocol::HTTP);
	REQUIRE(vk.GetDomain() == "vk.com");
	REQUIRE(vk.GetUrl() == "http://vk.com/id333");
	CHttpUrl github = CHttpUrl("github.com", "Test", Protocol::HTTPS);
	REQUIRE(github.GetDocument() == "/Test");
	REQUIRE(github.GetDomain() == "github.com");
	REQUIRE(github.GetPort() == 80);
	REQUIRE(github.GetProtocol() == Protocol::HTTPS);
	REQUIRE(github.GetUrl() == "https://github.com/Test");
}

SCENARIO("Different uncorrect tests")
{
	try
	{
		CHttpUrl url("/github.com", "Test", Protocol::HTTP);
	}
	catch (CUrlParsingError& e)
	{
		string message = e.what();
		REQUIRE(message == "Domain couldn't start with /");
	}
	try
	{
		CHttpUrl url("vk.com", "id333", Protocol::HTTP, 80);
	}
	catch (CUrlParsingError& e)
	{
		string message = e.what();
		REQUIRE(message == "Invalid port for this protocol");
	}
	try
	{
		CHttpUrl url("vk.com", "id333", Protocol::HTTP, 80);
	}
	catch (CUrlParsingError& e)
	{
		string message = e.what();
		REQUIRE(message == "Invalid port for this protocol");
	}
	try
	{
		CHttpUrl url("vk.com", "id333", Protocol::HTTPS, 443);
	}
	catch (CUrlParsingError& e)
	{
		string message = e.what();
		REQUIRE(message == "Invalid port for this protocol");
	}
	try
	{
		CHttpUrl url("wikipedia.com", "/page23", Protocol::HTTP, 80);
	}
	catch (CUrlParsingError& e)
	{
		string message = e.what();
		REQUIRE(message == "Invalid port for this protocol");
	}
	try
	{
		CHttpUrl url("/wikipedia.com", "/page23", Protocol::HTTP, 443);
	}
	catch (CUrlParsingError& e)
	{
		string message = e.what();
		REQUIRE(message == "Domain couldn't start with /");
	}
}