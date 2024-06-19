#include <iostream>

class Account { 
// TODO: Implement the class.
}

// Hebe Betrag ’amount’ ab
T withdraw( T amount ) { 
// TODO: Implement the function.
}

// Gib den aktuellen Kontostand zurück
T balance() const { 
// TODO: Implement the function.
}

// Überweise Betrag ’amount’ auf das Konto ’account’.
// Gib ’false’ zurück, falls Betrag nicht verfügbar, ansonsten ’true’. 
T transfer( T amount, Account& account ) {
// TODO: Implement the function.
};

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