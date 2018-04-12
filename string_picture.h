#ifndef __STRING_PICTURE_H_
#define __STRING_PICTURE_H_
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class StringPicture {
public:
    StringPicture() : width(0) {}

    StringPicture(const char** strArray, size_t cnt) : width(0) {
        for (size_t i = 0; i < cnt; ++i) {
            strElements.push_back(strArray[i]);
        }

        for (const string& element : strElements) {
            if (width < element.size())
                width = element.size();
        }
    }

    size_t GetWidth() const { return width; }
    size_t GetHeight() const { return strElements.size(); }
    const vector<string>& GetElements() const { return strElements; }

    void AddElement(const char* element) {
        strElements.push_back(element);
        if (strlen(element) > width)
            width = strlen(element);
    }

    void AddElement(const string& element) {
        strElements.push_back(element);
        if (element.size() > width)
            width = element.size();
    }

    StringPicture operator|(const StringPicture& pic) {
        StringPicture retPic;
        auto picElements = pic.GetElements();

        size_t maxHeight = strElements.size() < pic.GetHeight() ? pic.GetHeight() : strElements.size();
        string element;
        for (size_t i = 0; i < maxHeight; ++i) {
            element.clear();
            if (i < strElements.size()) {
                element.append(strElements[i]);
                for (size_t j = strElements[i].size(); j < width; ++j)
                    element.push_back(' ');
            }
            else {
                for (size_t j = 0; j < width; ++j)
                    element.push_back(' ');
            }

            if (i < pic.GetHeight()) {
                element.append(picElements[i]);
            }

            retPic.AddElement(element);
        }
        
        return retPic;
    }

    StringPicture operator&(const StringPicture& pic) {
        StringPicture retPic;

        for (const string &element : strElements) {
            retPic.AddElement(element);
        }

        auto picElements = pic.GetElements();
        for (const string& element : picElements) {
            retPic.AddElement(element);
        }

        return retPic;
    }

    friend ostream& operator<<(ostream& o, const StringPicture& pic) {
        for (const string& element : pic.strElements) {
            cout << element << '\n';
        }
        return o;
    }

private:
    vector<string> strElements;
    size_t width;
};

/********************************************************/
StringPicture frame(const StringPicture& pic) {
    StringPicture retPic;
    string firstElement;
    firstElement.push_back('+');
    for (size_t i = 0; i < pic.GetWidth(); ++i) {
        firstElement.push_back('-');
    }
    firstElement.push_back('+');
    retPic.AddElement(firstElement);

    string otherElement;
    const vector<string>& picElements = pic.GetElements();
    for (const string& element : picElements){
        otherElement.clear();
        otherElement.push_back('|');
        otherElement.append(element);
        for (size_t i = element.size(); i < pic.GetWidth(); ++i)
            otherElement.push_back(' ');
        otherElement.push_back('|');

        retPic.AddElement(otherElement);
    }

    retPic.AddElement(firstElement);
    return retPic;
}



#endif /*__STRING_PICTURE_H_*/