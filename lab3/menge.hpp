#include <iostream>

const int INT_MAX = 500;
class Menge{
    private:
        int* data;
        int num;
    public:
        Menge()
        {
            data = nullptr;
            num = 0;
        }
        bool insert(int x)
        {
            if(isElement(x)) return true;
            if(num==INT_MAX) return false;
            int* tmp = new int[num+1];
            for(int i = 0; i<num; i++)tmp[i] = data[i];
            tmp[num] = x;
            delete[] data;
            data=tmp;
            num++;
            return true;
        }

        bool isElement(int x)
        {
            for(int i = 0; i<num;i++)
            {
                if(data[i] == x) return true;
            }
            return false;
        }
        bool print()
        {
            for(int i = 0; i<num;i++)
            {
                std::cout<<data[i]<<" | ";;
            }
        }
};