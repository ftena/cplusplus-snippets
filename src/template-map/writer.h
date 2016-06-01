#include <map>

#ifndef WRITER_H
#define WRITER_H

template<typename  K, typename  V>
class Writer {
public:

    typedef typename std::map<K,V> TemplateMap;
    typedef typename TemplateMap::const_iterator const_iterator;

    Writer();

    void addGroup(K key, V value);

    TemplateMap getGroups();

private:
    TemplateMap my_map_;
};

template <typename  K, typename V>
Writer<K, V>::Writer ()
{

}

template <typename K, typename V>
void Writer<K, V>::addGroup (K key, V value)
{
    my_map_.insert(std::pair<K, V> (key, value));
}

template <typename K, typename V>
typename Writer<K, V>::TemplateMap Writer<K, V>::getGroups()
{
    return my_map_;
}

#endif // WRITER_H
