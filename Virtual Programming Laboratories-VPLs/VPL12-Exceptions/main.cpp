#include <iostream>
#include <string>
#include <exception>
#include <vector>

class NegativeResultException : public std::exception {
    private:
    int value;

    public:
    virtual const char* what() const throw() {
        return "Erro: Resultado Negativo.";
    }
    explicit NegativeResultException(int value) : value(value) {};

    int get_value() const {
        return this->value;
    }
};

int main () {
    std::vector<int> v = {-20, -10, 0, 10, 20};

    try {
        int index;
        std::cin >> index;

        if(index < 0 || index >= v.size())
            throw std::out_of_range("Erro: Parametro invalido.");

        int num = v.at(index);

        if(num < 0)
            throw NegativeResultException(num);
        else if(num = 0)
            throw std::logic_error("Erro: O resultado nao deve ser zero.");
        std::cout << num << std::endl;

    } catch(const NegativeResultException& e) {
        std::cout << e.what() << std::endl; 
        std::cout << e.get_value() << std::endl;
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
    


}
