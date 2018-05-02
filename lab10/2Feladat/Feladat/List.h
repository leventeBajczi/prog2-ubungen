#ifndef SLIST_H
#define SLIST_H
#include <assert.h>


namespace LinkedList
{

	typedef void * POSITION;

	// Ein Forward-Deklaration (wegen Friend-Deklaration n�tig)
	template<class TYPE> class SList;

	template <class TYPE>
	class ListElement
	{
	private:
		friend class SList<TYPE>;
		TYPE data;
		ListElement* pNext;
		void operator=(const ListElement& obj){}
		ListElement(const ListElement& obj){};
	public:
		ListElement(const TYPE& data, ListElement* pNext) : data(data), pNext(pNext)
		{}
		TYPE& getData()
		{
			return data;
		}
		bool operator <(const ListElement& theOther)
		{
			return data < theOther.data;
		}
	};


	template<class TYPE>
	class SList
	{
		ListElement<TYPE> * pStart;

		// Hilfsfunktion f�r rekursives L�schen
		bool clear(ListElement<TYPE> *pCurrent, ListElement<TYPE> **pNext)
		{
			if(!pCurrent) return false;
			*pNext = pCurrent->pNext;
			free(pCurrent);
			return (*pNext) ? true : false; 
		}
		SList(const SList&) {};
		void operator=(const SList&) {};
		static ListElement<TYPE>* endSymbol;

	public:
		// Eine leere Liste erzeugen
		SList()
		{
			pStart = nullptr;
		}

		// Destruktor
		virtual ~SList();

		// Alle Listelemente entfernen
		void clear()
		{
			ListElement<TYPE> *pTemp, *pNext;
			pTemp = pStart;
			while(clear(pTemp, &pNext)) pTemp = pNext;
		}

		// Liefert die Position des ersten Elementes
		POSITION start() { return reinterpret_cast<POSITION>(pStart); }

		// Visszat�r az adot poz�ci�ra mutat� elem referenci�j�val.
		// Ha a visszat�r�sk�nt kapott elemet megv�ltoztatjuk,
		// a list�ban is megv�ltozik. Az elem t�rl�se �rv�nytelenn�
		// teszi a visszat�r�si �rt�ket.
		TYPE& getAt(POSITION posititon)
		{

		}

		// Liefert die "Position" (Iterator) auf dem Element nach dem
		// letzten Element (das ist keine g�ltige Position mehr!)
		POSITION end() {return 0;}

		// Liefert die Position des Elementes bevor "position"
		// (kostspielige Operation!)
		POSITION previous(const POSITION position)
		{
			
		}
		
		// Liefert die Position des Elementes nach "position"
		POSITION next(POSITION position);

		// F�gt ein Element "element" (als Kopie) zur Liste
		// nach Position "position" und liefert die Position
		// des neu eingef�gten Elementes
		POSITION insert_after(POSITION position, const TYPE& element);
		
		// F�gt ein Element "element" (als Kopie) zur Liste
		// nach dem letzten Element, und liefert die Position
		// des neu eingef�gten Elementes
		POSITION push_back(const TYPE & element);

		// Elt�vol�tja a megadott elemet a list�b�l, �s visszat�r vele
		TYPE remove(POSITION position); 
	};

	// Definition der statischen Variable
	template<class TYPE>
	ListElement<TYPE> * SList<TYPE>::endSymbol=0;
}
#endif // SLIST_H