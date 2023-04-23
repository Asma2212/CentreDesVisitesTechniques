#ifndef ELEMENTSMAP_H
#define ELEMENTSMAP_H
#include <map>
#include<vector>
using namespace std;

template<class K, class V>
class ElementsMap {
  private:
    map<K, V> elements;

  public:
    ElementsMap(){}
    virtual ~ElementsMap(){}

    void ajouterElement(const K& cle, const V& valeur);
    void supprimerElement(const K& cle);
    V getElement(const K& cle);
    vector<V> getElements();
};
#endif // ELEMENTSMAP_H
