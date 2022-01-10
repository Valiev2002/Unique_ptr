#include <iostream>
template <class T>
class unique_ptr {
private:
    T* ptr;
public:

    unique_ptr() {
ptr= nullptr;
    }

    ~unique_ptr() {
       delete ptr;
    }

    unique_ptr(unique_ptr<T>&&r) {
ptr=r.ptr;
delete r;
    }

    unique_ptr<T>& operator=(unique_ptr<T>&&r) {
        if(this != &r){
            if(ptr != nullptr){
                delete ptr;
            }
        }
        return *this;
    }

    void reset(T* ptr=nullptr) {
        if (ptr){
            *ptr =0;
        }
    }

    T* release()
    {
        if(get()==nullptr)
            delete ptr;
        return nullptr;
    }

    void swap(unique_ptr& r) {
if(ptr !=nullptr){
    ptr= r.ptr;
}
    }

    T* operator->() {
        return *ptr;
    }

    T& operator*() {
        return *ptr;
    }

    operator bool() const {
        if(*this == ptr)
            return true;
        else return false;
    }

    T* get() {
        return ptr;
    }
};
int main() {


}
