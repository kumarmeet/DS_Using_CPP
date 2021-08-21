#include <bits/stdc++.h>
#include <limits>

using namespace std;

class ARRAY
{
private:
    int capacity;
    int index;
    int *arr;
    static int __cap;
    void swap(int &a, int &b)
    {
        int c;
        c = a;
        a = b;
        b = c;
    }

public:
    ARRAY(int cap) //constructor call for garbage initialized in array
    {
        capacity = cap;
        index = -1;
        arr = new int[capacity]; // dynamically memory allocation
    }

    ARRAY(int cap, int value) //constructor call for value initialized in array
    {
        capacity = cap;
        index = -1;
        arr = new int[capacity]; // dynamically memory allocation
        for (int i = 0; i < capacity; i++)
            arr[i] = value;
    }

    int getCapacity()
    {
        return capacity;
    }

    int getIndex()
    {
        return index;
    }

    void pushElement(int item)
    {
        if (getIndex() >= -1 && index < (getCapacity() - 1))
            arr[++index] = item;
        else if ((getIndex() + 1) == getCapacity())
            cout << "Over flow" << endl;
        __cap++; // this is for tracking print array
    }

    void operator[](int item) //operator overloading
    {
        if (getIndex() >= -1 && index < (getCapacity() - 1))
            arr[++index] = item;
        else if ((getIndex() + 1) == getCapacity())
            cout << "Over flow" << endl;
        __cap++; // this is for tracking print array
    }

    void insertElement(int idx, int item)
    {
        if (idx > -1 && idx < getCapacity())
        {
            capacity++;
            for (int i = getCapacity(); i >= idx; i--)
                arr[i] = arr[i - 1];
            arr[idx] = item;
            __cap++;
            index++;
        }
        else
            cout << "Invalid Index" << endl;
    }

    void updateArray(int idx, int item)
    {
        if (idx > -1 && idx < getCapacity())
            arr[idx] = item;
        else
            cout.operator<<("Invalid Index");
    }

    void sort() // insertion sort
    {
        int temp, j;
        for (int i = 1; i < getCapacity(); i++)
        {
            j = i - 1;
            temp = arr[i];

            while (j > -1 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    void reverse()
    {
        if (getCapacity() > 0)
        {
            int temp, j = (getCapacity() - 1);
            for (int i = 0; i < getCapacity() / 2; i++, j--)
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    int find(int item)
    {
        if (getCapacity() > 0)
        {
            for (int i = 0; i < getCapacity(); i++)
            {
                if (arr[i] == item)
                    return i;
            }
            return -1;
        }
        return -1;
    }

    int max()
    {
        if (getCapacity() > 0)
        {
            int max{INT32_MIN};
            for (int i = 0; i < getCapacity(); i++)
            {
                if (max < arr[i])
                    max = arr[i];
            }
            return max;
        }
        return -1;
    }

    int min()
    {
        if (getCapacity() > 0)
        {
            int min{INT32_MAX};
            for (int i = 0; i < getCapacity(); i++)
            {
                if (min > arr[i])
                    min = arr[i];
            }
            return min;
        }
        return -1;
    }

    int count()
    {
        return (getIndex() + 1);
    }

    bool isEmpty()
    {
        return (getIndex() == -1) ? true : false;
    }

    void deleteElement(int item)
    {
        int flag{0};
        if (getIndex() > -1)
        {
            for (int i = 0; i < getCapacity(); i++)
            {
                if (item == arr[i]) //1 2 3 4
                {
                    for (int j = i; j < getCapacity(); j++)
                        arr[j] = arr[j + 1];
                    index--;
                    __cap--;
                    flag = 1;
                    arr[getCapacity() - 1] = 0; // last array's element initialized with 0
                }
                if (flag)
                    break;
            }
        }
        else if (getIndex() == -1)
            cout << "Under flow" << endl;
    }

    void display()
    {
        if (getIndex() > -1 && __cap <= getCapacity())
        {
            for (int i = 0; i <= getIndex(); i++)
                cout << arr[i] << " ";
        }
    }
};

int ARRAY::__cap; //allocated static variable memory

int main()
{
    ARRAY arr(7, 0);

    arr.display();
    return 0;
}
