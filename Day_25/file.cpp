#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &v);
int linearSearch(vector<int> v, int target);
void reverseVector(vector<int> &v);

int main()
{
    // // declare vector with fixed size by using small brackets (size of array , value)
    // vector<int> vec(5, 0);
    // // vector functions
    // // 01 - size()
    // cout << vec.size() << endl;
    // // 02 - push_back() - to add element at last
    // vec.push_back(50);
    // // 03 - pop_back() - to remove last element
    // vec.pop_back();
    // // 04 - front() - to print first element
    // cout << vec.front() << endl;
    // // 05 - back() - to print last element
    // cout << vec.back() << endl;
    // // 06 - at() - to print value at specific index works same as vec[i]
    // cout << vec.at(3) << endl;

    // examples of capacity & size of vector
    // vector<int> test;
    // test.push_back(50);
    // test.push_back(50);
    // test.push_back(50);
    // cout << test.size() << endl;
    // cout << test.capacity() << endl;
    // test.push_back(50);
    // test.push_back(50);
    // cout << test.size() << endl;
    // cout << test.capacity() << endl;

    vector<int> v = {4, 1, 2, 1, 2};
    // int x = singleNumber(v);
    // cout << "single number is: " << x << endl;
    // int target = 4;
    // int y = linearSearch(v, target);
    // cout << "target number exist at index: " << y << endl;
    reverseVector(v);
    return 0;
}

/*
 static memory allocation       vs        dynamic memory allocation
 allocated at compile time                allocate at run time
 i.e arrays                               i.e vecors
 in stack                                 in heap memory
*/

/*
  how vectors works internally ?
  when any element in vector is added it checks whether vector has capacity to accept it , if not then it creates
  a new vector of double size of first and copy all elements of first vector and add the desired element.

  Actually vector has two properties size and capacity , size mean how many elements are there in vector and capacity
  means how much capacity vector has to store elements i.e
  vec[1 , 3 , 4 ,  _ ] , now vector has 3 size and capacity is 4
*/

int singleNumber(vector<int> &v)
{
    int ans = 0;
    for (int i : v)
    {
        ans ^= i;
    }
    return ans;

    /*
    things to remember about xor operator
    n^n = 0
    n^0 = n
    */
}

int linearSearch(vector<int> v, int target)
{
    for (int x = 0; x < v.size(); x++)
    {
        if (v[x] == target)
        {
            return x;
        }
    }

    return -1;
}

void reverseVector(vector<int> &v)
{
    int start = 0, end = v.size() - 1;
    while (start < end)
    {
        swap(v[start], v[end]);
        start++;
        end--;
    }

    for (int z : v)
    {
        cout << z << " " << endl;
    }
    cout << endl;
}