#include "StringList.h"
#include <cassert>

using namespace std;

size_t CStringList::GetSize() const
{
	return m_size;
}

void CStringList::PushBack(const std::string& data)
{
	auto newNode = std::make_unique<Node>(data, m_lastNode, nullptr);
	Node* newLastNode = newNode.get();
	if (m_lastNode)
	{
		m_lastNode->next = std::move(newNode);
	}
	else
	{
		m_firstNode = std::move(newNode);
	}
	m_lastNode = newLastNode;
	++m_size;
}

void CStringList::PushFront(const std::string& data)
{
	auto newNode = make_unique<Node>(data, nullptr, move(m_firstNode));
	Node* newLastNode = newNode.get();
	if (newNode->next)
	{
		newNode->next->prev = newNode.get();
	}
	else // empty list
	{
		m_lastNode = newNode.get();
	}
	m_firstNode = move(newNode);
	++m_size;
}

bool CStringList::IsEmpty() const
{
	return (m_size == 0);
}

void CStringList::Clear() 
{
	while (m_lastNode)
	{
		m_lastNode->next = nullptr;
		m_lastNode = m_lastNode->prev;
	}
	m_firstNode = nullptr;
	m_size = 0;
}

CStringList::CIterator CStringList::begin()
{
	return CIterator(m_firstNode.get(), false);
}

CStringList::CIterator CStringList::end()
{
	return CIterator(m_lastNode, false);
}

CStringList::CIterator const CStringList::cbegin() const
{
	return CIterator(m_firstNode.get(), false);
}

CStringList::CIterator const CStringList::cend() const
{
	return CIterator(m_lastNode, false);
}
	
CStringList::CIterator CStringList::rbegin()
{
	return CIterator(m_lastNode, true);
}

CStringList::CIterator CStringList::rend()
{
	return CIterator(m_firstNode->prev, true);
}

CStringList::CIterator const CStringList::crbegin() const
{
	return CIterator(m_lastNode, true);
}

CStringList::CIterator const CStringList::crend() const
{
	return CIterator(m_firstNode->prev, true);
}

std::string& CStringList::GetBackElement()
{
	assert(m_lastNode);
	return m_lastNode->data;
}

std::string const& CStringList::GetBackElement() const
{
	assert(m_lastNode);
	return m_lastNode->data;
}

std::string& CStringList::GetFrontElement()
{
	assert(m_firstNode);
	return m_firstNode->data;
}

std::string const& CStringList::GetFrontElement() const
{
	assert(m_firstNode);
	return m_firstNode->data;
}

CStringList::CIterator::CIterator(Node* node, bool isReverse)
	:m_node(node)
	,m_isReverse(isReverse)
{
}

CStringList::CIterator& CStringList::CIterator::operator++()
{
	m_node = (m_isReverse ? m_node->prev : m_node->next.get());
	return *this;
}

bool CStringList::CIterator::operator!=(CIterator const& other) const
{
	return m_node != other.m_node;
}

bool CStringList::CIterator::operator==(CIterator const& other) const
{
	return m_node == other.m_node;
}


CStringList::CIterator CStringList::CIterator::operator++(int)
{
	auto returned = *this;
	++(*this);
	return returned;
}


CStringList::CIterator& CStringList::CIterator::operator--()
{
	m_node = (m_isReverse ? m_node->next.get() : m_node->prev);
	return *this;
}

CStringList::CIterator CStringList::CIterator::operator--(int)
{
	auto returned = *this;
	--(*this);
	return returned;
}

std::string& CStringList::CIterator::operator*() const
{
	return m_node->data;
}

std::string* CStringList::CIterator::operator->() const
{
	return &m_node->data;
}

void CStringList::Append(const CIterator& it, std::string data)
{
	if (it == begin())
	{
		PushFront(data);
	}
	else if (it == end())
	{
		PushBack(data);
	}
	else
	{
		auto newNode = make_unique<Node>(data, it.m_node->prev, move(it.m_node->prev->next));
		it.m_node->prev = newNode.get();
		newNode->prev->next = move(newNode);
		++m_size;
	}
}

void CStringList::Erase(const CIterator& it)
{
	if (it == begin())
	{
		if (m_size == 1)
		{
			Clear();
			return;
		}
		it.m_node->next.get()->prev = nullptr;
		m_firstNode = std::move(it.m_node->next);
	}
	else if (it.m_node->data == GetBackElement())
	{
		it.m_node->prev->next = nullptr;
		m_lastNode = it.m_node->prev;
	}
	else
	{
		it.m_node->next->prev = it.m_node->prev;
		it.m_node->prev->next = std::move(it.m_node->next);
	}
	--m_size;
}