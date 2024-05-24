#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


class Apartments
{
private:
    int number;
    int floor;
    int apartmentType;
    vector<string> apartmentResident;
public:
    Apartments() : number(0), floor(0), apartmentType(0), apartmentResident({}) {}
    Apartments(int number, int floor, int apartmentType, vector<string> apartmentResident) :
    number(number),
    floor(floor),
    apartmentType(apartmentType),
    apartmentResident(apartmentResident)
    {}
    
    friend ostream& operator <<(ostream& os, const Apartments& apt)
    {
        os <<"Apartment number: "<< apt.number<<endl;
        os <<"Apartment floor: "<< apt.floor<<endl;
        os <<"Number of rooms in the apartment: "<< apt.apartmentType<<endl;
        os << "Residents of the apartment: ";
        for (size_t i = 0; i < apt.apartmentResident.size(); i++)
        {
            os << apt.apartmentResident[i]<< " ";
        }
            os << endl;
        os << endl;
        return os;
    }

    void print()
    {
        cout <<"Номер квартиры: "<<number<<endl;
        cout <<"Этаж квартиры: "<<floor<<endl;
        cout <<"Количество комнат в квартире: "<<apartmentType<<endl;
        cout<<"Жильцы в квартире: ";
        for (size_t i = 0; i < apartmentResident.size(); i++)
        {
            cout<<apartmentResident[i]<<" ";
        }
    }
    
    void printResidents()
    {
        for (size_t i = 0; i < apartmentResident.size(); i++)
        {
            cout<<apartmentResident[i]<<endl;
        }
    }
    
    
    
    void addNumberApartment(int valueNumb)
    {
        this->number = valueNumb;
    }
    
    void addFloorApartment(int valueFloor)
    {
        this->floor = valueFloor;
    }
    
    void addApartmentType(int valueApartmentType)
    {
        this->apartmentType = valueApartmentType;
    }
    
    void addResidentInApartment(string resident)
    {
        apartmentResident.push_back(resident);
    }
    
    void removeResidentInApartment(string resident)
    {
        for (size_t i = 0; i < apartmentResident.size(); i++)
        {
            if (apartmentResident[i] == resident)
            {
                apartmentResident.erase(apartmentResident.begin() + i);
            }
        }
    }
    
    int getNumberApartment() const
    {
        return number;
    }
    
    int getFloor()
    {
        return floor;
    }
    
    int getApartmentType()
    {
        return apartmentType;
    }
    
    
    vector<string> getApartmentResident()
    {
        return apartmentResident;
    }
    
    
    
    
};


int main()
{
    vector<Apartments> apartments;
    
    while (true)
    {
        int choice;
        cout<< "Доброго дня! Вас вітає Житловий фонд будинку"<<endl;
        cout<<"1 Додавання квартир.\n2 Видалення квартир.\n3 Закріплення мешканців за квартирою.\n4 Відкріплення мешканців від квартири.\n5 Збереження інформації у базу даних, цей файл корегувати заборонено!!!\n6 Завантаження інформації з бази даних.\n7 Відображення повного списку мешканців.\n8 Відображення повного переліку квартир.\n9 Відображення інформації про певну квартиру.\n10 Відображення інформації про квартири на певному поверсі.\n11 Відображення інформації про квартири одного типу (наприклад, відобразити усі однокімнатні квартири)\n12 Завантажити звіт у файл: 'forPrint.txt' для друку.\n\nНатисніть 0 для виходу з програми\nВведіть номер команды: ";
        cin>>choice;
        if (choice == 0)
        {
            break;
        }
        
        
        if (choice == 1)
        {
            int numbApart;
            int floorApart;
            int apartmentType;
            
            Apartments newApartment;
            
            cout<<endl;
            cout<<"Введите номер квартиры: ";
            cin>>numbApart;
            
            bool isUnique = true;
            for (const auto& apartment : apartments) 
            {
                if (apartment.getNumberApartment() == numbApart) {
                    isUnique = false;
                    break;
                }
            }
            if (!isUnique) 
            {
                cout << "Квартира с таким номером уже существует!" << endl;
                cout<<endl;
            }
            else
            {
                newApartment.addNumberApartment(numbApart);
                cout<<"Введите этаж квартиры: ";
                cin>>floorApart;
                newApartment.addFloorApartment(floorApart);
                cout<<"Введите количество комнат в квартире: ";
                cin>>apartmentType;
                newApartment.addApartmentType(apartmentType);
                apartments.push_back(newApartment);
                cout<<"Квартира успешно добавлена!"<<endl;
                cout<<endl;
                cout<<endl;
            }
            
            int choice;
            cout<<"Продолжить работу в программе?\n1 Да\n2 Нет\nВведите команду: ";
            cin>>choice;
            if (choice == 2)
            {
                break;
            }
            else
            {
                continue;
            }
            
        }
        
        if (choice == 2)
        {
            int choiceToDelete;
            cout << "Введите номер квартиры на удаление: ";
            cin >> choiceToDelete;

            vector<Apartments> updatedApartments;
            
            for (size_t i = 0; i < apartments.size(); i++)
            {
                if (apartments[i].getNumberApartment() == choiceToDelete)
                {}
                else
                {
                    updatedApartments.push_back(apartments[i]);
                }
            }

            apartments = updatedApartments;
            
            int choice;
            cout<<"Продолжить работу в программе?\n1 Да\n2 Нет\nВведите команду: ";
            cin>>choice;
            if (choice == 2)
            {
                break;
            }
            else
            {
                continue;
            }

        }
        
        if (choice == 3)
        {
            int choiceToAdd;
            cout << "Введите номер квартиры для добавления жильца(ов): ";
            cin >> choiceToAdd;
            cin.ignore();
            for (size_t i = 0; i < apartments.size(); i++)
            {
                if (apartments[i].getNumberApartment() == choiceToAdd)
                {
                    string resident;
                    cout<<"Введите ФИО жильца: ";
                    getline(cin, resident);
                    apartments[i].addResidentInApartment(resident);
                    cout << "Жилец успешно добавлен в квартиру." << endl;
                    break;
                }
            }
            
            int choice;
            cout<<"Продолжить работу в программе?\n1 Да\n2 Нет\nВведите команду: ";
            cin>>choice;
            if (choice == 2)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        
        if (choice == 4)
        {
            int choiceToDelete;
            cout << "Введите номер квартиры для удаление жильца: ";
            cin.ignore();
            cin >> choiceToDelete;
            cout<<endl;
            for (size_t i = 0; i < apartments.size(); i++)
            {
                if (apartments[i].getNumberApartment() == choiceToDelete)
                {
                    apartments[i].print();
                    cout<<endl;
                }
            }
            
            string deleteResident;
            cout << "Введите имя жильца, которого надо удалить из квартиры: ";
            cin>>deleteResident;
            
            
            for (size_t i = 0; i < apartments.size(); i++)
            {
                if (apartments[i].getNumberApartment() == choiceToDelete)
                {
                    apartments[i].removeResidentInApartment(deleteResident);
                    break;
                }
            }
            
            int choice;
            cout<<"Продолжить работу в программе?\n1 Да\n2 Нет\nВведите команду: ";
            cin>>choice;
            if (choice == 2)
            {
                break;
            }
            else
            {
                continue;
            }

        }
        
        if (choice == 5)
        {
            std::ofstream file("/Users/ivanrulevskiy/Desktop/WL/с ++/ExaminationTaskCpp/ExaminationTaskCpp/output.txt");

            if (!file.is_open()) {
                std::cerr << "Ошибка открытия файла!" << std::endl;
                return 1;
            }

            for (auto& apartment : apartments) {
                file << apartment.getNumberApartment() << " "
                     << apartment.getFloor() << " "
                     << apartment.getApartmentType() << " ";
                for (const auto& resident : apartment.getApartmentResident()) {
                    file << resident << " ";
                }
                file << "-" << std::endl;
            }

            file.close();
        }

        
        if (choice == 6)
        {
                    std::ifstream file("/Users/ivanrulevskiy/Desktop/WL/с ++/ExaminationTaskCpp/ExaminationTaskCpp/output.txt");

                    if (!file.is_open()) {
                        std::cerr << "Ошибка открытия файла!" << std::endl;
                        return 1;
                    }

                    apartments.clear();

                    int number, floor, apartmentType;
                    string line;

                    while (file >> number >> floor >> apartmentType) {
                        vector<string> residents;
                        string resident;
                        while (file >> resident) {
                            if (resident == "-") break;
                            residents.push_back(resident);
                        }
                        apartments.push_back(Apartments(number, floor, apartmentType, residents));
                    }

                    file.close();

                    cout << "Информация успешно загружена из файла." << endl;
                }

        if (choice == 7)
        {
            cout<<"Жильцы дома:"<<endl;
            for (size_t i = 0; i < apartments.size(); i++)
            {
                apartments[i].printResidents();
            }
            cout<<endl;
            
            int choice;
            cout<<"Продолжить работу в программе?\n1 Да\n2 Нет\nВведите команду: ";
            cin>>choice;
            if (choice == 2)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        
        if (choice == 8)
        {
            if (apartments.empty())
            {
                cout<<"В доме нет еще ни одной квартиры!"<<endl;
            }
            else
            {
                for (size_t i = 0; i < apartments.size(); i++)
                {
                    cout<<"Квартира "<< i + 1 <<endl;
                    apartments[i].print();
                    cout<<endl;
                }
            }
            int choice;
            cout<<"Продолжить работу в программе?\n1 Да\n2 Нет\nВведите команду: ";
            cin>>choice;
            if (choice == 2)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        
        if (choice == 9)
        {
            int newChoice;
            cout<<"Введите номер квартиры для отображения информации о ней: ";
            cin>>newChoice;
            for (size_t i = 0; i < apartments.size(); i++)
            {
                if (apartments[i].getNumberApartment() == newChoice)
                {
                    apartments[i].print();
                }
                cout<<endl;
            }
            int choice;
            cout<<"Продолжить работу в программе?\n1 Да\n2 Нет\nВведите команду: ";
            cin>>choice;
            if (choice == 2)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        
        if (choice == 10)
        {
            int newChoice;
            cout<<"Введите номер этажа для отображения всех квартир на этаже: ";
            cin>>newChoice;
            for (size_t i = 0; i < apartments.size(); i++)
            {
                if (apartments[i].getFloor() == newChoice)
                {
                    apartments[i].print();
                    cout<<endl;
                }
                cout<<endl;
            }
            int choice;
            cout<<"Продолжить работу в программе?\n1 Да\n2 Нет\nВведите команду: ";
            cin>>choice;
            if (choice == 2)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        
        if (choice == 11)
        {
            int newChoice;
            cout<<"Введите количество комнат в квартире для вывода однотипных квартир: ";
            cin>>newChoice;
            for (size_t i = 0; i < apartments.size(); i++)
            {
                if (apartments[i].getApartmentType() == newChoice)
                {
                    apartments[i].print();
                    cout<<endl;
                }
                cout<<endl;
            }
            int choice;
            cout<<"Продолжить работу в программе?\n1 Да\n2 Нет\nВведите команду: ";
            cin>>choice;
            if (choice == 2)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        
        if (choice == 12)
        {
            std::ofstream file("/Users/ivanrulevskiy/Desktop/WL/с ++/ExaminationTaskCpp/ExaminationTaskCpp/forPrint.txt");

            if (!file.is_open()) 
            {
                std::cerr << "Ошибка открытия файла!" << std::endl;
                return 1;
            }
            for (const auto& apartment : apartments)
            {
                file << apartment;
            }

            file.close();

            std::cout << "Данные успешно записаны в файл output.txt" << std::endl;
        }
        
        
    }
}
