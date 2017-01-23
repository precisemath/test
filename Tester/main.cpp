//
//  main.cpp
//  Tester
//
//  Created by Pavan Narendra on 5/22/16.
//  Copyright © 2016 Pavan Narendra. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <string>

using std::cout;
using std::endl;

//Used for map comparators
struct char_cmp {
    bool operator()(const char *a,const char *b) const {
        return strcmp(a, b) < 0;
    }
};

//Simple print function
void print (int &a) {
    cout << a << ' ';
}

//Simple square function
int square (int &a) {
    return a*a;
}

class AddValue {
private:
    int value;
public:
    AddValue(int v): value(v){
        cout << "In AddValue Constructor..." << endl;
    }
    
    void operator()(int &elem) {
        elem = value + elem;
    }
};

int main(int argc, const char * argv[]) {
    
    std::vector<int> a,b;
    
    for (int i = 0;i <=5;i++) {
        a.push_back(i);
    }
    
    //Copy example
    //Using a iterator adaptor
    std::copy(a.begin(), a.end(), std::back_inserter(b));
    
    for(std::vector<int>::iterator it = b.begin();it != b.end();it++) {
        std::cout << *it << std::endl;
    }
    
    std::deque<int> c;
    
    //Copy using a front inserter
    std::copy(a.begin(), a.end(), std::front_inserter(c));
    
    cout << "Print elements of deque c" << endl;
    
    for(std::deque<int>::iterator it = c.begin();it != c.end();it++) {
        std::cout << *it << std::endl;
    }
    
    //Copy using an inserter. Insert from teh second element onwards!
    std::copy(a.begin(), a.end(), std::inserter(c, c.begin()+1));
    
    cout << "Printing the elements of c after insertion from the second place onwards:" << endl;
    
    for(std::deque<int>::iterator it = c.begin();it != c.end();it++) {
        std::cout << *it << std::endl;
    }
    
    //Using for_each to print
    cout << "Print using the for_each function." << endl;
    std::for_each(a.begin(), a.end(), print);
    cout << endl;
    
    //Use foreach again
    cout << "Use for_each to add something to a" << endl;
    std::for_each(a.begin(), a.end(), AddValue(10));
    
    //Using stream iterators
    cout << "Print using output stream iterators" << endl;
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(cout," "));
    cout << endl;
    
    //Using transform
    cout << "Print the squares of a:" << endl;
    std::vector<int> sq;
    std::transform(a.begin(), a.end(), std::back_inserter(sq), square);
    std::copy(sq.begin(), sq.end(), std::ostream_iterator<int>(cout," "));
    cout << endl;
    
    //Find the minimum element
    cout << "The minimum element is:" << *std::min_element(a.begin(), a.end()) << endl;
    
    //Find the maximum element
    cout << "The maximum element is:" << *std::max_element(a.begin(), a.end()) << endl;
    
    //Find the eleement 4
    cout << "7 can be found at:" << *std::find(a.begin(), a.end(), 7) << endl;
    
    //map init example
    std::map<std::string, int> numbers;
    numbers["a"] = 1;
    numbers["b"] = 2;
    numbers["c"] = 3;
    numbers["d"] = 4;
    numbers["e"] = 5;
    
    for(std::map<std::string, int>::iterator it = numbers.begin();it != numbers.end();it++) {
        std::cout << it->first << std::endl;
        std::cout << it->second << std::endl;
    }

    //map init example
    std::map<const char*, int> numbers_char;
    numbers_char["a"] = 1;
    numbers_char["b"] = 2;
    numbers_char["c"] = 3;
    numbers_char["d"] = 4;
    numbers_char["e"] = 5;
    
    for(std::map<const char*, int>::iterator it = numbers_char.begin();it != numbers_char.end();it++) {
        std::cout << it->first << std::endl;
        std::cout << it->second << std::endl;
    }
    
    return 0;
}
