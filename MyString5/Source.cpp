#include <iostream>
#include <initializer_list>
using namespace std;

class MyString
{
    char* str;
    int length;

public:
    
    MyString()
    {
        length = 80;
        str = new char[length + 1];
        str[0] = '\0'; 
    }

    MyString(int size)
    {
        length = size;
        str = new char[length + 1];
        str[0] = '\0'; 
    }

    MyString(const char* input)
    {
        length = 0;
        while (input[length] != '\0')
        {
            length++;
        }

        str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            str[i] = input[i];
        }
        str[length] = '\0';
    }

    MyString(initializer_list<char> list)
    {
        length = list.size();
        str = new char[length + 1];
        int i = 0;
        for (char c : list)
        {
            str[i++] = c;
        }
        str[length] = '\0';
    }

    MyString(MyString&& other) noexcept
    {
        length = other.length;
        str = other.str;
        other.str = nullptr;
        other.length = 0;
    }

    MyString& operator=(MyString&& other) noexcept
    {
        if (this != &other)
        {
            delete[] str;
            length = other.length;
            str = other.str;
            other.str = nullptr;
            other.length = 0;
        }
        return *this;
    }

    ~MyString()
    {
        delete[] str;
    }

    void input()
    {
        cout << "Enter line: ";
        char temp[1000];
        cin.getline(temp, 1000);
        int newLength = 0;
        while (temp[newLength] != '\0')
        {
            newLength++;
        }
        delete[] str;
        str = new char[newLength + 1];
        for (int i = 0; i < newLength; i++)
        {
            str[i] = temp[i];
        }
        str[newLength] = '\0';
        length = newLength;
    }

    void output() const
    {
        cout << str << endl;
    }

    void MyStrcpy(MyString& obj)
    {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            str[i] = obj.str[i];
        }
        str[length] = '\0';
    }

    bool MyStrStr(const char* substr)
    {
        int substrLen = 0;
        while (substr[substrLen] != '\0')
        {
            substrLen++;
        }
        for (int i = 0; i <= length - substrLen; i++)
        {
            int j = 0;
            while (j < substrLen && str[i + j] == substr[j])
            {
                j++;
            }
            if (j == substrLen)
            {
                return true;
            }
        }
        return false;
    }

    int MyChr(char c)
    {
        for (int i = 0; i < length; i++)
        {
            if (str[i] == c)
            {
                return i;
            }
        }
        return -1;
    }

    int MyStrLen() const
    {
        return length;
    }

    void MyStrCat(MyString& b)
    {
        char* newStr = new char[length + b.length + 1];
        for (int i = 0; i < length; i++)
        {
            newStr[i] = str[i];
        }

        for (int i = 0; i < b.length; i++)
        {
            newStr[length + i] = b.str[i];
        }

        newStr[length + b.length] = '\0';
        delete[] str;
        str = newStr;
        length += b.length;
    }

    void MyDelChr(char c)
    {
        int newLength = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] != c)
            {
                newLength++;
            }
        }
        char* newStr = new char[newLength + 1];
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] != c)
            {
                newStr[j++] = str[i];
            }
        }
        newStr[newLength] = '\0';
        delete[] str; str = newStr;
        length = newLength;
    }

    int MyStrCmp(MyString& b)
    {
        for (int i = 0; i < length && i < b.length; i++)
        {
            if (str[i] < b.str[i])
            {
                return -1;
            }
            if (str[i] > b.str[i])
            {
                return 1;
            }
        }
        if (length < b.length)
        {
            return -1;
        }
        if (length > b.length)
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    MyString s1("Hip");
    MyString s2("Hop");

    s1.output();
    s2.output();

    cout << "String comparison: " << s1.MyStrCmp(s2) << endl;

    s1.MyStrCat(s2);
    s1.output();

    s1.MyDelChr('o');
    s1.output();

    MyString s3{ 'H', 'e', 'l', 'l', 'o' };
    s3.output();

    MyString s4 = move(s3);
    s4.output();

    MyString s5;
    s5 = move(s4);
    s5.output();

    return 0;
}