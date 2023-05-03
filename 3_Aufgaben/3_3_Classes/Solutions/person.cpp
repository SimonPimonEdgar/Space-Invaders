#include <iostream>

class Account { 
private:
  unsigned int _amount; // Kontostand

public:
  // Konstruktor
  Account( unsigned int amount=0 ) : _amount{ amount } {}

  // Zahle Betrag ’amount’ ein
  void deposit( unsigned int amount ) { _amount += amount;
}

// Hebe Betrag ’amount’ ab
unsigned int withdraw( unsigned int amount ) { 
  if( amount > _amount ) { return 0; } 
  _amount -= amount;
  return amount;
}

// Gib den aktuellen Kontostand zurück
unsigned int balance() const { return _amount; }

// Überweise Betrag ’amount’ auf das Konto ’account’.
// Gib ’false’ zurück, falls Betrag nicht verfügbar, ansonsten ’true’. 
bool transfer( unsigned int amount, Account& account ) {
  // Verbiete Überweisung auf das eigene Konto
  if( &account == this ) { 
    return false;
  }
  auto money = withdraw( amount ); 
  if( money == 0 ) {
    return false; 
  }
  account.deposit( money );
  return true; }
};

class Person { 
public:
  Person( const std::string& name, unsigned int age ) : 
          _name{ name },
          _age{ age } 
  {}

  virtual ~Person() = default;

  const std::string& name() const { return _name; }
  unsigned int age() const { return _age; }

  virtual void print() const {
    std::cout << _name << ", " << _age << std::endl;
  }

private:
  std::string _name; 
  unsigned int _age;
};

class Customer final : public Person { 
public:
  Customer( const std::string& name, unsigned int age, 
            unsigned int id ) :
      Person{ name, age }, 
      _id{ id },
      _account{}
  {}

  unsigned int id() const { return _id; }
  Account& account() { return _account; }

  void print() const override { 
    Person::print();
    std::cout << "Balance: " << _account.balance() << std::endl; 
  }

private:
  unsigned int _id; 
  Account _account;
};

int main() {
  Customer heinz{ "Heinz", 42, 1234 };
  Customer peter{ "Peter", 24, 5678 };
  Person& hr = heinz;
  heinz.account().deposit( 150 ); 
  heinz.account().transfer( 100, peter.account() ); 
  hr.print();
  peter.print();
}

/* Ausgabe: 
Heinz , 42 
Balance: 50 
Peter , 24 
Balance: 100 */

