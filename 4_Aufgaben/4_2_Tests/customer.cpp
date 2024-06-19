#define BOOST_TEST_MODULE boost_test_sequence_per_element
#include <boost/test/included/unit_test.hpp>

#include <iostream>

class Account { 
private:
  unsigned int _amount; // Kontostand

public:
  // Konstruktor
  Account( unsigned int amount ) : _amount{ amount } {}

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

/*
 * Aufgabe: Einsetzen von Unit Tests, die die angegebene main ersetzen.
 * Dazu sollte eine 
 *   BOOST_AUTO_TEST_CASE( test_customer ) { ... } eingeführt werden
 * und darin verschiedene Tests ueber
 *   BOOST_TEST( ... );
 * durchgefuehrt werden.
 */
int main() {
  std::cout << std::boolalpha;

  Account a{ 25 };
  a.deposit( 75 );
  a.deposit( 50 );
  std::cout << (a.balance() == 150) << std::endl; // true 
  std::cout << a.withdraw( 25 )  << std::endl; // 25
  std::cout << (a.balance() ==  125) << std::endl; // true
  std::cout << a.withdraw( 150 ) << std::endl; // 0

  Account b{ a };
  std::cout << a.transfer( 50, a) << std::endl; // false
  std::cout << a.transfer( 126, b ) << std::endl; // false
  std::cout << a.transfer( 125, b ) << std::endl; // true 
  std::cout << (a.balance() == 0) << std::endl; // true 
  std::cout << (b.balance() == 250) << std::endl; // true 
}