#include <iostream>
#include <list>
#include <string>

#define SUCCESS 0

class Objects {
private:
    static int auto_id;
    static int counter;
    int id;
    
public:
    Objects(int id = 0) {
        if (id < 0)
            this->id = id;
        else
            this->id = auto_id++;
        
        counter++;
    }

    int get_id() const {
        return id;
    }

    static int get_counter() {
        return counter;
    }

    const void* get_memory_address() const {
        return static_cast<const void*>(this);
    }

    ~Objects() {
        counter--;
    }
};

int Objects::auto_id = 1;
int Objects::counter = 0;

int main() {
    std::list<Objects*> objects;

    while (true) {
        char command;
        std::cin >> command;

        if (command == 'A') {
            Objects* obj = new Objects();
            objects.push_back(obj);
            std::cout << obj->get_id() << " " << obj->get_memory_address() << std::endl;
        }

        else if (command == 'C') {
            int id;
            std::cin >> id;
            if (id >= 0) {
                std::cout << "ERRO" << std::endl;
            } else {
                Objects* obj = new Objects(id);
                objects.push_front(obj);
                std::cout << obj->get_id() << " " << obj->get_memory_address() << std::endl;
            }
        }

        else if (command == 'R') {
            if (objects.empty()) {
                std::cout << "ERRO" << std::endl;
            } else {
                Objects* frontObj = objects.front();
                std::cout << frontObj->get_id() << " " << frontObj->get_memory_address() << std::endl;
                delete frontObj; // Libera a memória
                objects.pop_front();
            }
        }

        else if (command == 'N') {
            std::cout << Objects::get_counter() << std::endl;
        }

        else if (command == 'P') {
            int element;
            std::cin >> element;
            if (element < 1 || element > static_cast<int>(objects.size())) {
                std::cout << "ERRO" << std::endl;
            } else {
                Objects* current = nullptr;
                int counter = 0;

                for (auto iterator : objects) {
                    counter++;
                    if (counter == element) {
                        current = iterator;
                        break;
                    }
                }
                if (current) {
                    std::cout << current->get_id() << " " << current->get_memory_address() << std::endl;
                }
            }
        }

        else if (command == 'L') {
            for (auto iterator : objects) {
                std::cout << iterator->get_id() << " " << iterator->get_memory_address() << std::endl;
            }
        }

        else if (command == 'E') {
            break;
        }
    }

    for (auto obj : objects) {
        delete obj;
    }
    objects.clear();

    return SUCCESS;
}