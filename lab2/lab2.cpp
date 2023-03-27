#include <iostream>

class Element
{
    int Value;
    Element* NextPointer;
public:
    Element(int Value = 0, Element* NextPointer = nullptr) : Value(Value), NextPointer(NextPointer) {}
    int GetValue() { return Value; }
    void SetValue(int Value) { this->Value = Value; }
    Element *GetNextPointer() { return NextPointer; }
    void SetNextPointer(Element *NextPointer) { this->NextPointer = NextPointer; }
};

class Stack
{
    Element* FirstPointer;
public:
    Stack(Element* FirstPointer = nullptr) : FirstPointer(FirstPointer) {}
    Element &operator+=(int SubValue)
    {
        Element* currentElement = FirstPointer;
        while (currentElement != nullptr)
        {
            currentElement->SetValue(currentElement->GetValue() + SubValue);
        }
        return *FirstPointer;
    }

    Element &operator-=(int SubValue)
    {
        Element* currentElement = FirstPointer;
        while (currentElement != nullptr)
        {
            currentElement->SetValue(currentElement->GetValue() - SubValue);
        }
        return *FirstPointer;
    }

    int operator[](int SubValue)
    {
        Element* currentElement = FirstPointer;
        while (currentElement != nullptr and SubValue>=0)
        {
            if(SubValue==0)
                return currentElement->GetValue();
            SubValue--;
        }
    }

    friend std::istream &operator>>(std::istream &is, Stack &SubValue)
    {
        int Val;
        is >> Val;
        Element* temporary = new Element(Val, SubValue.FirstPointer);
        return is;
    }
    friend std::istream& operator<<(std::istream& is, Stack& SubValue)
    {
        int Val;
        is >> Val;
        Element* temporary = new Element(Val, SubValue.FirstPointer);
    }
};

int main()
{
    return 0;
}
