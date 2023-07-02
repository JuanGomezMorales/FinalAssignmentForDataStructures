#ifndef AssociativeArray_h
#define AssociativeArray_h
#pragma once
#include <iostream>
#include <queue>

template <typename K, typename V>
class AssociativeArray
{
  struct Node
  {
    K key;
    V value;
    Node* next;
  };

  Node* firstNode;
  int siz;

public:
  AssociativeArray(int = 2);
  AssociativeArray(const AssociativeArray<K, V>&);
  AssociativeArray<K, V>& operator=(const AssociativeArray<K, V>&);
  ~AssociativeArray();
  V operator[](const K&) const;
  V& operator[](const K&);
  bool containsKey(const K&) const;
  void deleteKey(const K&);
  std::queue<K> keys();
  int size() const;
  void clear();
};


template<typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(int cap)
{
  firstNode = nullptr;
  siz = 0;
}

template<typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V>& original)
{
  firstNode = nullptr;
  Node* lastNode = nullptr;
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->value = p->value;
    temp->key = p->key;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

template<typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray<K, V>& original)
{
  if (this != &original)
  {
    while (firstNode)
    {
      Node* p = firstNode;
      firstNode = firstNode->next;
      delete p;
    }

    Node* lastNode = nullptr;
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->value = p->value;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}

template<typename K, typename V>
AssociativeArray<K, V>::~AssociativeArray()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = p->next;
    delete p;
    siz--;
  }
}

template<typename K, typename V>
V AssociativeArray<K, V>::operator[](const K& key) const
{
  for (Node* p = firstNode; p; p = p->next)
  {
    if (p->key == key)
      return p->value;
  }
  return V();
}

template<typename K, typename V>
V& AssociativeArray<K, V>::operator[](const K& key)
{
  for (Node* p = firstNode; p; p = p->next)
  {
    if (p->key == key)
      return p->value;
  }
  Node* temp = new Node;
  temp->key = key;
  temp->value = V();
  temp->next = firstNode;
  firstNode = temp;
  ++siz;
  return firstNode->value;
}

template<typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& key) const
{
  for (Node* p = firstNode; p; p = p->next)
  {
    if (p->key == key)
      return true;
  }
  return false;
}

template<typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& key)
{
  Node* p, * prev;
  for (p = firstNode, prev = 0; p; prev = p, p = p->next)
  {
    if (p->key == key)
      break;
  }
  if (p)
  {
    --siz;
    if (prev) prev->next = p->next;
    else firstNode = p->next;
    delete p;
  }
}

template<typename K, typename V>
std::queue<K> AssociativeArray<K, V>::keys()
{
  std::queue<K> k_queue;
  for (Node* p = firstNode; p; p = p->next)
  {
    k_queue.push(p->key);
  }
  return k_queue;
}

template<typename K, typename V>
int AssociativeArray<K, V>::size() const
{
  return siz;
}

template<typename K, typename V>
void AssociativeArray<K, V>::clear()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = p->next;
    delete p;
    siz--;
  }
}
#endif
