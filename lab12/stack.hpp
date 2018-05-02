#include <stack>

template <class T>
class Stack 
{
private:
    std::stack<T> inhalt;
    int maxNummer;
public:
    Stack(int n = 0)
    {
        maxNummer = n;
    }	
    // Ein Stack erzeugen, mit n Stueck Elemente aus der typ T;			

    bool push(T t)
    {
        if(inhalt.size() > maxNummer)return false;
        inhalt.push(t);
        return true;
    }			
    // Neue element ins Stack platzieren
    // Rueckgabewert soll false sein wenn der Stack voll ist

    T  pop()
    {
        T ret = inhalt.top();
        inhalt.pop();
        return ret;
    }
    // Das zuletzt platzierte Element entnehmen

    bool isEmpty() const
    {
        return inhalt.size();
    }
    // True, falls der Stack leer ist

    bool dup()
    {
        if(inhalt.size() > maxNummer)return false;
        inhalt.push(inhalt.top());
    }
    // Dupliziert das letzte Element im Stack (platziert eine Kopie);
   // Rueckgabewert soll false sein wenn der Stack voll ist

    bool swap()
    {
        if(inhalt.size() <= 1) return false;
        T top = inhalt.top();
        inhalt.pop();
        T top2 = inhalt.top();
        inhalt.pop();
        inhalt.push(top);
        inhalt.push(top2);
        return true;
    }
    // Tauscht die zwei obersten Elemente des Stacks aus
    // Rueckgabewert soll false sein wenn der Stack leer ist

    int getSize() const
    {
        return inhalt.size();
    }		
    // Liefert die Anzahl der Elemente im Stack

};
