#include <iostream>
using namespace std;
struct Element{
    char data;
    Element* Next;
};
class List{
    // Адрес головного элемента списка
    Element* Head;
    // Адрес головного элемента списка
    Element* Tail;
    // Количество элементов списка
    int Count;
public:
    // Конструктор
    List();
    // Деструктор
    ~List();// Добавление элемента в список
    // (Новый элемент становится последним)
    void Add(char data); // Удаление элемента списка
    // (Удаляется головной элемент)
    void Del();
    // Удаление всего списка
    void DelAll();  // Распечатка содержимого списка
    // (Распечатка начинается с головного элемента)
    void Print(); // Получение количества элементов, находящихся в списке
    int GetCount();
    void AddInPos(int p);
    void DelInPos(int p);
    int Search(Element* el);
};
List::List(){
    // Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}
List::~List(){
    // Вызов функции удаления
    DelAll();
}
int List::GetCount(){
    // Возвращаем количество элементов
    return Count;
}
void List::Add(char data){
    // создание нового элемента
    Element* temp = new Element;    // заполнение данными
    temp->data = data;
    // следующий элемент отсутствует
    temp->Next = NULL;
    // новый элемент становится последним элементом списка
    // если он не первый добавленный
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // новый элемент становится единственным
    // если он первый добавленный
    else {
        Head = Tail = temp;
    }
}
void List::Del(){
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->Next;
    // удаляем бывший головной элемент
    delete temp;
}
void List::DelAll(){
    // Пока еще есть элементы
    while (Head != 0)
    // Удаляем элементы по одному
        Del();
}
void List::Print(){
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы
    while (temp != 0)
    {
        // Выводим данные
        cout << temp->data << " ";
        // Переходим на следующий элемент
        temp = temp->Next;
    }
    cout << "\n\n";
} // Тестовый пример

void List::AddInPos(int p){
    Element* temp = new Element;
    Element* save = Tail;
    for (int i = 1; i < p; i++){
        Tail = Tail->Next;
    }
    temp->Next = Tail->Next;
    Count++;
    Tail = save;
    delete[] save;
    
}

void List::DelInPos(int p){
    Element* save = Tail;
    for (int i = 1; i < p - 1; i++){
        Tail = Tail->Next;
    }
    delete[] Tail->Next;
    Tail->Next = Tail->Next->Next;
    Tail = save;
    delete[] save;
    Count--;
}

int List::Search(Element* el){
    Element* save = Tail;
    for (int i = 1; i < Count; i++){
        Tail = Tail->Next;
        if (Tail->data == el->data && Tail->Next == el->Next){
            return i;
        }
    }
    return NULL;
}

int main(){
    // Создаем объект класса List
    List lst;   // Тестовая строка
    char s[] = "Hello, World !!!\n";
    // Выводим строку
    cout << s << "\n\n";
    // Определяем длину строки
    unsigned long len = strlen(s);
    // Загоняем строку в список
    for (int i = 0; i < len; i++)
        lst.Add(s[i]);
    // Распечатываем содержимое списка
    lst.Print();
    // Удаляем три элемента списка
    lst.Del();
    lst.Del();
    lst.Del();
    //Распечатываем содержимое списка
    lst.Print();
}
