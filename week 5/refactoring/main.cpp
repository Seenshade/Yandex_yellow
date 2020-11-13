#include <iostream>
#include <string>
#include <vector>

/* 
  Замечания к исходному коду:
  1.[Дублирование кода]
  Во всех классах имеется поле Name, хотя по смыслу полицейского, студента и учителя объединяет то, что все они люди и у каждого своя роль.
  Решение: создать класс Human, с полем Name и конструктором, которым будут пользоваться дочерние классы при инициализации.
  
  2. В классах Teacher и Student нарушается базовый принцип ООП - инкапсуляция, их поля доступны для изменения снаружи.
  Решение: сделать данные поля приватными.

  3. Методы классов возвращающие их поля - должны быть константными, так как они не должны вносить изменения.
  Решение: добавить модификатор const к методам возвращающим поля класса.
  
  4.[Дублирование кода]
  Возможная ошибка при копировании в классе Student. Метод Walk содержит в себе реализацию класса SingSong.
  Решение: удалить строки не относящиеся логически к методу Walk

  5.[Дублирование кода]
  В классе Policeman метод Check перегружен 3 раза, для каждой роли.
  Решение: вместо обработки каждой роли, будем обрабатывать объект типа Human, в котором и содержатся для функции необходимые роль и имя.

  6.[Дублирование кода + неэффективная имплементация]
  Аналогично п.5, функция VisitPlaces реализована для каждой роли 3 раза.
  Решение: Аналогично п.5
  Замечание к функции: принимает копии объектов, вместо константных ссылок.

  7.[Дублирование кода]
  Метод Walk реализован для всех ролей, хотя данный метод присущ базовому классу Человек
  Решение: перенести реализацию в базовый класс.

  Итого:
  Было: 112 строк
  Стало: 93 строки
*/

using namespace std;

class Human{
public:
  virtual void Walk(const string& destination) const {
    cout << role_ << ": " << name_ << " walks to: " << destination << endl;
  };
  string Name() const {
    return name_;
  }
  string Role() const{
    return role_;
  }
  string Log() const {
    return role_ + ": " + name_;
  }
protected:
  Human(const string& name, const string& role)
  : name_(name)
  , role_(role)
  {};
private:
  const string name_;
  const string role_;
};

class Student : public Human {
public:
  Student(const string& name, const string& favouriteSong)
  : Human(name, "Student")
  , FavouriteSong(favouriteSong)
  {};

  void Walk(const string& destination) const override {
    cout << Log() << " walks to: " << destination << endl;
    cout << Log() << " sings a song: " << FavouriteSong << endl;
  };
  
  void Learn() const {
    cout << Log() << " learns" << endl;
  }

  void SingSong() const {
      cout << Log() << " sings a song: " << FavouriteSong << endl;
  }

private:
  const string FavouriteSong;
};

class Teacher : public Human{
public:
  Teacher(const string& name, const string& subject)
  : Human(name, "Teacher")
  , Subject(subject)
  {};

  void Teach() const {
    cout << Log() << " teaches: " << Subject << endl;
  }

private:
  const string Subject;
};


class Policeman : public Human {
public:
  Policeman(const string& name)
  : Human(name, "Policeman")
  {};
  void Check(const Human& h) const {
    cout << Log() << " checks " << h.Role() <<". " << h.Role() << "'s name is: " << h.Name() << endl;
  }
};

void VisitPlaces(Human& h, vector<string> places) {
  for (auto p : places) {
    h.Walk(p);
  }
}


int main() {
  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob");

  VisitPlaces(t, {"Moscow", "London"});
  p.Check(s);
  VisitPlaces(s, {"Moscow", "London"});
  return 0;
}