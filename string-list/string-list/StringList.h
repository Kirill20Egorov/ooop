#pragma once

#include <string>
#include <memory>

class CStringList
{
	struct Node
	{
		Node(const std::string& data, Node* prev, std::unique_ptr<Node>&& next)
			: data(data), prev(prev), next(std::move(next))
		{
		}
		std::string data;
		Node* prev;
		std::unique_ptr<Node> next;
	};
public:
	size_t GetSize()const;
	void PushBack(const std::string& data);
	void PushFront(const std::string& data);
	class CIterator
	{
		friend CStringList;
	public:
		CIterator() = default;
		CIterator(Node* node, bool isReverse);
		bool operator!=(CIterator const& other) const;
		bool operator==(CIterator const& other) const;

		CIterator& operator++();
		CIterator operator++(int);
		CIterator& operator--();
		CIterator operator--(int);
		std::string& operator*() const;
		std::string* operator->() const;
	private:
		Node* m_node = nullptr;
		bool m_isReverse = false;
	};
	void Append(const CIterator& it, std::string data);
	void Erase(const CIterator& it);
	CIterator begin();
	CIterator end();
	const CIterator cbegin() const;
	const CIterator cend() const;
	CIterator rbegin();
	CIterator rend();
	const CIterator crbegin() const;
	const CIterator crend() const;
	bool IsEmpty() const;
	void Clear();
	std::string& GetBackElement();
	std::string& GetFrontElement();
	std::string const& GetBackElement() const;
	std::string const& GetFrontElement() const;
private:
	size_t m_size = 0;
	std::unique_ptr<Node> m_firstNode;
	Node* m_lastNode = nullptr;
};