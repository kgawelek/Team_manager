#pragma once


template<class T>
class List_Element {
private:
	T element;
	List_Element* next = nullptr;

public:
    T& get_element() { return this->element; };
    List_Element* get_next() { return this->next; };
    void set_element(T new_element) { this->element = new_element; };
    void set_next(List_Element* new_next) { this->next = new_next; };

    template<class T> friend class My_list;
};


template<class T>
class My_list {
private:
	List_Element<T>* head = nullptr;

public:
    List_Element<T>* get_head() { return this->head; };
	
    void add_element(T t) {
        if (!head) {
            head = new List_Element<T>();
            head->element = t;

        }
        else {
            List_Element<T>* temp = this->head;
            while (temp->next)
                temp = temp->next;
            temp->next = new List_Element<T>();
            temp->next->element = t;
        }

    };


    void delete_element(List_Element<T>* el) {
        if (el == head) {
            List_Element<T>* temp = head->next;
            delete head;
            head = temp;

        }
        else {
            List_Element<T>* temp = head;
            while (temp->next && temp->next != el)
                temp = temp->next;
            if (temp->next) {
                List_Element<T>* temp2 = temp->next->next;
                delete temp->next;
                temp->next = temp2;
            }
        }
    };

    template <typename O>
    void print_elements(O& o) {
        List_Element<T>* temp = this->head;
        while (temp) {

            o << temp->element << std::endl;
            temp = temp->next;
        }
        std::cout << std::endl;
    }

};