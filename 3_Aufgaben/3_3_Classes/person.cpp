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
// TODO: Implement the function.
};

class Person { 
// TODO: Implement the class.
};

class Customer final : public Person { 
// TODO: Derive customer and implement the class.
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

